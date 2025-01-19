/*+===================================================================
	 File: Random.cpp
	 Summary: �����_�����W���[���v���O�����̎���
	 Author: AT12C192 01 �ؗY��Y
	 Date: 03/17.2024 ����쐬
===================================================================+*/
#include "Random.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <string>

Random::Random(void) : m_bMT(false), m_rd(nullptr), m_mt(nullptr), m_dist(nullptr)
{
	this->m_nSeed = static_cast<unsigned int>(time(NULL));
	srand(this->m_nSeed);
}

Random::Random(unsigned int nSeed) : m_bMT(false), m_rd(nullptr), m_mt(nullptr), m_dist(nullptr)
{
	this->m_nSeed = nSeed;
	srand(this->m_nSeed);
}

Random::~Random(void)
{
	if (m_rd != nullptr)
		delete m_rd;
	if (m_mt != nullptr)
		delete m_mt;
	if (m_dist != nullptr)
		delete m_dist;
}

void Random::enableMT(void)
{
	m_bMT = true;
	m_rd = new std::random_device();
	m_mt = new std::mt19937((*m_rd)());
	m_dist = new std::uniform_real_distribution<float>(0, RAND_MAX);
}

void Random::disableMT(void)
{
	m_bMT = false;
	delete m_dist;
	delete m_mt;
	delete m_rd;

	m_dist = nullptr;
	m_mt = nullptr;
	m_rd = nullptr;
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

int Random::GetInteger(int nMax, bool bIncludeZero) const
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
	if (m_bMT)
	{
		return static_cast<int>((*m_dist)(*m_mt)) % nMax + nInZero;
	}
	else
	{
		return rand() % nMax + nInZero;
	}
}

int Random::GetIntegerRange(int nMax, int nMin) const
{
	nMax++;
	nMax -= nMin;

	//�ő�l��+1�������̂���ŏ��l�������A����ŗ������������]��ɍŏ��l�𑫂�
	if (m_bMT)
	{
		return static_cast<int>((*m_dist)(*m_mt)) % nMax + nMin;
	}
	else
	{
		return rand() % nMax + nMin;
	}
}

float Random::GetDecimal(int nMax, int nPointPos, bool bIncludeZero) const
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
	if (m_bMT)
	{
		fRandom = static_cast<float>(static_cast<int>((*m_dist)(*m_mt)) % nVal + nInZero);
		fRandom /= nSetPointPos;
	}
	{
		fRandom = static_cast<float>(rand() % nVal + nInZero);
		fRandom /= nSetPointPos;
	}

	return fRandom;
}

float Random::GetDecimalRange(float fMax, float fMin, int nPointPos) const
{
	float fRandom;
	int nSetPointPos;
	int nMaxVal;
	int nMinVal;
	auto param = m_dist->param(); // ���݂̗����̍ő�l��ۑ�

	//10���A�\�������������̈ʂ����ݏ悵�����l
	nSetPointPos = static_cast<int>(pow(10, nPointPos));

	//�ő�l�A�ŏ��l�̌��𑝂₷
	nMaxVal = static_cast<int>(fMax * nSetPointPos);
	nMinVal = static_cast<int>(fMin * nSetPointPos);

	//�ő�l��+1�����Ƃ��납��A�ŏ��l������
	nMaxVal++;
	nMaxVal -= nMinVal;

	// �����ł��闐���̍ő�l����������ő�l�����������ꍇ�́A�ő�l��ύX
	if (nMaxVal > RAND_MAX)
	{
		std::uniform_real_distribution<float>::param_type SetParam(0, static_cast<float>(nMaxVal));
		m_dist->param(SetParam);
	}

	//�������ő�l����ŏ��l���������l�Ŋ������]��ɍŏ��l�𑫂��āA�����_�̈ʒu�����炷
	if (m_bMT)
	{
		fRandom = static_cast<float>(static_cast<int>((*m_dist)(*m_mt)) % nMaxVal + nMinVal);
		fRandom /= nSetPointPos;

		// �����ł��闐���̍ő�l�����ɖ߂�
		m_dist->param(param);
	}
	else
	{
		fRandom = static_cast<float>(rand() % nMaxVal + nMinVal);
		fRandom /= nSetPointPos;
	}

	return fRandom;
}

//��Random.Choice�̃R�[�h
#if 0
std::string Random::Choice(std::string ssInput, ...) const
{
	int nRandom;
	int nCount = 0;
	int i;
	std::string ssReturn;

	va_list args, args2, args3;
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
			ssReturn = va_arg(args3, const char *);
		}
	}
	va_end(args3);

	return ssReturn;
}
#endif