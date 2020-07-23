<GameFile>
  <PropertyGroup Name="cellBlasterBlue" Type="Node" ID="b32ee5de-ed45-4b8b-b7dd-c992ccd28d1b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="0.5000">
        <Timeline ActionTag="-142803466" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="30" Tween="False" Value="False" />
          <BoolFrame FrameIndex="31" Tween="False" Value="True" />
        </Timeline>
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
          <PointFrame FrameIndex="11" X="7.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="12" X="-1.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="13" X="-9.0000" Y="65.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="14" X="-1.0000" Y="65.0000">
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
          <AbstractNodeData Name="Particle_1" ActionTag="1274735571" Tag="33" IconVisible="True" TopMargin="96.0000" BottomMargin="-96.0000" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position Y="-96.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/spacerocket.plist" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="blue1" ActionTag="-1384357154" Tag="57" IconVisible="False" LeftMargin="-42.0000" RightMargin="-40.0000" TopMargin="-252.0000" BottomMargin="198.0000" ctype="SpriteObjectData">
            <Size X="82.0000" Y="54.0000" />
            <Children>
              <AbstractNodeData Name="Particle_2" ActionTag="-142803466" Tag="34" IconVisible="True" LeftMargin="42.0000" RightMargin="40.0000" TopMargin="189.0000" BottomMargin="-135.0000" ctype="ParticleObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="42.0000" Y="-135.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5122" Y="-2.5000" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/spacerocket1.plist" Plist="" />
                <BlendFunc Src="770" Dst="1" />
              </AbstractNodeData>
              <AbstractNodeData Name="blaster1" ActionTag="-708289813" Tag="53" IconVisible="False" LeftMargin="-5.0000" RightMargin="-7.0000" TopMargin="44.5000" BottomMargin="-85.5000" ctype="SpriteObjectData">
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
                  <AbstractNodeData Name="blue3" ActionTag="-32674615" Tag="59" IconVisible="False" LeftMargin="-3.0000" RightMargin="-3.0000" TopMargin="72.0000" BottomMargin="-53.0000" ctype="SpriteObjectData">
                    <Size X="100.0000" Y="76.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="47.0000" Y="-15.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="-0.1579" />
                    <PreSize X="1.0638" Y="0.8000" />
                    <FileData Type="Normal" Path="image/play/blaster/blue3.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="blaster2" ActionTag="513900939" Tag="54" IconVisible="False" LeftMargin="29.0000" RightMargin="33.0000" TopMargin="15.0000" BottomMargin="6.0000" ctype="SpriteObjectData">
                    <Size X="32.0000" Y="74.0000" />
                    <Children>
                      <AbstractNodeData Name="blaster3" ActionTag="-1779822254" Tag="55" IconVisible="False" LeftMargin="7.0000" RightMargin="3.0000" TopMargin="3.0000" BottomMargin="3.0000" ctype="SpriteObjectData">
                        <Size X="22.0000" Y="68.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="18.0000" Y="37.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5625" Y="0.5000" />
                        <PreSize X="0.6875" Y="0.9189" />
                        <FileData Type="Normal" Path="image/play/blaster/blaster3.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="blue2" ActionTag="576322959" Tag="58" IconVisible="False" LeftMargin="3.0000" RightMargin="-1.0000" TopMargin="-1.5000" BottomMargin="0.5000" ctype="SpriteObjectData">
                        <Size X="30.0000" Y="75.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="18.0000" Y="38.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.5625" Y="0.5135" />
                        <PreSize X="0.9375" Y="1.0135" />
                        <FileData Type="Normal" Path="image/play/blaster/blue2.png" Plist="" />
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
                <Position X="42.0000" Y="-38.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5122" Y="-0.7037" />
                <PreSize X="1.1463" Y="1.7593" />
                <FileData Type="Normal" Path="image/play/blaster/blaster1.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-1.0000" Y="225.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/blaster/blue1.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>