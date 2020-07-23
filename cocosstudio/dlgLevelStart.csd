<GameFile>
  <PropertyGroup Name="dlgLevelStart" Type="Scene" ID="2bbdcdff-98e8-4f4f-9329-1d14e64bf35b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000">
        <Timeline ActionTag="-1832007628" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="45" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="60" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1832007628" Property="FrameEvent">
          <EventFrame FrameIndex="60" Tween="False" Value="evt_finished" />
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Position">
          <PointFrame FrameIndex="0" X="359.9998" Y="1800.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </PointFrame>
          <PointFrame FrameIndex="14" X="359.9998" Y="640.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </PointFrame>
          <PointFrame FrameIndex="18" X="359.9998" Y="650.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="22" X="359.9998" Y="660.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="26" X="359.9998" Y="650.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="359.9998" Y="640.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </PointFrame>
          <PointFrame FrameIndex="45" X="359.9998" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="54" X="359.9998" Y="-500.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="359.9998" Y="-640.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.9000" Y="0.9000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="FlyIn" StartIndex="0" EndIndex="30">
          <RenderColor A="255" R="119" G="136" B="153" />
        </AnimationInfo>
        <AnimationInfo Name="FlyOut" StartIndex="45" EndIndex="60">
          <RenderColor A="255" R="176" G="196" B="222" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="312" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="bg" ActionTag="-1832007628" Alpha="127" Tag="116" IconVisible="False" TouchEnable="True" Scale9Width="46" Scale9Height="46" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Default" Path="Default/ImageFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="359.9998" RightMargin="360.0002" TopMargin="640.0000" BottomMargin="640.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Image_1" CanEdit="False" ActionTag="707715776" Tag="314" IconVisible="False" LeftMargin="-335.0017" RightMargin="-334.9983" TopMargin="-447.9952" BottomMargin="351.9952" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0017" Y="399.9952" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_2" CanEdit="False" ActionTag="-1008518909" Tag="315" IconVisible="False" LeftMargin="-335.0009" RightMargin="-334.9991" TopMargin="-351.9961" BottomMargin="-94.0039" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="446.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="-0.0009" Y="-94.0039" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_3" CanEdit="False" ActionTag="-1614951940" Tag="317" IconVisible="False" LeftMargin="-335.0009" RightMargin="-334.9991" TopMargin="93.9997" BottomMargin="-331.9997" Scale9Enable="True" LeftEage="78" RightEage="78" Scale9OriginX="78" Scale9Width="5" Scale9Height="238" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="238.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="-212.9997" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframebottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_4" CanEdit="False" ActionTag="596910182" Tag="318" IconVisible="False" LeftMargin="-285.0002" RightMargin="-284.9998" TopMargin="313.0002" BottomMargin="-437.0002" Scale9Enable="True" LeftEage="150" RightEage="150" Scale9OriginX="150" Scale9Width="9" Scale9Height="124" ctype="ImageViewObjectData">
                <Size X="570.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-375.0002" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgextend.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_5" CanEdit="False" ActionTag="1603248027" Tag="319" IconVisible="False" LeftMargin="-257.0002" RightMargin="-256.9998" TopMargin="228.5016" BottomMargin="-407.5016" Scale9Enable="True" LeftEage="110" RightEage="110" Scale9OriginX="110" Scale9Width="5" Scale9Height="179" ctype="ImageViewObjectData">
                <Size X="514.0000" Y="179.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-318.0016" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/btnslot.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_7" CanEdit="False" ActionTag="940055712" Tag="12" IconVisible="False" LeftMargin="-304.0002" RightMargin="-303.9998" TopMargin="-247.9974" BottomMargin="-85.0026" Scale9Enable="True" LeftEage="50" RightEage="50" Scale9OriginX="50" Scale9Width="508" Scale9Height="2" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="333.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="-0.0002" Y="247.9974" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrmiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_6" CanEdit="False" ActionTag="76587605" Tag="324" IconVisible="False" LeftMargin="-304.0009" RightMargin="-303.9991" TopMargin="-296.4984" BottomMargin="247.4984" Scale9Enable="True" LeftEage="304" RightEage="304" Scale9OriginX="304" Scale9Width="1" Scale9Height="49" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="49.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="271.9984" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrtop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_8" CanEdit="False" ActionTag="892197917" Tag="13" IconVisible="False" LeftMargin="-304.0002" RightMargin="-303.9998" TopMargin="85.0015" BottomMargin="-211.0015" Scale9Enable="True" LeftEage="45" RightEage="45" Scale9OriginX="45" Scale9Width="4" Scale9Height="126" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="126.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-148.0015" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrbottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="dlgpanelseper_2" ActionTag="-284254383" Tag="15" IconVisible="False" LeftMargin="-239.5002" RightMargin="-239.4998" TopMargin="-61.9967" BottomMargin="51.9967" ctype="SpriteObjectData">
                <Size X="479.0000" Y="10.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="56.9967" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelseper.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_play" ActionTag="-553722109" Tag="320" IconVisible="False" LeftMargin="-245.4016" RightMargin="-242.5984" TopMargin="240.0026" BottomMargin="-390.0026" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="244" RightEage="244" Scale9OriginX="244" Scale9Width="1" Scale9Height="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
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
                  <AbstractNodeData Name="Text_3" ActionTag="-747169178" Tag="26" IconVisible="False" LeftMargin="144.0000" RightMargin="144.0000" TopMargin="10.0000" BottomMargin="30.0000" FontSize="90" LabelText="Play" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="200.0000" Y="110.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="244.0000" Y="85.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.5000" Y="0.5667" />
                    <PreSize X="0.4098" Y="0.7333" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="91" G="127" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-1.4016" Y="-315.0026" />
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
              <AbstractNodeData Name="btn_close" ActionTag="-1581048205" Tag="321" IconVisible="False" LeftMargin="263.9998" RightMargin="-361.9998" TopMargin="-471.9957" BottomMargin="373.9957" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="98.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="312.9998" Y="422.9957" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <PressedFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/button/closebtn.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="boosterslot1" ActionTag="-411115830" Tag="185" IconVisible="False" LeftMargin="-213.5000" RightMargin="86.5000" TopMargin="29.5000" BottomMargin="-156.5000" TouchEnable="True" ctype="CheckBoxObjectData">
                <Size X="127.0000" Y="127.0000" />
                <Children>
                  <AbstractNodeData Name="booster1" ActionTag="1041441503" Tag="187" IconVisible="False" LeftMargin="-37.5000" RightMargin="-36.5000" TopMargin="-36.5000" BottomMargin="-37.5000" LeftEage="23" RightEage="23" TopEage="32" BottomEage="32" Scale9OriginX="23" Scale9OriginY="32" Scale9Width="155" Scale9Height="137" ctype="ImageViewObjectData">
                    <Size X="201.0000" Y="201.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="63.0000" Y="63.0000" />
                    <Scale ScaleX="0.4000" ScaleY="0.4000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4961" Y="0.4961" />
                    <PreSize X="1.5827" Y="1.5827" />
                    <FileData Type="Normal" Path="image/playui/rocket.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="txt_itemMc" ActionTag="-123125085" Tag="58" IconVisible="False" LeftMargin="49.0000" RightMargin="16.0000" TopMargin="76.5000" BottomMargin="13.5000" FontSize="30" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Bottom" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="62.0000" Y="37.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="80.0000" Y="32.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6299" Y="0.2520" />
                    <PreSize X="0.4882" Y="0.2913" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="115" G="153" B="23" />
                    <ShadowColor A="255" R="26" G="19" B="19" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="img_itemM" ActionTag="-831626298" VisibleForFrame="False" Tag="61" IconVisible="False" LeftMargin="56.6472" RightMargin="9.3528" TopMargin="64.6122" BottomMargin="7.3878" LeftEage="20" RightEage="20" TopEage="18" BottomEage="18" Scale9OriginX="20" Scale9OriginY="18" Scale9Width="21" Scale9Height="19" ctype="ImageViewObjectData">
                    <Size X="61.0000" Y="55.0000" />
                    <AnchorPoint ScaleX="0.3827" ScaleY="0.3251" />
                    <Position X="79.9919" Y="25.2683" />
                    <Scale ScaleX="0.7000" ScaleY="0.7000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6299" Y="0.1990" />
                    <PreSize X="0.4803" Y="0.4331" />
                    <FileData Type="Normal" Path="image/button/check.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-150.0000" Y="-93.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <NormalBackFileData Type="Normal" Path="image/button/button.png" Plist="" />
                <PressedBackFileData Type="Normal" Path="image/button/btnblue.png" Plist="" />
                <DisableBackFileData Type="Normal" Path="image/booster/boosterslot.png" Plist="" />
                <NodeNormalFileData Type="Normal" Path="image/button/btnblue.png" Plist="" />
                <NodeDisableFileData Type="Normal" Path="image/button/button.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="boosterslot2" ActionTag="1189651192" Tag="190" IconVisible="False" LeftMargin="-63.5000" RightMargin="-63.5000" TopMargin="29.5000" BottomMargin="-156.5000" TouchEnable="True" ctype="CheckBoxObjectData">
                <Size X="127.0000" Y="127.0000" />
                <Children>
                  <AbstractNodeData Name="booster2" ActionTag="2006299823" Tag="192" IconVisible="False" LeftMargin="-41.0815" RightMargin="-33.9185" TopMargin="-21.2761" BottomMargin="-43.7239" LeftEage="34" RightEage="34" TopEage="32" BottomEage="32" Scale9OriginX="34" Scale9OriginY="32" Scale9Width="134" Scale9Height="128" ctype="ImageViewObjectData">
                    <Size X="202.0000" Y="192.0000" />
                    <AnchorPoint ScaleX="0.5254" ScaleY="0.5931" />
                    <Position X="65.0543" Y="70.1493" />
                    <Scale ScaleX="0.4000" ScaleY="0.4000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5122" Y="0.5524" />
                    <PreSize X="1.5906" Y="1.5118" />
                    <FileData Type="Normal" Path="image/playui/bomb.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="txt_itemBc" ActionTag="-1911832595" Tag="59" IconVisible="False" LeftMargin="49.0000" RightMargin="16.0000" TopMargin="76.5000" BottomMargin="13.5000" FontSize="30" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Bottom" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="62.0000" Y="37.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="80.0000" Y="32.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6299" Y="0.2520" />
                    <PreSize X="0.4882" Y="0.2913" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="115" G="153" B="23" />
                    <ShadowColor A="255" R="26" G="19" B="19" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="img_itemB" ActionTag="-288866811" VisibleForFrame="False" Tag="62" IconVisible="False" LeftMargin="54.5000" RightMargin="11.5000" TopMargin="67.5000" BottomMargin="4.5000" LeftEage="20" RightEage="20" TopEage="18" BottomEage="18" Scale9OriginX="20" Scale9OriginY="18" Scale9Width="21" Scale9Height="19" ctype="ImageViewObjectData">
                    <Size X="61.0000" Y="55.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="85.0000" Y="32.0000" />
                    <Scale ScaleX="0.7000" ScaleY="0.7000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6693" Y="0.2520" />
                    <PreSize X="0.4803" Y="0.4331" />
                    <FileData Type="Normal" Path="image/button/check.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-93.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <NormalBackFileData Type="Normal" Path="image/button/button.png" Plist="" />
                <PressedBackFileData Type="Normal" Path="image/button/btnblue.png" Plist="" />
                <DisableBackFileData Type="Normal" Path="image/booster/boosterslot.png" Plist="" />
                <NodeNormalFileData Type="Normal" Path="image/button/btnblue.png" Plist="" />
                <NodeDisableFileData Type="Normal" Path="image/button/button.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="boosterslot3" ActionTag="238660094" Tag="191" IconVisible="False" LeftMargin="86.5004" RightMargin="-213.5004" TopMargin="29.5000" BottomMargin="-156.5000" TouchEnable="True" ctype="CheckBoxObjectData">
                <Size X="127.0000" Y="127.0000" />
                <Children>
                  <AbstractNodeData Name="booster3" ActionTag="-1037319606" Tag="193" IconVisible="False" LeftMargin="-34.5000" RightMargin="-33.5000" TopMargin="-34.5000" BottomMargin="-35.5000" LeftEage="64" RightEage="64" TopEage="65" BottomEage="65" Scale9OriginX="64" Scale9OriginY="65" Scale9Width="67" Scale9Height="67" ctype="ImageViewObjectData">
                    <Size X="195.0000" Y="197.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="63.0000" Y="63.0000" />
                    <Scale ScaleX="0.4000" ScaleY="0.4000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4961" Y="0.4961" />
                    <PreSize X="1.5354" Y="1.5512" />
                    <FileData Type="Normal" Path="image/playui/discoball.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="txt_itemEc" ActionTag="429467044" Tag="60" IconVisible="False" LeftMargin="49.0000" RightMargin="16.0000" TopMargin="76.5000" BottomMargin="13.5000" FontSize="30" LabelText="999" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Bottom" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="62.0000" Y="37.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="80.0000" Y="32.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6299" Y="0.2520" />
                    <PreSize X="0.4882" Y="0.2913" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="115" G="153" B="23" />
                    <ShadowColor A="255" R="26" G="19" B="19" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="img_itemE" ActionTag="-1753925771" VisibleForFrame="False" Tag="63" IconVisible="False" LeftMargin="54.5000" RightMargin="11.5000" TopMargin="67.5000" BottomMargin="4.5000" LeftEage="20" RightEage="20" TopEage="18" BottomEage="18" Scale9OriginX="20" Scale9OriginY="18" Scale9Width="21" Scale9Height="19" ctype="ImageViewObjectData">
                    <Size X="61.0000" Y="55.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="85.0000" Y="32.0000" />
                    <Scale ScaleX="0.7000" ScaleY="0.7000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6693" Y="0.2520" />
                    <PreSize X="0.4803" Y="0.4331" />
                    <FileData Type="Normal" Path="image/button/check.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="150.0004" Y="-93.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <NormalBackFileData Type="Normal" Path="image/button/button.png" Plist="" />
                <PressedBackFileData Type="Normal" Path="image/button/btnblue.png" Plist="" />
                <DisableBackFileData Type="Normal" Path="image/booster/boosterslot.png" Plist="" />
                <NodeNormalFileData Type="Normal" Path="image/button/btnblue.png" Plist="" />
                <NodeDisableFileData Type="Normal" Path="image/button/button.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2" ActionTag="68987114" Tag="16" IconVisible="False" LeftMargin="-142.4996" RightMargin="-142.5004" TopMargin="-27.9974" BottomMargin="-14.0026" FontSize="36" LabelText="Select Boosters:" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="285.0000" Y="42.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="0.0004" Y="6.9974" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="79" G="30" B="14" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-218.0000" RightMargin="-22.0000" TopMargin="-414.0000" BottomMargin="310.0000" FontSize="90" LabelText="Level" OutlineSize="2" ShadowOffsetX="10.0000" ShadowOffsetY="-10.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="240.0000" Y="104.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-98.0000" Y="362.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="247" G="237" B="185" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="131" G="25" B="28" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
              <AbstractNodeData Name="txt_lvl" ActionTag="516210619" Tag="55" IconVisible="False" LeftMargin="55.5000" RightMargin="-232.5000" TopMargin="-414.0000" BottomMargin="310.0000" FontSize="90" LabelText="600" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Bottom" ShadowOffsetX="10.0000" ShadowOffsetY="-10.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="177.0000" Y="104.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="144.0000" Y="362.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="247" G="237" B="185" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
              <AbstractNodeData Name="starl_slot" ActionTag="814767836" Tag="24" RotationSkewX="-8.0000" RotationSkewY="-8.0000" IconVisible="False" LeftMargin="-234.9994" RightMargin="82.9994" TopMargin="-233.9965" BottomMargin="93.9965" ctype="SpriteObjectData">
                <Size X="152.0000" Y="140.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-158.9994" Y="163.9965" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/starslot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="starc_slot" ActionTag="378484899" Tag="23" IconVisible="False" LeftMargin="-76.0004" RightMargin="-75.9996" TopMargin="-250.9983" BottomMargin="110.9983" ctype="SpriteObjectData">
                <Size X="152.0000" Y="140.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0004" Y="180.9983" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/starslot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="starr_slot" ActionTag="1260076787" Tag="25" RotationSkewX="8.0000" RotationSkewY="8.0000" IconVisible="False" LeftMargin="83.0001" RightMargin="-235.0001" TopMargin="-233.9965" BottomMargin="93.9965" ctype="SpriteObjectData">
                <Size X="152.0000" Y="140.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="159.0001" Y="163.9965" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/starslot.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="starl" ActionTag="1967243779" VisibleForFrame="False" Tag="27" IconVisible="False" LeftMargin="-229.5001" RightMargin="90.5001" TopMargin="-222.9973" BottomMargin="98.9973" ctype="SpriteObjectData">
                <Size X="139.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-160.0001" Y="160.9973" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/starl.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="starc" ActionTag="927356282" VisibleForFrame="False" Tag="28" IconVisible="False" LeftMargin="-65.0002" RightMargin="-64.9998" TopMargin="-241.4979" BottomMargin="120.4979" ctype="SpriteObjectData">
                <Size X="130.0000" Y="121.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="180.9979" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/starc.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="starr" ActionTag="1908962505" VisibleForFrame="False" Tag="29" IconVisible="False" LeftMargin="95.5001" RightMargin="-224.5001" TopMargin="-222.9973" BottomMargin="98.9973" ctype="SpriteObjectData">
                <Size X="129.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="160.0001" Y="160.9973" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/starr.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="359.9998" Y="640.0000" />
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