#pragma once
#include "tEntity.h"
#include "tGameObject.h"
#include "tObject.h"
#include "Bullet.h" 

namespace t
{
	class BulletPoolManager:public Entity
	{
	public:
		static Bullet* SetBullet()
		{
			Bullet* select = nullptr;
			select = object::Instantiate<Bullet>(enums::eLayerType::Bullet);
			pools.push_back(select);

			return select;
		}

		static Bullet* GetBullet()
		{
			Bullet* select = nullptr;

            // 선택한 풀의 놀고 있는(비활성화 된) 게임 오브젝트 접근
			for ( Bullet* iter : pools )
			{
				if ( !iter->IsActive() )
				{
					// 발견하면 select 변수에 할당
					select = iter;
					select->SetActive(true);
					break;
				}
			}
            // 못 찾았다면
            if ( select == nullptr )
            {
                // 새롭게 생성하고 select 변수에 할당
                /*select = object::Instantiate<GameObject>(enums::eLayerType::Bullet);
				pools.push_back(select);*/
				select = select = object::Instantiate<Bullet>(enums::eLayerType::Bullet);
				pools.push_back(select);
            }
            return select;
		}

	public:
		static std::vector<Bullet*> pools;
	};
}