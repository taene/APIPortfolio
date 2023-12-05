#pragma once
#include "pch.h"
#include "Component.h"
//#include "Bullet.h"

namespace t::object
{
	void Destory(GameObject* gameObject);
}

namespace t
{
	class GameObject
	{
	public:
		friend void object::Destory(GameObject* obj);

		enum class eState
		{
			Active ,
			Paused ,
			Dead ,
			End
		};

		GameObject();
		~GameObject();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Init();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;
			//mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* i : mComponents)
			{
				component = dynamic_cast<T*>(i);
				if (component)
					break;
			}

			return component;
		}

		eState GetActive() { return mState; }
		void SetActive(bool power)
		{
			if ( power == true ) mState = eState::Active;
			if ( power == false ) mState = eState::Paused;
		}
		bool IsActive() { return mState == eState::Active; }
		bool IsPaused() { return mState == eState::Paused; }
		bool IsDead() { return mState == eState::Dead; }

	private:
		void initTransform();
		void death() { mState = eState::Dead; }

		/*std::vector<Bullet*> &GetBullets()
		{
			for (auto& i : bullets)
			{
				i;
			}
			return bullets;
		}*/

	private:
		eState mState;
		std::vector<Component*> mComponents;
		/*Bullet* bullet;
		std::vector<Bullet*> bullets;*/
	};
}