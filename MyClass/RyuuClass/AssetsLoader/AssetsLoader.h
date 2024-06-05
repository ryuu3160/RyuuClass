/**
* @file AssetsLoader.h
 * @brief AssetsLoader class header file
 * @author Ryuu
 * @date 2021/02/14
 */
#pragma once
#include <map>
#include <string>

namespace RYUU
{
template<typename T>
class AssetsLoader
{
public:
	AssetsLoader();
	~AssetsLoader();

	/**
	 * @brief �A�Z�b�g���L�^����
	 * @param path �A�Z�b�g�ւ̃p�X
	 * @param name ���̃A�Z�b�g�̖��O
	 */
	void Set(T path, std::string name);

	/**
	 * @brief �A�Z�b�g�̃p�X���擾����
	 * @param FindName ��������A�Z�b�g�̖��O
	 * @return �A�Z�b�g�ւ̃p�X
	 */
	T Get(std::string FindName) const;

private:
	std::map<std::string, T> m_assets;
};
}

template<typename T>
RYUU::AssetsLoader<T>::AssetsLoader()
{
	m_assets.clear();
}

template<typename T>
RYUU::AssetsLoader<T>::~AssetsLoader()
{
	m_assets.clear();
}

template<typename T>
void RYUU::AssetsLoader<T>::Set(T path, std::string name)
{
	//���ɓ������O�̃A�Z�b�g���o�^����Ă��Ȃ����m�F
	if (m_assets.count(name) == 0)
	{
		m_assets[name] = path;
	}
}

template<typename T>
T RYUU::AssetsLoader<T>::Get(std::string FindName) const
{
	return m_assets[FindName];
}
