XXX.cs파일을 porting해서 XXX.h와 XXX.cpp로 만들어 주십시오.

public class SodaItem : Item ---->
	class SodaItem: public Item {

	
	
public SodaFakeItem BottomRight;
public SodaFakeItem TopLeft;
public SodaFakeItem TopRight;
public Animator CurrentAnimator;--------->

	public:
		SodaFakeItem* BottomRight;
		SodaFakeItem* TopLeft;
		SodaFakeItem* TopRight;
		Animator* CurrentAnimator 의 형식으로 public변수끼리, private 변수끼리, public함수끼리 등으로 묶어주십시오.

일체 모든 []형 실례로 public SodaBottle[] SodaBottles;는
std::vector<SodaBottle*> SodaBottles로 바꾸어주십시오.


private Dictionary<MatchType, SodaBottle> _availableBottles;는 
std::map<MatchType, SodaBottle> _availableBottles;로 바꾸어주십시오

ItemType,MatchType,GroupId,Direction,ExplodeReason,TiledEditorId는 enum class이므로 파라메터나 기타 형정의에서 그냥 쓰고
나머지는 오브젝트이므로 지적자형으로 바꾸어주어야합니다.

this.은 모두 this->로 바꾸어야 합니다.

null은 모두 nullptr로 바꾸어야 합니다.

enum class형의 사용을 교정해야 합니다. 실례로 TiledEditorId.SolidColor1은 TiledEditorId::SolidColor1로 써야 합니다.

오브젝트형사용을 고려해야 합니다. 실례로 this.CurrentLevel.CurrentItemGroups[GroupId.Group1].GetRandomItemType();는
this->CurrentLevel->CurrentItemGroups[GroupId::Group1]->GetRandomItemType();로 써야 합니다.

GameObject형, Transform형은 cocos2d::Node*로 치환합니다.
Animator형은 comment하고 Renderer는 cocos2d::Sprite*로 바꿉니다.
그리고 정의부에서는 이 변수관련코드는 // 합니다.

override는 h파일에서만 함수선언 뒤로 가야합니다. 생략하면 안됩니다.

Sorting관련은 함수정의부내부에서만 comment합니다.

AAA as BBB형문법은 dynamic_cast<BBB*>(AAA)로 바꿉니다.

IEnumerator는 이 단어만 comment하고 void형으로 합니다. IEnumerator xxxx... -> /*IEnumerator*/ void xxxx.....
그리고 IEnumertator의 함수 정의부 내부는 모두 comment합니다.

Vector, List, Dictictionary에 특별히 주의해주고 애매한것은 토의합시다.
Vector.Remove함수는 std::vector.erase()로 대치할수 있지만
Vector.RemoveAt함수는 std::vector.erase(std::find(vector.begin(),vector.end(), value));로 대치합니다.

native자료형의 성원변수가 초기값이 없이 선언되였으면 초기값을 주어야 합니다
실례로 private float _x;이면 private: float _x=0.0f;
bool형은 false, int형은 0, float형은 0.0f로 선언합니다.

C#에는 암시적인 오브젝트복사가 없습니다. 따라서 오브젝트의 대입은 .Clone함수를 쓰지 않는 이상 모두 참조변수로 치환하여야 합니다.
실례로 Dictionary<MatchType, Vector2> dictionary = this.SodaBottlePositions5;은
std::map<MatchType, cocos2d::Vec2>& dictionary = this->SodaBottlePositions5;로 바꾸어 씁니다.

배렬순환을 주의하여야합니다.
foreach(KeyValuePair<MatchType, Vector2> current in dictionary)를 for(std::pair<MatchType, cocos2d::Vec2> current : *dictionary)로 바꾸어야 하는데
이때 current에 대한 쓰기조작이 배렬의 변경을 의미하므로 for(std::pair<MatchType, cocos2d::Vec2>& current : *dictionary)로 바꾸어야 합니다.
특히 map에 대하여 순환할때 map의 첫째파라메터는 주키이므로 변경할수 없는 형이며 따라서 const를 붙여서 for(std::pair<const MatchType, cocos2d::Vec2>& current : *dictionary)로 하여야 합니다.

애매한것은 원본행을 수정행뒤에 comment쳐주십시오

애매한것은 철저히 토의하고 넘어가야지 후에 오유를 찾지 못합니다.
