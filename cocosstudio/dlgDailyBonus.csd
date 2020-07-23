<GameFile>
  <PropertyGroup Name="dlgDailyBonus" Type="Scene" ID="cdc3bc94-d815-4de9-96db-933877a272c6" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="0.5000">
        <Timeline ActionTag="1871556539" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-1065975250" Property="Alpha">
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
          <PointFrame FrameIndex="40" X="360.0000" Y="-600.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1191915271" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="27" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="25" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="evtIn" StartIndex="0" EndIndex="15">
          <RenderColor A="255" R="255" G="228" B="181" />
        </AnimationInfo>
        <AnimationInfo Name="evtOut" StartIndex="25" EndIndex="40">
          <RenderColor A="255" R="255" G="245" B="238" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="312" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="Image_10" CanEdit="False" ActionTag="1871556539" VisibleForFrame="False" Tag="410" IconVisible="False" LeftEage="337" RightEage="337" TopEage="601" BottomEage="601" Scale9OriginX="337" Scale9OriginY="601" Scale9Width="350" Scale9Height="620" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/mapui/mapuibg.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="blackbg" ActionTag="-1065975250" Alpha="142" Tag="409" IconVisible="False" TouchEnable="True" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="703.1729" BottomMargin="576.8271" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="imgTop" ActionTag="648578726" Tag="67" IconVisible="False" LeftMargin="-332.0000" RightMargin="-338.0000" TopMargin="-553.0000" BottomMargin="457.0000" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="3.0000" Y="505.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgMiddle" ActionTag="-1928407235" Tag="66" IconVisible="False" LeftMargin="-331.9998" RightMargin="-338.0002" TopMargin="-475.9500" BottomMargin="-469.9500" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="945.9000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="3.0002" Y="3.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgBottom" ActionTag="-514651647" Tag="65" IconVisible="False" LeftMargin="-331.9995" RightMargin="-338.0005" TopMargin="426.5000" BottomMargin="-513.5000" Scale9Enable="True" LeftEage="78" RightEage="78" BottomEage="50" Scale9OriginX="78" Scale9Width="5" Scale9Height="188" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="87.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="3.0005" Y="-470.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframebottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="ImageRgn" ActionTag="1556650899" Tag="1184" IconVisible="False" LeftMargin="-281.9992" RightMargin="-288.0008" TopMargin="494.0000" BottomMargin="-618.0000" Scale9Enable="True" LeftEage="150" RightEage="150" Scale9OriginX="150" Scale9Width="9" Scale9Height="124" ctype="ImageViewObjectData">
                <Size X="570.0000" Y="124.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="3.0008" Y="-556.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgextend.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="ImageButton" ActionTag="477173709" Tag="162" IconVisible="False" LeftMargin="-256.9995" RightMargin="-257.0005" TopMargin="410.5000" BottomMargin="-589.5000" Scale9Enable="True" LeftEage="110" RightEage="110" Scale9OriginX="110" Scale9Width="5" Scale9Height="179" ctype="ImageViewObjectData">
                <Size X="514.0000" Y="179.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="0.0005" Y="-500.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/button/btnslot.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnCollect" ActionTag="-1179781518" ZOrder="2" Tag="297" IconVisible="False" LeftMargin="-244.0000" RightMargin="-244.0000" TopMargin="423.0002" BottomMargin="-573.0002" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="244" RightEage="244" Scale9OriginX="244" Scale9Width="1" Scale9Height="150" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="488.0000" Y="150.0000" />
                <Children>
                  <AbstractNodeData Name="btnhighlight2_1" ActionTag="-1946747796" Tag="298" IconVisible="False" LeftMargin="27.4216" RightMargin="397.5784" TopMargin="23.5831" BottomMargin="106.4169" ctype="SpriteObjectData">
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
                  <AbstractNodeData Name="text_collect" ActionTag="58168569" Tag="299" IconVisible="False" LeftMargin="101.5000" RightMargin="103.5000" TopMargin="20.5000" BottomMargin="30.5000" FontSize="80" LabelText="Collect" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="283.0000" Y="99.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="243.0000" Y="80.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="249" G="240" B="195" />
                    <PrePosition X="0.4980" Y="0.5333" />
                    <PreSize X="0.5799" Y="0.6600" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="91" G="127" B="11" />
                    <ShadowColor A="255" R="58" G="82" B="8" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-498.0002" />
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
              <AbstractNodeData Name="content" ActionTag="-1365753652" Tag="300" IconVisible="True" LeftMargin="0.0001" RightMargin="-0.0001" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="title" ActionTag="783973300" Tag="151" IconVisible="False" LeftMargin="-297.0000" RightMargin="-303.0000" TopMargin="-492.0001" BottomMargin="408.0001" IsCustomSize="True" FontSize="70" LabelText="Daily Bonus" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="600.0000" Y="84.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="3.0000" Y="450.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="247" G="237" B="185" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="131" G="25" B="28" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="title_reward" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-135.0035" RightMargin="-314.9965" TopMargin="-354.9997" BottomMargin="304.9997" IsCustomSize="True" FontSize="30" LabelText="Collect your next reward in" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="450.0000" Y="50.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="89.9965" Y="329.9997" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="247" G="237" B="185" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="131" G="25" B="28" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="text_next_reward" ActionTag="434209487" Tag="205" IconVisible="False" LeftMargin="-0.0024" RightMargin="-299.9976" TopMargin="-289.9999" BottomMargin="209.9999" IsCustomSize="True" FontSize="50" LabelText="00:00:00&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="300.0000" Y="80.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="149.9976" Y="249.9999" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="247" G="237" B="185" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="131" G="25" B="28" />
                    <ShadowColor A="255" R="105" G="30" B="35" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="list_daily" ActionTag="-1175343569" Tag="153" IconVisible="False" LeftMargin="-310.0000" RightMargin="-315.0000" TopMargin="-210.0000" BottomMargin="-390.0000" ClipAble="False" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ScrollDirectionType="0" DirectionType="Vertical" ctype="ListViewObjectData">
                    <Size X="625.0000" Y="600.0000" />
                    <Children>
                      <AbstractNodeData Name="list1" ActionTag="-849727806" Tag="154" IconVisible="False" BottomMargin="450.0000" ClipAble="False" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ScrollDirectionType="0" ctype="ListViewObjectData">
                        <Size X="625.0000" Y="150.0000" />
                        <Children>
                          <AbstractNodeData Name="check_day1" ActionTag="-704645444" Tag="197" IconVisible="False" RightMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item1" ActionTag="2026239577" Tag="103" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item10" ActionTag="-416023848" ZOrder="1" Tag="198" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item11" ActionTag="-1044430983" ZOrder="1" Tag="199" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 15" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day1" ActionTag="247846052" ZOrder="1" Tag="201" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="62.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.1000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day2" ActionTag="324916133" ZOrder="1" Tag="202" IconVisible="False" LeftMargin="125.0000" RightMargin="375.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item2" ActionTag="-1111838339" ZOrder="2" Tag="110" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item20" ActionTag="-1471621944" ZOrder="1" Tag="1253" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item21" ActionTag="1677986951" ZOrder="1" Tag="1254" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 20" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day2" ActionTag="1156214954" ZOrder="2" Tag="91" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 2" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="187.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.3000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day3" ActionTag="776058645" ZOrder="2" Tag="203" IconVisible="False" LeftMargin="250.0000" RightMargin="250.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item3" ActionTag="-1964395085" ZOrder="3" Tag="114" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item30" ActionTag="-1856440729" ZOrder="3" Tag="1256" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 25" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item31" ActionTag="1314038399" ZOrder="3" Tag="1255" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day3" ActionTag="679440048" ZOrder="1" Tag="94" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 3" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="312.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day4" ActionTag="707825733" ZOrder="3" Tag="207" IconVisible="False" LeftMargin="375.0000" RightMargin="125.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item4" ActionTag="982304269" ZOrder="4" Tag="117" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item40" ActionTag="1105043199" ZOrder="3" Tag="1257" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 30" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item41" ActionTag="-342681794" ZOrder="3" Tag="1258" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day4" ActionTag="892284129" ZOrder="1" Tag="97" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 4&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="437.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day5" ActionTag="473915689" ZOrder="4" Tag="211" IconVisible="False" LeftMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item5" ActionTag="-1295835378" ZOrder="5" Tag="120" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item50" ActionTag="546903602" ZOrder="3" Tag="1259" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 35" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item51" ActionTag="243467001" ZOrder="3" Tag="1260" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day5" ActionTag="-1142594451" ZOrder="1" Tag="100" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 5&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="562.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.9000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position Y="450.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition Y="0.7500" />
                        <PreSize X="1.0000" Y="0.2500" />
                        <SingleColor A="255" R="150" G="150" B="255" />
                        <FirstColor A="255" R="150" G="150" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="list2" ActionTag="641556218" ZOrder="1" Tag="155" IconVisible="False" TopMargin="150.0000" BottomMargin="300.0000" ClipAble="False" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ScrollDirectionType="0" ctype="ListViewObjectData">
                        <Size X="625.0000" Y="150.0000" />
                        <Children>
                          <AbstractNodeData Name="check_day6" ActionTag="876931079" Tag="215" IconVisible="False" RightMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item6" ActionTag="-957961375" ZOrder="1" Tag="123" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item60" ActionTag="1381965532" ZOrder="1" Tag="1262" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item61" ActionTag="-1306665881" ZOrder="1" Tag="1261" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 40" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day6" ActionTag="963516770" ZOrder="1" Tag="103" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 6&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="62.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.1000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day7" ActionTag="-1420278532" ZOrder="1" Tag="219" IconVisible="False" LeftMargin="125.0000" RightMargin="375.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item7" ActionTag="1155258646" ZOrder="1" Tag="126" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item70" ActionTag="-1840879617" ZOrder="1" Tag="1263" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="27" RightEage="27" TopEage="27" BottomEage="27" Scale9OriginX="27" Scale9OriginY="27" Scale9Width="28" Scale9Height="28" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/common/coin.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item71" ActionTag="1650409478" ZOrder="1" Tag="1264" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 45" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day7" ActionTag="1843006655" ZOrder="1" Tag="106" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 7&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="187.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.3000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day8" ActionTag="-1227744065" ZOrder="2" Tag="223" IconVisible="False" LeftMargin="250.0000" RightMargin="250.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item8" ActionTag="-1679057156" ZOrder="1" Tag="129" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item80" ActionTag="-1361134813" ZOrder="1" Tag="1276" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item81" ActionTag="791710553" Tag="1275" RotationSkewX="45.0000" RotationSkewY="45.0000" IconVisible="False" LeftMargin="31.5000" RightMargin="56.5000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="14" Scale9Height="36" ctype="ImageViewObjectData">
                                    <Size X="37.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.2960" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/play/rocketvertical.png" Plist="" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day8" ActionTag="-790809212" ZOrder="1" Tag="109" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 8&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="312.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day9" ActionTag="870234901" ZOrder="3" Tag="227" IconVisible="False" LeftMargin="375.0000" RightMargin="125.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item9" ActionTag="1721895359" ZOrder="1" Tag="130" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item90" ActionTag="505650707" Tag="1267" RotationSkewX="45.0000" RotationSkewY="45.0000" IconVisible="False" LeftMargin="31.5000" RightMargin="56.5000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="14" Scale9Height="36" ctype="ImageViewObjectData">
                                    <Size X="37.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.2960" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/play/rocketvertical.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item91" ActionTag="820550929" ZOrder="1" Tag="1268" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day9" ActionTag="-13824337" ZOrder="1" Tag="112" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 9&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="437.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day10" ActionTag="407864181" ZOrder="4" Tag="231" IconVisible="False" LeftMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item10" ActionTag="1295388427" ZOrder="1" Tag="131" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item100" ActionTag="-2082167198" ZOrder="5" Tag="1269" RotationSkewX="45.0000" RotationSkewY="45.0000" IconVisible="False" LeftMargin="31.5000" RightMargin="56.5000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="14" Scale9Height="36" ctype="ImageViewObjectData">
                                    <Size X="37.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.2960" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/play/rocketvertical.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item101" ActionTag="431726155" ZOrder="5" Tag="1270" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 2" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day10" ActionTag="-470603074" ZOrder="1" Tag="115" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 10&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="562.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.9000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position Y="300.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition Y="0.5000" />
                        <PreSize X="1.0000" Y="0.2500" />
                        <SingleColor A="255" R="150" G="150" B="255" />
                        <FirstColor A="255" R="150" G="150" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="list3" ActionTag="-1394150627" ZOrder="2" Tag="156" IconVisible="False" TopMargin="300.0000" BottomMargin="150.0000" ClipAble="False" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ScrollDirectionType="0" ctype="ListViewObjectData">
                        <Size X="625.0000" Y="150.0000" />
                        <Children>
                          <AbstractNodeData Name="check_day11" ActionTag="707840720" Tag="235" IconVisible="False" RightMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item11" ActionTag="794599070" ZOrder="1" Tag="132" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item110" ActionTag="-920216008" ZOrder="5" Tag="1271" RotationSkewX="45.0000" RotationSkewY="45.0000" IconVisible="False" LeftMargin="32.0000" RightMargin="57.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="14" Scale9Height="36" ctype="ImageViewObjectData">
                                    <Size X="36.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.2880" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/play/rocketvertical.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item111" ActionTag="-846327745" ZOrder="5" Tag="1272" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 2" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day11" ActionTag="-838829009" ZOrder="1" Tag="119" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 11&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="62.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.1000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day12" ActionTag="-798379740" ZOrder="1" Tag="239" IconVisible="False" LeftMargin="125.0000" RightMargin="375.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item12" ActionTag="-2079867276" ZOrder="2" Tag="135" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item120" ActionTag="70921630" ZOrder="5" Tag="1285" RotationSkewX="45.0000" RotationSkewY="45.0000" IconVisible="False" LeftMargin="31.5000" RightMargin="56.5000" TopMargin="20.0000" BottomMargin="80.0000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="14" Scale9Height="36" ctype="ImageViewObjectData">
                                    <Size X="37.0000" Y="50.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.2960" Y="0.3333" />
                                    <FileData Type="Normal" Path="image/play/rocketvertical.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item121" ActionTag="-829429710" ZOrder="5" Tag="1286" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 3&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day12" ActionTag="-237865677" ZOrder="1" Tag="122" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 12&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="187.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.3000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day13" ActionTag="423975331" ZOrder="2" Tag="243" IconVisible="False" LeftMargin="250.0000" RightMargin="250.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item13" ActionTag="1040627792" ZOrder="3" Tag="138" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item130" ActionTag="263369489" ZOrder="3" Tag="1287" RotationSkewX="45.0000" RotationSkewY="45.0000" IconVisible="False" LeftMargin="32.0000" RightMargin="57.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="14" Scale9Height="36" ctype="ImageViewObjectData">
                                    <Size X="36.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.2880" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/play/rocketvertical.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item131" ActionTag="-315801498" ZOrder="3" Tag="1288" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 3&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day13" ActionTag="-2037863106" ZOrder="1" Tag="125" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 13&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="312.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day14" ActionTag="422871948" ZOrder="3" Tag="247" IconVisible="False" LeftMargin="375.0000" RightMargin="125.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item14" ActionTag="750367586" ZOrder="4" Tag="141" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item140" ActionTag="351548261" ZOrder="4" Tag="1289" IconVisible="False" LeftMargin="24.0000" RightMargin="49.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="44" Scale9Height="34" ctype="ImageViewObjectData">
                                    <Size X="52.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4160" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/play/bomb.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item141" ActionTag="2132024734" ZOrder="4" Tag="1290" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day14" ActionTag="1982554644" ZOrder="1" Tag="128" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 14&#xA;&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="437.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day15" ActionTag="-629644612" ZOrder="4" Tag="251" IconVisible="False" LeftMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item15" ActionTag="482236840" ZOrder="4" Tag="144" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item150" ActionTag="-761492615" ZOrder="4" Tag="1291" IconVisible="False" LeftMargin="24.0000" RightMargin="49.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="44" Scale9Height="34" ctype="ImageViewObjectData">
                                    <Size X="52.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4160" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/play/bomb.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item151" ActionTag="1025221329" ZOrder="4" Tag="1292" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 2&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day15" ActionTag="113078673" ZOrder="1" Tag="131" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 15&#xA;&#xA;&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="562.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.9000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position Y="150.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition Y="0.2500" />
                        <PreSize X="1.0000" Y="0.2500" />
                        <SingleColor A="255" R="150" G="150" B="255" />
                        <FirstColor A="255" R="150" G="150" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="list4" ActionTag="1359458754" ZOrder="3" Tag="157" IconVisible="False" TopMargin="450.0000" ClipAble="False" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ScrollDirectionType="0" ctype="ListViewObjectData">
                        <Size X="625.0000" Y="150.0000" />
                        <Children>
                          <AbstractNodeData Name="check_day16" ActionTag="1341301068" Tag="255" IconVisible="False" RightMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item16" ActionTag="-1798289716" ZOrder="1" Tag="147" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item160" ActionTag="-1042201752" ZOrder="4" Tag="1293" IconVisible="False" LeftMargin="24.0000" RightMargin="49.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="44" Scale9Height="34" ctype="ImageViewObjectData">
                                    <Size X="52.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4160" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/play/bomb.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item161" ActionTag="-606329247" ZOrder="4" Tag="1294" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 3&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day16" ActionTag="-1919689519" ZOrder="1" Tag="134" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 16&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="62.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.1000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day17" ActionTag="1131908066" ZOrder="1" Tag="259" IconVisible="False" LeftMargin="125.0000" RightMargin="375.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item17" ActionTag="-473875935" ZOrder="1" Tag="150" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item170" ActionTag="-195235741" Tag="1273" IconVisible="False" LeftMargin="27.0000" RightMargin="52.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="33" Scale9Height="34" ctype="ImageViewObjectData">
                                    <Size X="46.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.3680" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/playui/hammer.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item171" ActionTag="1762565615" ZOrder="1" Tag="1274" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day17" ActionTag="181660588" ZOrder="2" Tag="137" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 17&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="187.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.3000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day18" ActionTag="1576348853" ZOrder="2" Tag="263" IconVisible="False" LeftMargin="250.0000" RightMargin="250.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item18" ActionTag="-284917413" ZOrder="1" Tag="153" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item180" ActionTag="632596981" Tag="1277" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="22.5000" BottomMargin="82.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="91" Scale9Height="71" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="45.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3000" />
                                    <FileData Type="Normal" Path="image/playui/boxclub.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item181" ActionTag="1423161021" ZOrder="1" Tag="1278" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day18" ActionTag="1779347189" ZOrder="3" Tag="140" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 18&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="312.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day19" ActionTag="1158879328" ZOrder="3" Tag="267" IconVisible="False" LeftMargin="375.0000" RightMargin="125.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item19" ActionTag="2106712231" ZOrder="4" Tag="156" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item190" ActionTag="-701511826" ZOrder="5" Tag="1279" IconVisible="False" LeftMargin="25.0000" RightMargin="50.0000" TopMargin="20.5000" BottomMargin="80.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="139" Scale9Height="130" ctype="ImageViewObjectData">
                                    <Size X="50.0000" Y="49.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.4000" Y="0.3267" />
                                    <FileData Type="Normal" Path="image/playui/anvil.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item191" ActionTag="-191816194" ZOrder="5" Tag="1280" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day19" ActionTag="-1376954470" ZOrder="1" Tag="143" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 19&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="437.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.7000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                          <AbstractNodeData Name="check_day20" ActionTag="-2000153884" ZOrder="4" Tag="271" IconVisible="False" LeftMargin="500.0000" ctype="CheckBoxObjectData">
                            <Size X="125.0000" Y="150.0000" />
                            <Children>
                              <AbstractNodeData Name="check_item20" ActionTag="394129079" ZOrder="4" Tag="159" IconVisible="False" ClipAble="True" BackColorAlpha="0" ColorAngle="90.0000" Scale9Width="1" Scale9Height="1" ctype="PanelObjectData">
                                <Size X="125.0000" Y="150.0000" />
                                <Children>
                                  <AbstractNodeData Name="day_item200" ActionTag="2078638442" ZOrder="5" Tag="1281" IconVisible="False" LeftMargin="25.5000" RightMargin="50.5000" TopMargin="22.5000" BottomMargin="82.5000" LeftEage="30" RightEage="30" TopEage="32" BottomEage="32" Scale9OriginX="30" Scale9OriginY="32" Scale9Width="38" Scale9Height="26" ctype="ImageViewObjectData">
                                    <Size X="49.0000" Y="45.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="50.0000" Y="105.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="255" />
                                    <PrePosition X="0.4000" Y="0.7000" />
                                    <PreSize X="0.3920" Y="0.3000" />
                                    <FileData Type="Normal" Path="image/playui/dice.png" Plist="" />
                                  </AbstractNodeData>
                                  <AbstractNodeData Name="day_item201" ActionTag="1612186564" ZOrder="5" Tag="1282" IconVisible="False" LeftMargin="55.0000" RightMargin="20.0000" TopMargin="72.5000" BottomMargin="42.5000" IsCustomSize="True" FontSize="20" LabelText="+ 1" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ctype="TextObjectData">
                                    <Size X="50.0000" Y="35.0000" />
                                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                    <Position X="80.0000" Y="60.0000" />
                                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                    <CColor A="255" R="255" G="255" B="0" />
                                    <PrePosition X="0.6400" Y="0.4000" />
                                    <PreSize X="0.4000" Y="0.2333" />
                                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                    <OutlineColor A="255" R="255" G="165" B="0" />
                                    <ShadowColor A="255" R="255" G="255" B="0" />
                                  </AbstractNodeData>
                                </Children>
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.5000" Y="75.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="255" G="255" B="255" />
                                <PrePosition X="0.5000" Y="0.5000" />
                                <PreSize X="1.0000" Y="1.0000" />
                                <SingleColor A="255" R="150" G="200" B="255" />
                                <FirstColor A="255" R="150" G="200" B="255" />
                                <EndColor A="255" R="255" G="255" B="255" />
                                <ColorVector ScaleY="1.0000" />
                              </AbstractNodeData>
                              <AbstractNodeData Name="day20" ActionTag="-1459132619" ZOrder="1" Tag="146" IconVisible="False" LeftMargin="17.0000" RightMargin="18.0000" TopMargin="100.0000" BottomMargin="20.0000" IsCustomSize="True" FontSize="20" LabelText="Day 20&#xA;&#xA;&#xA;" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                                <Size X="90.0000" Y="30.0000" />
                                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                                <Position X="62.0000" Y="35.0000" />
                                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                                <CColor A="255" R="247" G="237" B="185" />
                                <PrePosition X="0.4960" Y="0.2333" />
                                <PreSize X="0.7200" Y="0.2000" />
                                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                                <OutlineColor A="255" R="131" G="25" B="28" />
                                <ShadowColor A="255" R="105" G="30" B="35" />
                              </AbstractNodeData>
                            </Children>
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="562.5000" Y="75.0000" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <PrePosition X="0.9000" Y="0.5000" />
                            <PreSize X="0.2000" Y="1.0000" />
                            <NormalBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <PressedBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <DisableBackFileData Type="Normal" Path="image/dailyBonus/day_bk.png" Plist="" />
                            <NodeNormalFileData Type="Normal" Path="image/dailyBonus/day_highlight.png" Plist="" />
                            <NodeDisableFileData Type="Normal" Path="image/dailyBonus/day_checked.png" Plist="" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint />
                        <Position />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition />
                        <PreSize X="1.0000" Y="0.2500" />
                        <SingleColor A="255" R="150" G="150" B="255" />
                        <FirstColor A="255" R="150" G="150" B="255" />
                        <EndColor A="255" R="255" G="255" B="255" />
                        <ColorVector ScaleY="1.0000" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint />
                    <Position X="-310.0000" Y="-390.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <SingleColor A="255" R="150" G="150" B="255" />
                    <FirstColor A="255" R="150" G="150" B="255" />
                    <EndColor A="255" R="255" G="255" B="255" />
                    <ColorVector ScaleY="1.0000" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="bear" ActionTag="837784214" Tag="308" IconVisible="False" LeftMargin="-308.0000" RightMargin="32.0000" TopMargin="-368.9996" BottomMargin="190.9996" LeftEage="121" RightEage="121" TopEage="78" BottomEage="78" Scale9OriginX="121" Scale9OriginY="78" Scale9Width="126" Scale9Height="82" ctype="ImageViewObjectData">
                    <Size X="276.0000" Y="178.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-170.0000" Y="279.9996" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="image/playui/bear.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="0.0001" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnClose" ActionTag="-457922759" Tag="113" IconVisible="False" LeftMargin="266.0002" RightMargin="-364.0002" TopMargin="-589.0002" BottomMargin="491.0002" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="98.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="315.0002" Y="540.0002" />
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
            </Children>
            <AnchorPoint />
            <Position X="360.0000" Y="576.8271" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4506" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>