#include "EnemyScript.h"
#include "tTime.h"

namespace t
{
	EnemyScript::EnemyScript()
		:targetTr(nullptr) , enemyTr(nullptr)
		, isDead(false)
		, health(0.0f) , maxHealth(0.0f) , speed(100.0f) , damage(0.0f)
	{}
	EnemyScript::~EnemyScript()
	{}
	void EnemyScript::Init()
	{}
	void EnemyScript::Start()
	{
		enemyTr = GetOwner()->GetComponent<Transform>();
	}
	void EnemyScript::Update()
	{
		follow();
	}
	void EnemyScript::LateUpdate()
	{}
	void EnemyScript::Render(HDC hdc)
	{}
	void EnemyScript::OnCollisionEnter(Collider * other)
	{}
	void EnemyScript::OnCollisionStay(Collider * other)
	{}
	void EnemyScript::OnCollisionExit(Collider * other)
	{}
	void EnemyScript::jump()
	{
		
	}
	void EnemyScript::follow()
	{  
		// 플레이어 위치로 이동
		Vector2 pos = enemyTr->GetPosition();
		Vector2 dirVec = targetTr->GetPosition() - pos;
		pos += dirVec.normalize() * speed * Time::DeltaTime();

		enemyTr->SetPosition(pos);
	}
}