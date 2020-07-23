<GameFile>
  <PropertyGroup Name="itemCreate" Type="Node" ID="1d6fe186-c73f-459a-adcc-718d416df2f1" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="30" Speed="0.1667">
        <Timeline ActionTag="-742414515" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="5" Tween="False" Value="True" />
          <BoolFrame FrameIndex="30" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-742414515" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="0" Tween="False" Src="770" Dst="1" />
        </Timeline>
        <Timeline ActionTag="142336018" Property="Scale">
          <ScaleFrame FrameIndex="5" X="0.2500" Y="0.2500">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="142336018" Property="Alpha">
          <IntFrame FrameIndex="5" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="142336018" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="5" Tween="False" Value="True" />
          <BoolFrame FrameIndex="30" Tween="False" Value="False" />
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="98" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="starParticle" ActionTag="-742414515" VisibleForFrame="False" Tag="791" IconVisible="True" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/ringStar.plist" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="ring1" ActionTag="142336018" VisibleForFrame="False" Tag="792" IconVisible="False" LeftMargin="-128.0000" RightMargin="-128.0000" TopMargin="-128.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
            <Size X="256.0000" Y="256.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="0.2500" ScaleY="0.2500" />
            <CColor A="255" R="255" G="255" B="128" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/ring1.png" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>