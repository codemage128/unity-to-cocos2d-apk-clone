<GameFile>
  <PropertyGroup Name="cellBlasterYellow" Type="Node" ID="b32ee5de-ed45-4b8b-b7dd-c992ccd28d1b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000" ActivedAnimationName="FlyOut">
        <Timeline ActionTag="-1384357154" Property="Position">
          <PointFrame FrameIndex="0" X="-1.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="-1.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="-1.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="-1.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="-1.0000" Y="33.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="-1.0000" Y="33.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="31" X="-1.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="-1.0000" Y="993.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1384357154" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.3500" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.3500" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="31" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1384357154" Property="RotationSkew">
          <ScaleFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="3.0000" Y="3.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="12" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="13" X="-3.0000" Y="-3.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="14" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1384357154" Property="AnchorPoint">
          <ScaleFrame FrameIndex="0" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="FlyIn" StartIndex="0" EndIndex="5">
          <RenderColor A="255" R="0" G="0" B="205" />
        </AnimationInfo>
        <AnimationInfo Name="FlyOut" StartIndex="10" EndIndex="60">
          <RenderColor A="255" R="255" G="228" B="196" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="51" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="yellow1" ActionTag="-1384357154" Tag="57" IconVisible="False" LeftMargin="-42.5000" RightMargin="-40.5000" TopMargin="-92.5000" BottomMargin="37.5000" ctype="SpriteObjectData">
            <Size X="83.0000" Y="55.0000" />
            <Children>
              <AbstractNodeData Name="blaster1" ActionTag="-708289813" Tag="53" IconVisible="False" LeftMargin="-5.0008" RightMargin="-5.9992" TopMargin="45.5000" BottomMargin="-85.5000" ctype="SpriteObjectData">
                <Size X="94.0000" Y="95.0000" />
                <Children>
                  <AbstractNodeData Name="blaster4" ActionTag="1125515660" Tag="56" IconVisible="False" LeftMargin="15.0000" RightMargin="15.0000" TopMargin="109.0000" BottomMargin="-48.0000" ctype="SpriteObjectData">
                    <Size X="64.0000" Y="34.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="47.0000" Y="-31.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.3263" />
                    <PreSize X="0.6809" Y="0.3579" />
                    <FileData Type="Normal" Path="image/play/blaster/blaster4.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="yellow3" ActionTag="-32674615" Tag="59" IconVisible="False" LeftMargin="-3.0000" RightMargin="-3.0000" TopMargin="76.0000" BottomMargin="-53.0000" ctype="SpriteObjectData">
                    <Size X="100.0000" Y="72.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="47.0000" Y="-17.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.1789" />
                    <PreSize X="1.0638" Y="0.7579" />
                    <FileData Type="Normal" Path="image/play/blaster/yellow3.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="blaster2" ActionTag="513900939" Tag="54" IconVisible="False" LeftMargin="29.0000" RightMargin="33.0000" TopMargin="15.0000" BottomMargin="6.0000" ctype="SpriteObjectData">
                    <Size X="32.0000" Y="74.0000" />
                    <Children>
                      <AbstractNodeData Name="blaster3" ActionTag="-1779822254" Tag="55" IconVisible="False" LeftMargin="6.0000" RightMargin="4.0000" TopMargin="3.0000" BottomMargin="3.0000" ctype="SpriteObjectData">
                        <Size X="22.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="17.0000" Y="37.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5313" Y="0.5000" />
                        <PreSize X="0.6875" Y="0.9189" />
                        <FileData Type="Normal" Path="image/play/blaster/blaster3.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="yellow2" ActionTag="576322959" Tag="58" IconVisible="False" LeftMargin="2.5000" RightMargin="-1.5000" TopMargin="-1.5000" BottomMargin="0.5000" ctype="SpriteObjectData">
                        <Size X="31.0000" Y="75.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="18.0000" Y="38.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5625" Y="0.5135" />
                        <PreSize X="0.9688" Y="1.0135" />
                        <FileData Type="Normal" Path="image/play/blaster/yellow2.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="45.0000" Y="43.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4787" Y="0.4526" />
                    <PreSize X="0.3404" Y="0.7789" />
                    <FileData Type="Normal" Path="image/play/blaster/blaster2.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="41.9992" Y="-38.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5060" Y="-0.6909" />
                <PreSize X="1.1325" Y="1.7273" />
                <FileData Type="Normal" Path="image/play/blaster/blaster1.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-1.0000" Y="65.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/blaster/yellow1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>