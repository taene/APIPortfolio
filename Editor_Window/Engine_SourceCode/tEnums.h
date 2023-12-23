#pragma once

namespace t::enums
{
	enum class eComponentType
	{
		Transform ,
		Colider ,
		Rigidbody ,
		Script ,
		SpriteRenderer ,
		Animator ,
		Camera ,
		End ,
	};

	enum class eLayerType
	{
		None,
		BackGround1,
		BackGround2,
		MapTile,
		Enemy,
		Player,
		InteractObject,
		PlayerBody,
		PlayerHead,
		Bullet,
		Particle,
		ForeGround1,
		ForeGround2,
		GameSystem,	//체력바 등


		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};

	enum class eColliderType
	{
		None ,
		Circle2D ,
		Rect2D ,
		End ,
	};

	enum class eUIType
	{
		HpBar,
		//Button,
		End,
	};
}