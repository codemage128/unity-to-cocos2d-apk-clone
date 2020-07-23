<GameFile>
  <PropertyGroup Name="dlgSetting" Type="Scene" ID="2bbdcdff-98e8-4f4f-9329-1d14e64bf35b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="32" Speed="0.5000">
        <Timeline ActionTag="-672098765" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="15" Value="178">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="25" Value="178">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="32" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Position">
          <PointFrame FrameIndex="0" X="360.0000" Y="626.9995">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="360.0000" Y="626.9995">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="25" X="360.0000" Y="626.9995">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="32" X="360.0000" Y="626.9995">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="FrameEvent">
          <EventFrame FrameIndex="32" Tween="False" Value="evtOut" />
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.0001" Y="0.0100">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="1.0000" Y="1.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="25" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="32" X="0.0100" Y="0.0100">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="evtIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="144" G="238" B="144" />
        </AnimationInfo>
        <AnimationInfo Name="evtOut" StartIndex="25" EndIndex="32">
          <RenderColor A="255" R="65" G="105" B="225" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="312" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="Image_10" ActionTag="-1035479163" VisibleForFrame="False" Tag="2067" IconVisible="False" LeftEage="337" RightEage="337" TopEage="601" BottomEage="601" Scale9OriginX="337" Scale9OriginY="601" Scale9Width="350" Scale9Height="620" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/mapui/mapuibg.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="blackbg" ActionTag="-672098765" Alpha="178" Tag="2066" IconVisible="False" TouchEnable="True" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="653.0005" BottomMargin="626.9995" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Image_1" ActionTag="707715776" Tag="314" IconVisible="False" LeftMargin="-335.0017" RightMargin="-334.9983" TopMargin="-447.9952" BottomMargin="351.9952" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0017" Y="399.9952" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_2" ActionTag="-1008518909" Tag="315" IconVisible="False" LeftMargin="-335.0009" RightMargin="-334.9991" TopMargin="-351.9961" BottomMargin="-94.0039" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="446.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="-0.0009" Y="-94.0039" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_3" ActionTag="-1614951940" Tag="317" IconVisible="False" LeftMargin="-335.0009" RightMargin="-334.9991" TopMargin="93.9997" BottomMargin="-331.9997" Scale9Enable="True" LeftEage="78" RightEage="78" Scale9OriginX="78" Scale9Width="5" Scale9Height="238" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="238.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="-212.9997" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframebottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_7" ActionTag="940055712" Tag="12" IconVisible="False" LeftMargin="-304.0002" RightMargin="-303.9998" TopMargin="-247.9974" BottomMargin="-85.0026" Scale9Enable="True" LeftEage="50" RightEage="50" Scale9OriginX="50" Scale9Width="508" Scale9Height="2" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="333.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="-0.0002" Y="247.9974" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrmiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_6" ActionTag="76587605" Tag="324" IconVisible="False" LeftMargin="-304.0001" RightMargin="-303.9999" TopMargin="-298.9989" BottomMargin="244.9989" Scale9Enable="True" LeftEage="45" RightEage="45" Scale9OriginX="45" Scale9Width="6" Scale9Height="54" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="54.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0001" Y="271.9989" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrtop2.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_8" ActionTag="892197917" Tag="13" IconVisible="False" LeftMargin="-304.0002" RightMargin="-303.9998" TopMargin="85.0015" BottomMargin="-211.0015" Scale9Enable="True" LeftEage="45" RightEage="45" Scale9OriginX="45" Scale9Width="4" Scale9Height="126" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="126.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-148.0015" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrbottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="dlgpanelseper_2" ActionTag="-284254383" Tag="15" IconVisible="False" LeftMargin="-239.5002" RightMargin="-239.4998" TopMargin="-54.0013" BottomMargin="44.0013" ctype="SpriteObjectData">
                <Size X="479.0000" Y="10.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="49.0013" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelseper.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnClose" ActionTag="-1581048205" Tag="321" IconVisible="False" LeftMargin="263.9998" RightMargin="-361.9998" TopMargin="-471.9957" BottomMargin="373.9957" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="98.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="312.9998" Y="422.9957" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-185.9996" RightMargin="-186.0004" TopMargin="-415.9956" BottomMargin="307.9956" FontSize="90" LabelText="Settings" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="372.0000" Y="108.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="0.0004" Y="361.9956" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="247" G="237" B="185" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="131" G="25" B="28" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
              <AbstractNodeData Name="spMusicSlot" ActionTag="-710134558" Tag="13" IconVisible="False" LeftMargin="-158.0001" RightMargin="42.0001" TopMargin="-219.5000" BottomMargin="104.5000" ctype="SpriteObjectData">
                <Size X="116.0000" Y="115.0000" />
                <Children>
                  <AbstractNodeData Name="chkMusic" ActionTag="2009829540" Tag="16" IconVisible="False" LeftMargin="12.0000" RightMargin="12.0000" TopMargin="11.0000" BottomMargin="12.0000" TouchEnable="True" ctype="CheckBoxObjectData">
                    <Size X="92.0000" Y="92.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="58.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5043" />
                    <PreSize X="0.7931" Y="0.8000" />
                    <NormalBackFileData Type="Normal" Path="image/button/btnsound.png" Plist="" />
                    <PressedBackFileData Type="Normal" Path="image/button/btnsound.png" Plist="" />
                    <DisableBackFileData Type="Default" Path="Default/CheckBox_Disable.png" Plist="" />
                    <NodeNormalFileData Type="Normal" Path="image/common/xline2.png" Plist="" />
                    <NodeDisableFileData Type="Default" Path="Default/CheckBoxNode_Disable.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-100.0001" Y="162.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/menubuttonslot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="spEffectSlot" ActionTag="-909644033" Tag="12" IconVisible="False" LeftMargin="41.9999" RightMargin="-157.9999" TopMargin="-219.5000" BottomMargin="104.5000" ctype="SpriteObjectData">
                <Size X="116.0000" Y="115.0000" />
                <Children>
                  <AbstractNodeData Name="chkEffect" ActionTag="-724791904" Tag="17" IconVisible="False" LeftMargin="11.5000" RightMargin="11.5000" TopMargin="11.0000" BottomMargin="12.0000" TouchEnable="True" ctype="CheckBoxObjectData">
                    <Size X="93.0000" Y="92.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="58.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5043" />
                    <PreSize X="0.8017" Y="0.8000" />
                    <NormalBackFileData Type="Normal" Path="image/button/btnmusic.png" Plist="" />
                    <PressedBackFileData Type="Normal" Path="image/button/btnmusic.png" Plist="" />
                    <DisableBackFileData Type="Default" Path="Default/CheckBox_Disable.png" Plist="" />
                    <NodeNormalFileData Type="Normal" Path="image/common/xline2.png" Plist="" />
                    <NodeDisableFileData Type="Default" Path="Default/CheckBoxNode_Disable.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="99.9999" Y="162.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/menubuttonslot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnSupport" ActionTag="-814964534" Tag="18" IconVisible="False" LeftMargin="-175.0004" RightMargin="-174.9996" TopMargin="11.5000" BottomMargin="-138.5000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="62" RightEage="30" Scale9OriginX="62" Scale9Width="35" Scale9Height="127" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="350.0000" Y="127.0000" />
                <Children>
                  <AbstractNodeData Name="supporticon_3" ActionTag="406671308" Tag="19" IconVisible="False" LeftMargin="9.0000" RightMargin="229.0000" TopMargin="8.4998" BottomMargin="11.5002" ctype="SpriteObjectData">
                    <Size X="112.0000" Y="107.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="65.0000" Y="65.0002" />
                    <Scale ScaleX="0.7000" ScaleY="0.7000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.1857" Y="0.5118" />
                    <PreSize X="0.3200" Y="0.8425" />
                    <FileData Type="Normal" Path="image/common/supporticon.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_1" ActionTag="-1810632669" Tag="20" IconVisible="False" LeftMargin="112.0000" RightMargin="32.0000" TopMargin="31.0000" BottomMargin="34.0000" FontSize="50" LabelText="Support" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="206.0000" Y="62.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="215.0000" Y="65.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="248" B="210" />
                    <PrePosition X="0.6143" Y="0.5118" />
                    <PreSize X="0.5886" Y="0.4882" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="90" G="126" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0004" Y="-75.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/button/button.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/button.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="360.0000" Y="626.9995" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4898" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>