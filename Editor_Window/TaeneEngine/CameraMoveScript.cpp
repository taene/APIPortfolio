#include "CameraMoveScript.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "tGameObject.h"

namespace t
{
	CameraMoveScript::CameraMoveScript()
	{
	}

	CameraMoveScript::~CameraMoveScript()
	{
	}

	void CameraMoveScript::Init()
	{
	}

	void CameraMoveScript::Start()
	{
	}

	void CameraMoveScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if ( Input::GetKeyPressed(eKeyCode::Right) )
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		if ( Input::GetKeyPressed(eKeyCode::Left) )
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if ( Input::GetKeyPressed(eKeyCode::Up) )
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		if ( Input::GetKeyPressed(eKeyCode::Down) )
		{
			pos.y += 300.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

	}

	void CameraMoveScript::LateUpdate()
	{
	}

	void CameraMoveScript::Render(HDC hdc)
	{
	}

}