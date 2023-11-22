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
	InGameScene::InGameScene()
	{
	}
	InGameScene::~InGameScene()
	{
	}
	void InGameScene::Init()
	{
		//Player* bg = new Player();
		//Transform* tr = bg->AddComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
		//tr->SetName(L"TR");

		//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Texture2D\\vheart_title.png");

		////�÷��̾� ��簡 �������� �������� ������ ����(�ε�)
		////���Ǳ�� ������
		////�ҷο쳪��Ʈ ����� ������ ���ó�� ������Ʈ�� �������� �������� ���̾��� ���ٰ��ְ� ����
		////���Ǳ濡�� ���ö� ���Ѽ��� �ȭ��(�ε�)
		////���Ǹ����� ������

		//AddGameObject(bg,);
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Texture2D\\vheart_title.png");
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