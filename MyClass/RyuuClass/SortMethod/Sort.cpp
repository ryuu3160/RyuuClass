//Sort.cpp
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace RYUU
{
//コンストラクタ
Sort::Sort(void)
{
	nWidth = 0;
	nLine = 0;
}

//コンストラクタ2
Sort::Sort(int nLine,int nWidth)
{
	this->nLine = nLine;
	this->nWidth = nWidth;
}

//デストラクタ
Sort::~Sort(void)
{

}

void Sort::IntegerSort(int* Array,int size,SORT_MODE mode) const
{
	int i,j;	//添え字
	int nTmp;	//データ一時保存場所
	int nGap;	//ギャップ
	int roop;	//要素数
	int nTop;	//未整列部の先頭要素添え字
	int* TmpArray;	//全データの一時保存場所

	roop = size / static_cast<int>(sizeof(*Array));//要素数

	TmpArray = new int[roop];//配列確保

	//値の初期化
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

	//ソート後の値を引数として渡された配列に格納
	switch (mode)
	{
	case SORT_MODE::ASCENDING://昇順
		for (i = 0; i < roop; i++)
		{
			Array[roop - i] = TmpArray[i];
		}
		break;
	case SORT_MODE::DESCENDING://降順
		for (i = 0; i < roop; i++)
		{
			Array[i] = TmpArray[i];
		}
		break;
	}

	delete[] TmpArray;//メモリ解放
	TmpArray = nullptr;
}

void Sort::SetStrArrayData(int nSize, int nWidth)
{
	this->nWidth = nWidth;
	this->nLine = nSize / nWidth;
}

void Sort::StringSort(char* Array, SORT_MODE mode) const
{
	int i,j;	//添え字
	int nGap;	//ギャップ
	int nTop;	//未整列部の先頭添え字
	int nDigit; //文字の桁
	char* szTmp;//データ一時保存場所
	char* szpKeep;//ポインターキープ
	char** szTmpArray;//全データ一時保存場所

	//2次元配列の確保
	szTmpArray = new char*[nLine];
	for (i = 0; i < nLine; i++)
	{
		szTmpArray[i] = new char[nWidth];
	}
	//配列確保
	szTmp = new char[nWidth];

	//作業スペースへの格納
	for (i = 0, szpKeep = Array; i < nLine; i++,szpKeep += nWidth)
	{
		strcpy_s(szTmpArray[i],nWidth, szpKeep);
		szTmpArray[i][nWidth - 1] = '\0';
	}

	//値の初期化
	nGap = 1;
	j = 0;
	nDigit = 0;

	//ギャップを設定
	while (nGap * 3 + 1 <= nLine)
	{
		nGap = nGap * 3 + 1;
	}

	while (nGap > 0)	//整列ループ
	{
		for (i = 0; i < nGap; i++)	//挿入法ループ
		{
			nTop = nGap + i;	//未整列部の先頭要素の添え字
			while (nTop < nLine)	//整列処理
			{
				j = nTop;
				while (szTmpArray[j - nGap][nDigit] == szTmpArray[j][nDigit] && nDigit < nWidth - 1)//n文字目が同じ文字だった場合、次の文字を比較
				{
					nDigit++;
				}
				while (j >= nGap && szTmpArray[j - nGap][nDigit] < szTmpArray[j][nDigit])	//挿入処理
				{
					strcpy_s(szTmp, nWidth, szTmpArray[j]);
					strcpy_s(szTmpArray[j], nWidth, szTmpArray[j - nGap]);
					strcpy_s(szTmpArray[j - nGap], nWidth, szTmp);
					j -= nGap;
				}
				nTop += nGap;
				nDigit = 0;//比較文字位置を先頭にリセット
			}
		}
		nGap /= 3;
	}

	switch (mode)
	{
	case SORT_MODE::ASCENDING://昇順
		for (i = 0; i < nLine; i++, Array += nWidth)
		{
			strcpy_s(Array, nWidth, szTmpArray[nLine - i - 1]);
		}
		break;
	case SORT_MODE::DESCENDING://降順
		for (i = 0; i < nLine; i++, Array += nWidth)
		{
			strcpy_s(Array, nWidth, szTmpArray[i]);
		}
		break;
	}

	//メモリ解放
	for (i = 0; i < nLine; i++)
	{
		delete[] szTmpArray[i];
		szTmpArray[i] = nullptr;//ヌルポ
	}
	delete[] szTmpArray;
	szTmpArray = nullptr;//ヌルポ
	delete[] szTmp;
	szTmp = nullptr;//ヌルポ
	szpKeep = nullptr;//ヌルポ
}

}