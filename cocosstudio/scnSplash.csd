<GameFile>
  <PropertyGroup Name="scnSplash" Type="Scene" ID="1299b41a-747d-45fd-ab6d-ddb599037284" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="0.5000" ActivedAnimationName="show">
        <Timeline ActionTag="-514090732" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="40" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="60" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="show" StartIndex="0" EndIndex="60">
          <RenderColor A="255" R="46" G="139" B="87" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="9" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="bg" ActionTag="485753123" Tag="5" IconVisible="False" LeftEage="10" RightEage="10" TopEage="10" BottomEage="10" Scale9OriginX="10" Scale9OriginY="10" Scale9Width="12" Scale9Height="12" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/common/blankwhite.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="splash" ActionTag="-514090732" Tag="10" IconVisible="False" ctype="SpriteObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/splash/splash.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>