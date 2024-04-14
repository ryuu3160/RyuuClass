//Random.cpp
#include "Random.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <string>

namespace RYUU
{

Random::Random(void)
{
	this->nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->nSeed);
}

Random::Random(unsigned int nSeed)
{
	this->nSeed = nSeed;
	srand(this->nSeed);
}

Random::~Random(void)
{
	
}

void Random::SetSeedTime(void)
{
	this->nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->nSeed);
}

void Random::SetSeed(unsigned int nSeed)
{
	this->nSeed = nSeed;
	srand(this->nSeed);
}

unsigned int Random::GetSeed(void) const
{
	return this->nSeed;
}

int Random::RandomInt(int nMax, bool bIncludeZero) const
{
	int nInZero;

	if (bIncludeZero)
	{
		nInZero = 0;
		nMax++;
	}
	else
	{
		nInZero = 1;
	}

	//乱数を最大値で割った余りにnInZeroを足す
	return rand() % nMax + nInZero;
}

int Random::RandomIntRange(int nMax, int nMin) const
{
	nMax++;
	nMax -= nMin;

	//最大値を+1したものから最小値を引き、それで乱数を割った余りに最小値を足す
	return rand() % nMax + nMin;
}

float Random::RandomFloat(int nMax, int nPointPos, bool bIncludeZero) const
{
	float fRandom;
	int nSetPointPos;
	int nVal;
	int nInZero;

	//10を、表示したい少数の位だけ累乗した数値
	nSetPointPos = static_cast<int>(pow(10, nPointPos));
	//最大値の桁を増やす
	nVal = nMax * nSetPointPos;

	if (bIncludeZero)
	{
		nInZero = 0;
		nVal++;
	}
	else
	{
		nInZero = 1;
	}

	//乱数を最大値で割った余りにnInZeroを足して、小数点をずらす
	fRandom = static_cast<float>(rand() % nVal + nInZero);
	fRandom /= nSetPointPos;

	return fRandom;
}

float Random::RandomFloatRange(int nMax, int nMin, int nPointPos) const
{
	float fRandom;
	int nSetPointPos;
	int nMaxVal;
	int nMinVal;

	//10を、表示したい少数の位だけ累乗した数値
	nSetPointPos = static_cast<int>(pow(10, nPointPos));

	//最大値、最小値の桁を増やす
	nMaxVal = nMax * nSetPointPos;
	nMinVal = nMin * nSetPointPos;

	//最大値を+1したところから、最小値を引く
	nMaxVal++;
	nMaxVal -= nMinVal;

	//乱数を最大値から最小値を引いた値で割った余りに最小値を足して、小数点の位置をずらす
	fRandom = static_cast<float>(rand() % nMaxVal + nMinVal);
	fRandom /= nSetPointPos;

	return fRandom;
}

void Random::RandomChoice(char* pszInput, ...) const
{
	int nRandom;
	int nCount = 0;
	int nPrint = 0;
	int i;
	int nLength = 0;
	char* szInputElement;

	szInputElement = new char[256];//配列確保

	va_list args, args2,args3;
	va_start(args, pszInput);
	va_copy(args2, args);
	va_copy(args3, args);

	//入力された文字列のカウント
	while (true)
	{
		if (va_arg(args, int) != NULL)
			nCount++;
		else
			break;
	}
	va_end(args);

	//入力された文字数が255文字以下かの判定
	for (i = 0; i < nCount; i++)
	{
		if (strlen(va_arg(args2, const char*)) > 255)
		{
			strcpy_s(pszInput, 6, "error");
			return;
		}
	}
	va_end(args2);

	//返す文字列の番号決め
	nRandom = rand() % nCount + 1;

	//返す文字列を仮格納
	for (i = 0; i < nRandom; i++)
	{
		strcpy_s(szInputElement, 256, va_arg(args3, const char*));
	}

	szInputElement[255] = '\0';

	va_end(args3);

	//文字数分だけ渡されたchar型配列に格納
	nLength = static_cast<int>(strlen(szInputElement)) + 1;
	strncpy_s(pszInput, nLength, szInputElement, nLength);

	delete[] szInputElement;//メモリ開放
}

}