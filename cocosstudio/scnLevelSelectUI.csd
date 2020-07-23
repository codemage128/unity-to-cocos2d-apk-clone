<GameFile>
  <PropertyGroup Name="scnLevelSelectUI" Type="Scene" ID="ebc04369-635b-4b62-8061-61eeb952c3a4" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="ui" ActionTag="-302525229" Tag="2599" IconVisible="True" RightMargin="720.0000" TopMargin="1280.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="energy_bar" ActionTag="1125998592" Tag="55" IconVisible="False" LeftMargin="-33.5000" RightMargin="-333.5000" TopMargin="-1257.0000" BottomMargin="1143.0000" ctype="SpriteObjectData">
                <Size X="367.0000" Y="114.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-378732470" Tag="59" IconVisible="False" LeftMargin="-2.6687" RightMargin="-3.6687" TopMargin="0.4543" BottomMargin="0.4543" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="2" Scale9Height="10" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="373.3374" Y="113.0914" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="184.0000" Y="57.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5014" Y="0.5000" />
                    <PreSize X="1.0173" Y="0.9920" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="image/common/empty.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/common/empty.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/common/empty.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="button+" ActionTag="-1534478263" Tag="56" IconVisible="False" LeftMargin="284.5004" RightMargin="7.4996" TopMargin="18.5001" BottomMargin="16.4999" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="45" Scale9Height="57" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="75.0000" Y="79.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="322.0004" Y="55.9999" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.8774" Y="0.4912" />
                    <PreSize X="0.2044" Y="0.6930" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/mapui/mapuiplus.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/mapui/mapuiplus.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="lbl_energy" ActionTag="-115719558" Tag="57" IconVisible="False" LeftMargin="15.5000" RightMargin="266.5000" TopMargin="22.0000" BottomMargin="32.0000" FontSize="48" LabelText="4/5" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Bottom" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                    <Size X="85.0000" Y="60.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="58.0000" Y="62.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.1580" Y="0.5439" />
                    <PreSize X="0.2316" Y="0.5263" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="102" G="0" B="0" />
                    <ShadowColor A="255" R="102" G="2" B="2" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="lbl_time" ActionTag="1509559697" Tag="58" IconVisible="False" LeftMargin="127.0000" RightMargin="100.0000" TopMargin="31.0000" BottomMargin="27.0000" FontSize="48" LabelText="30:00" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="140.0000" Y="56.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="197.0000" Y="55.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="79" G="30" B="14" />
                    <PrePosition X="0.5368" Y="0.4825" />
                    <PreSize X="0.3815" Y="0.4912" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="150.0000" Y="1200.0000" />
                <Scale ScaleX="0.7000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/mapui/mapuilifebar.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="coin_bar" ActionTag="418633038" Tag="51" IconVisible="False" LeftMargin="386.5000" RightMargin="-753.5000" TopMargin="-1261.5000" BottomMargin="1138.5000" ctype="SpriteObjectData">
                <Size X="367.0000" Y="123.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-52616856" Tag="53" IconVisible="False" LeftMargin="5.9911" RightMargin="1.5398" TopMargin="5.5850" BottomMargin="-0.1180" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="2" Scale9Height="10" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="359.4691" Y="117.5330" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="185.7257" Y="58.6485" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5061" Y="0.4768" />
                    <PreSize X="0.9795" Y="0.9556" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="image/common/empty.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/common/empty.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/common/empty.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="button+" ActionTag="-1908957460" Tag="52" IconVisible="False" LeftMargin="284.5000" RightMargin="7.5000" TopMargin="24.5000" BottomMargin="19.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="45" Scale9Height="57" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="75.0000" Y="79.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="322.0000" Y="59.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.8774" Y="0.4797" />
                    <PreSize X="0.2044" Y="0.6423" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="image/mapui/mapuiplus.png" Plist="" />
                    <NormalFileData Type="Normal" Path="image/mapui/mapuiplus.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="lbl_coin" ActionTag="-1702773303" Tag="54" IconVisible="False" LeftMargin="118.5008" RightMargin="91.4992" TopMargin="35.0000" BottomMargin="32.0000" FontSize="48" LabelText="20000" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="157.0000" Y="56.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="197.0008" Y="60.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="79" G="30" B="14" />
                    <PrePosition X="0.5368" Y="0.4878" />
                    <PreSize X="0.4278" Y="0.4553" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="570.0000" Y="1200.0000" />
                <Scale ScaleX="0.7000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/mapui/mapuicoinbar.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_map" ActionTag="1879248939" Tag="2616" IconVisible="False" LeftMargin="579.9061" RightMargin="-665.9061" TopMargin="-354.1996" BottomMargin="255.1996" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="56" Scale9Height="77" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="86.0000" Y="99.0000" />
                <Children>
                  <AbstractNodeData Name="bar" ActionTag="1531966044" Tag="69" IconVisible="False" LeftMargin="-11.0836" RightMargin="-29.4400" TopMargin="-40.6962" BottomMargin="98.1609" Scale9Enable="True" LeftEage="27" RightEage="27" TopEage="13" BottomEage="13" Scale9OriginX="27" Scale9OriginY="13" Scale9Width="28" Scale9Height="14" ctype="ImageViewObjectData">
                    <Size X="126.5236" Y="41.5353" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="52.1782" Y="118.9286" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.6067" Y="1.2013" />
                    <PreSize X="1.4712" Y="0.4195" />
                    <FileData Type="Normal" Path="image/mapui/map_stage_sign.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="score_prog_star_1_8" ActionTag="1201729400" Tag="1785" IconVisible="False" LeftMargin="-42.6933" RightMargin="82.6933" TopMargin="-48.4939" BottomMargin="101.4939" ctype="SpriteObjectData">
                    <Size X="46.0000" Y="46.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="-19.6933" Y="124.4939" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="-0.2290" Y="1.2575" />
                    <PreSize X="0.5349" Y="0.4646" />
                    <FileData Type="Normal" Path="image/mapui/mapuilvlstar.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="count" ActionTag="-1394909090" Tag="1784" IconVisible="False" LeftMargin="28.0001" RightMargin="13.9999" TopMargin="-32.5000" BottomMargin="106.5000" FontSize="22" LabelText="480" HorizontalAlignmentType="HT_Center" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="44.0000" Y="25.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="50.0001" Y="119.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="0" B="0" />
                    <PrePosition X="0.5814" Y="1.2020" />
                    <PreSize X="0.5116" Y="0.2525" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="label" ActionTag="-1462974969" Tag="50" IconVisible="False" LeftMargin="14.7309" RightMargin="14.2691" TopMargin="89.8270" BottomMargin="-22.8270" FontSize="24" LabelText="Map" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="57.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="43.2309" Y="-6.8270" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5027" Y="-0.0690" />
                    <PreSize X="0.6628" Y="0.3232" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="79" G="30" B="14" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="total" ActionTag="-1943024792" VisibleForFrame="False" Tag="1783" IconVisible="False" LeftMargin="49.7269" RightMargin="-3.7269" TopMargin="-28.3927" BottomMargin="106.3927" FontSize="18" LabelText="/ 480" VerticalAlignmentType="VT_Center" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="40.0000" Y="21.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="49.7269" Y="116.8927" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="44" G="42" B="42" />
                    <PrePosition X="0.5782" Y="1.1807" />
                    <PreSize X="0.4651" Y="0.2121" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="622.9061" Y="304.6996" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="image/mapui/lobby_btn_map.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/mapui/lobby_btn_map.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/mapui/lobby_btn_map.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_option" ActionTag="-956855548" Tag="2619" IconVisible="False" LeftMargin="557.7479" RightMargin="-687.7479" TopMargin="-213.3594" BottomMargin="83.3594" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="100" Scale9Height="108" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="130.0000" Y="130.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="-296540731" Tag="2622" IconVisible="False" LeftMargin="15.6567" RightMargin="24.3433" TopMargin="123.3474" BottomMargin="-25.3474" FontSize="24" LabelText="Option" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="90.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="60.6567" Y="-9.3474" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4666" Y="-0.0719" />
                    <PreSize X="0.6923" Y="0.2462" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="79" G="30" B="14" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="622.7479" Y="148.3594" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="image/mapui/lobby_btn_option.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/mapui/lobby_btn_option.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/mapui/lobby_btn_option.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="dailybonus" ActionTag="1952620669" Tag="64" IconVisible="False" LeftMargin="60.0444" RightMargin="-188.0444" TopMargin="-1040.2634" BottomMargin="931.2634" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="98" Scale9Height="87" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="128.0000" Y="109.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="-1881671440" Tag="66" IconVisible="False" LeftMargin="-10.4615" RightMargin="-9.5385" TopMargin="111.6990" BottomMargin="-32.6990" FontSize="24" LabelText="Daily Bonus" HorizontalAlignmentType="HT_Center" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="148.0000" Y="30.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="63.5385" Y="-17.6990" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4964" Y="-0.1624" />
                    <PreSize X="1.1563" Y="0.2752" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="79" G="30" B="14" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="counter" ActionTag="-826825669" Tag="68" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="7.0000" RightMargin="7.0000" TopMargin="141.0000" BottomMargin="-64.0000" FontSize="24" LabelText="00:00:00" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="114.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="64.0000" Y="-48.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.4404" />
                    <PreSize X="0.8906" Y="0.2936" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="79" G="30" B="14" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="124.0444" Y="985.7634" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/mapui/mapuidailybonus.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/mapui/mapuidailybonus.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="dailychallenge" ActionTag="-671560931" VisibleForFrame="False" Tag="65" IconVisible="False" LeftMargin="83.9084" RightMargin="-157.9084" TopMargin="-809.3774" BottomMargin="734.3774" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="44" Scale9Height="53" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="74.0000" Y="75.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="288163324" VisibleForFrame="False" Tag="67" IconVisible="False" LeftMargin="-61.6516" RightMargin="-58.3484" TopMargin="82.2162" BottomMargin="-39.2162" FontSize="24" LabelText="Daily Challenge" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="194.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="35.3484" Y="-23.2162" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4777" Y="-0.3095" />
                    <PreSize X="2.6216" Y="0.4267" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="79" G="30" B="14" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="counter" ActionTag="-334118167" VisibleForFrame="False" Tag="1003" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-20.0000" RightMargin="-20.0000" TopMargin="116.7500" BottomMargin="-73.7500" FontSize="24" LabelText="00:00:00" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="114.0000" Y="32.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="37.0000" Y="-57.7500" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.7700" />
                    <PreSize X="1.5405" Y="0.4267" />
                    <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                    <OutlineColor A="255" R="79" G="30" B="14" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.9084" Y="771.8774" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="image/mapui/mapuidailychallenge.png" Plist="" />
                <NormalFileData Type="Normal" Path="image/mapui/mapuidailychallenge.png" Plist="" />
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
      </ObjectData>
    </Content>
  </Content>
</GameFile>