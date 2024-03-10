//Sort.h
#ifndef _____SORT_H_____
#define _____SORT_H_____

class SORT
{
public:
	enum class SORT_MODE : unsigned int
	{
		ASCENDING,	//昇順
		DESCENDING,	//降順
	};

	SORT();	//コンストラクタ
	~SORT();//デストラクタ

	/**
	 * @fn
	 * @brief 整数型の配列をソートする
	 * @param [*Array] ソートしたい配列名
	 * @param [size] 配列の全体サイズ 記入方式:sizeof(配列名)
	 * @return なし
	 * @detail	ソートの方式はシェルソート
	 * @memo	配列の要素数は配列のサイズから求めるため、要素数が分からない配列であっても使用可能
	 *			要素数を直接引数として渡せないので若干手間がかかる
	 */
	void IntegerSort(int* Array,int size,SORT_MODE mode) const;

};

#endif // !_____SORT_H_____
