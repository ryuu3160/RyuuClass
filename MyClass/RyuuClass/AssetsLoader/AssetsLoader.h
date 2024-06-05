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
	 * @brief アセットを記録する
	 * @param path アセットへのパス
	 * @param name そのアセットの名前
	 */
	void Set(T path, std::string name);

	/**
	 * @brief アセットのパスを取得する
	 * @param FindName 検索するアセットの名前
	 * @return アセットへのパス
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
	//既に同じ名前のアセットが登録されていないか確認
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
