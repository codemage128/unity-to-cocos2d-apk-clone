<GameFile>
  <PropertyGroup Name="itemDiscoBeforeExplode" Type="Node" ID="d105a59c-1de1-49be-89ac-f506ab5c1712" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="20" Speed="0.5000">
        <Timeline ActionTag="1602935605" Property="Scale">
          <ScaleFrame FrameIndex="0" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1602935605" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="20" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="1602935605" Property="Alpha">
          <IntFrame FrameIndex="0" Value="63">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="128">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="98" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="explosion" ActionTag="-2112488555" Tag="48" IconVisible="True" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="before" ActionTag="-935287374" Tag="49" IconVisible="True" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="ring2" ActionTag="1602935605" Alpha="63" Tag="850" IconVisible="False" LeftMargin="-128.0000" RightMargin="-128.0000" TopMargin="-128.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
                    <Size X="256.0000" Y="256.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="2.0000" ScaleY="2.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="particle/ring2.png" Plist="" />
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