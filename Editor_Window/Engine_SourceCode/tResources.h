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

			//iterator�� ������ end() ��ȯ��
			if (iter == mResources.end())
				return nullptr;

			// iterator�� �θ��� Resource* �����̰� 
			// �������� Find�Լ��� T*�� �ڽ�����(Texture...)�̹Ƿ�
			// �θ��ڽİ��� ����ȯ�� �����ִ� dynamic_cast<T*>�� ����Ѵ�.
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
				//���� �������� ��θ� �߸�������
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