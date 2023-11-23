#pragma once
#include "tResource.h"

namespace t
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter
				= mResources.find(key);

			//iterator은 없으면 end() 반환함
			if (iter == mResources.end())
				return nullptr;

			// iterator은 부모인 Resource* 형태이고 
			// 가져오는 Find함수의 T*는 자식형태(Texture...)이므로
			// 부모자식간의 형변환을 맞춰주는 dynamic_cast<T*>를 사용한다.
			return dynamic_cast<T*> (iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
				return resource;

			resource = new T();
			if ( FAILED(resource->Load(path)) )
			{
				//여기 들어왔으면 경로를 잘못적은것
				assert(false);
			}

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}