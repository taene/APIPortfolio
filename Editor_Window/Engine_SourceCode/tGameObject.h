#pragma once
#include "pch.h"
#include "Component.h"
//#include "Bullet.h"

namespace t
{
	class GameObject
	{
	public:
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
			mComponents.push_back(comp);

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

	private:
		void initTransform();

		/*std::vector<Bullet*> &GetBullets()
		{
			for (auto& i : bullets)
			{
				i;
			}
			return bullets;
		}*/

	private:
		std::vector<Component*> mComponents;
		/*Bullet* bullet;
		std::vector<Bullet*> bullets;*/
	};
}