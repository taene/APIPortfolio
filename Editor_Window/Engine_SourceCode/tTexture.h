#pragma once
#include "tResource.h"

namespace t::graphics
{
	class Texture :public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return textureType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType textureType;
		Gdiplus::Image* mImage;	//png
		HBITMAP mBitmap;	//bmp
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
