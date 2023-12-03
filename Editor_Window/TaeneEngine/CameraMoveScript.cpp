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

	void CameraMoveScript::Update()
	{
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();

		//const float speed = 200.0f;

		//if (Input::GetKeyPressed(eKeyCode::A))
		//{
		//	pos.x -= speed * Time::DeltaTime();
		//	//tr->SetPosition(pos);
		//}
		//if (Input::GetKeyPressed(eKeyCode::D))
		//{
		//	pos.x += speed * Time::DeltaTime();
		//	//tr->SetPosition(pos);
		//}
		//if (Input::GetKeyPressed(eKeyCode::W))
		//{
		//	pos.y -= speed * Time::DeltaTime();
		//	//tr->SetPosition(pos);
		//}
		//if (Input::GetKeyPressed(eKeyCode::S))
		//{
		//	pos.y += speed * Time::DeltaTime();
		//	//tr->SetPosition(pos);
		//}
		//tr->SetPosition(pos);

	}

	void CameraMoveScript::LateUpdate()
	{
	}

	void CameraMoveScript::Render(HDC hdc)
	{
	}

}