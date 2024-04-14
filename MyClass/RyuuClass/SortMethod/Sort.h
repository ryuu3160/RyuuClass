/*
 * @file Sort.h
 * @brief ソートプログラムのヘッダ
 * @author 青木雄一郎
 * @date 作成日：03/10.2024
 * 
 * @date 03/10 関数の追加 [IntegerSort]
 * @date 03/11 関数の追加 [SetStrArrayData,StringSort]
 */

#ifndef _____SORT_H_____
#define _____SORT_H_____

namespace RYUU
{
class Sort
{
private:
	int nWidth;	//2次元配列の1列の幅
	int nLine;	//2次元配列の行数
public:
	enum class SORT_MODE : unsigned int
	{
		ASCENDING,	//昇順
		DESCENDING,	//降順
	};

	Sort();	//コンストラクタ
	/**
		* @fn
		* @brief 引数ありコンストラクタ
		* @param [nWidth] 2次元配列の1列の幅
		* @param [nLine] 2次元配列の行数
		* @detail	ソートする文字列型2次元配列の大きさが変わらない場合、コンストラクタで指定しちゃった方が良いかも
		* @memo	このコンストラクタを呼び出した場合は、SetStrArrayData関数を呼び出す必要はない
		*/
	Sort(int nLine, int nWidth);
	~Sort();//デストラクタ

	/**
		* @fn
		* @brief 整数型の配列をソートする
		* @param [*Array] ソートしたい配列名
		* @param [size] 配列の全体サイズ 記入方式:sizeof(配列名)
		* @param [mode] 昇順or降順の指定 記入方式:Sort::SORT_MODE::ASCENDING or DESCENDING
		* @return なし
		* @detail	ソートの方式はシェルソート
		* @memo	配列の要素数は配列のサイズから求めるため、要素数が分からない配列であっても使用可能
		*			要素数を直接引数として渡せないので若干手間がかかる
		*/
	void IntegerSort(int* Array, int size, SORT_MODE mode) const;

	/**
		* @fn
		* @brief 文字列型配列の大きさを設定する
		* @brief StringSort関数を実行する前に必ずこの関数を呼び出すこと
		* @param [size] 2次元配列の全体サイズ 記入方式:sizeof(配列名)
		* @param [width] 2次元配列の1列分の大きさ 記入方式:sizeof(配列名[0])
		* @return なし
		* @detail	StringSortを使用する時は、必ずこの関数を先に呼び出さなくてはならない
		*/
	void SetStrArrayData(int size, int width);

	/**
		* @fn
		* @brief 文字列型の2次元配列をソートする(1行1文とみなす)
		* @brief この関数を呼び出す前に、必ずSetStrArrayData関数を呼び出すこと
		* @param [*Array] 2次元配列へのポインタ 記入方式:配列名[0]
		* @param [mode] 昇順or降順の指定 記入方式:Sort::SORT_MODE::ASCENDING or DESCENDING
		* @return なし
		* @detail	ソートの方式はシェルソート
		* @memo	配列の要素数や列数などは先にSetStrArrayData関数で設定するため、引数として与える必要はない
		*/
	void StringSort(char* Array, SORT_MODE mode) const;

};
}

#endif // !_____SORT_H_____
