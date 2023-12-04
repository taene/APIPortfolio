#pragma once
#include "tEntity.h"

namespace t
{
	class Resource abstract :public Entity	//Resource 추상 클래스
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;	//순수가상함수

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }


	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}