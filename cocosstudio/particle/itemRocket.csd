<GameFile>
  <PropertyGroup Name="itemRocket" Type="Node" ID="0e57f0c2-2f85-4ca3-b483-eef03aa0a28e" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="0.5000">
        <Timeline ActionTag="1478169039" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="15" Tween="False" Value="True" />
          <BoolFrame FrameIndex="40" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="1478169039" Property="Position">
          <PointFrame FrameIndex="15" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="377680489" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="5" Tween="False" Value="False" />
          <BoolFrame FrameIndex="10" Tween="False" Value="True" />
          <BoolFrame FrameIndex="40" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="377680489" Property="Position">
          <PointFrame FrameIndex="5" X="50.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="-250.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="377680489" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="40" Tween="False" Src="771" Dst="1" />
        </Timeline>
        <Timeline ActionTag="-97673902" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="5" Tween="False" Value="False" />
          <BoolFrame FrameIndex="10" Tween="False" Value="True" />
          <BoolFrame FrameIndex="40" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-97673902" Property="Position">
          <PointFrame FrameIndex="5" X="-50.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="250.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-97673902" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="40" Tween="False" Src="771" Dst="1" />
        </Timeline>
        <Timeline ActionTag="-1723747824" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="5" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-988165858" Property="Position">
          <PointFrame FrameIndex="0" X="-36.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="-36.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="-1300.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-988165858" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="5" Tween="False" Value="True" />
          <BoolFrame FrameIndex="40" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-1509249225" Property="Position">
          <PointFrame FrameIndex="0" X="36.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="36.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="1300.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1509249225" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="5" Tween="False" Value="True" />
          <BoolFrame FrameIndex="40" Tween="False" Value="False" />
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="98" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="star" ActionTag="1478169039" VisibleForFrame="False" Tag="819" IconVisible="True" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.4000" ScaleY="1.4000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/lineOfStars.plist" Plist="" />
            <BlendFunc Src="771" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="star_1_0" ActionTag="377680489" VisibleForFrame="False" Tag="57" IconVisible="True" LeftMargin="50.0000" RightMargin="-50.0000" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="50.0000" />
            <Scale ScaleX="1.4000" ScaleY="1.4000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/lineOfStars1.plist" Plist="" />
            <BlendFunc Src="771" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="star_1_1" ActionTag="-97673902" VisibleForFrame="False" Tag="58" IconVisible="True" LeftMargin="-50.0000" RightMargin="50.0000" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="-50.0000" />
            <Scale ScaleX="1.4000" ScaleY="1.4000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/lineOfStars1.plist" Plist="" />
            <BlendFunc Src="771" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="rockethorizantal" ActionTag="-1723747824" Tag="816" IconVisible="False" LeftMargin="-50.0000" RightMargin="-50.0000" TopMargin="-36.0000" BottomMargin="-36.0000" ctype="SpriteObjectData">
            <Size X="100.0000" Y="72.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/rockethorizantal.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="rocketleft" ActionTag="-988165858" VisibleForFrame="False" Tag="817" IconVisible="False" LeftMargin="-73.0000" RightMargin="-1.0000" TopMargin="-36.0000" BottomMargin="-36.0000" ctype="SpriteObjectData">
            <Size X="74.0000" Y="72.0000" />
            <Children>
              <AbstractNodeData Name="fire1" ActionTag="-346428353" Tag="80" IconVisible="True" LeftMargin="125.0000" RightMargin="-51.0000" TopMargin="35.0000" BottomMargin="37.0000" ctype="ParticleObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="125.0000" Y="37.0000" />
                <Scale ScaleX="2.2000" ScaleY="2.2000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.6892" Y="0.5139" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/rocketFire.plist" Plist="" />
                <BlendFunc Src="770" Dst="1" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-36.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/rocketleft.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="rocketright" ActionTag="-1509249225" VisibleForFrame="False" Tag="818" IconVisible="False" LeftMargin="-0.5000" RightMargin="-72.5000" TopMargin="-37.0000" BottomMargin="-37.0000" ctype="SpriteObjectData">
            <Size X="73.0000" Y="74.0000" />
            <Children>
              <AbstractNodeData Name="fire2" ActionTag="1962743434" Tag="99" RotationSkewX="180.0000" RotationSkewY="180.0000" IconVisible="True" LeftMargin="-50.0000" RightMargin="123.0000" TopMargin="37.0000" BottomMargin="37.0000" ctype="ParticleObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="-50.0000" Y="37.0000" />
                <Scale ScaleX="2.2000" ScaleY="2.2000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="-0.6849" Y="0.5000" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/rocketFire.plist" Plist="" />
                <BlendFunc Src="770" Dst="1" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="36.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/rocketright.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>