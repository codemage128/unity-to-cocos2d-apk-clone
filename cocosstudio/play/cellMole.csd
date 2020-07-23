<GameFile>
  <PropertyGroup Name="cellMole" Type="Node" ID="8fa86a15-065e-44ae-93f7-52a42161128d" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="70" Speed="1.0000">
        <Timeline ActionTag="-229975694" Property="VisibleForFrame">
          <BoolFrame FrameIndex="10" Tween="False" Value="True" />
          <BoolFrame FrameIndex="65" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-1090085088" Property="VisibleForFrame">
          <BoolFrame FrameIndex="10" Tween="False" Value="False" />
          <BoolFrame FrameIndex="13" Tween="False" Value="True" />
          <BoolFrame FrameIndex="63" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="1100021592" Property="VisibleForFrame">
          <BoolFrame FrameIndex="10" Tween="False" Value="False" />
          <BoolFrame FrameIndex="15" Tween="False" Value="True" />
          <BoolFrame FrameIndex="60" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-694223665" Property="VisibleForFrame">
          <BoolFrame FrameIndex="10" Tween="False" Value="False" />
          <BoolFrame FrameIndex="17" Tween="False" Value="True" />
          <BoolFrame FrameIndex="57" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="704145482" Property="VisibleForFrame">
          <BoolFrame FrameIndex="10" Tween="False" Value="False" />
          <BoolFrame FrameIndex="19" Tween="False" Value="True" />
          <BoolFrame FrameIndex="55" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="618497540" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="-105.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="0.0000" Y="-105.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="0.0000" Y="-105.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="0.0000" Y="-35.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="22" X="0.0000" Y="-35.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="28" X="0.0000" Y="-35.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="45" X="0.0000" Y="-35.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="50" X="0.0000" Y="-35.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="65" X="0.0000" Y="-105.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="618497540" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="5" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="22" X="0.9000" Y="1.0900">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="25" X="1.0400" Y="0.9600">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="28" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="0.8900">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="1.0000" Y="0.8900">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="0.9000" Y="1.0900">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="618497540" Property="RotationSkew">
          <ScaleFrame FrameIndex="5" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="618497540" Property="FrameEvent">
          <EventFrame FrameIndex="70" Tween="False" Value="evt_animation_finished" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="FlyWaiting" StartIndex="0" EndIndex="5">
          <RenderColor A="255" R="0" G="206" B="209" />
        </AnimationInfo>
        <AnimationInfo Name="FlyIn" StartIndex="10" EndIndex="30">
          <RenderColor A="255" R="32" G="178" B="170" />
        </AnimationInfo>
        <AnimationInfo Name="FlyOut" StartIndex="45" EndIndex="80">
          <RenderColor A="255" R="253" G="245" B="230" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" Tag="140" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="boardback_6" ActionTag="851817442" Tag="146" IconVisible="False" LeftMargin="-48.5000" RightMargin="-48.5000" TopMargin="-37.5000" BottomMargin="-37.5000" ctype="SpriteObjectData">
            <Size X="97.0000" Y="75.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/mole/boardback.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ani" ActionTag="618497540" Tag="149" IconVisible="True" TopMargin="105.0000" BottomMargin="-105.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="ani1_1" ActionTag="-229975694" Tag="141" IconVisible="False" LeftMargin="-28.0000" RightMargin="-28.0000" TopMargin="-68.5000" BottomMargin="53.5000" ctype="SpriteObjectData">
                <Size X="56.0000" Y="15.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="61.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/mole/ani1.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ani2_2" ActionTag="-1090085088" VisibleForFrame="False" Tag="142" IconVisible="False" LeftMargin="-32.0000" RightMargin="-32.0000" TopMargin="-53.5000" BottomMargin="36.5000" ctype="SpriteObjectData">
                <Size X="64.0000" Y="17.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="45.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/mole/ani2.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ani3_3" ActionTag="1100021592" VisibleForFrame="False" Tag="143" IconVisible="False" LeftMargin="-33.0000" RightMargin="-33.0000" TopMargin="-37.0000" BottomMargin="21.0000" ctype="SpriteObjectData">
                <Size X="66.0000" Y="16.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="29.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/mole/ani3.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ani4_4" ActionTag="-694223665" VisibleForFrame="False" Tag="144" IconVisible="False" LeftMargin="-34.0000" RightMargin="-34.0000" TopMargin="-21.0000" BottomMargin="5.0000" ctype="SpriteObjectData">
                <Size X="68.0000" Y="16.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position Y="13.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/mole/ani4.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ani5_5" ActionTag="704145482" VisibleForFrame="False" Tag="145" IconVisible="False" LeftMargin="-34.0000" RightMargin="-34.0000" TopMargin="-6.0000" BottomMargin="-6.0000" ctype="SpriteObjectData">
                <Size X="68.0000" Y="12.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="image/play/mole/ani5.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position Y="-105.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="boardfront_7" ActionTag="857425636" Tag="147" IconVisible="False" LeftMargin="-50.0000" RightMargin="-50.0000" TopMargin="28.5000" BottomMargin="-61.5000" ctype="SpriteObjectData">
            <Size X="100.0000" Y="33.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="-45.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="image/play/mole/boardfront.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>