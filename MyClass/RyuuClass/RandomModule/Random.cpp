//Random.cpp
#include "Random.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <string>

RANDOM::RANDOM(void)
{
	this->nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->nSeed);
}

RANDOM::RANDOM(unsigned int nSeed)
{
	this->nSeed = nSeed;
	srand(this->nSeed);
}

RANDOM::~RANDOM(void)
{
	
}

void RANDOM::SetSeedTime(void)
{
	this->nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->nSeed);
}

void RANDOM::SetSeed(unsigned int nSeed)
{
	this->nSeed = nSeed;
	srand(this->nSeed);
}

unsigned int RANDOM::GetSeed(void) const
{
	return this->nSeed;
}

int RANDOM::RandomInt(int nMax, bool bIncludeZero) const
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

	//�������ő�l�Ŋ������]���nInZero�𑫂�
	return rand() % nMax + nInZero;
}

int RANDOM::RandomIntRange(int nMax, int nMin) const
{
	nMax++;
	nMax -= nMin;

	//�ő�l��+1�������̂���ŏ��l�������A����ŗ������������]��ɍŏ��l�𑫂�
	return rand() % nMax + nMin;
}

float RANDOM::RandomFloat(int nMax, int nPointPos, bool bIncludeZero) const
{
	float fRandom;
	int nSetPointPos;
	int nVal;
	int nInZero;

	//10���A�\�������������̈ʂ����ݏ悵�����l
	nSetPointPos = static_cast<int>(pow(10, nPointPos));
	//�ő�l�̌��𑝂₷
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

	//�������ő�l�Ŋ������]���nInZero�𑫂��āA�����_�����炷
	fRandom = static_cast<float>(rand() % nVal + nInZero);
	fRandom /= nSetPointPos;

	return fRandom;
}

float RANDOM::RandomFloatRange(int nMax, int nMin, int nPointPos) const
{
	float fRandom;
	int nSetPointPos;
	int nMaxVal;
	int nMinVal;

	//10���A�\�������������̈ʂ����ݏ悵�����l
	nSetPointPos = static_cast<int>(pow(10, nPointPos));

	//�ő�l�A�ŏ��l�̌��𑝂₷
	nMaxVal = nMax * nSetPointPos;
	nMinVal = nMin * nSetPointPos;

	//�ő�l��+1�����Ƃ��납��A�ŏ��l������
	nMaxVal++;
	nMaxVal -= nMinVal;

	//�������ő�l����ŏ��l���������l�Ŋ������]��ɍŏ��l�𑫂��āA�����_�̈ʒu�����炷
	fRandom = static_cast<float>(rand() % nMaxVal + nMinVal);
	fRandom /= nSetPointPos;

	return fRandom;
}

void RANDOM::RandomChoice(char* pszInput, ...) const
{
	int nRandom;
	int nCount = 0;
	int nPrint = 0;
	int i;
	int nLength = 0;
	char* szInputElement;

	szInputElement = new char[256];//�z��m��

	va_list args, args2,args3;
	va_start(args, pszInput);
	va_copy(args2, args);
	va_copy(args3, args);

	//���͂��ꂽ������̃J�E���g
	while (true)
	{
		if (va_arg(args, int) != NULL)
			nCount++;
		else
			break;
	}
	va_end(args);

	//���͂��ꂽ��������255�����ȉ����̔���
	for (i = 0; i < nCount; i++)
	{
		if (strlen(va_arg(args2, const char*)) > 255)
		{
			strcpy_s(pszInput, 6, "error");
			return;
		}
	}
	va_end(args2);

	//�Ԃ�������̔ԍ�����
	nRandom = rand() % nCount + 1;

	//�Ԃ�����������i�[
	for (i = 0; i < nRandom; i++)
	{
		strcpy_s(szInputElement, 256, va_arg(args3, const char*));
	}

	szInputElement[255] = '\0';

	va_end(args3);

	//�������������n���ꂽchar�^�z��Ɋi�[
	nLength = static_cast<int>(strlen(szInputElement)) + 1;
	strncpy_s(pszInput, nLength, szInputElement, nLength);

	delete[] szInputElement;//�������J��
}