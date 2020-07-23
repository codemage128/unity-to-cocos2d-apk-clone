#define COLLECT_PROPTERTY_KEYS

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;
using System.Security.Cryptography;
////////////////////////////
using Caravan.Meta.LevelMeta;
using ProtoBuf;
using ProtoBuf.Meta;
using ProtoBuf.Serializers;
using ProtoBuf.Compiler;

namespace ToonEditor {
    [DataContract] internal class LevelMetaInfo {
        [DataMember(Order = 0)] internal string fileName = "";
        [DataMember(Order = 1)] internal string description = "";

        public LevelMetaInfo(string sFile = "", string desc = "") { fileName = sFile; description = desc; }
    }
    [DataContract] internal class LevelMetaDataList {
        [DataMember] internal List<LevelMetaInfo> list = new List<LevelMetaInfo>();
    }


    class LevelManager 
    {
        static LevelManager _instance = null;
        public static LevelManager Instance {
            get { if (_instance == null) _instance = new LevelManager(); return _instance; }
            set { _instance = value; }
        }
        private string _importpath = "";
        private LevelMetaDataList filelist = null;
        Dictionary<string, int> LevelHashes = new Dictionary<string, int>();

        MD5 md5Hash = MD5.Create();

#if COLLECT_PROPTERTY_KEYS
        HashSet<string> properties = new HashSet<string>();
#endif

        public void import() {
            if(!Directory.Exists("import_json"))
                Directory.CreateDirectory("import_json");

            {
                // Configure open file dialog box
                OpenFileDialog dlg = new OpenFileDialog();
                dlg.FileName = DataStruct.Instance.LEVEL_IMPORT_DESCRIPTER; // Default file name
                dlg.DefaultExt = ".json"; // Default file extension
                dlg.Filter = "Level Descriptor (*.json)|*.json"; // Filter files by extension 

                // Process open file dialog box results 
                if (dlg.ShowDialog() != DialogResult.OK) 
                    return;

                DataStruct.Instance.LEVEL_IMPORT_DESCRIPTER = dlg.FileName;
                _importpath = Path.GetDirectoryName(DataStruct.Instance.LEVEL_IMPORT_DESCRIPTER) + "/";
            }

            try {
                FileStream stream = File.Open(DataStruct.Instance.LEVEL_IMPORT_DESCRIPTER, FileMode.Open);
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(LevelMetaDataList));
                filelist = (LevelMetaDataList)ser.ReadObject(stream);
                stream.Close();
            }
            catch (Exception eee) {
                MessageBox.Show(eee.Message, "Invalid Level Descriptor!!!");
                return;  
            }

            try {
                FileStream stream = File.Open(Path.Combine(_importpath, "registry.dat"), FileMode.Open);
                BinaryFormatter formatter = new BinaryFormatter();
                LevelHashes = (Dictionary<string, int>)formatter.Deserialize(stream);
                stream.Close();
            }
            catch (Exception rrr) {
                MessageBox.Show(rrr.Message, "Fail to Read registry.dat!!!");
            }

            foreach (LevelMetaInfo info in filelist.list) {
                LevelMetaData meta = (LevelMetaData)readLevel(_importpath + info.fileName);
                Level level = new Level();
                level._Name = meta.Name;
                level._Width = meta.Width;
                level._Height = meta.Height;
                level._MoveCount = meta.MoveCount;
                //GoalList
                foreach (GoalMetaData gmd in meta.GoalList) {  level._GoalList.Add(new Goal(gmd.Name, gmd.Count)); }
                //CellList
                level._CellList.Clear();
                foreach (CellMetaData cmd in meta.CellList) {
                    Cell cell = new Cell();
                    cell._BubbleCount = cmd.BubbleCount;
                    cell._TiledObject._Id = (TileSelect.TiledEditorId)cmd.TiledObject.Id;
                    cell._TiledObject._Ratio = cmd.TiledObject.Ratio;
                    foreach (MapFieldEntry mfe in cmd.TiledObject.Properties) { 
                        cell._TiledObject._Properties.Add(new Property(mfe.key, mfe.value));
#if COLLECT_PROPTERTY_KEYS
                        if (!properties.Contains(mfe.key))  properties.Add(mfe.key);
#endif
                    }

                    level._CellList.Add(cell);
                }
                //GroupList
                level._GroupList.Clear();
                foreach (GroupMetaData grmd in meta.GroupList) {
                    Group grp = new Group();
                    grp._Name = grmd.Name;
                    grp._Ratio = grmd.Ratio;
                    grp._ConditionAndIsUsed = grmd.ConditionAndIsUsed;
                    grp._GeneratePerTurn = grmd.GeneratePerTurn;
                    foreach (TiledObjectMetaData tomd in grmd.Items) {
                        Tile tile = new Tile();
                        tile._Id = (TileSelect.TiledEditorId)tomd.Id;
                        tile._Ratio = tomd.Ratio;
                        foreach (MapFieldEntry mfe in tomd.Properties)
                            tile._Properties.Add(new Property(mfe.key, mfe.value));
                        grp._Items.Add(tile);
                    }
                    foreach (MapFieldEntry mfe in grmd.Conditions) { grp._Conditions.Add(new Property(mfe.key, mfe.value)); }
                    grp._DropInterval = grmd.DropInterval;
                    foreach (int pos in grmd.DropPosList) { grp._DropPosList.Add(pos); }
                    grp._UseForDrop = grmd.UseForDrop;
                    grp._BarrelWeights = grmd.BarrelWeights;
                    level._GroupList.Add(grp);
                }

                //Stars
                level._Stars.Clear();
                foreach (int star in meta.Stars) { level._Stars.Add(star); }
                //Tutorial
                if (meta.Tutorial != null) {
                    level._Tutorial._Level = meta.Tutorial.Level;
                    level._Tutorial._Text = meta.Tutorial.Text;
                    foreach (int item in meta.Tutorial.Highlights) { level._Tutorial._Highlights.Add(item); }
                }
                //_PotionColorData
                foreach (int item in meta.PotionColorData) { level._PotionColorData.Add(item); }

                //Save To Json
                string sJsonPath = "import_json/" + info.description.Split(new char[] { '_', 'v' })[0];
                level.save(sJsonPath);
            }

#if COLLECT_PROPTERTY_KEYS
            //Genarate Sortied EnumClass 
            FileStream fs = File.Open("Properies.txt", FileMode.Create);
            StringBuilder sb = new StringBuilder();
            foreach (string name in properties) { sb.AppendLine(name); }
            byte[] bytes = Encoding.UTF8.GetBytes(sb.ToString());
            fs.Write(bytes, 0, bytes.Length);
            fs.Close();
#endif
        }

        public LevelMetaData readLevel(string filepath) {
            LevelMetaData ret = null;
            try {
                FileStream stream = File.Open(filepath, FileMode.Open);
                LevelDataMetaSerializer ser = new LevelDataMetaSerializer();
                ret = ser.DeserializeWithLengthPrefix(stream, null, typeof(LevelMetaData), PrefixStyle.Fixed32BigEndian, 3) as LevelMetaData;
            }
            catch (Exception ex) {
                MessageBox.Show(ex.Message, "ReadLevel Error!");
            }//*/
            return ret;
        }

        static string GetMd5Hash(MD5 md5Hash, string input)   {
            byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(input)); // Convert the input string to a byte array and compute the hash. 
            StringBuilder sBuilder = new StringBuilder();
            for (int i = 0; i < data.Length; i++)
                sBuilder.Append(data[i].ToString("x2"));
            return sBuilder.ToString();
        }


        public void export() {
            filelist = new LevelMetaDataList();
            Dictionary<string, int> LevelHashes = new Dictionary<string, int>();

            ////////////
            FolderBrowserDialog dlg = new FolderBrowserDialog();
            dlg.Description =       "Select the directory that you want to use as the default.";
            dlg.ShowNewFolderButton = true;
            dlg.RootFolder = Environment.SpecialFolder.MyComputer;
            dlg.SelectedPath = DataStruct.Instance.LEVEL_EXPORT_PATH;
            if (dlg.ShowDialog() != DialogResult.OK)
                return;

            DataStruct.Instance.LEVEL_EXPORT_PATH = dlg.SelectedPath;

            for (int idx = 1; idx <= DataStruct.Instance.MAX_LEVEL; idx++) {
                if(!File.Exists(Level.levelpath(idx)))
                    continue;
                Level level = Level.load(idx);
                LevelMetaInfo info = new LevelMetaInfo(GetMd5Hash(md5Hash, level._Name)+".bin", level._Name);
                filelist.list.Add(info);
                if (LevelHashes.Keys.Contains(info.fileName)) {
                    MessageBox.Show(string.Format("{0}-{1}-{2}", info.fileName, LevelHashes[info.fileName], idx), "Duplicated fileName !!!");
                }
                else
                    LevelHashes.Add(info.fileName, idx);

                //////////////////////
                LevelMetaData meta = new LevelMetaData();
                meta.Name = level._Name;
                meta.Width = level._Width;
                meta.Height = level._Height;
                meta.MoveCount = level._MoveCount;
                //GoalList
                foreach (Goal goal in level._GoalList) { GoalMetaData gmd = new GoalMetaData(); gmd.Name = goal._Name; gmd.Count = goal._Count; meta.GoalList.Add(gmd); }
                //CellList
                foreach (Cell cell in level._CellList) {
                    CellMetaData cmd = new CellMetaData();
                    cmd.BubbleCount = cell._BubbleCount;
                    cmd.TiledObject = new TiledObjectMetaData();
                    cmd.TiledObject.Id = (Int32)cell._TiledObject._Id;
                    cmd.TiledObject.Ratio = cell._TiledObject._Ratio;
                    foreach (Property prop in cell._TiledObject._Properties) { MapFieldEntry mfe = new MapFieldEntry(); mfe.key = prop._key; mfe.value = prop._value; cmd.TiledObject.Properties.Add(mfe); }
                    meta.CellList.Add(cmd);
                }
                //GroupList
                foreach (Group grp in level._GroupList) {
                    GroupMetaData grmd = new GroupMetaData();
                    grmd.Name = grp._Name;
                    grmd.Ratio = grp._Ratio;
                    grmd.ConditionAndIsUsed = grp._ConditionAndIsUsed;
                    grmd.GeneratePerTurn = grp._GeneratePerTurn;
                    if (grp._Items != null) foreach (Tile tile in grp._Items) {
                        TiledObjectMetaData tomd = new TiledObjectMetaData();
                        tomd.Id = (Int32)tile._Id;
                        tomd.Ratio = tile._Ratio;
                        foreach (Property prop in tile._Properties) { MapFieldEntry mfe = new MapFieldEntry(); mfe.key = prop._key; mfe.value = prop._value; tomd.Properties.Add(mfe); }
                        grmd.Items.Add(tomd);
                    }
                    if(grp._Conditions!= null) foreach (Property prop in grp._Conditions) { MapFieldEntry mfe = new MapFieldEntry(); mfe.key = prop._key; mfe.value = prop._value; grmd.Conditions.Add(mfe); }
                    grmd.DropInterval = grp._DropInterval;
                    if(grp._DropPosList != null) foreach (int pos in grp._DropPosList) { grmd.DropPosList.Add(pos); }
                    grmd.UseForDrop = grp._UseForDrop;
                    grmd.BarrelWeights = grp._BarrelWeights;
                }

                //Stars
                meta.Stars.Clear();
                foreach (int star in level._Stars) { meta.Stars.Add(star); }
                //Tutorial
                if (level._Tutorial != null) {
                    meta.Tutorial = new TutorialMetaData();
                    meta.Tutorial.Level = level._Tutorial._Level;
                    meta.Tutorial.Text = level._Tutorial._Text;
                    foreach (int item in level._Tutorial._Highlights) { meta.Tutorial.Highlights.Add(item); }
                }
                //_PotionColorData
                if (level._PotionColorData != null) foreach (int item in level._PotionColorData) { meta.PotionColorData.Add(item); }

                //Save To binary
                string sJsonPath = DataStruct.Instance.LEVEL_EXPORT_PATH + "/" + info.fileName;
                writeLevel(meta, sJsonPath);
            }

            //write "desc.json"
            try {
                string sDesc = Path.Combine(DataStruct.Instance.LEVEL_EXPORT_PATH, "desc.json");
                FileStream stream = File.Open(sDesc, FileMode.Create);
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(LevelMetaDataList)); 
                ser.WriteObject(stream, filelist);
                stream.Flush();
                stream.Close();
            }
            catch (Exception eee) {
                MessageBox.Show(eee.Message, "Fail to Save Level Descriptor!!!");
                return;
            }

            //write "registry.dat"
            try {
                string sRegistry = Path.Combine(DataStruct.Instance.LEVEL_EXPORT_PATH, "registry.dat");
                FileStream stream = File.Open(sRegistry, FileMode.Create);
                BinaryFormatter formatter = new BinaryFormatter();
                formatter.Serialize(stream, LevelHashes);
                stream.Flush();
                stream.Close();
            }
            catch (Exception rrrr) {
                MessageBox.Show(rrrr.Message, "Fail to Save registry.dat!!!");
                return;
            }
        }

        public void writeLevel(LevelMetaData meta, string filepath) {
            try {
                FileStream stream = File.Open(filepath, FileMode.Create);
                LevelDataMetaSerializer ser = new LevelDataMetaSerializer();
                ser.SerializeWithLengthPrefix(stream, meta, typeof(LevelMetaData), PrefixStyle.Fixed32BigEndian, 3);
                stream.Close();
            }
            catch (Exception ex) {
                MessageBox.Show(ex.Message, "WriteLevel Error!");
            }//*/
        }
    }
}
