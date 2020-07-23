<GameFile>
  <PropertyGroup Name="dlgLevelQuit" Type="Scene" ID="2bbdcdff-98e8-4f4f-9329-1d14e64bf35b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="50" Speed="0.5000">
        <Timeline ActionTag="-1135688418" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="15" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="45" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="50" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1135688418" Property="FrameEvent">
          <EventFrame FrameIndex="50" Tween="False" Value="evt_finished" />
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Position">
          <PointFrame FrameIndex="0" X="360.0000" Y="2000.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="360.0000" Y="640.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="360.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="45" X="360.0000" Y="-820.0000">
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
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="0.0000" Y="0.0000">
            <EasingData Type="26" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="FlyIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="0" G="250" B="154" />
        </AnimationInfo>
        <AnimationInfo Name="FlyOut" StartIndex="30" EndIndex="55">
          <RenderColor A="255" R="165" G="42" B="42" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="312" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="background" ActionTag="-1135688418" Alpha="127" Tag="157" IconVisible="False" TouchEnable="True" Scale9Enable="True" LeftEage="1" RightEage="1" TopEage="1" BottomEage="1" Scale9OriginX="1" Scale9OriginY="1" Scale9Width="44" Scale9Height="44" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Default" Path="Default/ImageFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="640.0000" BottomMargin="640.0000" ctype="SingleNodeObjectData">
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
              <AbstractNodeData Name="Image_4" ActionTag="596910182" Tag="318" IconVisible="False" LeftMargin="-285.0002" RightMargin="-284.9998" TopMargin="313.0002" BottomMargin="-437.0002" Scale9Enable="True" LeftEage="150" RightEage="150" Scale9OriginX="150" Scale9Width="9" Scale9Height="124" ctype="ImageViewObjectData">
                <Size X="570.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-375.0002" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgextend.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_5" ActionTag="1603248027" Tag="319" IconVisible="False" LeftMargin="-257.0002" RightMargin="-256.9998" TopMargin="228.5016" BottomMargin="-407.5016" Scale9Enable="True" LeftEage="110" RightEage="110" Scale9OriginX="110" Scale9Width="5" Scale9Height="179" ctype="ImageViewObjectData">
                <Size X="514.0000" Y="179.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-318.0016" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/btnslot.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_6" ActionTag="76587605" Tag="324" IconVisible="False" LeftMargin="-304.0009" RightMargin="-303.9991" TopMargin="-296.4984" BottomMargin="247.4984" Scale9Enable="True" LeftEage="304" RightEage="304" Scale9OriginX="304" Scale9Width="1" Scale9Height="49" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="49.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="271.9984" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrtop.png" Plist="" />
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
              <AbstractNodeData Name="btn_quit" ActionTag="-553722109" Tag="320" IconVisible="False" LeftMargin="-244.0009" RightMargin="-243.9991" TopMargin="240.0026" BottomMargin="-390.0026" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="244" RightEage="244" Scale9OriginX="244" Scale9Width="1" Scale9Height="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="488.0000" Y="150.0000" />
                <Children>
                  <AbstractNodeData Name="btnhighlight2_1" ActionTag="1339722504" Tag="13" IconVisible="False" LeftMargin="27.4216" RightMargin="397.5784" TopMargin="23.5831" BottomMargin="106.4169" ctype="SpriteObjectData">
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
                  <AbstractNodeData Name="Text_quit" ActionTag="-747169178" Tag="26" IconVisible="False" LeftMargin="149.5000" RightMargin="149.5000" TopMargin="20.5000" BottomMargin="30.5000" FontSize="80" LabelText="Quit" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="189.0000" Y="99.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="244.0000" Y="80.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.5000" Y="0.5333" />
                    <PreSize X="0.3873" Y="0.6600" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="91" G="127" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="-315.0026" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/button/btn.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/btn.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_close" ActionTag="-1581048205" Tag="321" IconVisible="False" LeftMargin="263.9998" RightMargin="-361.9998" TopMargin="-471.9957" BottomMargin="373.9957" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
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
              <AbstractNodeData Name="Text_1" ActionTag="68987114" Tag="16" IconVisible="False" LeftMargin="-172.5001" RightMargin="-172.4999" TopMargin="14.5014" BottomMargin="-77.5014" FontSize="54" LabelText="You will lose" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="345.0000" Y="63.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0001" Y="-46.0014" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="79" G="30" B="14" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2" ActionTag="-463339379" Tag="437" IconVisible="False" LeftMargin="-71.4983" RightMargin="42.4983" TopMargin="78.4998" BottomMargin="-141.4998" FontSize="54" LabelText="1" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="29.0000" Y="63.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-56.9983" Y="-109.9998" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="202" G="42" B="57" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2_1" ActionTag="-1155655289" Tag="438" IconVisible="False" LeftMargin="-27.9969" RightMargin="-78.0031" TopMargin="78.4999" BottomMargin="-141.4999" FontSize="54" LabelText="life!" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="106.0000" Y="63.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="25.0031" Y="-109.9999" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="79" G="30" B="14" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="heart_broken_shadow_1" ActionTag="-22062880" Alpha="113" Tag="95" IconVisible="False" LeftMargin="-79.0000" RightMargin="-79.0000" TopMargin="-177.0000" BottomMargin="43.0000" ctype="SpriteObjectData">
                <Size X="158.0000" Y="134.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="110.0000" />
                <Scale ScaleX="1.5000" ScaleY="1.5000" />
                <CColor A="255" R="0" G="0" B="0" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/playui/heart_broken_shadow.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="heart_broken_1" ActionTag="-1767282065" Tag="436" IconVisible="False" LeftMargin="-105.0000" RightMargin="-105.0000" TopMargin="-208.5000" BottomMargin="31.5000" ctype="SpriteObjectData">
                <Size X="210.0000" Y="177.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="120.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/playui/heart_broken.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-248.4996" RightMargin="-248.5004" TopMargin="-404.4956" BottomMargin="319.4956" FontSize="70" LabelText="Are You Sure?" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="497.0000" Y="85.0000" />
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
            </Children>
            <AnchorPoint />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="0.9000" ScaleY="0.9000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>