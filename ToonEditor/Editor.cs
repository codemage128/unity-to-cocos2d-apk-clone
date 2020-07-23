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
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Xml;
using System.Drawing.Drawing2D;
//using System.Diagnostics.Process;

namespace ToonEditor
{
    public partial class Editor : Form
    {
        private bool _modify = false;  //modified ?
        private int _currentLevelIdx = 0; //index of current level num
        private Level   _level = null;
        private Cell[,] _board = null;
        private Point[,] _fakeboard = null;
        private Point FAKENULL = new Point(-1, -1);
        private Cell _currentCell = null;
        private Point _currentCellPos = new Point(0, 0);
        private static int bBusy = 0;
        private static bool bBusyGroup = false;
        private static bool bLevelChangeByOther = false;

        private Button[] _btnGoals = new Button[3];
        private Label[] _txtGoals = new Label[3];
        private NumericUpDown[] _numGoals = new NumericUpDown[3];

        private List<CheckBox> _chkGrpItems = new List<CheckBox>();
        private List<PictureBox> _picGrpItems = new List<PictureBox>();
        private List<NumericUpDown> _numGrpRatios = new List<NumericUpDown>();

        //for draw
        private SizeF szCell = new SizeF(50, 60);
        private Point ptBoardLT = new Point(0, 0);
        private Image imgFrame = null;
        private Image imgBubble = null;
        private Image imgFocus = null;
        private List<Image> imgWall = new List<Image>();

        public Editor() {
            InitializeComponent();

            _btnGoals[0] = btnGoal1; _numGoals[0] = numGoal1; _txtGoals[0] = txtGoal1;
            _btnGoals[1] = btnGoal2; _numGoals[1] = numGoal2; _txtGoals[1] = txtGoal2;
            _btnGoals[2] = btnGoal3; _numGoals[2] = numGoal3; _txtGoals[2] = txtGoal3;

            _chkGrpItems.Add(chkGrpItem1);  _picGrpItems.Add(picGrpItem1);  _numGrpRatios.Add(numGrpRatio1); 
            _chkGrpItems.Add(chkGrpItem2);  _picGrpItems.Add(picGrpItem2);  _numGrpRatios.Add(numGrpRatio2); 
            _chkGrpItems.Add(chkGrpItem3);  _picGrpItems.Add(picGrpItem3);  _numGrpRatios.Add(numGrpRatio3); 
            _chkGrpItems.Add(chkGrpItem4);  _picGrpItems.Add(picGrpItem4);  _numGrpRatios.Add(numGrpRatio4); 
            _chkGrpItems.Add(chkGrpItem5);  _picGrpItems.Add(picGrpItem5);  _numGrpRatios.Add(numGrpRatio5); 
            _chkGrpItems.Add(chkGrpItem6);  _picGrpItems.Add(picGrpItem6);  _numGrpRatios.Add(numGrpRatio6); 
            _chkGrpItems.Add(chkGrpItem7);  _picGrpItems.Add(picGrpItem7);  _numGrpRatios.Add(numGrpRatio7); 
            _chkGrpItems.Add(chkGrpItem8);  _picGrpItems.Add(picGrpItem8);  _numGrpRatios.Add(numGrpRatio8); 
        }

        private void Editor_Load(object sender, EventArgs e) {
            //Load DataStruct Constants.
            DataStruct.Instance.load();

            _level = new Level();
            _board = new Cell[DataStruct.Instance.MAX_HEIGHT, DataStruct.Instance.MAX_WIDTH];
            _fakeboard = new Point[DataStruct.Instance.MAX_HEIGHT, DataStruct.Instance.MAX_WIDTH];
            for (int row = 0; row < DataStruct.Instance.MAX_HEIGHT; row++)
                for (int col = 0; col < DataStruct.Instance.MAX_WIDTH; col++) {
                    _board[row, col] = new Cell();
                    _fakeboard[row, col] = new Point(-1,-1);
                }
                    

            //Init UI
            listLevel.Items.Clear();
            for (int i = 1; i <= DataStruct.Instance.MAX_LEVEL; i++) {
                listLevel.Items.Add(i.ToString(DataStruct.Instance.LEVEL_NAMEFORMAT));
                ListViewItem li = listLevel.Items[i - 1] as ListViewItem;
                if (li != null) { li.ForeColor = File.Exists(Level.levelpath(i)) ? Color.Black : Color.Red; }
            }

            numWidth.Maximum = DataStruct.Instance.MAX_WIDTH; numWidth.Minimum = DataStruct.Instance.MIN_WIDTH;
            numHeight.Maximum = DataStruct.Instance.MAX_HEIGHT; numHeight.Minimum = DataStruct.Instance.MIN_HEIGHT;
            numLevel.Maximum = DataStruct.Instance.MAX_LEVEL;

            imgFrame = global::ToonEditor.Properties.Resources.wire;
            imgBubble = global::ToonEditor.Properties.Resources.bubble;
            imgFocus = global::ToonEditor.Properties.Resources.TileFocus;
            imgWall.Add(global::ToonEditor.Properties.Resources.wall1);
            imgWall.Add(global::ToonEditor.Properties.Resources.wall2);
            imgWall.Add(global::ToonEditor.Properties.Resources.wall3);

            TileSelect.Instance.Visible = false; //load _tileImages ..
            GoalSelect.Instance.Visible = false; //load _goalImages ..

            this.KeyPreview = true; //OnKeyDown Enable

            btnImport.Enabled = File.Exists("LevelDataMeta.dll") && File.Exists("LevelDataMetaSerializer.dll") && File.Exists("protobuf-net.dll");

            chkEditable.Checked = DataStruct.Instance.EDITABLE;
            chkEditable_CheckedChanged(null, null);

            if (DataStruct.Instance.EDITABLE)
                timerLevelGuard_Tick(null, null);
        }
        
        private void Editor_FormClosed(object sender, FormClosedEventArgs e) {
            if (_modify && DialogResult.Yes == MessageBox.Show("Do you save this level?", "Level Modified !!!", MessageBoxButtons.YesNo))
                btnSave_Click(null, null);

            TileSelect.Instance.Close();
            GoalSelect.Instance.Close();

            DataStruct.Instance.save();
            DataStruct.Instance = null;
        }

        private void init() {
            /////////// Update UI ///////
            txtName.Text = _level._Name;
            numWidth.Value = _level._Width;
            numHeight.Value = _level._Height;
            numMoves.Value = _level._MoveCount;
            numStar1.Value = _level._Stars[0];
            numStar2.Value = _level._Stars[1];
            numStar3.Value = _level._Stars[2];

            for (int nn = 0; nn < 3; nn++) {
                if (_level._GoalList != null && _level._GoalList.Count > nn) {
                    _numGoals[nn].Value = _level._GoalList[nn]._Count;
                    _btnGoals[nn].Tag = _level._GoalList[nn]._Name;
                    if(GoalSelect.Instance._goalImages.ContainsKey(_btnGoals[nn].Tag.ToString()))
                        _btnGoals[nn].BackgroundImage = GoalSelect.Instance._goalImages[_btnGoals[nn].Tag.ToString()];
                    else {
                        MessageBox.Show(_btnGoals[nn].Tag.ToString(), "Invalid GoalName!!!");
                        _btnGoals[nn].Tag = "";
                        _btnGoals[nn].BackgroundImage = global::ToonEditor.Properties.Resources.none;
                    }
                }
                else {
                    _btnGoals[nn].Tag = "none";
                    _btnGoals[nn].BackgroundImage = global::ToonEditor.Properties.Resources.none;
                    _numGoals[nn].Value = 0;
                }
            }
            
            int iCell = 0;
            for (int row = 0; row < _level._Height; row++)
                for (int col = 0; col < _level._Width; col++) {
                    if (_level._CellList != null && _level._CellList.Count > iCell)
                        _board[row, col] = _level._CellList[iCell++];
                    
                }
            for (int row = 0; row < _level._Height; row++)
                for (int col = 0; col < _level._Width; col++) {
                    _fakeboard[row, col] = FAKENULL;
                }
            for (int row = 0; row < _level._Height; row++)
                for (int col = 0; col < _level._Width; col++) {
                    //Large Tile Fake Mark
                    if (TileSelect.IsLargeTile(_board[row, col]._TiledObject._Id))
                        PutTile(new Point(col, row), _board[row, col]._TiledObject._Id);
                }
            _currentCellPos.X = Math.Min(_currentCellPos.X, _level._Width - 1);
            _currentCellPos.Y = Math.Min(_currentCellPos.Y, _level._Height - 1);
            setCurrentCell(_currentCellPos);

            //init tabGroup
            numGroupSize.Value = _level._GroupList.Count;
            tabGroup.TabPages.Clear();
            while (tabGroup.TabPages.Count < _level._GroupList.Count) {
                TabPage newTab = new TabPage((tabGroup.TabPages.Count + 1).ToString());
                newTab.ImageIndex = tabGroup.TabPages.Count;
                tabGroup.TabPages.Add(newTab);
            }

            updateCurrentGroup();
 
            CalcBoardSize();
            panelBoard.VerticalScroll.Value = panelBoard.VerticalScroll.Maximum;

            this.picBoard.Invalidate();
        }
        private void setModify(bool modify) { 
            _modify = modify;
            this.Text = "ToonBlast Level Editor-" + _level.level_path + (_modify ? "*" : ""); 
        }
        private Point tileFromPoint(PictureBox pic, int x, int y) {
            y -= ptBoardLT.Y;
            x -= ptBoardLT.X;
            int col = (int)Math.Min(_level._Width, x / szCell.Width); col = Math.Max(col, 0);
            int row = (int)Math.Min(_level._Height, y / szCell.Height); row = Math.Max(row, 0);
            return new Point(col, row);
        }
        private bool IsValidPos(Point pos) { return (pos.X >= 0 && pos.X < _level._Width && pos.Y >= 0 && pos.Y < _level._Height); }
        private void CalcBoardSize() {
            szCell.Width = picBoard.Width / (_level._Width + 1);
            szCell.Height = szCell.Width * 120 / 100f;
            picBoard.Height = (int)((_level._Height + 1) * szCell.Height);
            //panelBoard.ClientSize = new Size(picBoard.Width, picBoard.Height);
            ptBoardLT.X = (int)(picBoard.Width - szCell.Width * _level._Width) / 2;
            ptBoardLT.Y = (int)(picBoard.Height - szCell.Height * _level._Height) / 2;
        }
        private void picBoard_Paint(object sender, PaintEventArgs e) {
            Graphics g = e.Graphics;
            Font countfnt = new Font("arial", 12);
            Brush countbrush = new SolidBrush(Color.White);

            PictureBox pic = sender as PictureBox;
            //draw grid
            PointF ptBoardRB = new PointF(ptBoardLT.X + szCell.Width * _level._Width, ptBoardLT.Y + szCell.Height * _level._Height);
            Color crLine = Color.Black;  //crLine.A= (byte)100;
            Pen penLine = new Pen(crLine, 1); penLine.DashStyle = DashStyle.Dot;
            for (int row = 0; row <= _level._Height; row++) {
                PointF p1 = new PointF(ptBoardLT.X, ptBoardLT.Y + szCell.Height * row);
                PointF p2 = new PointF(ptBoardRB.X, ptBoardLT.Y + szCell.Height * row);
                g.DrawLine(penLine, p1, p2);
            }
            for (int col = 0; col <= _level._Width; col++) {
                PointF p1 = new PointF(ptBoardLT.X + szCell.Width * col, ptBoardLT.Y);
                PointF p2 = new PointF(ptBoardLT.X + szCell.Width * col, ptBoardRB.Y);
                g.DrawLine(penLine, p1, p2);
            }

            Color[] matchColors = new Color[] { Color.Yellow, Color.Red, Color.Blue, Color.Green, Color.Purple, Color.Orange };
            //draw tiles
            for (int row = 0; row < _level._Height; row++) {
                for (int col = 0; col < _level._Width; col++) {
                    Cell cell = _board[row, col];
                    Size logsz = TileSelect.GetTileSize(cell._TiledObject._Id);
                    RectangleF rect = new RectangleF(
                        ptBoardLT.X + szCell.Width * col,
                        ptBoardLT.Y + szCell.Height * (row + 1 - logsz.Height),
                        logsz.Width * szCell.Width, 
                        logsz.Height * szCell.Height);

                    if (cell._TiledObject._Id != TileSelect.TiledEditorId.None) {
                        //Skip for FakeItem of GiantItem.
                        if (_fakeboard[row, col].Equals(FAKENULL) || _fakeboard[row, col].Equals(new Point(col, row))) {
                            g.DrawImage(TileSelect.Instance._tileImages[(int)cell._TiledObject._Id], rect);
                            if (cell.HasProperty("Frame"))
                                g.DrawImage(imgFrame, rect);
                            if (cell.HasProperty("wall")) {
                                if(!IsValidPos(new Point(col-1, row)) || !_board[row, col-1]._TiledObject.HasProperty("wall"))
                                    g.DrawImage(imgWall[0], rect);
                                if (!IsValidPos(new Point(col + 1, row)) || !_board[row, col+1]._TiledObject.HasProperty("wall"))
                                    g.DrawImage(imgWall[2], rect);
                                else
                                    g.DrawImage(imgWall[1], rect);
                            }
                            if (cell.HasProperty("matchType")) {
                                SolidBrush drawBrush = new SolidBrush(matchColors[Int32.Parse(cell.GetProperty("matchType"))]);
                                g.FillRectangle(drawBrush, rect.X, rect.Y, rect.Width * 0.5f, rect.Height * 0.2f);
                            }
                                
                            if (cell._BubbleCount > 0)
                                g.DrawImage(imgBubble, RectangleF.Inflate(rect, 5, 5));
                        }
                    }
                    
                }

                //draw Focus
                if (_currentCell != null) {
                    Size logsz = TileSelect.GetTileSize(_currentCell._TiledObject._Id);
                    RectangleF rect = new RectangleF(
                        ptBoardLT.X + szCell.Width * _currentCellPos.X,
                        ptBoardLT.Y + szCell.Height * (_currentCellPos.Y + 1 - logsz.Height),
                        logsz.Width * szCell.Width,
                        logsz.Height * szCell.Height);
                    g.DrawImage(imgFocus, rect);
                }
                
            }
        }

        private void ClearTile(Point pos) {
            if (!IsValidPos(pos)) return;

            Cell cell = _board[pos.Y, pos.X];
            Size orgSize = TileSelect.GetTileSize(cell._TiledObject._Id);
            if(cell._TiledObject._Id != TileSelect.TiledEditorId.Empty) 
                cell._TiledObject._Id = TileSelect.TiledEditorId.None;

            if (!_fakeboard[pos.Y, pos.X].Equals(FAKENULL) && !_fakeboard[pos.Y, pos.X].Equals(pos)) 
                ClearTile(_fakeboard[pos.Y, pos.X]);
            _fakeboard[pos.Y, pos.X] = FAKENULL;

            //If this is LargeTile, Release this's FakeItems.
            if (orgSize.Width > 1 || orgSize.Height > 1) {
                for (int off_x = 0; off_x < orgSize.Width; off_x++)
                    for (int off_y = 0; off_y < orgSize.Height; off_y++) {
                        Point posFake = new Point(pos.X + off_x, pos.Y - off_y);
                        if (IsValidPos(posFake))
                            _fakeboard[posFake.Y, posFake.X] = FAKENULL;
                    }
            }
        }
        private bool PutTile(Point pos, TileSelect.TiledEditorId newId) {
            if (!IsValidPos(pos)) 
                return false;

            Size logsz = TileSelect.GetTileSize(newId);
            if ((pos.X + logsz.Width > _level._Width) || (pos.Y < logsz.Height - 1)) // LargeTile Can Put ??
                return false;

            //1. Remove Invalid LargeTiles
            for(int off_x = 0; off_x < logsz.Width; off_x++)
                for (int off_y = 0; off_y < logsz.Height; off_y++) {
                    Point posFake = new Point(pos.X + off_x, pos.Y - off_y);
                    ClearTile(posFake);
                }

            //put new Tile
            _board[pos.Y, pos.X]._TiledObject._Id = newId;
            if (newId == TileSelect.TiledEditorId.None)
                _board[pos.Y, pos.X].Clear();
            else if(TileSelect.IsLargeTile(newId)) {
                _board[pos.Y, pos.X]._BubbleCount = 0;
                _board[pos.Y, pos.X].RemoveProperty("Frame");

                for (int off_x = 0; off_x < logsz.Width; off_x++)  //for LargeTile
                    for (int off_y = 0; off_y < logsz.Height; off_y++) {
                        Point posFake = new Point(pos.X + off_x, pos.Y - off_y);
                        if (!IsValidPos(posFake) || posFake.Equals(pos))
                            continue;
                        _fakeboard[posFake.Y, posFake.X] = new Point(pos.X, pos.Y);
                        _board[posFake.Y, posFake.X].Clear();
                        _board[posFake.Y, posFake.X]._TiledObject._Id = TileSelect.TiledEditorId.Empty;
                    }
            }
            
            return true;
        }
        private void picBoard_MouseUp(object sender, MouseEventArgs e) {
            PictureBox pic = sender as PictureBox;
            Point pos = _currentCellPos = tileFromPoint(pic, e.X, e.Y);
            _currentCell = _board[pos.Y, pos.X];

            if (e.Button == System.Windows.Forms.MouseButtons.Left && DataStruct.Instance.EDITABLE) {
                TileSelect.TiledEditorId newId = (TileSelect.TiledEditorId)Int32.Parse(selTile.Tag.ToString());
    
                if(_currentCell._TiledObject._Id != newId)
                    setModify(true);

                PutTile(pos, newId);
            }

            setCurrentCell(_currentCellPos);
            pic.Invalidate();
        }
        private void setCurrentCell(Point pos) {
            pos.X = Math.Max(pos.X, 0); pos.X = Math.Min(pos.X, _level._Width-1);
            pos.Y = Math.Max(pos.Y, 0); pos.Y = Math.Min(pos.Y, _level._Height-1);
            _currentCellPos = pos;
            _currentCell = _board[pos.Y, pos.X];

            bBusy++;

            selTile.BackgroundImage = TileSelect.Instance._tileImages[(int)_currentCell._TiledObject._Id];
            selTile.Tag = ((int)_currentCell._TiledObject._Id).ToString();
            txtSelTileName.Text = _currentCell._TiledObject._Id.ToString();
            txtSelTileSize.Text = TileSelect.GetTileSize(_currentCell._TiledObject._Id).ToString();

            panelCellProp.Enabled = _currentCell._TiledObject._Id != TileSelect.TiledEditorId.None;
            chkBubble.Checked = _currentCell._BubbleCount > 0;
            chkFrame.Checked = numFrame.Visible = _currentCell.HasProperty("Frame");
            numFrame.Value = Int32.Parse(_currentCell.GetProperty("Frame", "1"));

            chkCapacity.Checked = numCapacity.Visible = _currentCell.HasProperty("capacity");
            numCapacity.Value = Int32.Parse(_currentCell.GetProperty("capacity", "0"));

            chkOrder.Checked = numOrder.Visible = _currentCell.HasProperty("order");
            numOrder.Value = Int32.Parse(_currentCell.GetProperty("order", "0"));

            chkMatchType.Checked = cbMatchType.Visible = _currentCell.HasProperty("matchType");
            cbMatchType.SelectedIndex = Int32.Parse(_currentCell.GetProperty("matchType", "0"));

            chkDirection.Checked = cbDirection.Visible = _currentCell.HasProperty("direction");
            cbDirection.SelectedIndex = Int32.Parse(_currentCell.GetProperty("direction", "1"));

            chkOffset.Checked = txtOffset.Visible = _currentCell.HasProperty("offset");
            txtOffset.Text = _currentCell.GetProperty("offset", "");

            chkScale.Checked = txtScale.Visible = _currentCell.HasProperty("scale");
            txtScale.Text = _currentCell.GetProperty("scale", "");

            chkWall.Checked = txtWall.Visible = txtWallCnt.Visible = _currentCell.HasProperty("wall");
            txtWall.Text = _currentCell.GetProperty("wall", "");


            //Count Same TileIDs .
            bool bSepFound = false;
            int nTile = 0, nTileAll = 0, nFrame = 0, nFrameAll = 0, nBubble = 0, nBubbleAll = 0, nWall = 0, nWallAll = 0; 
            for (int row = _level._Height-1; row >= 0 ; row--)
                for (int col = 0; col < _level._Width; col++) {
                    Cell cell = _board[row, col];
                    if (cell._TiledObject._Id == TileSelect.TiledEditorId.Seperator)
                        bSepFound = true;
                    if (cell._TiledObject._Id == _currentCell._TiledObject._Id) {  nTileAll++;    if (!bSepFound)   nTile++; }
                    if (cell._BubbleCount > 0) { nBubbleAll++; if (!bSepFound) nBubble++; }
                    if (cell.HasProperty("Frame")) { nFrameAll++; if (!bSepFound) nFrame++;  }
                    if (cell.HasProperty("wall")) { nWallAll++; if (!bSepFound) nWall++; }
                }

            txtSameCount.Text = string.Format("x {0:D1}", nTile) + ((nTile == nTileAll) ? "" : string.Format(" ({0:D1})", nTileAll));
            txtBubbleCnt.Text = string.Format("x {0:D1}", nBubble) + ((nBubble == nBubbleAll) ? "" : string.Format(" ({0:D1})", nBubbleAll));
            txtFrameCnt.Text = string.Format("x {0:D1}", nFrame) + ((nFrame == nFrameAll) ? "" : string.Format(" ({0:D1})", nFrameAll));
            txtWallCnt.Text = string.Format("x {0:D1}", nWall) + ((nWall == nWallAll) ? "" : string.Format(" ({0:D1})", nWallAll));
            bBusy--;
        }
        private void onKeyDown(object sender, KeyEventArgs e) {
            String sKey = e.KeyCode.ToString();
            if (e.Control && sKey == "Up") { setCurrentCell(new Point(_currentCellPos.X, _currentCellPos.Y - 1)); picBoard.Invalidate(); e.Handled = true; }
            if (e.Control && sKey == "Down") { setCurrentCell(new Point(_currentCellPos.X, _currentCellPos.Y + 1)); picBoard.Invalidate(); e.Handled = true; }
            if (e.Control && sKey == "Left") { setCurrentCell(new Point(_currentCellPos.X - 1, _currentCellPos.Y)); picBoard.Invalidate(); e.Handled = true; }
            if (e.Control && sKey == "Right") { setCurrentCell(new Point(_currentCellPos.X + 1, _currentCellPos.Y)); picBoard.Invalidate(); e.Handled = true; }

            if (e.Control && (sKey == "C")) {
                e.Handled = true;
                if (_currentCell != null) _currentCell.ToClipbard();
            }

            if(!DataStruct.Instance.EDITABLE) {
                return;
            }

            if (sKey == "F1") { selTile_Click(selTile, null); }
            if (sKey == "F2") { if (e.Alt) _numGoals[0].Select(); else onBtnGoals(_btnGoals[0], null); return; }
            if (sKey == "F3") { if (e.Alt) _numGoals[1].Select(); else onBtnGoals(_btnGoals[1], null); return; }
            if (sKey == "F4") { if (e.Alt) _numGoals[2].Select(); else onBtnGoals(_btnGoals[2], null); return; }

            if (sKey == "F") { if (chkFrame.Enabled) chkFrame.Checked = !chkFrame.Checked; e.Handled = true; }
            if (sKey == "B") { if (chkBubble.Enabled) chkBubble.Checked = !chkBubble.Checked; e.Handled = true; }
            if (sKey == "W") { if (chkWall.Enabled) chkWall.Checked = !chkWall.Checked; e.Handled = true; }

            if (e.Control && (sKey == "Delete")) { btnClear_Click(null, null); e.Handled = true; }
            if (e.Control && (sKey == "S")) { btnSave_Click(null, null); e.Handled = true; }
            if (e.Control && (sKey == "R")) { btnRun_Click(null, null); e.Handled = true; }
            
            if (e.Control && (sKey == "V")) {
                e.Handled = true;
                Cell clipCell = Cell.FromClipboard();
                if (clipCell != null) {
                    _board[_currentCellPos.Y, _currentCellPos.X] = clipCell;
                    PutTile(_currentCellPos, clipCell._TiledObject._Id);  //update Fakeboard
                    setCurrentCell(_currentCellPos);
                    picBoard.Invalidate();
                }
                
            }
        }
        private void timerLevelGuard_Tick(object sender, EventArgs e) {
            if (bBusy > 0)
                return;
            Microsoft.Win32.RegistryKey key = Microsoft.Win32.Registry.CurrentUser.CreateSubKey("ToonEditor");
            int idxNew = Int32.Parse(key.GetValue("lastLevel", _currentLevelIdx.ToString()).ToString());
            key.Close();
            if (_currentLevelIdx != idxNew) {
                bLevelChangeByOther = true;
                numLevel.Value = idxNew + 1; //called numLevel_ValueChanged()
                bLevelChangeByOther = false;
            }
        }
        private void numLevel_ValueChanged(object sender, EventArgs e) {
            int idxNew = Int32.Parse(numLevel.Value.ToString()) - 1;
            idxNew = Math.Max(0, idxNew); idxNew = Math.Min(idxNew, DataStruct.Instance.MAX_LEVEL-1);
            if (_currentLevelIdx != idxNew) {
                listLevel.TopItem = listLevel.FocusedItem = listLevel.Items[idxNew];
                listLevel.Items[idxNew].Selected = true;
            }
        }
        private void listLevel_SelectedIndexChanged(object sender, EventArgs e) {
            if (bBusy > 0 || listLevel.SelectedIndices.Count == 0)
                return;

            bBusy  ++;
            int idxNew = listLevel.SelectedIndices[0];
            if (_modify && DialogResult.Yes == MessageBox.Show("Do you save this level?", "Level Modified !!!", MessageBoxButtons.YesNo))
                btnSave_Click(null, null);
            setModify(false);

            _currentLevelIdx = idxNew;
            if (!bLevelChangeByOther) {
                Microsoft.Win32.RegistryKey key = Microsoft.Win32.Registry.CurrentUser.CreateSubKey("ToonEditor");
                key.SetValue("lastLevel", _currentLevelIdx.ToString());
                key.Close();
            }
            numLevel.Value = _currentLevelIdx + 1;
            _level = Level.load(_currentLevelIdx + 1);
            
            init();

            bBusy  --;
        }
        private void btnClear_Click(object sender, EventArgs e) {
            for (int row = 0; row < _level._Height; row++)
                for (int col = 0; col < _level._Width; col++)
                    _board[row, col].Clear();
            picBoard.Invalidate();
            setModify(true);
        }
        private void btnSave_Click(object sender, EventArgs e) {
            ///
            _level._Name = txtName.Text;
            _level._Width = Int32.Parse(numWidth.Value.ToString());
            _level._Height = Int32.Parse(numHeight.Value.ToString());
            _level._MoveCount = Int32.Parse(numMoves.Value.ToString());

            _level._GoalList.Clear();
            for (int nn = 0; nn < 3; nn++) {
                if (_btnGoals[nn].Tag.ToString() != "" && _btnGoals[nn].Tag.ToString() != "none") {
                    Goal goal = new Goal();
                    goal._Name = _btnGoals[nn].Tag.ToString();
                    goal._Count = Int32.Parse(_numGoals[nn].Value.ToString());
                    _level._GoalList.Add(goal);
                }
            }

            _level._CellList.Clear();
            for (int row = 0; row < _level._Height; row++) {
                for (int col = 0; col < _level._Width; col++) {
                    _level._CellList.Add(_board[row, col]);
                }
            }

            string level_path = _level.save(_currentLevelIdx + 1);
            setModify(false);

            ListViewItem li = listLevel.SelectedItems[0];
            if (li != null)
                li.ForeColor = File.Exists(level_path) ? Color.Black : Color.Red;
        }
        private void btnRun_Click(object sender, EventArgs e) {
            if (listLevel.SelectedIndices.Count == 0)
                return;
            btnSave_Click(null, null); //Save Current Level

            if (!File.Exists(DataStruct.Instance.PATH_PLAYER)) {
                MessageBox.Show(DataStruct.Instance.PATH_PLAYER, "Player Not Found!!!");
                return;
            }
            try {
                System.Diagnostics.ProcessStartInfo info = new System.Diagnostics.ProcessStartInfo(DataStruct.Instance.PATH_PLAYER, "BY_LEVELEDITOR:" + (listLevel.SelectedIndices[0] + 1).ToString(DataStruct.Instance.LEVEL_NAMEFORMAT));
                System.Diagnostics.Process.Start(info);
            }
            catch (Exception re) {
                MessageBox.Show(re.Message, "Player Lauch Fail!!!");
            }
        }
        private void panelBoard_SizeChanged(object sender, EventArgs e) { CalcBoardSize(); picBoard.Invalidate(); }
        private void onBtnGoals(object sender, EventArgs e) { 
            if (bBusy > 0 || bBusyGroup) return; 
            Button btnGoal = sender as Button; 
            if (btnGoal != null) GoalSelect.Instance.ShowForButton(btnGoal); 
            setModify(true); }
        private void onBtnGoal_BakgroundImageChanged(object sender, EventArgs e) {
            Button btn = sender as Button; if (btn == null) return;
            int idx = _btnGoals.ToList().IndexOf(btn);
            if (idx != -1)
                _txtGoals[idx].Text = btn.Tag.ToString();
        }
        private void selTile_Click(object sender, EventArgs e) { TileSelect.Instance.ShowForPicturBox(selTile); }
        private void onCellProperty_CheckedChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            CheckBox chk = sender as CheckBox;
            if (_currentCell == null || chk == null) return;
            string key = chk.Text.Replace("&", "");  //Remove '&'.
            if (key == "Frame") {
                if (chkFrame.Checked) _currentCell.SetProperty(key, numFrame.Value.ToString()); else _currentCell.RemoveProperty(key);
                numFrame.Visible = chkFrame.Checked; picBoard.Invalidate();
            }
            else if (key == "capacity") {
                if (chkCapacity.Checked) _currentCell.SetProperty(key, numCapacity.Value.ToString()); else _currentCell.RemoveProperty(key);
                numCapacity.Visible = chkCapacity.Checked; picBoard.Invalidate();
            }
            else if (key == "order") {
                if (chkOrder.Checked) _currentCell.SetProperty(key, numOrder.Value.ToString()); else _currentCell.RemoveProperty(key);
                numOrder.Visible = chkOrder.Checked; picBoard.Invalidate();
            }
            else if (key == "matchType") {
                if (chkMatchType.Checked) _currentCell.SetProperty(key, cbMatchType.SelectedIndex.ToString()); else _currentCell.RemoveProperty(key);
                cbMatchType.Visible = chkMatchType.Checked; picBoard.Invalidate();
            }
            else if (key == "direction") {
                if (chkDirection.Checked) _currentCell.SetProperty(key, cbDirection.SelectedIndex.ToString()); else _currentCell.RemoveProperty(key);
                cbDirection.Visible = chkDirection.Checked; picBoard.Invalidate();
            }
            else if (key == "offset") {
                if (chkOffset.Checked) _currentCell.SetProperty(key, txtOffset.Text); else _currentCell.RemoveProperty(key);
                txtOffset.Visible = chkOffset.Checked; picBoard.Invalidate();
            }
            else if (key == "scale") {
                if (chkScale.Checked) _currentCell.SetProperty(key, txtScale.Text); else _currentCell.RemoveProperty(key);
                txtScale.Visible = chkScale.Checked; picBoard.Invalidate();
            }
            else if (key == "wall") {
                if (chkWall.Checked) _currentCell.SetProperty(key, txtWall.Text); else _currentCell.RemoveProperty(key);
                txtWall.Visible = chkWall.Checked; picBoard.Invalidate();
            }
            else { return; }
            setModify(true);
        }
        private void onCellProperty_ValueChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            Control ctrl = sender as Control;
            if (_currentCell == null || ctrl == null) return;
            string key = ctrl.Tag.ToString();
            if (key == "Frame") {
                _currentCell.SetProperty(key, numFrame.Value.ToString()); 
                picBoard.Invalidate();
            }
            else if (key == "capacity") { _currentCell.SetProperty(key, numCapacity.Value.ToString());    picBoard.Invalidate(); }
            else if (key == "order") { _currentCell.SetProperty(key, numOrder.Value.ToString());          picBoard.Invalidate(); }
            else if (key == "matchType") { _currentCell.SetProperty(key, cbMatchType.SelectedIndex.ToString()); picBoard.Invalidate(); }
            else if (key == "direction") { _currentCell.SetProperty(key, cbDirection.SelectedIndex.ToString()); picBoard.Invalidate(); }
            else if (key == "offset") { _currentCell.SetProperty(key, txtOffset.Text);                          picBoard.Invalidate(); }
            else if (key == "scale") { _currentCell.SetProperty(key, txtScale.Text);                      picBoard.Invalidate(); }
            else if (key == "wall") { _currentCell.SetProperty(key, txtWall.Text);                        picBoard.Invalidate(); }
            else { return; }
            setModify(true);
        }
        private void chkBubble_CheckedChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            if (_currentCell == null)   return;
            _currentCell._BubbleCount = chkBubble.Checked ? 1 : 0;
            picBoard.Invalidate();
            setModify(true);
        }
        private void numHeight_ValueChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            _level._Height = Int32.Parse(numHeight.Value.ToString());
            CalcBoardSize();
            picBoard.Invalidate();
            setModify(true);
        }
        private void numWidth_ValueChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            _level._Width = Int32.Parse(numWidth.Value.ToString());
            CalcBoardSize();
            picBoard.Invalidate();
            setModify(true);
        }

        private void updateCurrentGroup() {
            int iGroup = tabGroup.SelectedIndex;
            grpGroupInfo.Visible = (iGroup != -1);
            if (iGroup == -1) {
                return;
            }

            txtGroupName.Text = _level._GroupList[iGroup]._Name;
            numRatio.Value = _level._GroupList[iGroup]._Ratio;
            chkConditionAndIsUsed.Checked = _level._GroupList[iGroup]._ConditionAndIsUsed;
            numGeneratePerTurn.Value = _level._GroupList[iGroup]._GeneratePerTurn;

            for (int nn = 0; nn < _chkGrpItems.Count; nn++) {
                if (nn < _level._GroupList[iGroup]._Items.Count) {
                    _chkGrpItems[nn].Checked = _picGrpItems[nn].Visible = _numGrpRatios[nn].Visible = true;
                    _picGrpItems[nn].Tag = _level._GroupList[iGroup]._Items[nn]._Id;
                    _picGrpItems[nn].BackgroundImage = TileSelect.Instance._tileImages[(int)_level._GroupList[iGroup]._Items[nn]._Id];
                    _numGrpRatios[nn].Value = _level._GroupList[iGroup]._Items[nn]._Ratio;
                }
                else {
                    _chkGrpItems[nn].Checked = _picGrpItems[nn].Visible = _numGrpRatios[nn].Visible = false;
                }
            }
        }
        private void numGroupSize_ValueChanged(object sender, EventArgs e) {
            if (bBusy > 0) return;
            int nGrpSize = Int32.Parse(numGroupSize.Value.ToString());
            while (tabGroup.TabPages.Count > nGrpSize) {
                tabGroup.TabPages.RemoveAt(tabGroup.TabPages.Count - 1);
                _level._GroupList.RemoveAt(_level._GroupList.Count - 1);
            }

            while (tabGroup.TabPages.Count < nGrpSize) {
                TabPage newTab = new TabPage((tabGroup.TabPages.Count+1).ToString());
                newTab.ImageIndex = tabGroup.TabPages.Count;
                tabGroup.TabPages.Add(newTab);
                Group newGrp = new Group();
                newGrp._Name = "group" + (_level._GroupList.Count + 1).ToString();
                _level._GroupList.Add(newGrp);
            }
            updateCurrentGroup();
            setModify(true);
        }
        private void tabGroup_SelectedIndexChanged(object sender, EventArgs e) {
            if (bBusy > 0) return;
            bBusyGroup = true;
            updateCurrentGroup();
            bBusyGroup = false;
        }
        private void onBtnGroupItem(object sender, EventArgs e) { TileSelect.Instance.ShowForPicturBox(sender as PictureBox); }
        private void onChkGrpItems_Clicked(object sender, EventArgs e) {
            bBusyGroup = true;
            CheckBox chk = sender as CheckBox;
            int idx = _chkGrpItems.IndexOf(chk);
            if (idx == -1 || chk == null)
                return;

            chk.Checked = true;
            int newCount = idx + 1;
            int iGroup = tabGroup.SelectedIndex;
            if (newCount == _level._GroupList[iGroup]._Items.Count)
                return;

            while (_level._GroupList[iGroup]._Items.Count < newCount) {
                Tile tile = new Tile(); tile._Id = TileSelect.TiledEditorId.SolidColor1;
                _level._GroupList[iGroup]._Items.Add(tile);
            }
            while (_level._GroupList[iGroup]._Items.Count > newCount)
                _level._GroupList[iGroup]._Items.RemoveAt(_level._GroupList[iGroup]._Items.Count-1);

            updateCurrentGroup();
            bBusyGroup = false;
            setModify(true);
        }
        private void onGrpItems_BackgroundImageChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            PictureBox pic = sender as PictureBox;
            int idx = _picGrpItems.IndexOf(pic);
            if (idx == -1 || pic == null)
                return;
            TileSelect.TiledEditorId newID = (TileSelect.TiledEditorId)Int32.Parse(pic.Tag.ToString());
            if (newID != _level._GroupList[tabGroup.SelectedIndex]._Items[idx]._Id)
                setModify(true);
            _level._GroupList[tabGroup.SelectedIndex]._Items[idx]._Id = newID;
        }
        private void onGrpItemRatio_ValueChanged(object sender, EventArgs e) {
            if (bBusy > 0 || bBusyGroup) return;
            NumericUpDown num = sender as NumericUpDown;
            int idx = _numGrpRatios.IndexOf(num);
            if (idx == -1 || num == null)
                return;
            _level._GroupList[tabGroup.SelectedIndex]._Items[idx]._Ratio = Int32.Parse(num.Value.ToString());
            setModify(true);
        }
        private void txtGroupName_TextChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; _level._GroupList[tabGroup.SelectedIndex]._Name = txtGroupName.Text; setModify(true); }
        private void numRatio_ValueChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; _level._GroupList[tabGroup.SelectedIndex]._Ratio = Int32.Parse(numRatio.Value.ToString()); setModify(true); }
        private void chkConditionAndIsUsed_CheckedChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; _level._GroupList[tabGroup.SelectedIndex]._ConditionAndIsUsed = chkConditionAndIsUsed.Checked; setModify(true); }
        private void numGeneratePerTurn_ValueChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; _level._GroupList[tabGroup.SelectedIndex]._GeneratePerTurn = Int32.Parse(numGeneratePerTurn.Value.ToString()); setModify(true); }
        private void numDropInterval_ValueChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; _level._GroupList[tabGroup.SelectedIndex]._DropInterval = Int32.Parse(numDropInterval.Value.ToString()); setModify(true); }
        private void numUseForDrop_ValueChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; _level._GroupList[tabGroup.SelectedIndex]._UseForDrop = Int32.Parse(numUseForDrop.Value.ToString()); setModify(true); }
        private void numMoves_ValueChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; setModify(true); }
        private void numGoalCnt_ValueChanged(object sender, EventArgs e) { if (bBusy > 0 || bBusyGroup) return; setModify(true); }

        private void btnImport_Click(object sender, EventArgs e) {
            LevelManager.Instance.import();
        }
        private void btnExport_Click(object sender, EventArgs e) {
            LevelManager.Instance.export();
        }

        private void chkEditable_CheckedChanged(object sender, EventArgs e) {
            DataStruct.Instance.EDITABLE = chkEditable.Checked;
            grpGoalList.Enabled = grpGroupList.Enabled = grpLevelInfo.Enabled = DataStruct.Instance.EDITABLE;
            btnClear.Enabled = btnSave.Enabled = DataStruct.Instance.EDITABLE;
            grpCellInfo.Enabled = DataStruct.Instance.EDITABLE;
            splitContainer1.Panel2Collapsed = !DataStruct.Instance.EDITABLE;

            timerLevelGuard.Enabled = (!DataStruct.Instance.EDITABLE && DataStruct.Instance.LEVEL_INDEXGUARD > 100);
            if (timerLevelGuard.Enabled)
                timerLevelGuard.Interval = DataStruct.Instance.LEVEL_INDEXGUARD;
        }
    }
}
