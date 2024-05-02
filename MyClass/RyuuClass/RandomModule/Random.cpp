//Random.cpp
#include "Random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <string>

namespace RYUU
{

Random::Random(void)
{
	this->m_nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->m_nSeed);
}

Random::Random(unsigned int nSeed)
{
	this->m_nSeed = nSeed;
	srand(this->m_nSeed);
}

Random::~Random(void)
{
	
}

void Random::SetSeedTime(void)
{
	this->m_nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->m_nSeed);
}

void Random::SetSeed(unsigned int nSeed)
{
	this->m_nSeed = nSeed;
	srand(this->m_nSeed);
}

unsigned int Random::GetSeed(void) const
{
	return this->m_nSeed;
}

int Random::GetRandom(int nMax, bool bIncludeZero) const
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

int Random::GetRandomRange(int nMax, int nMin) const
{
	nMax++;
	nMax -= nMin;

	//�ő�l��+1�������̂���ŏ��l�������A����ŗ������������]��ɍŏ��l�𑫂�
	return rand() % nMax + nMin;
}

float Random::GetRandom(int nMax, int nPointPos, bool bIncludeZero) const
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

float Random::GetRandomRange(int nMax, int nMin, int nPointPos) const
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

std::string Random::Choice(std::string ssInput, ...) const
{
	int nRandom;
	int nCount = 0;
	int i;
	std::string ssReturn;

	va_list args, args2,args3;
	va_start(args, ssInput);
	va_copy(args2, args);
	va_copy(args3, args);

	//���͂��ꂽ������̃J�E���g
	nCount++;//1�ڂ̈����̃J�E���g
	while (true)
	{
		if (va_arg(args, int) != NULL)
			nCount++;
		else
			break;
	}
	va_end(args);

	//���͂��ꂽ��������std::string�̏�������ȉ����̔���
	for (i = 0; i < nCount - 1; i++)
	{
		if (va_arg(args2, std::string).size() > ssReturn.max_size() || ssInput.size() > ssReturn.max_size())
		{
			ssReturn = "error";
			return ssReturn;
		}
	}
	va_end(args2);

	//�Ԃ�������̔ԍ�����
	nRandom = rand() % nCount + 1;

	//�Ԃ�����������i�[
	if (nRandom == 1)
		ssReturn = ssInput;
	else
	{
		for (i = 0; i < nRandom - 1; i++)
		{
			ssReturn = va_arg(args3, const char*);
		}
	}
	va_end(args3);

	return ssReturn;
}
}