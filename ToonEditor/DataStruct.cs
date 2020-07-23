using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.IO;
using System.Xml;
using System.Windows.Forms;

namespace ToonEditor {
    [DataContract] internal class DataStruct {
        static DataStruct _instance = null;
        public static DataStruct Instance {
            get { if (_instance == null) _instance = new DataStruct(); return _instance; }
            set { _instance = value; }
        }
        [DataMember(Order=0)] internal int MAX_WIDTH = 9;
        [DataMember(Order=1)] internal int MIN_WIDTH = 5;
        [DataMember(Order=2)] internal int MAX_HEIGHT = 100;
        [DataMember(Order=3)] internal int MIN_HEIGHT = 1;

        [DataMember(Order=4)] internal int MAX_LEVEL = 1350;
        [DataMember(Order=5)] internal string PATH_LEVEL = "res/level/";
        [DataMember(Order=6)] internal string PATH_PLAYER = "ToonBlast.exe";
        [DataMember(Order=7)] internal string LEVEL_NAMEFORMAT = "D4";
        [DataMember(Order=8)] internal int LEVEL_INDEXGUARD = 1500;
        [DataMember(Order=9)] internal bool EDITABLE = false;

        [DataMember(Order = 10)]
        internal string LEVEL_IMPORT_DESCRIPTER = "C:/Users/KimCholSong/Documents/Virtuous Ten Studio/Projects/UnityToCocos/tbwork/Data/assets/peak/desc.json";
        [DataMember(Order = 11)]
        internal string LEVEL_EXPORT_PATH = "C:/Users/KimCholSong/Documents/Virtuous Ten Studio/Projects/UnityToCocos/tbwork/Data/assets/peak";

        public void load() {
            string file_path = Application.ExecutablePath.Split(new char[] { '\\', '/' }).Last().ToLower() + ".json";
            if (File.Exists(file_path)) {
                FileStream stream = File.Open(file_path, FileMode.Open);
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(DataStruct));
                DataStruct.Instance = (DataStruct)ser.ReadObject(stream);
                stream.Close();
            }
        }
        public void save() {
            //Save DataStruct Constants.
            try {
                string file_path = Application.ExecutablePath.Split(new char[] { '\\', '/' }).Last().ToLower() + ".json";
                FileStream stream = File.Open(file_path, FileMode.Create, FileAccess.Write);
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(DataStruct));
                XmlDictionaryWriter writer = JsonReaderWriterFactory.CreateJsonWriter(stream, Encoding.UTF8, false, true, "    ");
                ser.WriteObject(writer, DataStruct.Instance);
                writer.Flush();
                stream.Close();
            }
            catch (System.IO.IOException ioe) {
                MessageBox.Show(ioe.Message.ToString(), "Fail to Load DataStruct!");
            }
        }
    }

    [DataContract] internal class Property {
        public Property(string key = "", string value = "") { _key = key; _value = value; }
        [DataMember(Order=0)] public string _key = "Frame";
        [DataMember(Order=1)] public string _value = "1";
    }

    [DataContract]  internal class Tile {
        [DataMember(Order=0)] public TileSelect.TiledEditorId _Id = TileSelect.TiledEditorId.None;
        [DataMember(Order=1)] public int _Ratio = 0;
        [DataMember(Order=2)] public List<Property> _Properties = new List<Property>();
        public void Clear() {
            this._Id = TileSelect.TiledEditorId.None;
            this._Ratio = 0;
            this._Properties.Clear();
        }
        public bool HasProperty(string key) { return FindPropery(key) != -1; }
        public void RemoveProperty(string key) { int idx = FindPropery(key); if (idx != -1) _Properties.RemoveAt(idx); }
        public string GetProperty(string key, string def = "") {
            int idx = FindPropery(key);
            if (idx != -1) return _Properties[idx]._value;
            return def;
        }
        public void SetProperty(string key, string value) {
            int idx = FindPropery(key);
            if (idx == -1) _Properties.Add(new Property(key, value));
            else           _Properties[idx]._value = value; 
        }
        private int FindPropery(string key) {
            for (int nn = 0; nn < _Properties.Count; nn++)
                if (key == _Properties[nn]._key)
                    return nn;
            return -1;
        }
    }
    [DataContract]  internal class Cell {
        [DataMember(Order=0)] internal Tile _TiledObject = new Tile();
        [DataMember(Order=1)] internal int _BubbleCount = 0;

        ////////////
        public void Clear() {
            _TiledObject.Clear();
            _BubbleCount = 0;
        }
        public bool HasProperty(string key) { return _TiledObject.HasProperty(key); }
        public void RemoveProperty(string key) { _TiledObject.RemoveProperty(key); }
        public string GetProperty(string key, string def = "") { return _TiledObject.GetProperty(key, def); }
        public void SetProperty(string key, string value) { _TiledObject.SetProperty(key, value); }

        public void ToClipbard() {
            MemoryStream stream = new MemoryStream();
            DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Cell));
            XmlDictionaryWriter writer = JsonReaderWriterFactory.CreateJsonWriter(stream, Encoding.UTF8, false, true, "    ");
            ser.WriteObject(writer, this);
            writer.Flush();
            byte[] ba = stream.ToArray();
            //Clipboard.SetData("ToonEditorCell", (Object)ba);
            Clipboard.SetText(Encoding.UTF8.GetString(ba));
            stream.Close();
        }
        public static Cell FromClipboard() {
            Cell cell = null;
#if false
            if (Clipboard.ContainsData("ToonEditorCell")) {
                byte[] sJson = Clipboard.GetData("ToonEditorCell") as byte[];
                MemoryStream stream = new MemoryStream(sJson, false);
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Cell));
                cell = ser.ReadObject(stream) as Cell;
                stream.Close();
            }
#else
            if (Clipboard.ContainsText()) {
                byte[] baJson = Encoding.UTF8.GetBytes(Clipboard.GetText());
                if (baJson != null && baJson.Length > 0) {
                    MemoryStream stream = new MemoryStream(baJson, false);
                    try {
                        DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Cell));
                        cell = ser.ReadObject(stream) as Cell;
                    }
                    catch (Exception e) {
                        MessageBox.Show(e.Message, "Invalid Cell Data!!!");
                    }
                    stream.Close();
                }
            }
#endif
            return cell;
        }
    }

    [DataContract] internal class Goal {
        public Goal(string name = "", int count = 0) { _Name = name; _Count = count; }
        [DataMember(Order=0)]  internal string _Name = "balloongoal";
        [DataMember(Order=1)]  internal int _Count = 5;
    }

    [DataContract] internal class Group {
        [DataMember(Order=0)]  internal string _Name = "0001_1001v01_K";
        [DataMember(Order=1)]  internal int _Ratio = 0;
        [DataMember(Order=2)]  internal bool _ConditionAndIsUsed = false;
        [DataMember(Order=3)]  internal int _GeneratePerTurn = 0;
        [DataMember(Order=4)]  internal List<Tile> _Items = new List<Tile>();
        [DataMember(Order=5)]  internal List<Property> _Conditions = new List<Property>();
        [DataMember(Order=6)]  internal int _DropInterval = 0;
        [DataMember(Order=7)]  internal List<int> _DropPosList = new List<int>();
        [DataMember(Order=8)]  internal int _UseForDrop = 0;
        [DataMember(Order=9)]  internal string _BarrelWeights = "";  //New
    }

    [DataContract]  internal class Tutorial {
        [DataMember(Order=0)]  internal int _Level = 0;
        [DataMember(Order=1)]  internal List<int> _Highlights = new List<int>();
        [DataMember(Order=2)]  internal string _Text = "";  
    }

    [DataContract]  internal class Level {
        [DataMember(Order=0)]  internal string _Name = "0001_1001v01_K";
        [DataMember(Order=1)]  internal int         _Width = DataStruct.Instance.MIN_WIDTH;
        [DataMember(Order=2)]  internal int         _Height = DataStruct.Instance.MIN_HEIGHT;
        [DataMember(Order=3)]  internal int         _MoveCount = 50;
        [DataMember(Order=4)]  internal List<Goal>  _GoalList = new List<Goal>();
        [DataMember(Order=5)]  internal List<Cell>  _CellList = new List<Cell>();
        [DataMember(Order=6)]  internal List<Group> _GroupList = new List<Group>();
        [DataMember(Order=7)]  internal List<int>   _Stars = new List<int>();
        [DataMember(Order=8)]  internal Tutorial    _Tutorial = new Tutorial();
        [DataMember(Order=9)]  internal List<int>   _PotionColorData = new List<int>();
        public string level_path = "";
        public Level() {
            for (int nn = 0; nn < 3; nn ++ )
                _Stars.Add(0);
            for (int row = 0; row < _Height; row++)
                for (int col = 0; col < _Width; col++)
                    this._CellList.Add(new Cell());
        }

        public static string levelpath(int level) { 
            string path = Path.GetFullPath(DataStruct.Instance.PATH_LEVEL + (level).ToString(DataStruct.Instance.LEVEL_NAMEFORMAT));
            path = path.Replace('\\', '/');
            return path;
        }
        public static Level load(int level) {
            Level ret = null;
            string level_path = levelpath(level);
            try {
                if (File.Exists(level_path)) {
                    FileStream stream = File.Open(level_path, FileMode.Open);
                    DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Level));
                    ret = (Level)ser.ReadObject(stream);
                    stream.Close();
                    ret.level_path = Path.GetFullPath(level_path);
                }
                else {
                    ret = new Level();
                    ret.level_path = level_path;
                    int lvlTmp = (level < 1000) ? level : (level - 1000);
                    ret._Name = string.Format("{0:D4}_1{1:D3}v01_K", level, lvlTmp);
                }
            }
            catch (IOException ioe) {
                MessageBox.Show(ioe.Message.ToString(), "Level Load Fail!");
            }
            return ret;
        }

        public string save(int level) { return save(levelpath(level)); }
        public string save(string level_path) {
            try {
                FileStream stream = File.Open(level_path, FileMode.Create);
                DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Level));
                /*ser.WriteObject(stream, _level);//*/
                XmlDictionaryWriter writer = JsonReaderWriterFactory.CreateJsonWriter(stream, Encoding.UTF8, false, true, "    ");
                ser.WriteObject(writer, this);
                writer.Flush();
                stream.Close();
                level_path = Path.GetFullPath(level_path);
            }
            catch (IOException ioe) {
                MessageBox.Show(ioe.Message.ToString(), "Failed to Save Level.");
            }
            return level_path;
        }
    }
}
