<GameFile>
  <PropertyGroup Name="dlgAddItem" Type="Scene" ID="b689e1d2-ad60-43b3-97b1-54dfa9533a9b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="50" Speed="0.5000" ActivedAnimationName="FlyIn">
        <Timeline ActionTag="2088982553" Property="Alpha">
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
        <Timeline ActionTag="2088982553" Property="FrameEvent">
          <EventFrame FrameIndex="50" Tween="False" Value="evt_finished" />
        </Timeline>
        <Timeline ActionTag="2006229446" Property="Position">
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
        <Timeline ActionTag="2006229446" Property="Scale">
          <ScaleFrame FrameIndex="15" X="0.9000" Y="0.9000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="2006229446" Property="RotationSkew">
          <ScaleFrame FrameIndex="15" X="0.0000" Y="0.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="FlyIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="216" G="191" B="216" />
        </AnimationInfo>
        <AnimationInfo Name="FlyOut" StartIndex="30" EndIndex="55">
          <RenderColor A="255" R="199" G="21" B="133" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="100" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="background" ActionTag="2088982553" Alpha="0" Tag="410" IconVisible="False" TouchEnable="True" Scale9Enable="True" LeftEage="1" RightEage="1" TopEage="1" BottomEage="1" Scale9OriginX="1" Scale9OriginY="1" Scale9Width="44" Scale9Height="44" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Default" Path="Default/ImageFile.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="2006229446" Tag="395" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="-720.0000" BottomMargin="2000.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Image_1" ActionTag="-801809875" Tag="396" IconVisible="False" LeftMargin="-335.0017" RightMargin="-334.9983" TopMargin="-447.9952" BottomMargin="351.9952" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0017" Y="399.9952" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_2" ActionTag="-77988380" Tag="397" IconVisible="False" LeftMargin="-335.0009" RightMargin="-334.9991" TopMargin="-351.9961" BottomMargin="-94.0039" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="446.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="-0.0009" Y="-94.0039" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_3" ActionTag="-1282714198" Tag="398" IconVisible="False" LeftMargin="-335.0009" RightMargin="-334.9991" TopMargin="93.9997" BottomMargin="-331.9997" Scale9Enable="True" LeftEage="78" RightEage="78" Scale9OriginX="78" Scale9Width="5" Scale9Height="238" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="238.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="-212.9997" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframebottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_4" ActionTag="-708150431" Tag="399" IconVisible="False" LeftMargin="-285.0002" RightMargin="-284.9998" TopMargin="313.0002" BottomMargin="-437.0002" Scale9Enable="True" LeftEage="150" RightEage="150" Scale9OriginX="150" Scale9Width="9" Scale9Height="124" ctype="ImageViewObjectData">
                <Size X="570.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-375.0002" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgextend.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_5" ActionTag="-986007686" Tag="400" IconVisible="False" LeftMargin="-257.0002" RightMargin="-256.9998" TopMargin="228.5016" BottomMargin="-407.5016" Scale9Enable="True" LeftEage="110" RightEage="110" Scale9OriginX="110" Scale9Width="5" Scale9Height="179" ctype="ImageViewObjectData">
                <Size X="514.0000" Y="179.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-318.0016" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/btnslot.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_6" ActionTag="324397836" Tag="401" IconVisible="False" LeftMargin="-304.0009" RightMargin="-303.9991" TopMargin="-296.4984" BottomMargin="247.4984" Scale9Enable="True" LeftEage="304" RightEage="304" Scale9OriginX="304" Scale9Width="1" Scale9Height="49" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="49.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="271.9984" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrtop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_7" ActionTag="-1868905001" Tag="402" IconVisible="False" LeftMargin="-304.0002" RightMargin="-303.9998" TopMargin="-247.9974" BottomMargin="-85.0026" Scale9Enable="True" LeftEage="50" RightEage="50" Scale9OriginX="50" Scale9Width="508" Scale9Height="2" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="333.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="-0.0002" Y="247.9974" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrmiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_8" ActionTag="1826170952" Tag="403" IconVisible="False" LeftMargin="-304.0002" RightMargin="-303.9998" TopMargin="85.0015" BottomMargin="-211.0015" Scale9Enable="True" LeftEage="45" RightEage="45" Scale9OriginX="45" Scale9Width="4" Scale9Height="126" ctype="ImageViewObjectData">
                <Size X="608.0000" Y="126.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0002" Y="-148.0015" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrbottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_buy" ActionTag="-568361504" Tag="404" IconVisible="False" LeftMargin="-244.0009" RightMargin="-243.9991" TopMargin="240.0026" BottomMargin="-390.0026" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="244" RightEage="244" Scale9OriginX="244" Scale9Width="1" Scale9Height="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="488.0000" Y="150.0000" />
                <Children>
                  <AbstractNodeData Name="btnhighlight2_1" ActionTag="-1129841799" Tag="405" IconVisible="False" LeftMargin="27.4216" RightMargin="397.5784" TopMargin="23.5831" BottomMargin="106.4169" ctype="SpriteObjectData">
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
                  <AbstractNodeData Name="button_text" ActionTag="471146061" Tag="406" IconVisible="False" LeftMargin="93.0000" RightMargin="231.0000" TopMargin="20.5000" BottomMargin="30.5000" FontSize="80" LabelText="Buy" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="164.0000" Y="99.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="175.0000" Y="80.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.3586" Y="0.5333" />
                    <PreSize X="0.3361" Y="0.6600" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="91" G="127" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="coin" ActionTag="-1588191408" Tag="569" IconVisible="False" LeftMargin="264.0000" RightMargin="142.0000" TopMargin="32.0001" BottomMargin="35.9999" ctype="SpriteObjectData">
                    <Size X="82.0000" Y="82.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="305.0000" Y="76.9999" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6250" Y="0.5133" />
                    <PreSize X="0.1680" Y="0.5467" />
                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text" ActionTag="-333173586" Tag="568" IconVisible="False" LeftMargin="329.0000" RightMargin="77.0000" TopMargin="47.0001" BottomMargin="52.9999" FontSize="40" LabelText="400" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="82.0000" Y="50.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="370.0000" Y="77.9999" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.7582" Y="0.5200" />
                    <PreSize X="0.1680" Y="0.3333" />
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
              <AbstractNodeData Name="btn_close" ActionTag="-947671125" Tag="321" IconVisible="False" LeftMargin="263.9998" RightMargin="-361.9998" TopMargin="-471.9957" BottomMargin="373.9957" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
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
              <AbstractNodeData Name="lightbeam" ActionTag="297827563" Tag="291" IconVisible="False" LeftMargin="-291.0000" RightMargin="-291.0000" TopMargin="-284.0000" BottomMargin="-200.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                <Size X="582.0000" Y="484.0000" />
                <Children>
                  <AbstractNodeData Name="center" ActionTag="62076246" Tag="292" IconVisible="True" LeftMargin="280.0000" RightMargin="302.0000" TopMargin="189.0000" BottomMargin="295.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                    <Size X="0.0000" Y="0.0000" />
                    <AnchorPoint />
                    <Position X="280.0000" Y="295.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4811" Y="0.6095" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="fxShine.csd" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="42.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="150" G="200" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="HammerNode" ActionTag="753002902" VisibleForFrame="False" Tag="592" IconVisible="True" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="title" ActionTag="-1383452616" Tag="593" IconVisible="False" LeftMargin="-151.9996" RightMargin="-152.0004" TopMargin="-404.5000" BottomMargin="319.5000" FontSize="70" LabelText="Hammer" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="304.0000" Y="85.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0004" Y="362.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="237" G="232" B="205" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="105" G="30" B="35" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="hammerlarge" ActionTag="777433758" Tag="819" IconVisible="False" LeftMargin="-93.0000" RightMargin="-93.0000" TopMargin="-197.5000" BottomMargin="2.5000" ctype="SpriteObjectData">
                    <Size X="186.0000" Y="195.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position Y="100.0000" />
                    <Scale ScaleX="1.2500" ScaleY="1.2500" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="image/playui/hammerlarge.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text" ActionTag="-95675401" Tag="594" IconVisible="False" LeftMargin="-241.9998" RightMargin="-242.0002" TopMargin="81.0000" BottomMargin="-185.0000" FontSize="45" LabelText="Removes any cube or&#xA;obstacle!" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="484.0000" Y="104.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0002" Y="-133.0000" />
                    <Scale ScaleX="0.9427" ScaleY="1.0000" />
                    <CColor A="255" R="79" G="30" B="14" />
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
              <AbstractNodeData Name="BoxingGloveNode" ActionTag="1777863813" VisibleForFrame="False" Tag="589" IconVisible="True" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="title" ActionTag="-2012003831" Tag="590" IconVisible="False" LeftMargin="-240.4996" RightMargin="-240.5004" TopMargin="-404.5000" BottomMargin="319.5000" FontSize="70" LabelText="Boxing Glove" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="481.0000" Y="85.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0004" Y="362.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="237" G="232" B="205" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="105" G="30" B="35" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="boxclub" ActionTag="-1614838170" Tag="824" IconVisible="False" LeftMargin="-75.5000" RightMargin="-75.5000" TopMargin="-167.5000" BottomMargin="32.5000" ctype="SpriteObjectData">
                    <Size X="151.0000" Y="135.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position Y="100.0000" />
                    <Scale ScaleX="1.8000" ScaleY="1.8000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="image/playui/boxclub.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text" ActionTag="1720799347" Tag="591" IconVisible="False" LeftMargin="-257.9998" RightMargin="-258.0002" TopMargin="81.0000" BottomMargin="-185.0000" FontSize="45" LabelText="Remove everthing in a&#xA;column!" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="516.0000" Y="104.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0002" Y="-133.0000" />
                    <Scale ScaleX="0.9427" ScaleY="1.0000" />
                    <CColor A="255" R="79" G="30" B="14" />
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
              <AbstractNodeData Name="AnvilNode" ActionTag="-1852120992" VisibleForFrame="False" Tag="588" IconVisible="True" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="title" ActionTag="1082545059" Tag="409" IconVisible="False" LeftMargin="-95.9996" RightMargin="-96.0004" TopMargin="-404.5000" BottomMargin="319.5000" FontSize="70" LabelText="Anvil" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="192.0000" Y="85.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0004" Y="362.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="237" G="232" B="205" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="105" G="30" B="35" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="anvil" ActionTag="-170489360" Tag="825" IconVisible="False" LeftMargin="-99.5000" RightMargin="-99.5000" TopMargin="-197.0000" BottomMargin="3.0000" ctype="SpriteObjectData">
                    <Size X="199.0000" Y="194.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position Y="100.0000" />
                    <Scale ScaleX="1.3800" ScaleY="1.3800" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="image/playui/anvil.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text" ActionTag="1508813593" Tag="408" IconVisible="False" LeftMargin="-268.9998" RightMargin="-269.0002" TopMargin="81.0000" BottomMargin="-185.0000" FontSize="45" LabelText="Removes everthing in a&#xA;column!" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="538.0000" Y="104.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0002" Y="-133.0000" />
                    <Scale ScaleX="0.9427" ScaleY="1.0000" />
                    <CColor A="255" R="79" G="30" B="14" />
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
              <AbstractNodeData Name="DiceNode" ActionTag="2014124082" VisibleForFrame="False" Tag="595" IconVisible="True" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="title" ActionTag="195436335" Tag="596" IconVisible="False" LeftMargin="-77.9996" RightMargin="-78.0004" TopMargin="-404.5000" BottomMargin="319.5000" FontSize="70" LabelText="Dice" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="156.0000" Y="85.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0004" Y="362.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="237" G="232" B="205" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="105" G="30" B="35" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="dice" ActionTag="340714693" Tag="95" IconVisible="False" LeftMargin="-49.0000" RightMargin="-49.0000" TopMargin="-145.0000" BottomMargin="55.0000" ctype="SpriteObjectData">
                    <Size X="98.0000" Y="90.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position Y="100.0000" />
                    <Scale ScaleX="2.5000" ScaleY="2.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="image/playui/dice.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text" ActionTag="1924283440" Tag="597" IconVisible="False" LeftMargin="-198.9998" RightMargin="-199.0002" TopMargin="81.0000" BottomMargin="-185.0000" FontSize="45" LabelText="Shuffles all of the&#xA;cubes!" HorizontalAlignmentType="HT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="398.0000" Y="104.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="0.0002" Y="-133.0000" />
                    <Scale ScaleX="0.9427" ScaleY="1.0000" />
                    <CColor A="255" R="79" G="30" B="14" />
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
              <AbstractNodeData Name="count" ActionTag="219112455" Tag="820" IconVisible="False" LeftMargin="88.0000" RightMargin="-174.0000" TopMargin="-50.0000" BottomMargin="-30.0000" FontSize="66" LabelText="x3" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="86.0000" Y="80.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="131.0000" Y="10.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="237" G="232" B="205" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="105" G="30" B="35" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="360.0000" Y="2000.0000" />
            <Scale ScaleX="0.9000" ScaleY="0.9000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.5625" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>