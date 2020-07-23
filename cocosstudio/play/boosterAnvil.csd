<GameFile>
  <PropertyGroup Name="boosterAnvil" Type="Node" ID="0a5da508-8625-44b6-a8a5-9677ed3ea20e" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="30" Speed="0.5000">
        <Timeline ActionTag="197582504" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="1000.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="-1000.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="252" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="root" ActionTag="197582504" Tag="14" IconVisible="True" TopMargin="-1000.0000" BottomMargin="1000.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="Particle_2" ActionTag="-2044494887" Tag="58" IconVisible="True" ctype="ParticleObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position />
                <Scale ScaleX="9.0000" ScaleY="9.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="particle/smoke4.plist" Plist="" />
                <BlendFunc Src="770" Dst="1" />
              </AbstractNodeData>
              <AbstractNodeData Name="anvil" ActionTag="162386074" Tag="253" IconVisible="False" LeftMargin="-99.5000" RightMargin="-99.5000" TopMargin="-97.0000" BottomMargin="-97.0000" ctype="SpriteObjectData">
                <Size X="199.0000" Y="194.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/playui/anvil.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position Y="1000.0000" />
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