/*
 * @file Random.h
 * @brief ランダムモジュールプログラムのヘッダ
 * @author 青木雄一郎
 * @date 作成日：03/17.2024
 *
 * @date 03/10 関数の追加 [IntegerRandom]
 */
#ifndef _____RANDOM_MODULE_H_____
#define _____RANDOM_MODULE_H_____

class RANDOM
{
private:
	unsigned int nSeed;

public:

	/**
	 * @fn
	 * @brief 引数なしコンストラクタ
	 * @brief 呼び出し時の時間がシード値として記録される
	 * @detail	シード値を特に決めない場合はこのコンストラクタを使用する
	 */
	RANDOM();
	/**
	 * @fn
	 * @brief 引数ありコンストラクタ
	 * @brief 引数がシード値として記録される
	 * @detail	シード値を指定したい場合はこのコンストラクタを使用する
	 */
	RANDOM(unsigned int nSeed);

	~RANDOM();//デストラクタ

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
	int RandomInt(int nMax, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief 指定範囲で整数値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大値
	 * @param [nMin] 生成する乱数の最小値
	 * @return 生成した乱数をint型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	int RandomIntRange(int nMax, int nMin) const;

	/**
	 * @fn
	 * @brief 小数値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大整数値
	 * @param [nPointPos] 生成する乱数の小数点位置 | 例：小数点第1位 → 1 | 第2位 → 2
	 * @param [bIncludeZero] 生成する乱数の最小値が0かを指定(true:0 | false:1)
	 * @return 生成した乱数をfloat型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	float RandomFloat(int nMax, int nPointPos, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief 指定範囲で小数点値の乱数を生成する
	 * @param [nMax] 生成する乱数の最大値
	 * @param [nMin] 生成する乱数の最小値
	 * @param [nPointPos] 生成する乱数の小数点位置 | 例：小数点第1位 → 1 | 第2位 → 2
	 * @return 生成した乱数をfloat型で返す
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 */
	float RandomFloatRange(int nMax, int nMin, int nPointPos) const;

	/**
	 * @fn
	 * @brief 引数として与えた複数の文字列をランダムで1つchar型配列に格納
	 * @param [pszInput] 選ばれた文字列を受け取る為のchar型配列名※配列の大きさは255 + 1まで
	 * @param [...] 複数の引数を指定可能、文字列を与えられることを想定している
	 * @param 最後に必ずNULLを引数として渡す(例はプロトタイプ宣言のコメントを参照)
	 * @detail シード値は必ず設定されているので、この関数が失敗することは無い
	 *
	 *			使用例：int main(void)
	 *					{
	 *						char szTest[255 + 1];
	 *						random_choice(szTest,"テスト1","テスト2","テスト3",NULL);
	 *					}
	 */
	void RandomChoice(char* pszInput, ...) const;
};

#endif // !_____RANDOM_MODULE_H_____