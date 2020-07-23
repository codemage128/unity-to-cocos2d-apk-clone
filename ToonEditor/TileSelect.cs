using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ToonEditor
{
    public partial class TileSelect : Form
    {
         public enum TiledEditorId {
	        None,
	        Empty = 9,
	        Seperator,
	        SolidColor1 = 1,
	        SolidColor2,
	        SolidColor3,
	        SolidColor4,
	        SolidColor5,
	        SolidColor6,
	        Group1 = 21,
	        Group2,
	        Group3,
	        Group4,
	        Group5,
	        Group6,
	        Group7,
	        Group8,
	        Group9,
	        Group10,
	        Group11,
	        Duck1 = 41,
	        Duck2,
	        Duck3,
	        Duck4,
	        Duck5,
	        GiantDuck = 121,
	        GiantPinata = 72,
	        Bubble = 61,
	        Frame = 46,
	        WallYellow = 221, //New
	        WallRed, //New
	        WallBlue, //New
	        WallGreen, //New
	        WallPurple, //New
	        WallOrange, //New
	        Balloon = 63,
	        LightBulb,
	        Crate,
	        CrateLayer1,
	        CrateLayer2,
	        CrateLayer3,
	        MagicHat = 103,
	        Pinata = 62,
	        Jelly = 123,
	        CanToss = 69,
	        EasterEgg = 71,
	        Soap = 76, //New............
	        ColoredBallon1 = 104,
	        ColoredBallon2,
	        ColoredBallon3,
	        ColoredBallon4,
	        ColoredBallon5,
	        ColoredBallon6,
	        Oyster = 90,
	        Soda4 = 136,
	        Soda5 = 138,
	        WaterMelon = 91,
	        MetalCrate,
	        ColorCrateYellow0 = 110,
	        ColorCrateYellow1,
	        ColorCrateYellow2,
	        ColorCrateRed0,
	        ColorCrateRed1,
	        ColorCrateRed2,
	        ColorCrateBlue0 = 124,
	        ColorCrateBlue1,
	        ColorCrateBlue2,
	        ColorCrateGreen0,
	        ColorCrateGreen1,
	        ColorCrateGreen2,
	        ColorCratePurple0,
	        ColorCratePurple1,
	        ColorCratePurple2,
	        ColorCrateOrange0,
	        ColorCrateOrange1,
	        ColorCrateOrange2,
	        RocketHorizantal = 81,
	        RocketVertical,
	        Bomb,
	        DiscoBallColor1,
	        DiscoBallColor2,
	        DiscoBallColor3,
	        DiscoBallColor4,
	        DiscoBallColor5,
	        DiscoBallColor6,
	        BalloonGenerator1 = 74,
	        BalloonGenerator2,
	        Fish1 = 93,
	        Fish2,
	        Honey,
	        DiamondOpen,
	        DiamondClose,
	        MoleItem = 77,//New
	        BirdHouse = 54,//New
	        PotionYellow,//New
	        PotionRed,//New
	        PotionBlue,//New
	        PotionGreen,//New
	        PotionPurple,//New
	        PotionOrange,//New
	        Billboard = 98,
	        Stone,//New
	        PenguinItem = 78,//New
	        BarrelItem,//New...........
	        UfoItem = 51,//New
	        HanoiItem = 48,//New
	        GiftItem = 47,//New
	        ColoredSodaYellow = 161,
	        ColoredSodaRed = 163,
	        ColoredSodaBlue = 165,
	        ColoredSodaGreen = 167,
	        ColoredSodaPurple = 169,
	        BlasterYellowUp = 171,//New
	        BlasterYellowDown,//New
	        BlasterYellowRight = 153,//New
	        BlasterYellowLeft = 173,//New
	        BlasterRedUp = 175,//New
	        BlasterRedDown,//New
	        BlasterRedRight = 157,//New
	        BlasterRedLeft = 177,//New
	        BlasterBlueUp = 201,//New
	        BlasterBlueDown,//New
	        BlasterBlueRight = 183,//New
	        BlasterBlueLeft = 203,//New
	        BlasterGreenUp = 205,//New
	        BlasterGreenDown,//New
	        BlasterGreenRight = 187,//New
	        BlasterGreenLeft = 207,//New
	        BlasterPurpleUp = 209,//New
	        BlasterPurpleDown,//New
	        BlasterPurpleRight = 191,//New
	        BlasterPurpleLeft = 211,//New
	        BlasterOrangeUp = 213,//New
	        BlasterOrangeDown,//New
	        BlasterOrangeRight = 195,//New
	        BlasterOrangeLeft = 215//New
        };

        static TileSelect _instance = null;
        public static TileSelect Instance {
            get { if (_instance == null) _instance = new TileSelect(); return _instance; }
            set { _instance = value; }
        }
        public Dictionary<int, Image> _tileImages = new Dictionary<int, Image>();
        public static bool IsLargeTile(TiledEditorId id) { Size sz = GetTileSize(id); return sz.Width > 1 || sz.Height > 1; }
        public static Size GetTileSize(TiledEditorId id) {
            switch (id) {
                case TileSelect.TiledEditorId.GiantDuck:
                case TileSelect.TiledEditorId.GiantPinata:
                case TileSelect.TiledEditorId.CanToss:
                case TileSelect.TiledEditorId.Soda4:
                case TileSelect.TiledEditorId.Soda5:
                case TileSelect.TiledEditorId.ColoredSodaYellow:
                case TileSelect.TiledEditorId.ColoredSodaRed:
                case TileSelect.TiledEditorId.ColoredSodaBlue:
                case TileSelect.TiledEditorId.ColoredSodaGreen:
                case TileSelect.TiledEditorId.ColoredSodaPurple:
                    return new Size(2,2);

                case TileSelect.TiledEditorId.BlasterYellowLeft:
                case TileSelect.TiledEditorId.BlasterYellowRight:
                case TileSelect.TiledEditorId.BlasterRedLeft:
                case TileSelect.TiledEditorId.BlasterRedRight:
                case TileSelect.TiledEditorId.BlasterBlueLeft:
                case TileSelect.TiledEditorId.BlasterBlueRight:
                case TileSelect.TiledEditorId.BlasterGreenLeft:
                case TileSelect.TiledEditorId.BlasterGreenRight:
                case TileSelect.TiledEditorId.BlasterPurpleLeft:
                case TileSelect.TiledEditorId.BlasterPurpleRight:
                case TileSelect.TiledEditorId.BlasterOrangeLeft:
                case TileSelect.TiledEditorId.BlasterOrangeRight:
                    return new Size(2, 1);

                case TileSelect.TiledEditorId.BlasterYellowUp:
                case TileSelect.TiledEditorId.BlasterYellowDown:
                case TileSelect.TiledEditorId.BlasterRedUp:
                case TileSelect.TiledEditorId.BlasterRedDown:
                case TileSelect.TiledEditorId.BlasterBlueUp:
                case TileSelect.TiledEditorId.BlasterBlueDown:
                case TileSelect.TiledEditorId.BlasterGreenUp:
                case TileSelect.TiledEditorId.BlasterGreenDown:
                case TileSelect.TiledEditorId.BlasterPurpleUp:
                case TileSelect.TiledEditorId.BlasterPurpleDown:
                case TileSelect.TiledEditorId.BlasterOrangeUp:
                case TileSelect.TiledEditorId.BlasterOrangeDown:
                    return new Size(1, 2);
            }
            return new Size(1, 1);
        }

        private Control _selTile = null;
        public void ShowForPicturBox(Control selTile) {
            _selTile = selTile;
            this.Visible = true;
        }

        public TileSelect() {
            InitializeComponent();
            Control.ControlCollection Controls = this.flowLayoutPanel.Controls;
            foreach (object child in Controls) {
                Button btn = child as Button;
                int id = Int32.Parse(btn.Tag.ToString());
                if(!_tileImages.ContainsKey(id))
                    _tileImages.Add(id, btn.BackgroundImage);
            }

#if (false)
            //Genarate Sortied EnumClass 
            Dictionary<string, int> enumTileEditorIds = new Dictionary<string, int>(); 
            HashSet<string> names = new HashSet<string>(); 
            foreach (KeyValuePair<int, Image> pair in _tileImages) {
                TiledEditorId id = (TiledEditorId)pair.Key;
                enumTileEditorIds.Add(id.ToString(), (Int32)id);
            }

            FileStream fs = File.Open("TiledEditorId.cs", FileMode.Create);
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("public enum TiledEditorId\n{");
            IEnumerable<KeyValuePair<string, int>> query = enumTileEditorIds.OrderBy(pet => pet.Key);
            foreach (KeyValuePair<string, int> pair in query) {
                sb.AppendFormat("    {0} = 0x{1:x}, //{2:D},\n", pair.Key, pair.Value, pair.Value);
            }
            sb.AppendLine("}");
            byte[] bytes = Encoding.UTF8.GetBytes(sb.ToString());
            fs.Write(bytes, 0, bytes.Length);
            fs.Close();
#endif
        }

        private void onTileClick(object sender, EventArgs e) {
            Button btn = sender as Button;
            if (btn != null || _selTile != null) {
                _selTile.Tag = btn.Tag;
                _selTile.BackgroundImage = btn.BackgroundImage;
            }
        }

        private void TileSelect_Deactivate(object sender, EventArgs e) {
            this.Visible = false;
        }
        private void TileSelect_FormClosed(object sender, FormClosedEventArgs e) {
            TileSelect.Instance = null;
        }
    }
}
