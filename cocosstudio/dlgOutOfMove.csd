<GameFile>
  <PropertyGroup Name="dlgOutOfMove" Type="Scene" ID="2bbdcdff-98e8-4f4f-9329-1d14e64bf35b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="0.5000">
        <Timeline ActionTag="-1890653939" Property="Alpha">
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
          <PointFrame FrameIndex="0" X="-500.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="360.0000" Y="640.0000">
            <EasingData Type="26" />
          </PointFrame>
          <PointFrame FrameIndex="25" X="360.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="1220.0000" Y="640.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="evtIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="255" G="20" B="147" />
        </AnimationInfo>
        <AnimationInfo Name="evtOut" StartIndex="25" EndIndex="40">
          <RenderColor A="255" R="154" G="205" B="50" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="312" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="Image_10" ActionTag="-653491014" VisibleForFrame="False" Tag="181" IconVisible="False" LeftEage="337" RightEage="337" TopEage="601" BottomEage="601" Scale9OriginX="337" Scale9OriginY="601" Scale9Width="350" Scale9Height="620" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/mapui/mapuibg.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="blackbg" ActionTag="-1890653939" Alpha="0" Tag="179" IconVisible="False" TouchEnable="True" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="-500.0000" RightMargin="1220.0000" TopMargin="640.0000" BottomMargin="640.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Image_1" ActionTag="707715776" Tag="314" IconVisible="False" LeftMargin="-535.0017" RightMargin="-534.9983" TopMargin="-359.0000" BottomMargin="263.0000" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="1070.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0017" Y="311.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_2" ActionTag="-1008518909" Tag="315" IconVisible="False" LeftMargin="-535.0009" RightMargin="-534.9991" TopMargin="-262.9961" BottomMargin="-94.0039" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="1070.0000" Y="357.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="-0.0009" Y="-94.0039" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_3" ActionTag="-1614951940" Tag="317" IconVisible="False" LeftMargin="-535.0009" RightMargin="-534.9991" TopMargin="93.9997" BottomMargin="-331.9997" Scale9Enable="True" LeftEage="78" RightEage="78" Scale9OriginX="78" Scale9Width="5" Scale9Height="238" ctype="ImageViewObjectData">
                <Size X="1070.0000" Y="238.0000" />
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
              <AbstractNodeData Name="Image_7" ActionTag="940055712" Tag="12" IconVisible="False" LeftMargin="-499.9997" RightMargin="-500.0003" TopMargin="-173.0009" BottomMargin="-84.9991" Scale9Enable="True" LeftEage="50" RightEage="50" Scale9OriginX="50" Scale9Width="508" Scale9Height="2" ctype="ImageViewObjectData">
                <Size X="1000.0000" Y="258.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="0.0003" Y="173.0009" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrmiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_6" ActionTag="76587605" Tag="324" IconVisible="False" LeftMargin="-500.0009" RightMargin="-499.9991" TopMargin="-227.0000" BottomMargin="173.0000" Scale9Enable="True" LeftEage="31" RightEage="31" Scale9OriginX="31" Scale9Width="34" Scale9Height="54" ctype="ImageViewObjectData">
                <Size X="1000.0000" Y="54.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-0.0009" Y="200.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrtop2.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_8" ActionTag="892197917" Tag="13" IconVisible="False" LeftMargin="-500.0000" RightMargin="-500.0000" TopMargin="85.0000" BottomMargin="-211.0000" Scale9Enable="True" LeftEage="45" RightEage="45" Scale9OriginX="45" Scale9Width="4" Scale9Height="126" ctype="ImageViewObjectData">
                <Size X="1000.0000" Y="126.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-148.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgpanelrbottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="lightbeam" ActionTag="1972008016" Tag="102" IconVisible="False" LeftMargin="-475.0000" RightMargin="-475.0000" TopMargin="-201.0000" BottomMargin="-187.0000" TouchEnable="True" ClipAble="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                <Size X="950.0000" Y="388.0000" />
                <Children>
                  <AbstractNodeData Name="center" ActionTag="-547092180" Tag="141" IconVisible="True" LeftMargin="475.0000" RightMargin="475.0000" TopMargin="163.0000" BottomMargin="225.0000" StretchWidthEnable="False" StretchHeightEnable="False" InnerActionSpeed="0.5000" CustomSizeEnabled="False" ctype="ProjectNodeObjectData">
                    <Size X="0.0000" Y="0.0000" />
                    <AnchorPoint />
                    <Position X="475.0000" Y="225.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5799" />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="fxShine.csd" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="7.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <SingleColor A="255" R="150" G="200" B="255" />
                <FirstColor A="255" R="150" G="200" B="255" />
                <EndColor A="255" R="255" G="255" B="255" />
                <ColorVector ScaleY="1.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnPlayOn" ActionTag="-553722109" Tag="320" IconVisible="False" LeftMargin="-244.0009" RightMargin="-243.9991" TopMargin="240.0026" BottomMargin="-390.0026" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="244" RightEage="244" Scale9OriginX="244" Scale9Width="1" Scale9Height="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
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
                  <AbstractNodeData Name="Text_3" ActionTag="-747169178" Tag="26" IconVisible="False" LeftMargin="52.5047" RightMargin="196.4953" TopMargin="32.5000" BottomMargin="42.5000" FontSize="60" LabelText="Play On" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="239.0000" Y="75.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="172.0047" Y="80.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.3525" Y="0.5333" />
                    <PreSize X="0.4898" Y="0.5000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="91" G="127" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="coin_18" ActionTag="888081114" Tag="121" IconVisible="False" LeftMargin="295.0009" RightMargin="110.9991" TopMargin="32.0001" BottomMargin="35.9999" ctype="SpriteObjectData">
                    <Size X="82.0000" Y="82.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.0009" Y="76.9999" />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6885" Y="0.5133" />
                    <PreSize X="0.1680" Y="0.5467" />
                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="Text_3_0" ActionTag="2017768725" Tag="122" IconVisible="False" LeftMargin="362.6179" RightMargin="52.3821" TopMargin="49.0001" BottomMargin="54.9999" FontSize="36" LabelText="100" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="73.0000" Y="46.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="399.1179" Y="77.9999" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.8179" Y="0.5200" />
                    <PreSize X="0.1496" Y="0.3067" />
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
              <AbstractNodeData Name="btnClose" ActionTag="-1581048205" Tag="321" IconVisible="False" LeftMargin="263.9998" RightMargin="-361.9998" TopMargin="-333.9996" BottomMargin="235.9996" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="98.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="312.9998" Y="284.9996" />
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
              <AbstractNodeData Name="outofmovering_1" ActionTag="1064624007" Tag="41" IconVisible="False" LeftMargin="-175.0000" RightMargin="-175.0000" TopMargin="-213.5000" BottomMargin="-133.5000" ctype="SpriteObjectData">
                <Size X="350.0000" Y="347.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="40.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/common/outofmovering.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2" ActionTag="68987114" Tag="16" IconVisible="False" LeftMargin="-266.0000" RightMargin="174.0000" TopMargin="125.5000" BottomMargin="-174.5000" FontSize="42" LabelText="Add" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="92.0000" Y="49.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-220.0000" Y="-150.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="79" G="30" B="14" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2_0" ActionTag="-1763126658" Tag="98" IconVisible="False" LeftMargin="-164.0000" RightMargin="136.0000" TopMargin="125.5000" BottomMargin="-174.5000" FontSize="42" LabelText="5" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="28.0000" Y="49.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-150.0000" Y="-150.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="178" G="57" B="68" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2_1" ActionTag="1321238820" Tag="99" IconVisible="False" LeftMargin="-128.5000" RightMargin="-266.5000" TopMargin="125.5000" BottomMargin="-174.5000" FontSize="42" LabelText="moves to continue" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="395.0000" Y="49.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="69.0000" Y="-150.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="79" G="30" B="14" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-233.9995" RightMargin="-234.0005" TopMargin="-324.9986" BottomMargin="246.9986" FontSize="64" LabelText="Out Of Moves!" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="468.0000" Y="78.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="0.0005" Y="285.9986" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="247" G="237" B="185" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="131" G="25" B="28" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
              <AbstractNodeData Name="Text_2_1_0" ActionTag="-1978874941" Tag="100" RotationSkewX="-7.0000" RotationSkewY="-7.0000" IconVisible="False" LeftMargin="-64.9998" RightMargin="-65.0002" TopMargin="-96.0000" BottomMargin="-26.0000" FontSize="100" LabelText="+5" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-5.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="130.0000" Y="122.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="0.0002" Y="35.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="228" B="171" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="141" G="1" B="28" />
                <ShadowColor A="255" R="141" G="1" B="28" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-500.0000" Y="640.0000" />
            <Scale ScaleX="0.9000" ScaleY="0.9000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.6944" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>