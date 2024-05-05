/*
 * @file Random.h
 * @brief ランダムモジュールプログラムのヘッダ
 * @author 青木雄一郎
 * @date 作成日：03/17.2024
 *
 * @date 03/10 関数の追加 [IntegerRandom]
 */
#pragma once

#include <string>
#include <initializer_list>

namespace RYUU
{
class Random
{
private:
	unsigned int m_nSeed;

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
	float GetDecimalRange(int nMax, int nMin, int nPointPos) const;

	/**
	 * @fn
	 * @brief 引数として与えた複数の文字列をランダムで1つを返す
	 * @param [...args] 複数の引数を指定可能、文字列を与えられることを想定している
	 * @return std::string型
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 * @memo 引数に文字列以外を渡すとエラーになる
	 */
	template<typename ...A>
	std::string Choice(A... args) const;
};

//Random.Choiceの定義
template<typename ...A>
std::string Random::Choice(A... args) const
{
	int nRandom;
	int nCount = 0;
	int i;
	std::string ssReturn;

	//引数のカウント
	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		nCount++;
	}

	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		if (ss.size() >= ss.max_size())
		{
			ssReturn = "error";
			return ssReturn;
		}
	}

	//返す文字列の番号決め
	nRandom = rand() % nCount + 1;

	i = 1;//カウンタ

	for (std::string ss : std::initializer_list<std::string>{args...})
	{
		if (nRandom == i)
		{
			ssReturn = ss;
			return ssReturn;
		}
		i++;
	}

	return ssReturn;
}

}