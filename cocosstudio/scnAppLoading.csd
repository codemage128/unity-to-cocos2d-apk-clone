<GameFile>
  <PropertyGroup Name="scnAppLoading" Type="Scene" ID="30c1fd9a-40ae-49a6-80a0-20a6720ed68b" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="0.5000" ActivedAnimationName="show">
        <Timeline ActionTag="-871612391" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="30" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="37" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="43" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="60" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="show" StartIndex="0" EndIndex="60">
          <RenderColor A="255" R="60" G="179" B="113" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="11" ctype="GameNodeObjectData">
        <Size X="720.0000" Y="1280.0000" />
        <Children>
          <AbstractNodeData Name="bg" ActionTag="-558578308" Tag="5" FrameEvent="loading_finished" IconVisible="False" LeftEage="190" RightEage="190" TopEage="337" BottomEage="337" Scale9OriginX="190" Scale9OriginY="337" Scale9Width="340" Scale9Height="606" ctype="ImageViewObjectData">
            <Size X="720.0000" Y="1280.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="360.0000" Y="640.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="image/splash/apploadingbg.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="loading" ActionTag="-871612391" Alpha="0" Tag="7" IconVisible="False" LeftMargin="216.9024" RightMargin="246.0976" TopMargin="1137.5562" BottomMargin="81.4438" ctype="SpriteObjectData">
            <Size X="257.0000" Y="61.0000" />
            <AnchorPoint ScaleX="0.5568" ScaleY="0.3042" />
            <Position X="360.0000" Y="100.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.0781" />
            <PreSize X="0.3569" Y="0.0477" />
            <FileData Type="Normal" Path="image/splash/loading.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>