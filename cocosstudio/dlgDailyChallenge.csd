<GameFile>
  <PropertyGroup Name="dlgDailyChallenge" Type="Scene" ID="fb805c0b-188a-4624-bbd0-52cd860f5cbc" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="0.5000">
        <Timeline ActionTag="3548072" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-984669500" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="15" Value="178">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="25" Value="178">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="40" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Position">
          <PointFrame FrameIndex="0" X="360.0000" Y="2000.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="360.0000" Y="640.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="25" X="360.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="360.0000" Y="-700.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.9000" Y="0.9000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="0.9000" Y="0.9000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="25" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="evtIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="255" G="228" B="181" />
        </AnimationInfo>
        <AnimationInfo Name="evtOut" StartIndex="25" EndIndex="40">
          <RenderColor A="255" R="240" G="255" B="255" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="312" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="Image_10" ActionTag="3548072" VisibleForFrame="False" Tag="143" IconVisible="False" LeftEage="337" RightEage="337" TopEage="601" BottomEage="601" Scale9OriginX="337" Scale9OriginY="601" Scale9Width="350" Scale9Height="620" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/mapui/mapuibg.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="blackbg" ActionTag="-984669500" Alpha="59" Tag="142" IconVisible="False" TouchEnable="True" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="579.8740" BottomMargin="700.1260" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="imgTop" ActionTag="648578726" Tag="67" IconVisible="False" LeftMargin="-340.0000" RightMargin="-340.0000" TopMargin="-606.0000" BottomMargin="510.0000" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="680.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="558.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgMiddle" ActionTag="-1928407235" Tag="66" IconVisible="False" LeftMargin="-339.9979" RightMargin="-340.0021" TopMargin="-512.0000" BottomMargin="-495.0000" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="680.0000" Y="1007.0000" />
                <Children>
                  <AbstractNodeData Name="panelTime" ActionTag="-1914618279" Tag="279" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="74.8000" RightMargin="74.8000" TopMargin="50.3500" BottomMargin="896.2300" TouchEnable="True" ClipAble="False" BackColorAlpha="108" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                    <Size X="530.4000" Y="60.4200" />
                    <Children>
                      <AbstractNodeData Name="Text_14" ActionTag="-1659170422" Tag="280" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="28.6200" RightMargin="240.7800" TopMargin="9.2100" BottomMargin="9.2100" FontSize="36" LabelText="Completed in:  " HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                        <Size X="261.0000" Y="42.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="159.1200" Y="30.2100" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.3000" Y="0.5000" />
                        <PreSize X="0.4921" Y="0.6951" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtTime" ActionTag="1128726383" Tag="281" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="297.0240" RightMargin="17.3759" TopMargin="1.6164" BottomMargin="2.8036" FontSize="48" LabelText="21:01:44" HorizontalAlignmentType="HT_Right" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="216.0000" Y="56.0000" />
                        <AnchorPoint ScaleY="0.4894" />
                        <Position X="297.0240" Y="30.2100" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5600" Y="0.5000" />
                        <PreSize X="0.4072" Y="0.9268" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="0" G="0" B="0" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" />
                    <Position X="340.0000" Y="896.2300" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.8900" />
                    <PreSize X="0.7800" Y="0.0600" />
                    <SingleColor A="255" R="0" G="0" B="0" />
                    <FirstColor A="255" R="150" G="200" B="255" />
                    <EndColor A="255" R="255" G="255" B="255" />
                    <ColorVector ScaleY="1.0000" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="btnChallenge0" ActionTag="2080398538" Tag="336" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="29.9880" RightMargin="24.4120" TopMargin="138.0597" BottomMargin="607.1204" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" TopEage="30" BottomEage="30" Scale9OriginX="38" Scale9OriginY="30" Scale9Width="104" Scale9Height="137" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="625.6000" Y="261.8200" />
                    <Children>
                      <AbstractNodeData Name="panelTop" ActionTag="-1107540315" Tag="337" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="177.5765" RightMargin="27.9331" TopMargin="18.9034" BottomMargin="119.8874" ClipAble="False" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                        <Size X="420.0904" Y="123.0292" />
                        <Children>
                          <AbstractNodeData Name="txtChallenge" ActionTag="10222660" Tag="338" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="16.8036" RightMargin="16.8036" TopMargin="6.1515" BottomMargin="6.1515" IsCustomSize="True" FontSize="36" LabelText="Collect 10 Stars " HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="386.4832" Y="110.7263" />
                            <AnchorPoint />
                            <Position X="16.8036" Y="6.1515" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="148" G="117" B="41" />
                            <PrePosition X="0.0400" Y="0.0500" />
                            <PreSize X="0.9200" Y="0.9000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="0" G="0" B="0" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" />
                        <Position X="387.6217" Y="119.8874" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6196" Y="0.4579" />
                        <PreSize X="0.6715" Y="0.4699" />
                        <SingleColor A="255" R="0" G="0" B="0" />
                        <FirstColor A="255" R="150" G="200" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="iconChallenge" ActionTag="-964784259" Tag="339" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="38.0960" RightMargin="463.5040" TopMargin="19.1642" BottomMargin="118.6558" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="29" Scale9Height="29" ctype="ImageViewObjectData">
                        <Size X="124.0000" Y="124.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="100.0960" Y="180.6558" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1600" Y="0.6900" />
                        <PreSize X="0.1982" Y="0.4736" />
                        <FileData Type="Normal" Path="image/common/scorestar.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="dlgpanelseper_2" ActionTag="-2127825339" Tag="340" IconVisible="False" LeftMargin="86.0814" RightMargin="60.5186" TopMargin="143.5068" BottomMargin="108.3132" ctype="SpriteObjectData">
                        <Size X="479.0000" Y="10.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="325.5814" Y="113.3132" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.4328" />
                        <PreSize X="0.7657" Y="0.0382" />
                        <FileData Type="Normal" Path="image/dialog/dlgpanelseper.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="panelBottom" ActionTag="1533681797" Tag="341" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="9.3840" RightMargin="9.3841" TopMargin="170.2353" BottomMargin="3.6655" ClipAble="False" BackColorAlpha="151" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                        <Size X="606.8320" Y="87.9192" />
                        <Children>
                          <AbstractNodeData Name="lblBonus" ActionTag="-2071600283" Tag="342" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="267.0061" RightMargin="241.8259" TopMargin="17.6844" BottomMargin="28.2347" FontSize="36" LabelText="Earn:" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="98.0000" Y="42.0000" />
                            <AnchorPoint ScaleY="0.5000" />
                            <Position X="267.0061" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.4400" Y="0.5600" />
                            <PreSize X="0.1615" Y="0.4777" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="0" G="0" B="0" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="iconBonus" ActionTag="-1227874764" Tag="343" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="394.8772" RightMargin="145.9547" TopMargin="5.6844" BottomMargin="16.2347" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                            <Size X="66.0000" Y="66.0000" />
                            <Children>
                              <AbstractNodeData Name="particleBonus" ActionTag="-755630571" Tag="57" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="33.0000" RightMargin="33.0000" TopMargin="33.0000" BottomMargin="33.0000" ctype="ParticleObjectData">
                                <Size X="0.0000" Y="0.0000" />
                                <AnchorPoint />
                                <Position X="33.0000" Y="33.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="0.0000" Y="0.0000" />
                                <FileData Type="Normal" Path="particle/MagicHat.plist" Plist="" />
                                <BlendFunc Src="770" Dst="1" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="427.8772" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7051" Y="0.5600" />
                            <PreSize X="0.1088" Y="0.7507" />
                            <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="panelBonusMul" ActionTag="1780124499" Tag="344" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="479.3973" RightMargin="18.2050" TopMargin="8.3523" BottomMargin="18.9026" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                            <Size X="109.2298" Y="60.6642" />
                            <Children>
                              <AbstractNodeData Name="txtBonusMul" ActionTag="-429273142" Tag="345" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="22.1149" RightMargin="22.1149" TopMargin="-0.0813" BottomMargin="2.7456" FontSize="50" LabelText="x2" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="65.0000" Y="58.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="54.6149" Y="31.7456" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5233" />
                                <PreSize X="0.5951" Y="0.9561" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="255" G="0" B="0" />
                                <ShadowColor A="255" R="0" G="0" B="0" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="534.0121" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.8800" Y="0.5600" />
                            <PreSize X="0.1800" Y="0.6900" />
                            <SingleColor A="255" R="0" G="0" B="0" />
                            <FirstColor A="255" R="100" G="100" B="100" />
                            <EndColor A="255" R="0" G="0" B="0" />
                            <ColorVector ScaleY="1.0000" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="panelProgress" ActionTag="-497694430" Tag="346" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="33.6792" RightMargin="375.6897" TopMargin="8.0797" BottomMargin="19.1752" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                            <Size X="197.4631" Y="60.6642" />
                            <Children>
                              <AbstractNodeData Name="progress" ActionTag="1319588674" Alpha="197" Tag="347" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="-2.9619" RightMargin="0.9873" TopMargin="0.0000" ProgressInfo="0" ctype="LoadingBarObjectData">
                                <Size X="199.4377" Y="60.6642" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="96.7569" Y="30.3321" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="250" G="188" B="88" />
                                <PrePosition X="0.4900" Y="0.5000" />
                                <PreSize X="1.0100" Y="1.0000" />
                                <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="txtProgress" ActionTag="-768286962" Tag="348" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="54.2320" RightMargin="54.2311" TopMargin="-1.1326" BottomMargin="3.7969" FontSize="50" LabelText="0/4" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="89.0000" Y="58.0000" />
                                <AnchorPoint ScaleX="0.5457" ScaleY="0.3595" />
                                <Position X="102.7993" Y="24.6479" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5206" Y="0.4063" />
                                <PreSize X="0.4507" Y="0.9561" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="255" G="0" B="0" />
                                <ShadowColor A="255" R="0" G="0" B="0" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="132.4107" Y="49.5073" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.2182" Y="0.5631" />
                            <PreSize X="0.3254" Y="0.6900" />
                            <SingleColor A="255" R="0" G="0" B="0" />
                            <FirstColor A="255" R="100" G="100" B="100" />
                            <EndColor A="255" R="4" G="4" B="4" />
                            <ColorVector ScaleY="1.0000" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" />
                        <Position X="312.8000" Y="3.6655" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5000" Y="0.0140" />
                        <PreSize X="0.9700" Y="0.3358" />
                        <SingleColor A="255" R="187" G="101" B="4" />
                        <FirstColor A="255" R="172" G="102" B="0" />
                        <EndColor A="255" R="48" G="17" B="0" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="342.7880" Y="738.0303" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5041" Y="0.7329" />
                    <PreSize X="0.9200" Y="0.2600" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="btnChallenge1" ActionTag="-1803764899" Tag="282" IconVisible="False" PositionPercentXEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="25.5680" RightMargin="28.8320" TopMargin="411.0900" BottomMargin="334.0900" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" TopEage="30" BottomEage="30" Scale9OriginX="38" Scale9OriginY="30" Scale9Width="104" Scale9Height="137" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="625.6000" Y="261.8200" />
                    <Children>
                      <AbstractNodeData Name="panelTop" ActionTag="-780462995" Tag="284" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="177.5765" RightMargin="27.9331" TopMargin="18.9034" BottomMargin="119.8874" ClipAble="False" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                        <Size X="420.0904" Y="123.0292" />
                        <Children>
                          <AbstractNodeData Name="txtChallenge" ActionTag="514709496" Tag="286" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="16.8036" RightMargin="16.8036" TopMargin="6.1515" BottomMargin="6.1515" IsCustomSize="True" FontSize="36" LabelText="Use Bomb 20 times." HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="386.4832" Y="110.7263" />
                            <AnchorPoint />
                            <Position X="16.8036" Y="6.1515" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="148" G="117" B="41" />
                            <PrePosition X="0.0400" Y="0.0500" />
                            <PreSize X="0.9200" Y="0.9000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="0" G="0" B="0" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" />
                        <Position X="387.6217" Y="119.8874" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6196" Y="0.4579" />
                        <PreSize X="0.6715" Y="0.4699" />
                        <SingleColor A="255" R="0" G="0" B="0" />
                        <FirstColor A="255" R="150" G="200" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="iconChallenge" ActionTag="-408611563" Tag="288" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="38.0960" RightMargin="463.5040" TopMargin="19.1642" BottomMargin="118.6558" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="44" Scale9Height="46" ctype="ImageViewObjectData">
                        <Size X="124.0000" Y="124.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="100.0960" Y="180.6558" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1600" Y="0.6900" />
                        <PreSize X="0.1982" Y="0.4736" />
                        <FileData Type="Normal" Path="image/play/balloon.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="dlgpanelseper_2" ActionTag="-93252573" Tag="314" IconVisible="False" LeftMargin="86.0814" RightMargin="60.5186" TopMargin="143.5068" BottomMargin="108.3132" ctype="SpriteObjectData">
                        <Size X="479.0000" Y="10.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="325.5814" Y="113.3132" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.4328" />
                        <PreSize X="0.7657" Y="0.0382" />
                        <FileData Type="Normal" Path="image/dialog/dlgpanelseper.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="panelBottom" ActionTag="-2146031096" Tag="316" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="9.3840" RightMargin="9.3841" TopMargin="170.2353" BottomMargin="3.6655" ClipAble="False" BackColorAlpha="151" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                        <Size X="606.8320" Y="87.9192" />
                        <Children>
                          <AbstractNodeData Name="lblBonus" ActionTag="-421765089" Tag="317" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="267.0061" RightMargin="241.8259" TopMargin="17.6844" BottomMargin="28.2347" FontSize="36" LabelText="Earn:" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="98.0000" Y="42.0000" />
                            <AnchorPoint ScaleY="0.5000" />
                            <Position X="267.0061" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.4400" Y="0.5600" />
                            <PreSize X="0.1615" Y="0.4777" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="0" G="0" B="0" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="iconBonus" ActionTag="-1600025240" Tag="315" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="394.8772" RightMargin="145.9547" TopMargin="5.6844" BottomMargin="16.2347" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="44" Scale9Height="36" ctype="ImageViewObjectData">
                            <Size X="66.0000" Y="66.0000" />
                            <Children>
                              <AbstractNodeData Name="particleBonus" ActionTag="-876593120" Tag="117" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="33.0000" RightMargin="33.0000" TopMargin="33.0000" BottomMargin="33.0000" ctype="ParticleObjectData">
                                <Size X="0.0000" Y="0.0000" />
                                <AnchorPoint />
                                <Position X="33.0000" Y="33.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="0.0000" Y="0.0000" />
                                <FileData Type="Normal" Path="particle/MagicHat.plist" Plist="" />
                                <BlendFunc Src="770" Dst="1" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="427.8772" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7051" Y="0.5600" />
                            <PreSize X="0.1088" Y="0.7507" />
                            <FileData Type="Normal" Path="image/playui/dice.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="panelBonusMul" ActionTag="-675943816" Tag="318" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="479.3973" RightMargin="18.2050" TopMargin="8.3523" BottomMargin="18.9026" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                            <Size X="109.2298" Y="60.6642" />
                            <Children>
                              <AbstractNodeData Name="txtBonusMul" ActionTag="-1358911702" Tag="319" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="25.1149" RightMargin="25.1149" TopMargin="-0.0813" BottomMargin="2.7456" FontSize="50" LabelText="x1" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="59.0000" Y="58.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="54.6149" Y="31.7456" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5233" />
                                <PreSize X="0.5401" Y="0.9561" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="255" G="0" B="0" />
                                <ShadowColor A="255" R="0" G="0" B="0" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="534.0121" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.8800" Y="0.5600" />
                            <PreSize X="0.1800" Y="0.6900" />
                            <SingleColor A="255" R="0" G="0" B="0" />
                            <FirstColor A="255" R="100" G="100" B="100" />
                            <EndColor A="255" R="0" G="0" B="0" />
                            <ColorVector ScaleY="1.0000" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="panelProgress" ActionTag="-1444893595" Tag="321" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="33.6792" RightMargin="375.6897" TopMargin="8.0797" BottomMargin="19.1752" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                            <Size X="197.4631" Y="60.6642" />
                            <Children>
                              <AbstractNodeData Name="progress" ActionTag="1477443011" Alpha="197" Tag="320" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="-2.9619" RightMargin="0.9873" TopMargin="0.0000" ProgressInfo="24" ctype="LoadingBarObjectData">
                                <Size X="199.4377" Y="60.6642" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="96.7569" Y="30.3321" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="250" G="188" B="88" />
                                <PrePosition X="0.4900" Y="0.5000" />
                                <PreSize X="1.0100" Y="1.0000" />
                                <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="txtProgress" ActionTag="2024185796" Tag="322" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="54.2320" RightMargin="54.2311" TopMargin="-1.1326" BottomMargin="3.7969" FontSize="50" LabelText="1/4" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="89.0000" Y="58.0000" />
                                <AnchorPoint ScaleX="0.5457" ScaleY="0.3595" />
                                <Position X="102.7993" Y="24.6479" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5206" Y="0.4063" />
                                <PreSize X="0.4507" Y="0.9561" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="255" G="0" B="0" />
                                <ShadowColor A="255" R="0" G="0" B="0" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="132.4107" Y="49.5073" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.2182" Y="0.5631" />
                            <PreSize X="0.3254" Y="0.6900" />
                            <SingleColor A="255" R="0" G="0" B="0" />
                            <FirstColor A="255" R="100" G="100" B="100" />
                            <EndColor A="255" R="4" G="4" B="4" />
                            <ColorVector ScaleY="1.0000" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" />
                        <Position X="312.8000" Y="3.6655" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5000" Y="0.0140" />
                        <PreSize X="0.9700" Y="0.3358" />
                        <SingleColor A="255" R="187" G="101" B="4" />
                        <FirstColor A="255" R="172" G="102" B="0" />
                        <EndColor A="255" R="48" G="17" B="0" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="338.3680" Y="465.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4976" Y="0.4618" />
                    <PreSize X="0.9200" Y="0.2600" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="btnChallenge2" ActionTag="906195032" Tag="323" IconVisible="False" PositionPercentXEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="26.1120" RightMargin="28.2880" TopMargin="690.0900" BottomMargin="55.0900" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="50" RightEage="113" TopEage="30" BottomEage="30" Scale9OriginX="50" Scale9OriginY="30" Scale9Width="17" Scale9Height="137" DisplayState="False" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="625.6000" Y="261.8200" />
                    <Children>
                      <AbstractNodeData Name="panelTop" ActionTag="1911558049" Tag="324" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="177.5765" RightMargin="27.9331" TopMargin="18.9034" BottomMargin="119.8874" ClipAble="False" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                        <Size X="420.0904" Y="123.0292" />
                        <Children>
                          <AbstractNodeData Name="txtChallenge" ActionTag="-1556657941" Tag="325" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="16.8036" RightMargin="16.8036" TopMargin="6.1515" BottomMargin="6.1515" IsCustomSize="True" FontSize="36" LabelText="Use Earth 10 times." HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="386.4831" Y="110.7263" />
                            <AnchorPoint />
                            <Position X="16.8036" Y="6.1515" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="148" G="117" B="41" />
                            <PrePosition X="0.0400" Y="0.0500" />
                            <PreSize X="0.9200" Y="0.9000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="0" G="0" B="0" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" />
                        <Position X="387.6217" Y="119.8874" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6196" Y="0.4579" />
                        <PreSize X="0.6715" Y="0.4699" />
                        <SingleColor A="255" R="0" G="0" B="0" />
                        <FirstColor A="255" R="150" G="200" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="iconChallenge" ActionTag="119615564" Tag="326" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="38.0960" RightMargin="463.5040" TopMargin="19.1642" BottomMargin="118.6558" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="46" Scale9Height="40" ctype="ImageViewObjectData">
                        <Size X="124.0000" Y="124.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="100.0960" Y="180.6558" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.1600" Y="0.6900" />
                        <PreSize X="0.1982" Y="0.4736" />
                        <FileData Type="Normal" Path="image/play/carrot.png" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="dlgpanelseper_2" ActionTag="-308322550" Tag="327" IconVisible="False" LeftMargin="86.0814" RightMargin="60.5186" TopMargin="143.5068" BottomMargin="108.3132" ctype="SpriteObjectData">
                        <Size X="479.0000" Y="10.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="325.5814" Y="113.3132" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5204" Y="0.4328" />
                        <PreSize X="0.7657" Y="0.0382" />
                        <FileData Type="Normal" Path="image/dialog/dlgpanelseper.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="panelBottom" ActionTag="-1998728324" Tag="328" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="9.3840" RightMargin="9.3840" TopMargin="170.2353" BottomMargin="3.6655" ClipAble="False" BackColorAlpha="151" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Enable="True" LeftEage="42" RightEage="42" TopEage="49" BottomEage="49" Scale9OriginX="-42" Scale9OriginY="-49" Scale9Width="84" Scale9Height="98" ctype="PanelObjectData">
                        <Size X="606.8320" Y="87.9192" />
                        <Children>
                          <AbstractNodeData Name="lblBonus" ActionTag="-643316205" Tag="329" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="267.0061" RightMargin="241.8259" TopMargin="17.6844" BottomMargin="28.2347" FontSize="36" LabelText="Earn:" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="98.0000" Y="42.0000" />
                            <AnchorPoint ScaleY="0.5000" />
                            <Position X="267.0061" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.4400" Y="0.5600" />
                            <PreSize X="0.1615" Y="0.4777" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="0" G="0" B="0" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="iconBonus" ActionTag="-1411766549" Tag="330" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="394.8772" RightMargin="145.9547" TopMargin="5.6844" BottomMargin="16.2347" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="39" Scale9Height="44" ctype="ImageViewObjectData">
                            <Size X="66.0000" Y="66.0000" />
                            <Children>
                              <AbstractNodeData Name="particleBonus" ActionTag="-178500749" Tag="118" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="33.0000" RightMargin="33.0000" TopMargin="33.0000" BottomMargin="33.0000" ctype="ParticleObjectData">
                                <Size X="0.0000" Y="0.0000" />
                                <AnchorPoint />
                                <Position X="33.0000" Y="33.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="0.0000" Y="0.0000" />
                                <FileData Type="Normal" Path="particle/MagicHat.plist" Plist="" />
                                <BlendFunc Src="770" Dst="1" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="427.8772" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7051" Y="0.5600" />
                            <PreSize X="0.1088" Y="0.7507" />
                            <FileData Type="Normal" Path="image/playui/hammer.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="panelBonusMul" ActionTag="-1155934075" Tag="331" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="479.3973" RightMargin="18.2050" TopMargin="8.3523" BottomMargin="18.9026" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                            <Size X="109.2298" Y="60.6642" />
                            <Children>
                              <AbstractNodeData Name="txtBonusMul" ActionTag="-458822445" Tag="332" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="22.1149" RightMargin="22.1149" TopMargin="-0.0813" BottomMargin="2.7456" FontSize="50" LabelText="x3" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="65.0000" Y="58.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="54.6149" Y="31.7456" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5233" />
                                <PreSize X="0.5951" Y="0.9561" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="255" G="0" B="0" />
                                <ShadowColor A="255" R="0" G="0" B="0" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="534.0121" Y="49.2347" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.8800" Y="0.5600" />
                            <PreSize X="0.1800" Y="0.6900" />
                            <SingleColor A="255" R="0" G="0" B="0" />
                            <FirstColor A="255" R="100" G="100" B="100" />
                            <EndColor A="255" R="0" G="0" B="0" />
                            <ColorVector ScaleY="1.0000" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="panelProgress" ActionTag="-2027145181" Tag="333" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="33.6792" RightMargin="375.6897" TopMargin="8.0797" BottomMargin="19.1752" ClipAble="False" BackColorAlpha="102" ComboBoxIndex="2" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                            <Size X="197.4631" Y="60.6642" />
                            <Children>
                              <AbstractNodeData Name="progress" ActionTag="1851165962" Alpha="197" Tag="334" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="-2.9619" RightMargin="0.9873" TopMargin="0.0000" ProgressInfo="65" ctype="LoadingBarObjectData">
                                <Size X="199.4377" Y="60.6642" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="96.7569" Y="30.3321" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="250" G="188" B="88" />
                                <PrePosition X="0.4900" Y="0.5000" />
                                <PreSize X="1.0100" Y="1.0000" />
                                <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" Plist="" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="txtProgress" ActionTag="-243948712" Tag="335" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="36.2239" RightMargin="39.2392" TopMargin="-1.1326" BottomMargin="3.7969" FontSize="50" LabelText="6/10" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="122.0000" Y="58.0000" />
                                <AnchorPoint ScaleX="0.5457" ScaleY="0.3595" />
                                <Position X="102.7993" Y="24.6479" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5206" Y="0.4063" />
                                <PreSize X="0.6178" Y="0.9561" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="255" G="0" B="0" />
                                <ShadowColor A="255" R="0" G="0" B="0" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="132.4107" Y="49.5073" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.2182" Y="0.5631" />
                            <PreSize X="0.3254" Y="0.6900" />
                            <SingleColor A="255" R="0" G="0" B="0" />
                            <FirstColor A="255" R="100" G="100" B="100" />
                            <EndColor A="255" R="4" G="4" B="4" />
                            <ColorVector ScaleY="1.0000" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" />
                        <Position X="312.8000" Y="3.6655" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5000" Y="0.0140" />
                        <PreSize X="0.9700" Y="0.3358" />
                        <SingleColor A="255" R="187" G="101" B="4" />
                        <FirstColor A="255" R="172" G="102" B="0" />
                        <EndColor A="255" R="48" G="17" B="0" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="338.9120" Y="186.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4984" Y="0.1847" />
                    <PreSize X="0.9200" Y="0.2600" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" />
                <Position X="0.0021" Y="-495.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgBottom" ActionTag="-514651647" Tag="65" IconVisible="False" LeftMargin="-340.0005" RightMargin="-339.9995" TopMargin="476.5000" BottomMargin="-563.5000" Scale9Enable="True" LeftEage="78" RightEage="78" BottomEage="50" Scale9OriginX="78" Scale9Width="5" Scale9Height="188" ctype="ImageViewObjectData">
                <Size X="680.0000" Y="87.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0005" Y="-520.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframebottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgBottomBtn" ActionTag="-1856958377" Tag="383" IconVisible="False" LeftMargin="-285.0005" RightMargin="-284.9995" TopMargin="547.0002" BottomMargin="-671.0002" Scale9Enable="True" LeftEage="150" RightEage="150" Scale9OriginX="150" Scale9Width="9" Scale9Height="124" ctype="ImageViewObjectData">
                <Size X="570.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0005" Y="-609.0002" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgextend.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-306.4999" RightMargin="-306.5001" TopMargin="-567.5000" BottomMargin="482.5000" IsCustomSize="True" FontSize="68" LabelText="Daily Challenge" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="613.0000" Y="85.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="0.0001" Y="525.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="247" G="237" B="185" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="131" G="25" B="28" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgBottomBtnSlot" ActionTag="-1739831109" Tag="108" IconVisible="False" LeftMargin="-257.0002" RightMargin="-256.9998" TopMargin="465.5000" BottomMargin="-644.5000" Scale9Enable="True" LeftEage="110" RightEage="110" Scale9OriginX="110" Scale9Width="5" Scale9Height="179" ctype="ImageViewObjectData">
                <Size X="514.0000" Y="179.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-555.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/btnslot.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnContinue" ActionTag="-1291112590" Tag="380" IconVisible="False" LeftMargin="-244.0000" RightMargin="-244.0000" TopMargin="480.0000" BottomMargin="-630.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="244" RightEage="244" Scale9OriginX="244" Scale9Width="1" Scale9Height="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="488.0000" Y="150.0000" />
                <Children>
                  <AbstractNodeData Name="btnhighlight2_1" ActionTag="330082057" Tag="381" IconVisible="False" LeftMargin="27.4216" RightMargin="397.5784" TopMargin="23.5831" BottomMargin="106.4169" ctype="SpriteObjectData">
                    <Size X="63.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.9216" Y="116.4169" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.1207" Y="0.7761" />
                    <PreSize X="0.1291" Y="0.1333" />
                    <FileData Type="Normal" Path="image/button/btnhighlight2.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="txtName" ActionTag="-754421776" Tag="382" IconVisible="False" LeftMargin="55.5000" RightMargin="55.5000" TopMargin="20.5000" BottomMargin="30.5000" FontSize="80" LabelText="Continue" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="377.0000" Y="99.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="244.0000" Y="80.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.5000" Y="0.5333" />
                    <PreSize X="0.7725" Y="0.6600" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="91" G="127" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-555.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <PressedFileData Type="Normal" Path="image/button/btn.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/btn.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnClose" ActionTag="-457922759" Tag="113" IconVisible="False" LeftMargin="263.0000" RightMargin="-361.0000" TopMargin="-649.0000" BottomMargin="551.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="98.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="312.0000" Y="600.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="360.0000" Y="700.1260" />
            <Scale ScaleX="0.9000" ScaleY="0.9000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5470" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>