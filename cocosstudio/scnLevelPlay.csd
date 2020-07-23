<GameFile>
  <PropertyGroup Name="scnLevelPlay" Type="Scene" ID="84193393-4494-449d-b027-810d8223b870" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="35" Speed="0.5000">
        <Timeline ActionTag="-1351060851" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="10" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="25" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="35" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1380742294" Property="Position">
          <PointFrame FrameIndex="0" X="-78.0000" Y="250.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="-78.0000" Y="250.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="14" X="78.0000" Y="250.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="31" X="78.0000" Y="250.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="-78.0000" Y="250.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="689583413" Property="Position">
          <PointFrame FrameIndex="0" X="-100.0000" Y="390.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="-100.0000" Y="390.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="17" X="78.0000" Y="390.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="28" X="78.0000" Y="390.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="-100.0000" Y="390.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-590463200" Property="Position">
          <PointFrame FrameIndex="0" X="-120.0000" Y="540.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="-120.0000" Y="540.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="78.0000" Y="540.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="25" X="78.0000" Y="540.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="-120.0000" Y="540.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="normal" StartIndex="0" EndIndex="1">
          <RenderColor A="255" R="100" G="149" B="237" />
        </AnimationInfo>
        <AnimationInfo Name="menuEnter" StartIndex="10" EndIndex="20">
          <RenderColor A="255" R="255" G="20" B="147" />
        </AnimationInfo>
        <AnimationInfo Name="menuExit" StartIndex="25" EndIndex="35">
          <RenderColor A="255" R="255" G="105" B="180" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="465" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="bg" CanEdit="False" ActionTag="-881925489" Tag="466" IconVisible="False" ctype="SpriteObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="221" G="221" B="221" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/levelstart/bg1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="board" CanEdit="False" ActionTag="-2085827226" Tag="177" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="695.0000" BottomMargin="585.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="360.0000" Y="585.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4570" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="scorebarback" CanEdit="False" ActionTag="-757177395" Tag="138" IconVisible="False" LeftMargin="230.0000" RightMargin="20.0000" TopMargin="176.0000" BottomMargin="1072.0000" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="470.0000" Y="32.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="230.0000" Y="1088.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="108" G="1" B="11" />
            <PrePosition X="0.3194" Y="0.8500" />
            <PreSize X="0.6528" Y="0.0250" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="scorebar" CanEdit="False" ActionTag="2041559612" Tag="137" IconVisible="False" LeftMargin="230.0000" RightMargin="20.0000" TopMargin="176.0000" BottomMargin="1072.0000" ProgressInfo="69" ctype="LoadingBarObjectData">
            <Size X="470.0000" Y="32.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="230.0000" Y="1088.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3194" Y="0.8500" />
            <PreSize X="0.6528" Y="0.0250" />
            <ImageFileData Type="Normal" Path="image/common/scorebar.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="topbar" CanEdit="False" ActionTag="-313613684" Tag="468" IconVisible="False" LeftMargin="-16.0000" RightMargin="-16.0000" BottomMargin="1029.0000" ctype="SpriteObjectData">
            <Size X="752.0000" Y="251.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="360.0000" Y="1280.0000" />
            <Scale ScaleX="0.9575" ScaleY="0.9575" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.0000" />
            <PreSize X="1.0444" Y="0.1961" />
            <FileData Type="Normal" Path="image/playui/topbar.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="scorestarslot1" CanEdit="False" ActionTag="1376842761" Tag="141" IconVisible="False" LeftMargin="347.1889" RightMargin="328.8111" TopMargin="168.0000" BottomMargin="1068.0000" ctype="SpriteObjectData">
            <Size X="44.0000" Y="44.0000" />
            <Children>
              <AbstractNodeData Name="particle" CanEdit="False" ActionTag="1864562236" Tag="270" IconVisible="True" LeftMargin="21.0000" RightMargin="23.0000" TopMargin="20.0000" BottomMargin="24.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="21.0000" Y="24.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4773" Y="0.5455" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/goalStar.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="star" CanEdit="False" ActionTag="2010281218" Tag="144" IconVisible="False" LeftMargin="-19.5000" RightMargin="-19.5000" TopMargin="-22.5000" BottomMargin="-16.5000" ctype="SpriteObjectData">
                <Size X="83.0000" Y="83.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="22.0000" Y="25.0000" />
                <Scale ScaleX="0.3500" ScaleY="0.3500" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5682" />
                <PreSize X="1.8864" Y="1.8864" />
                <FileData Type="Normal" Path="image/common/scorestar.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="369.1889" Y="1090.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5128" Y="0.8516" />
            <PreSize X="0.0611" Y="0.0344" />
            <FileData Type="Normal" Path="image/common/scorestarslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="scorestarslot2" CanEdit="False" ActionTag="252081225" Tag="140" IconVisible="False" LeftMargin="495.7830" RightMargin="180.2170" TopMargin="168.0000" BottomMargin="1068.0000" ctype="SpriteObjectData">
            <Size X="44.0000" Y="44.0000" />
            <Children>
              <AbstractNodeData Name="particle" CanEdit="False" ActionTag="1041082523" Tag="289" IconVisible="True" LeftMargin="21.0000" RightMargin="23.0000" TopMargin="20.0000" BottomMargin="24.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="21.0000" Y="24.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4773" Y="0.5455" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/goalStar.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="star" CanEdit="False" ActionTag="-1465200696" Tag="143" IconVisible="False" LeftMargin="-19.5000" RightMargin="-19.5000" TopMargin="-22.5000" BottomMargin="-16.5000" ctype="SpriteObjectData">
                <Size X="83.0000" Y="83.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="22.0000" Y="25.0000" />
                <Scale ScaleX="0.3500" ScaleY="0.3500" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5682" />
                <PreSize X="1.8864" Y="1.8864" />
                <FileData Type="Normal" Path="image/common/scorestar.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="517.7830" Y="1090.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7191" Y="0.8516" />
            <PreSize X="0.0611" Y="0.0344" />
            <FileData Type="Normal" Path="image/common/scorestarslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="scorestarslot3" CanEdit="False" ActionTag="-2094251633" Tag="139" IconVisible="False" LeftMargin="673.0000" RightMargin="3.0000" TopMargin="175.0000" BottomMargin="1061.0000" ctype="SpriteObjectData">
            <Size X="44.0000" Y="44.0000" />
            <Children>
              <AbstractNodeData Name="particle" CanEdit="False" ActionTag="-1504047384" Tag="290" IconVisible="True" LeftMargin="21.0000" RightMargin="23.0000" TopMargin="20.0000" BottomMargin="24.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="21.0000" Y="24.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4773" Y="0.5455" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/goalStar.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="star" CanEdit="False" ActionTag="1691742945" Tag="142" IconVisible="False" LeftMargin="-19.5000" RightMargin="-19.5000" TopMargin="-22.5000" BottomMargin="-16.5000" ctype="SpriteObjectData">
                <Size X="83.0000" Y="83.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="22.0000" Y="25.0000" />
                <Scale ScaleX="0.3500" ScaleY="0.3500" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5682" />
                <PreSize X="1.8864" Y="1.8864" />
                <FileData Type="Normal" Path="image/common/scorestar.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="695.0000" Y="1083.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9653" Y="0.8461" />
            <PreSize X="0.0611" Y="0.0344" />
            <FileData Type="Normal" Path="image/common/scorestarslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="goalframe" CanEdit="False" ActionTag="979953296" Tag="469" IconVisible="False" LeftMargin="357.0000" RightMargin="271.0000" TopMargin="12.0000" BottomMargin="1228.0000" Scale9Enable="True" LeftEage="44" RightEage="44" Scale9OriginX="44" Scale9Width="4" Scale9Height="40" ctype="ImageViewObjectData">
            <Size X="92.0000" Y="40.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="403.0000" Y="1248.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5597" Y="0.9750" />
            <PreSize X="0.1278" Y="0.0313" />
            <FileData Type="Normal" Path="image/playui/framelabelback.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="goal" CanEdit="False" ActionTag="-1083756767" Tag="471" IconVisible="False" LeftMargin="365.5000" RightMargin="285.5000" TopMargin="13.0002" BottomMargin="1232.9998" FontSize="28" LabelText="Goal" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="69.0000" Y="34.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="400.0000" Y="1249.9998" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="248" B="209" />
            <PrePosition X="0.5556" Y="0.9766" />
            <PreSize X="0.0958" Y="0.0266" />
            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
            <OutlineColor A="255" R="138" G="38" B="40" />
            <ShadowColor A="255" R="102" G="31" B="36" />
          </AbstractNodeData>
          <AbstractNodeData Name="movesframe" CanEdit="False" ActionTag="1465593710" Tag="470" IconVisible="False" LeftMargin="588.9993" RightMargin="39.0007" TopMargin="12.0000" BottomMargin="1228.0000" Scale9Enable="True" LeftEage="44" RightEage="44" Scale9OriginX="44" Scale9Width="4" Scale9Height="40" ctype="ImageViewObjectData">
            <Size X="92.0000" Y="40.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="634.9993" Y="1248.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8819" Y="0.9750" />
            <PreSize X="0.1278" Y="0.0313" />
            <FileData Type="Normal" Path="image/playui/framelabelback.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="moves" CanEdit="False" ActionTag="639821900" Tag="472" IconVisible="False" LeftMargin="594.4986" RightMargin="44.5014" TopMargin="15.0035" BottomMargin="1234.9965" FontSize="24" LabelText="Moves" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="81.0000" Y="30.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="634.9986" Y="1249.9965" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="248" B="209" />
            <PrePosition X="0.8819" Y="0.9766" />
            <PreSize X="0.1125" Y="0.0234" />
            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
            <OutlineColor A="255" R="138" G="38" B="40" />
            <ShadowColor A="255" R="102" G="31" B="36" />
          </AbstractNodeData>
          <AbstractNodeData Name="move_count" CanEdit="False" ActionTag="-532954603" Tag="473" IconVisible="False" LeftMargin="592.0002" RightMargin="45.9998" TopMargin="58.5000" BottomMargin="1148.5000" FontSize="60" LabelText="54" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
            <Size X="82.0000" Y="73.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="633.0002" Y="1185.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="248" B="209" />
            <PrePosition X="0.8792" Y="0.9258" />
            <PreSize X="0.1139" Y="0.0570" />
            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
            <OutlineColor A="255" R="102" G="31" B="36" />
            <ShadowColor A="255" R="102" G="31" B="36" />
          </AbstractNodeData>
          <AbstractNodeData Name="bottombar" CanEdit="False" ActionTag="-1353713262" Tag="475" IconVisible="False" TopMargin="1142.0000" LeftEage="3" RightEage="3" TopEage="45" BottomEage="45" Scale9OriginX="3" Scale9OriginY="45" Scale9Width="6" Scale9Height="48" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="138.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="360.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" />
            <PreSize X="1.0000" Y="0.1078" />
            <FileData Type="Normal" Path="image/booster/boosterbar.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="bear" ActionTag="9504432" Tag="70" IconVisible="True" LeftMargin="122.0000" RightMargin="598.0000" TopMargin="192.0000" BottomMargin="1088.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="122.0000" Y="1088.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1694" Y="0.8500" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="charactor/bearhead.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="bearframebottom" CanEdit="False" ActionTag="-938453792" Tag="118" IconVisible="False" LeftMargin="13.3000" RightMargin="474.7000" TopMargin="147.0000" BottomMargin="1038.0000" ctype="SpriteObjectData">
            <Size X="232.0000" Y="95.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="129.3000" Y="1085.5000" />
            <Scale ScaleX="0.9575" ScaleY="0.9575" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1796" Y="0.8480" />
            <PreSize X="0.3222" Y="0.0742" />
            <FileData Type="Normal" Path="image/playui/bearframebottom.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="goals" CanEdit="False" ActionTag="1372125989" Tag="53" IconVisible="False" LeftMargin="297.0000" RightMargin="207.0000" TopMargin="62.5000" BottomMargin="1152.5000" ClipAble="False" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
            <Size X="216.0000" Y="65.0000" />
            <Children>
              <AbstractNodeData Name="icon1" CanEdit="False" ActionTag="-672388375" Tag="54" IconVisible="False" LeftMargin="-0.5000" RightMargin="161.5000" BottomMargin="-1.0000" LeftEage="32" RightEage="32" TopEage="33" BottomEage="33" Scale9OriginX="32" Scale9OriginY="33" Scale9Width="36" Scale9Height="54" ctype="ImageViewObjectData">
                <Size X="55.0000" Y="66.0000" />
                <Children>
                  <AbstractNodeData Name="complete" ActionTag="1502176166" Tag="282" IconVisible="False" LeftMargin="1.0000" RightMargin="-24.0000" TopMargin="17.5000" BottomMargin="-24.5000" LeftEage="25" RightEage="25" TopEage="24" BottomEage="24" Scale9OriginX="25" Scale9OriginY="24" Scale9Width="28" Scale9Height="25" ctype="ImageViewObjectData">
                    <Size X="78.0000" Y="73.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="40.0000" Y="12.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.7273" Y="0.1818" />
                    <PreSize X="1.4182" Y="1.1061" />
                    <FileData Type="Normal" Path="image/playui/check_mark.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="-2142876938" Tag="58" IconVisible="False" LeftMargin="18.5000" RightMargin="-6.5000" TopMargin="42.5000" BottomMargin="-13.5000" FontSize="30" LabelText="24" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="43.0000" Y="37.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="40.0000" Y="5.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="248" B="209" />
                    <PrePosition X="0.7273" Y="0.0758" />
                    <PreSize X="0.7818" Y="0.5606" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="102" G="31" B="36" />
                    <ShadowColor A="255" R="102" G="31" B="36" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="27.0000" Y="32.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1250" Y="0.4923" />
                <PreSize X="0.2546" Y="1.0154" />
                <FileData Type="Normal" Path="image/play/solidcolor6.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="particle1" CanEdit="False" ActionTag="-1853061825" Tag="108" IconVisible="True" LeftMargin="27.0000" RightMargin="189.0000" TopMargin="33.0000" BottomMargin="32.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="27.0000" Y="32.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1250" Y="0.4923" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/goal.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="icon2" CanEdit="False" ActionTag="1905171469" ZOrder="1" Tag="55" IconVisible="False" LeftMargin="85.0000" RightMargin="85.0000" TopMargin="3.5000" BottomMargin="2.5000" LeftEage="15" RightEage="15" TopEage="19" BottomEage="19" Scale9OriginX="15" Scale9OriginY="19" Scale9Width="42" Scale9Height="52" ctype="ImageViewObjectData">
                <Size X="46.0000" Y="59.0000" />
                <Children>
                  <AbstractNodeData Name="complete" ActionTag="277348221" Tag="283" IconVisible="False" LeftMargin="1.0000" RightMargin="-33.0000" TopMargin="10.5000" BottomMargin="-24.5000" LeftEage="25" RightEage="25" TopEage="24" BottomEage="24" Scale9OriginX="25" Scale9OriginY="24" Scale9Width="28" Scale9Height="25" ctype="ImageViewObjectData">
                    <Size X="78.0000" Y="73.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="40.0000" Y="12.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.8696" Y="0.2034" />
                    <PreSize X="1.6957" Y="1.2373" />
                    <FileData Type="Normal" Path="image/playui/check_mark.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="-254465699" Tag="60" IconVisible="False" LeftMargin="18.5000" RightMargin="-15.5000" TopMargin="35.5000" BottomMargin="-13.5000" FontSize="30" LabelText="17" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="43.0000" Y="37.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="40.0000" Y="5.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="248" B="209" />
                    <PrePosition X="0.8696" Y="0.0847" />
                    <PreSize X="0.9348" Y="0.6271" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="102" G="31" B="36" />
                    <ShadowColor A="255" R="102" G="31" B="36" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="108.0000" Y="32.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4923" />
                <PreSize X="0.2130" Y="0.9077" />
                <FileData Type="Normal" Path="image/play/cantoss.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="particle2" CanEdit="False" ActionTag="-574186502" Tag="124" IconVisible="True" LeftMargin="108.0000" RightMargin="108.0000" TopMargin="33.0000" BottomMargin="32.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="108.0000" Y="32.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4923" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/goal.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="icon3" CanEdit="False" ActionTag="706536689" ZOrder="2" Tag="56" IconVisible="False" LeftMargin="156.5000" RightMargin="4.5000" TopMargin="4.5000" BottomMargin="3.5000" LeftEage="32" RightEage="32" TopEage="33" BottomEage="33" Scale9OriginX="32" Scale9OriginY="33" Scale9Width="34" Scale9Height="36" ctype="ImageViewObjectData">
                <Size X="55.0000" Y="57.0000" />
                <Children>
                  <AbstractNodeData Name="complete" ActionTag="512386726" Tag="284" IconVisible="False" LeftMargin="1.0000" RightMargin="-24.0000" TopMargin="8.5000" BottomMargin="-24.5000" LeftEage="25" RightEage="25" TopEage="24" BottomEage="24" Scale9OriginX="25" Scale9OriginY="24" Scale9Width="28" Scale9Height="25" ctype="ImageViewObjectData">
                    <Size X="78.0000" Y="73.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="40.0000" Y="12.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.7273" Y="0.2105" />
                    <PreSize X="1.4182" Y="1.2807" />
                    <FileData Type="Normal" Path="image/playui/check_mark.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="37462952" Tag="61" IconVisible="False" LeftMargin="29.0000" RightMargin="4.0000" TopMargin="33.5000" BottomMargin="-13.5000" FontSize="30" LabelText="5" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="22.0000" Y="37.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="40.0000" Y="5.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="248" B="209" />
                    <PrePosition X="0.7273" Y="0.0877" />
                    <PreSize X="0.4000" Y="0.6491" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="102" G="31" B="36" />
                    <ShadowColor A="255" R="102" G="31" B="36" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="184.0000" Y="32.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.8519" Y="0.4923" />
                <PreSize X="0.2546" Y="0.8769" />
                <FileData Type="Normal" Path="image/play/duck1.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="particle3" CanEdit="False" ActionTag="1145867437" Tag="128" IconVisible="True" LeftMargin="184.0000" RightMargin="32.0000" TopMargin="33.0000" BottomMargin="32.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="184.0000" Y="32.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.8519" Y="0.4923" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/goal.csd" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="405.0000" Y="1185.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5625" Y="0.9258" />
            <PreSize X="0.3000" Y="0.0508" />
            <SingleColor A="255" R="150" G="150" B="255" />
            <FirstColor A="255" R="150" G="150" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="item1" CanEdit="False" ActionTag="412635289" Tag="476" IconVisible="False" LeftMargin="177.0000" RightMargin="419.0000" TopMargin="1167.5000" BottomMargin="7.5000" ctype="SpriteObjectData">
            <Size X="124.0000" Y="105.0000" />
            <Children>
              <AbstractNodeData Name="empty" CanEdit="False" ActionTag="-21371947" Tag="490" IconVisible="False" LeftMargin="5.5000" RightMargin="5.5000" TopMargin="-10.5000" BottomMargin="-7.5000" ctype="SpriteObjectData">
                <Size X="113.0000" Y="123.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="54.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5143" />
                <PreSize X="0.9113" Y="1.1714" />
                <FileData Type="Normal" Path="image/booster/boosterslotempty.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn" CanEdit="False" ActionTag="-1575636199" Tag="31" IconVisible="False" LeftMargin="4.0000" RightMargin="4.0000" TopMargin="4.5000" BottomMargin="5.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="86" Scale9Height="73" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="116.0000" Y="95.0000" />
                <Children>
                  <AbstractNodeData Name="icon" CanEdit="False" ActionTag="786807349" Tag="371" IconVisible="False" LeftMargin="-35.0000" RightMargin="-35.0000" TopMargin="-49.5000" BottomMargin="-50.5000" ctype="SpriteObjectData">
                    <Size X="186.0000" Y="195.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="47.0000" />
                    <Scale ScaleX="0.3800" ScaleY="0.3800" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.4947" />
                    <PreSize X="1.6034" Y="2.0526" />
                    <FileData Type="Normal" Path="image/playui/hammerlarge.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="2065051438" Tag="372" IconVisible="False" LeftMargin="53.0000" RightMargin="5.0000" TopMargin="57.0000" BottomMargin="2.0000" FontSize="28" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="58.0000" Y="36.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="82.0000" Y="20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.7069" Y="0.2105" />
                    <PreSize X="0.5000" Y="0.3789" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="45" G="82" B="12" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="53.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5048" />
                <PreSize X="0.9355" Y="0.9048" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="239.0000" Y="60.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3319" Y="0.0469" />
            <PreSize X="0.1722" Y="0.0820" />
            <FileData Type="Normal" Path="image/booster/boosterbuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="item2" CanEdit="False" ActionTag="972658109" Tag="23" IconVisible="False" LeftMargin="312.0000" RightMargin="284.0000" TopMargin="1167.5000" BottomMargin="7.5000" ctype="SpriteObjectData">
            <Size X="124.0000" Y="105.0000" />
            <Children>
              <AbstractNodeData Name="empty" CanEdit="False" ActionTag="-2019797037" Tag="24" IconVisible="False" LeftMargin="5.5000" RightMargin="5.5000" TopMargin="-10.5000" BottomMargin="-7.5000" ctype="SpriteObjectData">
                <Size X="113.0000" Y="123.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="54.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5143" />
                <PreSize X="0.9113" Y="1.1714" />
                <FileData Type="Normal" Path="image/booster/boosterslotempty.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn" CanEdit="False" ActionTag="-962721730" Tag="144" IconVisible="False" LeftMargin="4.0000" RightMargin="4.0000" TopMargin="4.5000" BottomMargin="5.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="86" Scale9Height="73" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="116.0000" Y="95.0000" />
                <Children>
                  <AbstractNodeData Name="icon" CanEdit="False" ActionTag="1416160526" Tag="373" IconVisible="False" LeftMargin="-17.5000" RightMargin="-17.5000" TopMargin="-19.5000" BottomMargin="-20.5000" ctype="SpriteObjectData">
                    <Size X="151.0000" Y="135.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="47.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.4947" />
                    <PreSize X="1.3017" Y="1.4211" />
                    <FileData Type="Normal" Path="image/playui/boxclub.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="-1458651238" Tag="374" IconVisible="False" LeftMargin="53.0000" RightMargin="5.0000" TopMargin="57.0000" BottomMargin="2.0000" FontSize="28" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="58.0000" Y="36.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="82.0000" Y="20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.7069" Y="0.2105" />
                    <PreSize X="0.5000" Y="0.3789" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="45" G="82" B="12" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="53.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5048" />
                <PreSize X="0.9355" Y="0.9048" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="374.0000" Y="60.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5194" Y="0.0469" />
            <PreSize X="0.1722" Y="0.0820" />
            <FileData Type="Normal" Path="image/booster/boosterbuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="item3" CanEdit="False" ActionTag="-755713122" Tag="25" IconVisible="False" LeftMargin="446.9990" RightMargin="149.0010" TopMargin="1167.5000" BottomMargin="7.5000" ctype="SpriteObjectData">
            <Size X="124.0000" Y="105.0000" />
            <Children>
              <AbstractNodeData Name="empty" CanEdit="False" ActionTag="-105434761" Tag="26" IconVisible="False" LeftMargin="5.5000" RightMargin="5.5000" TopMargin="-10.5000" BottomMargin="-7.5000" ctype="SpriteObjectData">
                <Size X="113.0000" Y="123.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="54.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5143" />
                <PreSize X="0.9113" Y="1.1714" />
                <FileData Type="Normal" Path="image/booster/boosterslotempty.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn" CanEdit="False" ActionTag="-1466144551" Tag="145" IconVisible="False" LeftMargin="4.0000" RightMargin="4.0000" TopMargin="4.5000" BottomMargin="5.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="86" Scale9Height="73" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="116.0000" Y="95.0000" />
                <Children>
                  <AbstractNodeData Name="icon" CanEdit="False" ActionTag="-1871246647" Tag="375" IconVisible="False" LeftMargin="-41.5000" RightMargin="-41.5000" TopMargin="-49.0000" BottomMargin="-50.0000" ctype="SpriteObjectData">
                    <Size X="199.0000" Y="194.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="47.0000" />
                    <Scale ScaleX="0.3800" ScaleY="0.3800" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.4947" />
                    <PreSize X="1.7155" Y="2.0421" />
                    <FileData Type="Normal" Path="image/playui/anvil.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="-1527275983" Tag="376" IconVisible="False" LeftMargin="53.0000" RightMargin="5.0000" TopMargin="57.0000" BottomMargin="2.0000" FontSize="28" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="58.0000" Y="36.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="82.0000" Y="20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.7069" Y="0.2105" />
                    <PreSize X="0.5000" Y="0.3789" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="45" G="82" B="12" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="53.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5048" />
                <PreSize X="0.9355" Y="0.9048" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="508.9990" Y="60.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7069" Y="0.0469" />
            <PreSize X="0.1722" Y="0.0820" />
            <FileData Type="Normal" Path="image/booster/boosterbuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="item4" CanEdit="False" ActionTag="335035283" Tag="27" IconVisible="False" LeftMargin="581.9999" RightMargin="14.0001" TopMargin="1167.5000" BottomMargin="7.5000" ctype="SpriteObjectData">
            <Size X="124.0000" Y="105.0000" />
            <Children>
              <AbstractNodeData Name="empty" CanEdit="False" ActionTag="-421139285" Tag="28" IconVisible="False" LeftMargin="5.5000" RightMargin="5.5000" TopMargin="-10.5000" BottomMargin="-7.5000" ctype="SpriteObjectData">
                <Size X="113.0000" Y="123.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="54.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5143" />
                <PreSize X="0.9113" Y="1.1714" />
                <FileData Type="Normal" Path="image/booster/boosterslotempty.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn" CanEdit="False" ActionTag="-2014557217" Tag="146" IconVisible="False" LeftMargin="4.0000" RightMargin="4.0000" TopMargin="4.5000" BottomMargin="5.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="86" Scale9Height="73" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="116.0000" Y="95.0000" />
                <Children>
                  <AbstractNodeData Name="icon" CanEdit="False" ActionTag="1703076759" Tag="377" IconVisible="False" LeftMargin="-41.0000" RightMargin="-41.0000" TopMargin="-43.0000" BottomMargin="-44.0000" ctype="SpriteObjectData">
                    <Size X="198.0000" Y="182.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="47.0000" />
                    <Scale ScaleX="0.3800" ScaleY="0.3800" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.4947" />
                    <PreSize X="1.7069" Y="1.9158" />
                    <FileData Type="Normal" Path="image/playui/dice2.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" CanEdit="False" ActionTag="-322937334" Tag="378" IconVisible="False" LeftMargin="53.0000" RightMargin="5.0000" TopMargin="57.0000" BottomMargin="2.0000" FontSize="28" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="58.0000" Y="36.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="82.0000" Y="20.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.7069" Y="0.2105" />
                    <PreSize X="0.5000" Y="0.3789" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="45" G="82" B="12" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.0000" Y="53.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5048" />
                <PreSize X="0.9355" Y="0.9048" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="643.9999" Y="60.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8944" Y="0.0469" />
            <PreSize X="0.1722" Y="0.0820" />
            <FileData Type="Normal" Path="image/booster/boosterbuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="menucover" CanEdit="False" ActionTag="-1351060851" Alpha="0" Tag="63" IconVisible="False" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="pausebtn" CanEdit="False" ActionTag="-1313907128" Tag="477" IconVisible="False" LeftMargin="25.0000" RightMargin="589.0000" TopMargin="1167.5000" BottomMargin="7.5000" ctype="SpriteObjectData">
            <Size X="106.0000" Y="105.0000" />
            <Children>
              <AbstractNodeData Name="btn" CanEdit="False" ActionTag="-39439541" Tag="478" IconVisible="False" LeftMargin="8.0000" RightMargin="8.0000" TopMargin="7.0000" BottomMargin="8.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="60" Scale9Height="68" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="90.0000" Y="90.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="53.0000" Y="53.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5048" />
                <PreSize X="0.8491" Y="0.8571" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/button/btnmenu.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/btnmenu.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="78.0000" Y="60.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1083" Y="0.0469" />
            <PreSize X="0.1472" Y="0.0820" />
            <FileData Type="Normal" Path="image/button/pausebtnslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="musicbtn" CanEdit="False" ActionTag="-1380742294" Tag="487" IconVisible="False" LeftMargin="-136.0000" RightMargin="740.0000" TopMargin="972.5000" BottomMargin="192.5000" ctype="SpriteObjectData">
            <Size X="116.0000" Y="115.0000" />
            <Children>
              <AbstractNodeData Name="chk" CanEdit="False" ActionTag="-795018991" Tag="488" IconVisible="False" LeftMargin="11.5000" RightMargin="11.5000" TopMargin="12.0000" BottomMargin="11.0000" TouchEnable="True" ctype="CheckBoxObjectData">
                <Size X="93.0000" Y="92.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="58.0000" Y="57.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4957" />
                <PreSize X="0.8017" Y="0.8000" />
                <NormalBackFileData Type="Normal" Path="image/button/btnmusic.png" Plist="" />
                <PressedBackFileData Type="Normal" Path="image/button/btnmusic.png" Plist="" />
                <DisableBackFileData Type="Default" Path="Default/CheckBox_Disable.png" Plist="" />
                <NodeNormalFileData Type="Normal" Path="image/common/xline.png" Plist="" />
                <NodeDisableFileData Type="Default" Path="Default/CheckBoxNode_Disable.png" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-78.0000" Y="250.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.1083" Y="0.1953" />
            <PreSize X="0.1611" Y="0.0898" />
            <FileData Type="Normal" Path="image/button/menubuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="soundbtn" CanEdit="False" ActionTag="689583413" Tag="486" IconVisible="False" LeftMargin="-158.0000" RightMargin="762.0000" TopMargin="832.5000" BottomMargin="332.5000" ctype="SpriteObjectData">
            <Size X="116.0000" Y="115.0000" />
            <Children>
              <AbstractNodeData Name="chk" CanEdit="False" ActionTag="2764915" Tag="489" IconVisible="False" LeftMargin="12.0000" RightMargin="12.0000" TopMargin="12.0000" BottomMargin="11.0000" TouchEnable="True" ctype="CheckBoxObjectData">
                <Size X="92.0000" Y="92.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="58.0000" Y="57.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4957" />
                <PreSize X="0.7931" Y="0.8000" />
                <NormalBackFileData Type="Normal" Path="image/button/btnsound.png" Plist="" />
                <PressedBackFileData Type="Normal" Path="image/button/btnsound.png" Plist="" />
                <DisableBackFileData Type="Default" Path="Default/CheckBox_Disable.png" Plist="" />
                <NodeNormalFileData Type="Normal" Path="image/common/xline.png" Plist="" />
                <NodeDisableFileData Type="Default" Path="Default/CheckBoxNode_Disable.png" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-100.0000" Y="390.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.1389" Y="0.3047" />
            <PreSize X="0.1611" Y="0.0898" />
            <FileData Type="Normal" Path="image/button/menubuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="quitbtn" CanEdit="False" ActionTag="-590463200" Tag="22" IconVisible="False" LeftMargin="-178.0000" RightMargin="782.0000" TopMargin="682.5000" BottomMargin="482.5000" ctype="SpriteObjectData">
            <Size X="116.0000" Y="115.0000" />
            <Children>
              <AbstractNodeData Name="btn" CanEdit="False" ActionTag="1503266808" Tag="481" IconVisible="False" LeftMargin="13.0000" RightMargin="13.0000" TopMargin="13.0000" BottomMargin="12.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="60" Scale9Height="68" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="90.0000" Y="90.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="58.0000" Y="57.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4957" />
                <PreSize X="0.7759" Y="0.7826" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/button/btnback.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/btnback.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-120.0000" Y="540.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.1667" Y="0.4219" />
            <PreSize X="0.1611" Y="0.0898" />
            <FileData Type="Normal" Path="image/button/menubuttonslot.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>