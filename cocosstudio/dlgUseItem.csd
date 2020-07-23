<GameFile>
  <PropertyGroup Name="dlgUseItem" Type="Scene" ID="55b3df16-271f-4976-b54f-db212492f351" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="50" Speed="0.5000">
        <Timeline ActionTag="842732357" Property="Position">
          <PointFrame FrameIndex="0" X="360.0000" Y="1440.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="360.0000" Y="1153.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="360.0000" Y="1153.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="45" X="360.0000" Y="1440.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="50" X="360.0000" Y="1440.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="842732357" Property="Scale">
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="842732357" Property="RotationSkew">
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="842732357" Property="FrameEvent">
          <EventFrame FrameIndex="50" Tween="False" Value="evt_finished" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="flyIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="143" G="188" B="139" />
        </AnimationInfo>
        <AnimationInfo Name="stay" StartIndex="16" EndIndex="29">
          <RenderColor A="255" R="255" G="99" B="71" />
        </AnimationInfo>
        <AnimationInfo Name="flyOut" StartIndex="30" EndIndex="50">
          <RenderColor A="255" R="255" G="165" B="0" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="49" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="root" ActionTag="842732357" Tag="2" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="127.0000" BottomMargin="1153.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="dlgbar" ActionTag="890413445" Tag="3" IconVisible="False" LeftMargin="-370.0000" RightMargin="-370.0000" TopMargin="-127.5000" BottomMargin="-127.5000" Scale9Enable="True" TopEage="34" BottomEage="20" Scale9OriginY="34" Scale9Width="32" Scale9Height="46" ctype="ImageViewObjectData">
                <Size X="740.0000" Y="255.0000" />
                <Children>
                  <AbstractNodeData Name="Panel" ActionTag="543143528" Tag="879" IconVisible="False" TopMargin="32.0000" BottomMargin="19.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                    <Size X="740.0000" Y="204.0000" />
                    <Children>
                      <AbstractNodeData Name="shine" ActionTag="-1824781243" Tag="4" IconVisible="True" LeftMargin="150.0000" RightMargin="590.0000" TopMargin="94.0000" BottomMargin="110.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                        <Size X="0.0000" Y="0.0000" />
                        <AnchorPoint />
                        <Position X="150.0000" Y="110.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2027" Y="0.5392" />
                        <PreSize X="0.0000" Y="0.0000" />
                        <FileData Type="Normal" Path="fxShine.csd" Plist="" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="HammerNode" ActionTag="-1824898712" VisibleForFrame="False" Tag="1056" IconVisible="True" RightMargin="740.0000" TopMargin="204.0000" ctype="SingleNodeObjectData">
                        <Size X="0.0000" Y="0.0000" />
                        <Children>
                          <AbstractNodeData Name="hammer" ActionTag="871656649" Tag="5" RotationSkewX="-25.0000" RotationSkewY="-25.0000" IconVisible="False" LeftMargin="103.5000" RightMargin="-196.5000" TopMargin="-159.0000" BottomMargin="61.0000" ctype="SpriteObjectData">
                            <Size X="93.0000" Y="98.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="150.0000" Y="110.0000" />
                            <Scale ScaleX="1.6500" ScaleY="1.6500" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FileData Type="Normal" Path="image/playui/hammer.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text_hammer" ActionTag="-1872739385" Tag="973" RotationSkewY="0.0009" IconVisible="False" LeftMargin="366.5000" RightMargin="-593.5000" TopMargin="-172.0000" BottomMargin="108.0000" FontSize="52" LabelText="Hammer" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.5000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="227.0000" Y="64.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="140.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="237" G="232" B="205" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="105" G="30" B="35" />
                            <ShadowColor A="255" R="105" G="30" B="35" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text" ActionTag="-1217749032" Tag="1049" RotationSkewY="0.0004" IconVisible="False" LeftMargin="321.0000" RightMargin="-639.0000" TopMargin="-89.0000" BottomMargin="61.0000" FontSize="24" LabelText="Tap any item to remove it!" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                            <Size X="318.0000" Y="28.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="58" G="27" B="29" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="110" G="110" B="110" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="BoxingGloveNode" ActionTag="-988206518" VisibleForFrame="False" Tag="1058" IconVisible="True" RightMargin="740.0000" TopMargin="204.0000" ctype="SingleNodeObjectData">
                        <Size X="0.0000" Y="0.0000" />
                        <Children>
                          <AbstractNodeData Name="boxclub" ActionTag="-1316922976" Tag="1042" IconVisible="False" LeftMargin="74.5000" RightMargin="-225.5000" TopMargin="-177.5000" BottomMargin="42.5000" ctype="SpriteObjectData">
                            <Size X="151.0000" Y="135.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="150.0000" Y="110.0000" />
                            <Scale ScaleX="1.1000" ScaleY="1.1000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FileData Type="Normal" Path="image/playui/boxclub.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text_boxclub" ActionTag="694165157" Tag="1052" RotationSkewY="0.0012" IconVisible="False" LeftMargin="300.5000" RightMargin="-659.5000" TopMargin="-172.0000" BottomMargin="108.0000" FontSize="52" LabelText="Boxing Glove" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.5000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="359.0000" Y="64.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="140.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="237" G="232" B="205" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="105" G="30" B="35" />
                            <ShadowColor A="255" R="105" G="30" B="35" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text" ActionTag="-399161108" Tag="1053" RotationSkewY="-0.0004" IconVisible="False" LeftMargin="336.5000" RightMargin="-623.5000" TopMargin="-103.0000" BottomMargin="47.0000" FontSize="24" LabelText="Tap any item to remove&#xA;everything in that row!" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                            <Size X="287.0000" Y="56.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="58" G="27" B="29" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="110" G="110" B="110" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="AnvilNode" ActionTag="627802569" VisibleForFrame="False" Tag="1057" IconVisible="True" RightMargin="740.0000" TopMargin="204.0000" ctype="SingleNodeObjectData">
                        <Size X="0.0000" Y="0.0000" />
                        <Children>
                          <AbstractNodeData Name="anvil" ActionTag="-1404695213" Tag="1041" IconVisible="False" LeftMargin="50.5000" RightMargin="-249.5000" TopMargin="-201.0000" BottomMargin="7.0000" ctype="SpriteObjectData">
                            <Size X="199.0000" Y="194.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="150.0000" Y="104.0000" />
                            <Scale ScaleX="0.9000" ScaleY="0.9000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FileData Type="Normal" Path="image/playui/anvil.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text_anvil" ActionTag="-161926373" Tag="1050" RotationSkewY="0.0009" IconVisible="False" LeftMargin="408.5000" RightMargin="-551.5000" TopMargin="-172.0000" BottomMargin="108.0000" FontSize="52" LabelText="Anvil" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.5000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="143.0000" Y="64.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="140.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="237" G="232" B="205" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="105" G="30" B="35" />
                            <ShadowColor A="255" R="105" G="30" B="35" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text" ActionTag="-1855827372" Tag="1051" RotationSkewY="-0.0005" IconVisible="False" LeftMargin="318.5000" RightMargin="-641.5000" TopMargin="-103.0000" BottomMargin="47.0000" FontSize="24" LabelText="Tap any item to remove&#xA;everything in that column!" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                            <Size X="323.0000" Y="56.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="58" G="27" B="29" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="110" G="110" B="110" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="DiceNode" ActionTag="-1558303127" VisibleForFrame="False" Tag="1059" IconVisible="True" RightMargin="740.0000" TopMargin="204.0000" ctype="SingleNodeObjectData">
                        <Size X="0.0000" Y="0.0000" />
                        <Children>
                          <AbstractNodeData Name="dice" ActionTag="-298864975" Tag="1043" IconVisible="False" LeftMargin="101.0000" RightMargin="-199.0000" TopMargin="-155.0000" BottomMargin="65.0000" FlipX="True" ctype="SpriteObjectData">
                            <Size X="98.0000" Y="90.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="150.0000" Y="110.0000" />
                            <Scale ScaleX="1.4400" ScaleY="1.4400" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FileData Type="Normal" Path="image/playui/dice.png" Plist="" />
                            <BlendFunc Src="1" Dst="771" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text_Dice" ActionTag="-1538359164" Tag="1054" RotationSkewY="0.0012" IconVisible="False" LeftMargin="421.5000" RightMargin="-538.5000" TopMargin="-172.0000" BottomMargin="108.0000" FontSize="52" LabelText="Dice" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.5000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="117.0000" Y="64.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="140.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="237" G="232" B="205" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="105" G="30" B="35" />
                            <ShadowColor A="255" R="105" G="30" B="35" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="Text" ActionTag="-999754892" Tag="1055" RotationSkewY="-0.0004" IconVisible="False" LeftMargin="303.0000" RightMargin="-657.0000" TopMargin="-103.0000" BottomMargin="47.0000" FontSize="24" LabelText="Tap any cube to shuffle all of&#xA;the cubes!" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                            <Size X="354.0000" Y="56.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="480.0000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="58" G="27" B="29" />
                            <PrePosition />
                            <PreSize X="0.0000" Y="0.0000" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="255" G="0" B="0" />
                            <ShadowColor A="255" R="110" G="110" B="110" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="0.0000" Y="0.0000" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="370.0000" Y="121.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.4745" />
                    <PreSize X="1.0000" Y="0.8000" />
                    <SingleColor A="255" R="150" G="200" B="255" />
                    <FirstColor A="255" R="150" G="200" B="255" />
                    <EndColor A="255" R="255" G="255" B="255" />
                    <ColorVector ScaleY="1.0000" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgbar.png" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="360.0000" Y="1153.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9008" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>