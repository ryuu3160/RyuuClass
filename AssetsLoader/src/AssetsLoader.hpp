 /*+===================================================================
	 File: AssetsLoader.hpp
	 Summary: AssetsLoader class header file
	 Author: AT12C192 01 青木雄一郎
	 Date: 03/10.2024 初回作成
			 /10 関数の追加 [IntegerSort]
			 /11 関数の追加 [SetStrArrayData,StringSort]
 ===================================================================+*/
#pragma once
#include <map>
#include <string>

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

template<typename T>
AssetsLoader<T>::AssetsLoader()
{
	m_assets.clear();
}

template<typename T>
AssetsLoader<T>::~AssetsLoader()
{
	m_assets.clear();
}

template<typename T>
void AssetsLoader<T>::Set(T path, std::string name)
{
	//既に同じ名前のアセットが登録されていないか確認
	if (m_assets.count(name) == 0)
	{
		m_assets[name] = path;
	}
}

template<typename T>
T AssetsLoader<T>::Get(std::string FindName) const
{
	return m_assets[FindName];
}
