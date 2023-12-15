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

		static Texture* Create(const std::wstring& name , UINT width , UINT height);

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		void SetWidth(UINT width) { mWidth = width; }
		UINT GetHeight() { return mHeight; }
		void SetHeight(UINT height) { mHeight = height; }
		void SetSize(Vector2 size) { mWidth = size.x; mHeight = size.y; }

		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return textureType; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() { return mbAlpha; }

	private:
		bool mbAlpha;
		eTextureType textureType;
		Gdiplus::Image* mImage;	//png
		HBITMAP mBitmap;	//bmp
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
