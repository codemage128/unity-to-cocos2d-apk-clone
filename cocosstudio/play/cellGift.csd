<GameFile>
  <PropertyGroup Name="cellGift" Type="Node" ID="8941c18c-bc1c-4e2f-86cf-052deb805f3e" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="55" Speed="1.0000" ActivedAnimationName="FlyOut">
        <Timeline ActionTag="-518066378" Property="Position">
          <PointFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-518066378" Property="Scale">
          <ScaleFrame FrameIndex="20" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-224722372" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="0.0000" Y="-2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="28" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="-3.0000" Y="7.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="45" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="51" X="1.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="55" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-224722372" Property="Scale">
          <ScaleFrame FrameIndex="10" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.0000" Y="0.9600">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="28" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="35" X="1.0000" Y="1.0500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-224722372" Property="RotationSkew">
          <ScaleFrame FrameIndex="28" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="35" X="-4.0000" Y="-4.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="51" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="55" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="FlyIn" StartIndex="0" EndIndex="5">
          <RenderColor A="255" R="255" G="240" B="245" />
        </AnimationInfo>
        <AnimationInfo Name="FlyOut" StartIndex="10" EndIndex="55">
          <RenderColor A="255" R="224" G="255" B="255" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="117" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Node_1" ActionTag="-224722372" Tag="123" IconVisible="True" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="giftback" ActionTag="-518066378" Tag="119" IconVisible="False" LeftMargin="-47.0000" RightMargin="-47.0000" TopMargin="-49.0000" BottomMargin="-49.0000" ctype="SpriteObjectData">
                <Size X="94.0000" Y="98.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/gift/giftback.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="shadow" ActionTag="-1437662974" Tag="121" IconVisible="False" LeftMargin="-29.5000" RightMargin="-29.5000" TopMargin="6.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                <Size X="59.0000" Y="18.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="-15.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/gift/shadow.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="tree" ActionTag="-614831509" Tag="122" IconVisible="False" LeftMargin="-25.0000" RightMargin="-25.0000" TopMargin="-36.5000" BottomMargin="-16.5000" ctype="SpriteObjectData">
                <Size X="50.0000" Y="53.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="10.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/gift/tree.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="Particle_1" ActionTag="734662105" Tag="9" IconVisible="True" LeftMargin="1.0000" RightMargin="-1.0000" TopMargin="-39.0000" BottomMargin="39.0000" ctype="ParticleObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="1.0000" Y="39.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/Snowing.plist" Plist="" />
                <BlendFunc Src="770" Dst="1" />
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