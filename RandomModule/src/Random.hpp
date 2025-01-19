 /*+===================================================================
	 File: Random.hpp
	 Summary: ランダムモジュールプログラムのヘッダ
	 Author: AT12C192 01 青木雄一郎
	 Date: 03/17.2024 初回作成
 ===================================================================+*/
#pragma once

#include <string>
#include <vector>
#include <list>
#include <initializer_list>
#include <random>
#include <debugapi.h>

class Random
{
public:

	/**
	 * @fn
	 * @brief 引数なしコンストラクタ
	 * @brief 呼び出し時の時間がシード値として記録される
	 * @detail	シード値を特に決めない場合はこのコンストラクタを使用する
	 */
	Random();
	/**
	 * @fn
	 * @brief 引数ありコンストラクタ
	 * @brief 引数がシード値として記録される
	 * @detail	シード値を指定したい場合はこのコンストラクタを使用する
	 */
	Random(unsigned int nSeed);

	~Random();//デストラクタ

	/**
	 * @brief メルセンヌ・ツイスタ―の有効化
	 * @param  無し
	 */
	void enableMT(void);

	/**
	 * @brief メルセンヌ・ツイスタ―の無効化
	 * @param  無し
	 */
	void disableMT(void);

	/**
	 * @fn
	 * @brief 呼び出し時の時間を使用してシード値を設定する
	 * @return なし
	 * @detail　設定したシード値はメンバ変数nSeedに記録される
	 */
	void SetSeedTime(void);

	/**
	 * @fn
	 * @brief 引数を使用してシード値を設定する
	 * @param [nSeed] 設定したい整数値
	 * @return なし
	 * @detail　設定したシード値はメンバ変数nSeedに記録される
	 */
	void SetSeed(unsigned int nSeed);

	/**
	 * @fn
	 * @brief 呼び出し時に設定されているシード値を表示する
	 * @return unsigned int型の数値
	 * @detail　メンバ変数nSeedに記録されている値を返す
	 */
	unsigned int GetSeed(void) const;

	/**
	 * @fn
	 * @brief 整数値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大値
	 * @param [bIncludeZero] 生成する乱数の最小値が0かを指定(true:0 | false:1)
	 * @return 生成した乱数をint型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	int GetInteger(int nMax, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief 指定範囲で整数値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大値
	 * @param [nMin] 生成する乱数の最小値
	 * @return 生成した乱数をint型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	int GetIntegerRange(int nMax, int nMin) const;

	/**
	 * @fn
	 * @brief 小数値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大整数値
	 * @param [nPointPos] 生成する乱数の小数点位置 | 例：小数点第1位 → 1 | 第2位 → 2
	 * @param [bIncludeZero] 生成する乱数の最小値が0かを指定(true:0 | false:1)
	 * @return 生成した乱数をfloat型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	float GetDecimal(int nMax, int nPointPos, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief 指定範囲で小数点値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大値
	 * @param [nMin] 生成する乱数の最小値
	 * @param [nPointPos] 生成する乱数の小数点位置 | 例：小数点第1位 → 1 | 第2位 → 2
	 * @return 生成した乱数をfloat型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	float GetDecimalRange(float fMax, float fMin, int fPointPos) const;

	/**
	 * @fn
	 * @brief 与えた複数の文字列からランダムで1つを返す
	 * @param [...args] 複数の引数を指定可能、文字列を与えられることを想定している
	 * @return std::string型
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 * @memo 引数に文字列以外を渡すとエラーになる
	 */
	template<typename ...A>
	std::string Choice(A... args) const;

	/**
	 * @brief 複数のデータが格納されたvectorからランダムで1つを返す
	 * @tparam T vectorの型名
	 * @param aray vectorの変数名
	 * @return vectorの型と同じ型
	 */
	template<typename T>
	T Choice(const std::vector<T>& aray) const;

	/**
	 * @brief 複数のデータが格納されたvectorからランダムで1つを返す
	 * @tparam T vectorの型名
	 * @param aray vectorの変数名
	 * @return vectorの型と同じ型
	 */
	template<typename T>
	T Choice(const std::list<T>& aray) const;

	/**
	 * @brief 引数で与えたvectorのデータからランダムに複数の要素を選択してvectorとして返す
	 * @brief 要素の重複はない
	 * @tparam T 渡すvectorの型名
	 * @param &aray vectorの変数名
	 * @param num 取得したい要素の個数
	 * @return vectorクラス
	 * @memo 取得する要素数は元のvectorの要素数より大きくすることは出来ない
	 */
	template<typename T>
	std::vector<T> Sample(const std::vector<T> &aray, int num) const;

	/**
	 * @brief 引数で与えたlistのデータからランダムに複数の要素を選択してlistとして返す
	 * @brief 要素の重複はない
	 * @tparam T 渡すlistの型名
	 * @param &aray listの変数名
	 * @param num 取得したい要素の個数
	 * @return listクラス
	 * @memo 取得する要素数は元のvectorの要素数より大きくすることは出来ない
	 */
	template<typename T>
	std::list<T> Sample(const std::list<T>& aray, int num) const;

	/**
	 * @brief 引数で与えたvectorのデータからランダムに複数の要素を選択してvectorとして返す
	 * @brief 要素の重複あり
	 * @tparam T 渡すvectorの型名
	 * @param &aray vectorの変数名
	 * @param k 取得する要素数
	 * @return vectorクラス
	 * @memo 取得する要素数は元のvectorの要素数より大きくすることが出来る
	 */
	template<typename T>
	std::vector<T> Choices(const std::vector<T>& aray, int k) const;

	/**
	 * @brief 引数で与えたlistのデータからランダムに複数の要素を選択してlistとして返す
	 * @brief 要素の重複あり
	 * @tparam T 渡すlistの型名
	 * @param &aray listの変数名
	 * @param k 取得する要素数
	 * @return listクラス
	 * @memo 取得する要素数は元のvectorの要素数より大きくすることが出来る
	 */
	template<typename T>
	std::list<T> Choices(const std::list<T>& aray, int k) const;

	private:
		unsigned int m_nSeed;
		bool m_bMT;//メルセンヌツイスターを使用するか
		std::random_device* m_rd;//非決定的な乱数生成
		std::mt19937* m_mt;//メルセンヌツイスター
		std::uniform_real_distribution<float>* m_dist;//一様分布生成器
};




//Random.Choiceの定義
template<typename ...A>
std::string Random::Choice(A... args) const
{
	int nRandom;
	int nCount = 0;
	int i;
	std::string strReturn;

	//引数のカウント
	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		nCount++;
	}

	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		if (ss.size() >= ss.max_size())
		{
			strReturn = "error";
			return strReturn;
		}
	}

	//返す文字列の番号決め
	if (m_bMT)
	{
		nRandom = static_cast<int>((*m_dist)(*m_mt)) % nCount + 1;
	}
	else
	{
		nRandom = rand() % nCount + 1;
	}

	i = 1;//カウンタ

	for (std::string ss : std::initializer_list<std::string>{args...})
	{
		if (nRandom == i)
		{
			strReturn = ss;
			return strReturn;
		}
		i++;
	}

	return strReturn;
}

//Random.Choiceの定義(vector)
template<typename T>
T Random::Choice(const std::vector<T>& aray) const
{
	T put;
	int nRandom;
	int nCount = 0;

	//要素がない場合のエラー
	if (aray.empty())
	{
		put = -1;
	}

	//返す文字列の番号決め
	if (m_bMT)
	{
		nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
	}
	else
	{
		nRandom = rand() % aray.size();
	}

	put = aray[nRandom];

	return put;
}

//Random.Choiceの定義(list)
template<typename T>
T Random::Choice(const std::list<T>& aray) const
{
	T put;
	int nRandom;
	int nCount = 0;
	auto itr = aray.begin();

	//要素がない場合のエラー
	if (aray.empty())
	{
		put = -1;
	}

	//返す文字列の番号決め
	if (m_bMT)
	{
		nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
	}
	else
	{
		nRandom = rand() % aray.size();
	}

	for (int i = 0; i < nRandom; i++)
	{
		itr++;
	}
	put = *itr;

	return put;
}

//Random.Sampleの定義(vector)
template<typename T>
std::vector<T> Random::Sample(const std::vector<T> &aray, int num) const
{
	std::vector<T> sample;
	std::vector<int> Already;
	int nRandom;	//プッシュするデータの要素番号
	int nPushCount = 0;
	bool bPush = true;

	//要素数が配列のサイズよりも大きい場合のエラー
	if (aray.size() < num)
	{
		OutputDebugStringA("error : Too many elements to retrieve");
		sample.clear();
		return sample;
	}

	//プッシュ処理
	while (nPushCount < num)
	{
		//乱数生成
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}

		//重複排除
		for (int i = 0; i < Already.size(); i++)
		{
			if (Already[i] == nRandom)
			{
				bPush = false;
				break;
			}
			else
			{
				bPush = true;
			}
		}

		//値の挿入
		if (bPush)
		{
			sample.push_back(aray[nRandom]);
			Already.push_back(nRandom);
			nPushCount++;
		}
	}

	return sample;
}

//Random.Sampleの定義(list)
template<typename T>
std::list<T> Random::Sample(const std::list<T>& aray, int num) const
{
	std::list<T> sample;
	std::vector<int> Already;
	int nRandom;	//プッシュするデータの要素番号
	int nPushCount = 0;
	bool bPush = true;

	//要素数が配列のサイズよりも大きい場合のエラー
	if (aray.size() < num)
	{
		OutputDebugStringA("error : Too many elements to retrieve");
		sample.clear();
		return sample;
	}

	//プッシュ処理
	while (nPushCount < num)
	{
		//乱数生成
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}

		//重複排除
		for (int i = 0; i < Already.size(); i++)
		{
			if (Already[i] == nRandom)
			{
				bPush = false;
				break;
			}
			else
			{
				bPush = true;
			}
		}

		//値の挿入
		if (bPush)
		{
			auto itr = aray.begin();
			for (int i = 0; i < nRandom; i++)
			{
				itr++;
			}
			sample.push_back(*itr);
			Already.push_back(nRandom);
			nPushCount++;
		}
	}

	return sample;
}

//Random.Choicesの定義(vector)
template<typename T>
std::vector<T> Random::Choices(const std::vector<T>& aray, int k) const
{
	std::vector<T> choices;
	int nRandom;	//プッシュするデータの要素番号

	//プッシュ処理
	for (int i = 0;i < k;i++)
	{
		//乱数生成
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}
		//プッシュ
		choices.push_back(aray[nRandom]);
	}

	return choices;
}

//Random.Choicesの定義(list)
template<typename T>
std::list<T> Random::Choices(const std::list<T>& aray, int k) const
{
	std::list<T> choices;
	int nRandom;	//プッシュするデータの要素番号

	//プッシュ処理
	for (int i = 0; i < k; i++)
	{
		//先頭イテレーター取得
		auto itr = aray.begin();
		//乱数生成
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}

		for (int j = 0; j < nRandom; j++)
		{
			itr++;
		}
		//プッシュ
		choices.push_back(*itr);
	}
	return choices;
}
