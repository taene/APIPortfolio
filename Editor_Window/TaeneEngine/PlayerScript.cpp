#include "PlayerScript.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "tGameObject.h"

namespace t
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Init()
	{
	}
	void PlayerScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		const float speed = 100.0f;
		
		if (Input::GetKeyPressed(eKeyCode::A) || Input::GetKeyPressed(eKeyCode::Left))
		{
			pos.x -= speed * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKeyPressed(eKeyCode::D) || Input::GetKeyPressed(eKeyCode::Right))
		{
			pos.x += speed * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKeyPressed(eKeyCode::W) || Input::GetKeyPressed(eKeyCode::Up))
		{
			pos.y -= speed * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKeyPressed(eKeyCode::S) || Input::GetKeyPressed(eKeyCode::Down))
		{
			pos.y += speed * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKeyDown(eKeyCode::SpaceBar))
		{
			//// ÃÑ¾Ë ½î±â
			//bullet = new Bullet();
			//bullet->GetPlayerPosition(100 + mX, 100 + mY, 200 + mX, 200 + mY);
			//bullets.push_back(bullet);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}