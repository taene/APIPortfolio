#include "InGameScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

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
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Texture2D\\vheart_title.png");

		//플레이어 기사가 절벽으로 떨어지는 동영상 먼저(로딩)
		//왕의길로 떨어짐
		//할로우나이트 배경은 연극의 배경처럼 오브젝트를 때려박은 여러개의 레이어들로 원근감있게 했음
		//왕의길에서 나올때 문뿌수고 까만화면(로딩)
		//흙의마을로 도착함

		AddGameObject(bg);
	}
	void InGameScene::Update()
	{
		Scene::Update();
	}
	void InGameScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void InGameScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}