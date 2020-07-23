<GameFile>
  <PropertyGroup Name="boosterHummerFinish" Type="Scene" ID="9cb1fb8a-5c41-4bd2-a5c9-6b80665427ba" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="51" Speed="1.0000">
        <Timeline ActionTag="1732660013" Property="Scale">
          <ScaleFrame FrameIndex="5" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="2.5000" Y="2.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1732660013" Property="Alpha">
          <IntFrame FrameIndex="5" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="50" Value="25">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="1732660013" Property="VisibleForFrame">
          <BoolFrame FrameIndex="50" Tween="False" Value="True" />
          <BoolFrame FrameIndex="51" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="1635453548" Property="Scale">
          <ScaleFrame FrameIndex="5" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="2.5000" Y="2.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1635453548" Property="Alpha">
          <IntFrame FrameIndex="5" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="50" Value="25">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="1635453548" Property="VisibleForFrame">
          <BoolFrame FrameIndex="50" Tween="False" Value="True" />
          <BoolFrame FrameIndex="51" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-613880003" Property="Scale">
          <ScaleFrame FrameIndex="5" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="2.5000" Y="2.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-613880003" Property="Alpha">
          <IntFrame FrameIndex="5" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="50" Value="76">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-613880003" Property="VisibleForFrame">
          <BoolFrame FrameIndex="50" Tween="False" Value="True" />
          <BoolFrame FrameIndex="51" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="2138011198" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="0" Tween="False" Src="324" Dst="1" />
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" Tag="344" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="ring1" ActionTag="1732660013" VisibleForFrame="False" Alpha="25" Tag="349" IconVisible="False" LeftMargin="-128.0000" RightMargin="592.0000" TopMargin="1152.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
            <Size X="256.0000" Y="256.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="2.5000" ScaleY="2.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.3556" Y="0.2000" />
            <FileData Type="Normal" Path="particle/ring2.png" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="ring2" ActionTag="1635453548" VisibleForFrame="False" Alpha="25" Tag="350" IconVisible="False" LeftMargin="-128.0000" RightMargin="592.0000" TopMargin="1152.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
            <Size X="256.0000" Y="256.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="2.5000" ScaleY="2.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.3556" Y="0.2000" />
            <FileData Type="Normal" Path="particle/ring1.png" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="ring3" ActionTag="-613880003" VisibleForFrame="False" Alpha="76" Tag="352" IconVisible="False" LeftMargin="-128.0000" RightMargin="592.0000" TopMargin="1152.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
            <Size X="256.0000" Y="256.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="2.5000" ScaleY="2.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.3556" Y="0.2000" />
            <FileData Type="Normal" Path="particle/ring3.png" Plist="" />
            <BlendFunc Src="770" Dst="1" />
          </AbstractNodeData>
          <AbstractNodeData Name="paticle" ActionTag="2138011198" Tag="353" IconVisible="True" LeftMargin="-10.0000" RightMargin="730.0000" TopMargin="1280.0000" ctype="ParticleObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="-10.0000" />
            <Scale ScaleX="1.5000" ScaleY="1.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="-0.0139" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="particle/itemhummer.plist" Plist="" />
            <BlendFunc Src="324" Dst="1" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>