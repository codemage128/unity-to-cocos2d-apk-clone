<GameFile>
  <PropertyGroup Name="dlgBuyCoin" Type="Scene" ID="662d66de-fe09-46d1-84ce-35b258ca00bc" Version="3.10.0.0" />
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
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
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
          <AbstractNodeData Name="blackbg" ActionTag="-984669500" Alpha="178" Tag="142" IconVisible="False" TouchEnable="True" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="root" ActionTag="-1191915271" Tag="322" IconVisible="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="640.0000" BottomMargin="640.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="imgTop" ActionTag="648578726" Tag="67" IconVisible="False" LeftMargin="-335.0000" RightMargin="-335.0000" TopMargin="-554.0000" BottomMargin="458.0000" Scale9Enable="True" LeftEage="112" RightEage="112" Scale9OriginX="112" Scale9Width="7" Scale9Height="96" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="506.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframetop.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgMiddle" ActionTag="-1928407235" Tag="66" IconVisible="False" LeftMargin="-335.0000" RightMargin="-335.0000" TopMargin="-458.3280" BottomMargin="-487.5720" Scale9Enable="True" LeftEage="76" RightEage="76" Scale9OriginX="76" Scale9Width="79" Scale9Height="4" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="945.9000" />
                <Children>
                  <AbstractNodeData Name="imgCoin0" ActionTag="-2023068944" Tag="114" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="28.4080" RightMargin="25.1920" TopMargin="49.7587" BottomMargin="773.5614" Scale9Enable="True" LeftEage="59" RightEage="59" TopEage="87" BottomEage="47" Scale9OriginX="59" Scale9OriginY="87" Scale9Width="62" Scale9Height="63" ctype="ImageViewObjectData">
                    <Size X="616.4000" Y="122.5800" />
                    <Children>
                      <AbstractNodeData Name="iconCoin0" ActionTag="-1735020826" Tag="115" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="161.7025" RightMargin="242.6975" TopMargin="19.4842" BottomMargin="15.0958" ctype="SpriteObjectData">
                        <Size X="212.0000" Y="88.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="267.7025" Y="59.0958" />
                        <Scale ScaleX="0.6100" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4343" Y="0.4821" />
                        <PreSize X="0.3439" Y="0.7179" />
                        <FileData Type="Normal" Path="image/buycoin/coiin0.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="btnCoin0" ActionTag="-553722109" Tag="320" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="367.7751" RightMargin="17.1667" TopMargin="16.4564" BottomMargin="21.4331" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" Scale9OriginX="38" Scale9Width="40" Scale9Height="95" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="231.4582" Y="84.6905" />
                        <Children>
                          <AbstractNodeData Name="txtMoney" ActionTag="-747169178" Tag="26" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="43.7291" RightMargin="43.7291" TopMargin="13.8453" BottomMargin="13.8452" FontSize="44" LabelText="$ 0.99" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="144.0000" Y="57.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="115.7291" Y="42.3452" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="249" G="240" B="195" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.6221" Y="0.6730" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="91" G="127" B="11" />
                            <ShadowColor A="255" R="58" G="82" B="8" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="483.5042" Y="63.7784" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.7844" Y="0.5203" />
                        <PreSize X="0.3755" Y="0.6909" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtMoney0" ActionTag="-1858066754" Tag="116" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="21.7589" RightMargin="504.6411" TopMargin="27.6804" BottomMargin="41.8996" FontSize="44" LabelText="100" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="90.0000" Y="53.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="21.7589" Y="68.3996" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="249" G="240" B="195" />
                        <PrePosition X="0.0353" Y="0.5580" />
                        <PreSize X="0.1460" Y="0.4324" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="127" G="0" B="7" />
                        <ShadowColor A="255" R="127" G="0" B="7" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.6080" Y="834.8514" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5024" Y="0.8826" />
                    <PreSize X="0.9200" Y="0.1296" />
                    <FileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="imgCoin1" ActionTag="1150886911" Tag="117" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="28.4080" RightMargin="25.1920" TopMargin="195.4256" BottomMargin="627.8912" Scale9Enable="True" LeftEage="59" RightEage="59" TopEage="85" BottomEage="65" Scale9OriginX="59" Scale9OriginY="85" Scale9Width="62" Scale9Height="47" ctype="ImageViewObjectData">
                    <Size X="616.4000" Y="122.5832" />
                    <Children>
                      <AbstractNodeData Name="iconCoin1" ActionTag="-1767139955" Tag="118" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="125.7025" RightMargin="206.6975" TopMargin="4.4858" BottomMargin="0.0974" ctype="SpriteObjectData">
                        <Size X="284.0000" Y="118.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="267.7025" Y="59.0974" />
                        <Scale ScaleX="0.6100" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4343" Y="0.4821" />
                        <PreSize X="0.4607" Y="0.9626" />
                        <FileData Type="Normal" Path="image/buycoin/coin1.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="btnCoin1" ActionTag="-67032387" Tag="119" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="367.7751" RightMargin="17.1667" TopMargin="16.4568" BottomMargin="21.4337" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" Scale9OriginX="38" Scale9Width="40" Scale9Height="95" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="231.4582" Y="84.6927" />
                        <Children>
                          <AbstractNodeData Name="txtMoney" ActionTag="-1779087219" Tag="120" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="43.7291" RightMargin="43.7291" TopMargin="13.8464" BottomMargin="13.8464" FontSize="44" LabelText="$ 4.99" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="144.0000" Y="57.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="115.7291" Y="42.3464" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="249" G="240" B="195" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.6221" Y="0.6730" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="91" G="127" B="11" />
                            <ShadowColor A="255" R="58" G="82" B="8" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="483.5042" Y="63.7800" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.7844" Y="0.5203" />
                        <PreSize X="0.3755" Y="0.6909" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtMoney1" ActionTag="-1440116205" Tag="121" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="21.7589" RightMargin="504.6411" TopMargin="27.6818" BottomMargin="41.9014" FontSize="44" LabelText="550" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="90.0000" Y="53.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="21.7589" Y="68.4014" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="249" G="240" B="195" />
                        <PrePosition X="0.0353" Y="0.5580" />
                        <PreSize X="0.1460" Y="0.4324" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="127" G="0" B="7" />
                        <ShadowColor A="255" R="127" G="0" B="7" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.6080" Y="689.1828" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5024" Y="0.7286" />
                    <PreSize X="0.9200" Y="0.1296" />
                    <FileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="imgCoin2" ActionTag="-1924507698" Tag="122" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="28.4080" RightMargin="25.1920" TopMargin="341.0942" BottomMargin="482.2226" Scale9Enable="True" LeftEage="59" RightEage="59" TopEage="85" BottomEage="65" Scale9OriginX="59" Scale9OriginY="85" Scale9Width="62" Scale9Height="47" ctype="ImageViewObjectData">
                    <Size X="616.4000" Y="122.5832" />
                    <Children>
                      <AbstractNodeData Name="iconCoin2" ActionTag="-1239974572" Tag="123" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="118.7025" RightMargin="199.6975" TopMargin="-8.0142" BottomMargin="-12.4026" ctype="SpriteObjectData">
                        <Size X="298.0000" Y="143.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="267.7025" Y="59.0974" />
                        <Scale ScaleX="0.6100" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4343" Y="0.4821" />
                        <PreSize X="0.4835" Y="1.1666" />
                        <FileData Type="Normal" Path="image/buycoin/coin2.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="btnCoin2" ActionTag="1016996280" Tag="124" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="367.7751" RightMargin="17.1667" TopMargin="16.4568" BottomMargin="21.4337" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" Scale9OriginX="38" Scale9Width="40" Scale9Height="95" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="231.4582" Y="84.6927" />
                        <Children>
                          <AbstractNodeData Name="txtMoney" ActionTag="-62307614" Tag="125" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="43.7291" RightMargin="43.7291" TopMargin="13.8464" BottomMargin="13.8464" FontSize="44" LabelText="$ 9.99" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="144.0000" Y="57.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="115.7291" Y="42.3464" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="249" G="240" B="195" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.6221" Y="0.6730" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="91" G="127" B="11" />
                            <ShadowColor A="255" R="58" G="82" B="8" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="483.5042" Y="63.7800" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.7844" Y="0.5203" />
                        <PreSize X="0.3755" Y="0.6909" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtMoney2" ActionTag="962467802" Tag="126" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="21.7589" RightMargin="475.6411" TopMargin="27.6818" BottomMargin="41.9014" FontSize="44" LabelText="1200" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="119.0000" Y="53.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="21.7589" Y="68.4014" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="249" G="240" B="195" />
                        <PrePosition X="0.0353" Y="0.5580" />
                        <PreSize X="0.1931" Y="0.4324" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="127" G="0" B="7" />
                        <ShadowColor A="255" R="127" G="0" B="7" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.6080" Y="543.5142" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5024" Y="0.5746" />
                    <PreSize X="0.9200" Y="0.1296" />
                    <FileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="imgCoin3" ActionTag="-1153220912" Tag="127" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="28.4080" RightMargin="25.1920" TopMargin="486.7629" BottomMargin="336.5540" Scale9Enable="True" LeftEage="59" RightEage="59" TopEage="85" BottomEage="65" Scale9OriginX="59" Scale9OriginY="85" Scale9Width="62" Scale9Height="47" ctype="ImageViewObjectData">
                    <Size X="616.4000" Y="122.5832" />
                    <Children>
                      <AbstractNodeData Name="iconCoin3" ActionTag="2003639660" Tag="128" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="110.7025" RightMargin="191.6975" TopMargin="-5.5142" BottomMargin="-9.9026" ctype="SpriteObjectData">
                        <Size X="314.0000" Y="138.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="267.7025" Y="59.0974" />
                        <Scale ScaleX="0.6100" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4343" Y="0.4821" />
                        <PreSize X="0.5094" Y="1.1258" />
                        <FileData Type="Normal" Path="image/buycoin/coin3.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="btnCoin3" ActionTag="623861895" Tag="129" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="367.7751" RightMargin="17.1667" TopMargin="16.4568" BottomMargin="21.4337" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" Scale9OriginX="38" Scale9Width="40" Scale9Height="95" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="231.4582" Y="84.6927" />
                        <Children>
                          <AbstractNodeData Name="txtMoney" ActionTag="221240431" Tag="130" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="29.2291" RightMargin="29.2291" TopMargin="13.8464" BottomMargin="13.8464" FontSize="44" LabelText="$ 19.99" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="173.0000" Y="57.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="115.7291" Y="42.3464" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="249" G="240" B="195" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.7474" Y="0.6730" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="91" G="127" B="11" />
                            <ShadowColor A="255" R="58" G="82" B="8" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="483.5042" Y="63.7800" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.7844" Y="0.5203" />
                        <PreSize X="0.3755" Y="0.6909" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtMoney3" ActionTag="-2037953489" Tag="131" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="21.7589" RightMargin="475.6411" TopMargin="27.6818" BottomMargin="41.9014" FontSize="44" LabelText="2500" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="119.0000" Y="53.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="21.7589" Y="68.4014" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="249" G="240" B="195" />
                        <PrePosition X="0.0353" Y="0.5580" />
                        <PreSize X="0.1931" Y="0.4324" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="127" G="0" B="7" />
                        <ShadowColor A="255" R="127" G="0" B="7" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.6080" Y="397.8456" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5024" Y="0.4206" />
                    <PreSize X="0.9200" Y="0.1296" />
                    <FileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="imgCoin4" ActionTag="-840979438" Tag="132" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="28.4080" RightMargin="25.1920" TopMargin="632.4315" BottomMargin="190.8854" Scale9Enable="True" LeftEage="59" RightEage="59" TopEage="85" BottomEage="65" Scale9OriginX="59" Scale9OriginY="85" Scale9Width="62" Scale9Height="47" ctype="ImageViewObjectData">
                    <Size X="616.4000" Y="122.5832" />
                    <Children>
                      <AbstractNodeData Name="iconCoin4" ActionTag="1013562573" Tag="133" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="70.2025" RightMargin="151.1975" TopMargin="-6.0142" BottomMargin="-10.4026" ctype="SpriteObjectData">
                        <Size X="395.0000" Y="139.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="267.7025" Y="59.0974" />
                        <Scale ScaleX="0.6100" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4343" Y="0.4821" />
                        <PreSize X="0.6408" Y="1.1339" />
                        <FileData Type="Normal" Path="image/buycoin/coin4.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="btnCoin4" ActionTag="-1616044090" Tag="134" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="367.7751" RightMargin="17.1667" TopMargin="16.4568" BottomMargin="21.4337" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" Scale9OriginX="38" Scale9Width="40" Scale9Height="95" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="231.4582" Y="84.6927" />
                        <Children>
                          <AbstractNodeData Name="txtMoney" ActionTag="-1177146921" Tag="135" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="29.2291" RightMargin="29.2291" TopMargin="13.8464" BottomMargin="13.8464" FontSize="44" LabelText="$ 49.99" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="173.0000" Y="57.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="115.7291" Y="42.3464" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="249" G="240" B="195" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.7474" Y="0.6730" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="91" G="127" B="11" />
                            <ShadowColor A="255" R="58" G="82" B="8" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="483.5042" Y="63.7800" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.7844" Y="0.5203" />
                        <PreSize X="0.3755" Y="0.6909" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtMoney4" ActionTag="-398769857" Tag="136" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="21.7589" RightMargin="475.6411" TopMargin="27.6818" BottomMargin="41.9014" FontSize="44" LabelText="6500" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="119.0000" Y="53.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="21.7589" Y="68.4014" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="249" G="240" B="195" />
                        <PrePosition X="0.0353" Y="0.5580" />
                        <PreSize X="0.1931" Y="0.4324" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="127" G="0" B="7" />
                        <ShadowColor A="255" R="127" G="0" B="7" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.6080" Y="252.1770" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5024" Y="0.2666" />
                    <PreSize X="0.9200" Y="0.1296" />
                    <FileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="imgCoin5" ActionTag="-2121035760" Tag="137" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="28.4080" RightMargin="25.1920" TopMargin="778.0055" BottomMargin="45.3113" Scale9Enable="True" LeftEage="59" RightEage="59" TopEage="85" BottomEage="65" Scale9OriginX="59" Scale9OriginY="85" Scale9Width="62" Scale9Height="47" ctype="ImageViewObjectData">
                    <Size X="616.4000" Y="122.5832" />
                    <Children>
                      <AbstractNodeData Name="iconCoin5" ActionTag="-234549617" Tag="138" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="85.2025" RightMargin="166.1975" TopMargin="-22.5142" BottomMargin="-26.9026" ctype="SpriteObjectData">
                        <Size X="365.0000" Y="172.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="267.7025" Y="59.0974" />
                        <Scale ScaleX="0.6100" ScaleY="0.6000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4343" Y="0.4821" />
                        <PreSize X="0.5921" Y="1.4031" />
                        <FileData Type="Normal" Path="image/buycoin/coin5.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="btnCoin5" ActionTag="-416425773" Tag="139" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" LeftMargin="367.7751" RightMargin="17.1667" TopMargin="16.4568" BottomMargin="21.4337" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="38" RightEage="38" Scale9OriginX="38" Scale9Width="40" Scale9Height="95" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                        <Size X="231.4582" Y="84.6927" />
                        <Children>
                          <AbstractNodeData Name="txtMoney" ActionTag="1957106140" Tag="140" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="29.2291" RightMargin="29.2291" TopMargin="13.8464" BottomMargin="13.8464" FontSize="44" LabelText="$ 99.99" OutlineSize="3" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                            <Size X="173.0000" Y="57.0000" />
                            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                            <Position X="115.7291" Y="42.3464" />
                            <Scale ScaleX="1.0000" ScaleY="1.0000" />
                            <CColor A="255" R="249" G="240" B="195" />
                            <PrePosition X="0.5000" Y="0.5000" />
                            <PreSize X="0.7474" Y="0.6730" />
                            <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                            <OutlineColor A="255" R="91" G="127" B="11" />
                            <ShadowColor A="255" R="58" G="82" B="8" />
                          </AbstractNodeData>
                        </Children>
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="483.5042" Y="63.7800" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.7844" Y="0.5203" />
                        <PreSize X="0.3755" Y="0.6909" />
                        <TextColor A="255" R="65" G="65" B="70" />
                        <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                        <PressedFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <NormalFileData Type="Normal" Path="image/booster/boosterbutton.png" Plist="" />
                        <OutlineColor A="255" R="255" G="0" B="0" />
                        <ShadowColor A="255" R="110" G="110" B="110" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="txtMoney5" ActionTag="-517487290" Tag="141" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="21.7589" RightMargin="446.6411" TopMargin="27.6818" BottomMargin="41.9014" FontSize="44" LabelText="14000" OutlineEnabled="True" ShadowOffsetX="4.0000" ShadowOffsetY="-4.0000" ShadowEnabled="True" ctype="TextObjectData">
                        <Size X="148.0000" Y="53.0000" />
                        <AnchorPoint ScaleY="0.5000" />
                        <Position X="21.7589" Y="68.4014" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="249" G="240" B="195" />
                        <PrePosition X="0.0353" Y="0.5580" />
                        <PreSize X="0.2401" Y="0.4324" />
                        <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                        <OutlineColor A="255" R="127" G="0" B="7" />
                        <ShadowColor A="255" R="127" G="0" B="7" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="336.6080" Y="106.6029" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5024" Y="0.1127" />
                    <PreSize X="0.9200" Y="0.1296" />
                    <FileData Type="Normal" Path="image/buycoin/buycoinslot.png" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" />
                <Position Y="-487.5720" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframemiddle.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="imgBottom" ActionTag="-514651647" Tag="65" IconVisible="False" LeftMargin="-335.0000" RightMargin="-335.0000" TopMargin="484.5000" BottomMargin="-571.5000" Scale9Enable="True" LeftEage="78" RightEage="78" BottomEage="50" Scale9OriginX="78" Scale9Width="5" Scale9Height="188" ctype="ImageViewObjectData">
                <Size X="670.0000" Y="87.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-528.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/dialog/dlgframebottom.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="2015538212" Tag="14" IconVisible="False" LeftMargin="-186.2663" RightMargin="-214.4621" TopMargin="-516.2037" BottomMargin="431.2037" IsCustomSize="True" FontSize="70" LabelText="Buy Coins" HorizontalAlignmentType="HT_Center" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="3.0000" ShadowOffsetY="-3.0000" ShadowEnabled="True" ctype="TextObjectData">
                <Size X="400.7285" Y="85.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="14.0979" Y="473.7037" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="247" G="237" B="185" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="fonts/ERASBD.TTF" Plist="" />
                <OutlineColor A="255" R="131" G="25" B="28" />
                <ShadowColor A="255" R="105" G="30" B="35" />
              </AbstractNodeData>
              <AbstractNodeData Name="btnClose" ActionTag="-457922759" Tag="113" IconVisible="False" LeftMargin="263.9937" RightMargin="-361.9937" TopMargin="-596.4275" BottomMargin="498.4275" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="68" Scale9Height="76" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="98.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="312.9937" Y="547.4275" />
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