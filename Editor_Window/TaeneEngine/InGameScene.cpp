#include "InGameScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "tInput.h"
#include "MainMenuScene.h"
#include "SceneManager.h"
#include "tObject.h"

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
		Scene::Init();
		/*플레이어 기사가 절벽으로 떨어지는 동영상 먼저(로딩)
		왕의길로 떨어짐
		할로우나이트 배경은 연극의 배경처럼 오브젝트를 때려박은 여러개의 레이어들로 원근감있게 했음
		왕의길에서 나올때 문뿌수고 까만화면(로딩)
		흙의마을로 도착함*/

		bg1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2(0, 0));
		SpriteRenderer* sr1 = bg1->AddComponent<SpriteRenderer>();
		sr1->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Back Ground Image\\20201106232225_1.jpg");
		sr1->SetSize(Vector2(1600, 900));

		knight = object::Instantiate<Player>
			(enums::eLayerType::Player, Vector2(250.0f, 550.0f));
		SpriteRenderer* sr2 = knight->AddComponent<SpriteRenderer>();
		sr2->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\The Knight\\knight.png");
		sr2->SetSize(Vector2(sr2->GetSize().x * 0.1f, sr2->GetSize().y * 0.1f));
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