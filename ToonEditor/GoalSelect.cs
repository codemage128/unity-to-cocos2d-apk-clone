using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ToonEditor
{
    public partial class GoalSelect : Form
    {
        static GoalSelect _instance = null;
        public static GoalSelect Instance {
            get { if(_instance==null) _instance = new GoalSelect(); return _instance; }
            set { _instance = value; }
        }

        public Dictionary<string, Image> _goalImages = new Dictionary<string, Image>();
        Control _btnGoal = null;

        public GoalSelect() {
            InitializeComponent();
            this.Visible = false;

            foreach (ListViewItem item in listView1.Items) {
                string id = item.Tag.ToString();
                if (!_goalImages.ContainsKey(id))
                    _goalImages.Add(id, imageList1.Images[imageList1.Images.IndexOfKey(item.ImageKey)]);
            }
        }

        public void ShowForButton(Control btn) {
            _btnGoal = btn;
            this.Visible = true;

            if (_btnGoal == null)
                return;
            foreach (ListViewItem item in listView1.Items) {
                if (_btnGoal.Tag.ToString() == item.Tag.ToString()) {
                    item.Selected = true;
                    break;
                }
            }
        }

        private void GoalSelect_Deactivate(object sender, EventArgs e) {
            GoalSelect.Instance.Visible = false;
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e) {
            if (listView1.SelectedIndices.Count == 0 || _btnGoal == null)
                return;
            ListViewItem item = listView1.Items[listView1.SelectedIndices[0]];
            _btnGoal.Tag = item.Tag;
            _btnGoal.BackgroundImage = imageList1.Images[imageList1.Images.IndexOfKey(item.ImageKey)];
        }

        private void GoalSelect_FormClosed(object sender, FormClosedEventArgs e) {
            GoalSelect.Instance = null;
        }
    }
}
