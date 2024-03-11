//Sort.cpp
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SORT::SORT(void)
{

}

SORT::~SORT(void)
{

}

void SORT::IntegerSort(int* Array,int size,SORT_MODE mode) const
{
	int i,j;	//添え字
	int nTmp;	//データ一時保存場所
	int nGap;	//ギャップ
	int roop;	//要素数
	int nTop;	//未整列部の先頭要素添え字
	int* TmpArray;	//全データの一時保存場所

	roop = size / static_cast<int>(sizeof(*Array));//要素数

	TmpArray = new int[roop];//配列確保

	nGap = 1;
	j = 0;
	nTmp = 0;

	//ワークスペースにデータを格納
	for (i = 0; i < roop; i++)
	{
		TmpArray[i] = Array[i];
	}

	//ギャップを設定
	while (nGap * 3 + 1 <= roop)
	{
		nGap = nGap * 3 + 1;
	}
	
	while (nGap > 0)	//整列ループ
	{
		for (i = 0; i < nGap; i++)	//挿入法ループ
		{
			nTop = nGap + i;	//未整列部の先頭要素の添え字
			while (nTop < roop)	//整列処理
			{
				j = nTop;
				while (j >= nGap && TmpArray[j - nGap] < TmpArray[j])	//挿入処理
				{
					nTmp = TmpArray[j];
					TmpArray[j] = TmpArray[j - nGap];
					TmpArray[j - nGap] = nTmp;
					j -= nGap;
				}
				nTop += nGap;
			}
		}
		nGap /= 3;
	}

	switch (mode)
	{
	case SORT_MODE::ASCENDING:
		for (i = 0; i < roop; i++)
		{
			Array[roop - i] = TmpArray[i];
		}
		break;
	case SORT_MODE::DESCENDING:
		for (i = 0; i < roop; i++)
		{
			Array[i] = TmpArray[i];
		}
		break;
	}

	delete[] TmpArray;//解放
}