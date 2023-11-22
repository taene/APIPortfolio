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
		/*�÷��̾� ��簡 �������� �������� ������ ����(�ε�)
		���Ǳ�� ������
		�ҷο쳪��Ʈ ����� ������ ���ó�� ������Ʈ�� �������� �������� ���̾��� ���ٰ��ְ� ����
		���Ǳ濡�� ���ö� ���Ѽ��� �ȭ��(�ε�)
		���Ǹ����� ������*/

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