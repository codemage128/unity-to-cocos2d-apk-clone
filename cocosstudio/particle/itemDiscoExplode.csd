<GameFile>
  <PropertyGroup Name="itemDiscoExplode" Type="Node" ID="d105a59c-1de1-49be-89ac-f506ab5c1712" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="0.5000">
        <Timeline ActionTag="1526481436" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.5000" Y="1.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="0.6000" Y="0.6000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1526481436" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="20" Tween="False" Value="True" />
          <BoolFrame FrameIndex="40" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1526481436" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="40" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-956220214" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="28" X="5.0000" Y="5.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-956220214" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="28" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-956220214" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="28" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="40" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="879873315" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="4.0000" Y="4.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="879873315" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="True" />
          <BoolFrame FrameIndex="20" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="879873315" Property="Alpha">
          <IntFrame FrameIndex="0" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="40" Value="0">
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
              <AbstractNodeData Name="after" ActionTag="719859019" Tag="50" IconVisible="True" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="star9" ActionTag="1526481436" Alpha="0" Tag="886" IconVisible="False" LeftMargin="-128.0000" RightMargin="-128.0000" TopMargin="-128.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
                    <Size X="256.0000" Y="256.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="particle/star9.png" Plist="" />
                    <BlendFunc Src="770" Dst="1" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="ring3" ActionTag="-956220214" Alpha="0" Tag="885" IconVisible="False" LeftMargin="-128.0000" RightMargin="-128.0000" TopMargin="-128.0000" BottomMargin="-128.0000" ctype="SpriteObjectData">
                    <Size X="256.0000" Y="256.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="5.0000" ScaleY="5.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="particle/ring2.png" Plist="" />
                    <BlendFunc Src="770" Dst="1" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="dot2" ActionTag="879873315" Alpha="0" Tag="887" IconVisible="False" LeftMargin="-64.0000" RightMargin="-64.0000" TopMargin="-64.0000" BottomMargin="-64.0000" ctype="SpriteObjectData">
                    <Size X="128.0000" Y="128.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FileData Type="Normal" Path="particle/dot2.png" Plist="" />
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