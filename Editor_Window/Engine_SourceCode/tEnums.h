#pragma once

namespace t::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround1,
		BackGround2,
		BackGround3,
		BackGround4,
		MapTile,
		InteractObject,
		Enemy,
		Player,
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
}