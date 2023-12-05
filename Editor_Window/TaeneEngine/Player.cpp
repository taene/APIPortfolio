#include "Player.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "tObject.h"
#include "tTexture.h"
#include "tResources.h"
#include "tAnimator.h"
#include "SpriteRenderer.h"

namespace t
{
	void Player::Init()
	{
		GameObject::Init();

		createHeadAnimation();
		createBodyAnimation();
	}

	void Player::Update()
	{
		GameObject::Update();

		/*bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1 , Vector2::Zero);
		graphics::Texture* bgT = Resources::Find<graphics::Texture>(L"LS_StartMenu");
		Animator* bgAni = bg->AddComponent<Animator>();
		Transform* bgTr = bg->GetComponent<Transform>();
		bgTr->SetScale(Vector2(3.0f , 3.0f));
		bgAni->CreateAnimation(L"StartMenu" , bgT
			, Vector2(0.0f , 0.0f) , Vector2(480.0f , 272.0f) ,
			Vector2(bgTr->GetPosition().x / 2.0f , bgTr->GetPosition().y / 2.0f) , 40 , 0.05f);
		bgAni->PlayAnimation(L"StartMenu");*/

		/*GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1 , Vector2(0 , 0));
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* bgT = Resources::Find<graphics::Texture>(L"MMS_Bg");
		bgSr->SetTexture(bgT);
		bgSr->SetSize(Vector2(bgSr->GetTextureSize().x * 3.0f , bgSr->GetTextureSize().y * 3.0f));*/

		head = object::Instantiate<GameObject>(enums::eLayerType::Player , Vector2::Zero);
		SpriteRenderer* headSr = head->AddComponent<SpriteRenderer>();
		graphics::Texture* headIdleT = nullptr;
		headIdleT->SetTextureAtSpriteSheet( Resources::Find<graphics::Texture>(L"MMS_Bg") , index번호 , vector size , spriteLength,);

		headSr->SetTexture(headIdleT);
		Transform* headTr = head->GetComponent<Transform>();
		//headTr->SetScale(Vector2(3.0f , 3.0f));

		
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Player::createHeadAnimation()
	{
		graphics::Texture* headDownT = Resources::Find<graphics::Texture>(L"Player_HeadDown");
		Animator* headAni = head->AddComponent<Animator>();
		Transform* headTr = head->GetComponent<Transform>();

		headAni->CreateAnimation(L"HeadDown" , headDownT
			, Vector2(0.0f , 0.0f) , Vector2(480.0f , 272.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 40 , 0.05f);
		//headAni->PlayAnimation(L"HeadDown");
	}
	void Player::createBodyAnimation()
	{
	
	}
}
