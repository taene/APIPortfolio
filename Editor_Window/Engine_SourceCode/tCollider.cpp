#include "tCollider.h"
#include "tGameObject.h"
#include "Script.h"

namespace t
{
	UINT Collider::CollisionID = 1;

	Collider::Collider(eColliderType type)
		: Component(enums::eComponentType::Colider)
		, mID(CollisionID++)
		, mOffset(Vector2::Zero)
		, mSize(Vector2::One)
		, mType(type)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Init()
	{
	}
	void Collider::Start()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render(HDC hdc)
	{
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(other);
	}
}