#include "InGameScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "tInput.h"
#include "MainMenuScene.h"
#include "SceneManager.h"
#include "tObject.h"
#include "tTexture.h"
#include "tResources.h"
#include "PlayerScript.h"

namespace t
{
	InGameScene::InGameScene():bg1(nullptr), knight(nullptr)
	{
	}
	InGameScene::~InGameScene()
	{
	}
	void InGameScene::Init()
	{
		/*플레이어 기사가 절벽으로 떨어지는 동영상 먼저(로딩)
		왕의길로 떨어짐
		할로우나이트 배경은 연극의 배경처럼 오브젝트를 때려박은 여러개의 레이어들로 원근감있게 했음
		왕의길에서 나올때 문뿌수고 까만화면(로딩)
		흙의마을로 도착함*/

		bg1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2(0, 0));
		SpriteRenderer* sr1 = bg1->AddComponent<SpriteRenderer>();
		graphics::Texture* tBg1 = Resources::Find<graphics::Texture>(L"IGS_BG");
		sr1->SetTexture(tBg1);
		sr1->SetSize(Vector2(1601.f, 900.0f));


		knight = object::Instantiate<Player>
			(enums::eLayerType::Player, Vector2(250.0f, 550.0f));
		SpriteRenderer* sr2 = knight->AddComponent<SpriteRenderer>();
		knight->AddComponent<PlayerScript>();
		graphics::Texture* tKnight = Resources::Find<graphics::Texture>(L"IGS_Player");
		sr2->SetTexture(tKnight);
		sr2->SetSize(Vector2(sr2->GetTextureSize().x * 0.1f, sr2->GetTextureSize().y * 0.1f));

		
		Scene::Init();
	}
	void InGameScene::Update()
	{
		Scene::Update();
	}
	void InGameScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"MainMenuScene");
		}
	}
	void InGameScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"InGame Scene";
		TextOut(hdc, 0, 0, str, 12);
	}
	void InGameScene::OnEnter()
	{
	}
	void InGameScene::OnExit()
	{
	}
}