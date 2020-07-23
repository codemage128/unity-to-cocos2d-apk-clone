<GameFile>
  <PropertyGroup Name="scnLevelLoading" Type="Scene" ID="e45682e0-328e-4706-8d94-4d7bf8740a78" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="30" Speed="0.5000" ActivedAnimationName="show">
        <Timeline ActionTag="-683467303" Property="Alpha">
          <IntFrame FrameIndex="30" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="show" StartIndex="0" EndIndex="30">
          <RenderColor A="255" R="112" G="128" B="144" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="13" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="loading" ActionTag="-683467303" Tag="10" IconVisible="False" Scale9Width="46" Scale9Height="46" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Default" Path="Default/ImageFile.png" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>