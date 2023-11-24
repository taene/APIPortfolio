#pragma once

namespace t::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
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
		Effects,
		ForeGround1,
		ForeGround2,
		GameSystem,	//ü�¹� ��


		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}