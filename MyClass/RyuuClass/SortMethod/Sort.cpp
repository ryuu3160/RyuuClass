//Sort.cpp
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace RYUU
{
//�R���X�g���N�^
Sort::Sort(void)
{
	nWidth = 0;
	nLine = 0;
}

//�R���X�g���N�^2
Sort::Sort(int nLine,int nWidth)
{
	this->nLine = nLine;
	this->nWidth = nWidth;
}

//�f�X�g���N�^
Sort::~Sort(void)
{

}

void Sort::IntegerSort(int* Array,int size,SORT_MODE mode) const
{
	int i,j;	//�Y����
	int nTmp;	//�f�[�^�ꎞ�ۑ��ꏊ
	int nGap;	//�M���b�v
	int roop;	//�v�f��
	int nTop;	//�����񕔂̐擪�v�f�Y����
	int* TmpArray;	//�S�f�[�^�̈ꎞ�ۑ��ꏊ

	roop = size / static_cast<int>(sizeof(*Array));//�v�f��

	TmpArray = new int[roop];//�z��m��

	//�l�̏�����
	nGap = 1;
	j = 0;
	nTmp = 0;

	//���[�N�X�y�[�X�Ƀf�[�^���i�[
	for (i = 0; i < roop; i++)
	{
		TmpArray[i] = Array[i];
	}

	//�M���b�v��ݒ�
	while (nGap * 3 + 1 <= roop)
	{
		nGap = nGap * 3 + 1;
	}
	
	while (nGap > 0)	//���񃋁[�v
	{
		for (i = 0; i < nGap; i++)	//�}���@���[�v
		{
			nTop = nGap + i;	//�����񕔂̐擪�v�f�̓Y����
			while (nTop < roop)	//���񏈗�
			{
				j = nTop;
				while (j >= nGap && TmpArray[j - nGap] < TmpArray[j])	//�}������
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

	//�\�[�g��̒l�������Ƃ��ēn���ꂽ�z��Ɋi�[
	switch (mode)
	{
	case SORT_MODE::ASCENDING://����
		for (i = 0; i < roop; i++)
		{
			Array[roop - i] = TmpArray[i];
		}
		break;
	case SORT_MODE::DESCENDING://�~��
		for (i = 0; i < roop; i++)
		{
			Array[i] = TmpArray[i];
		}
		break;
	}

	delete[] TmpArray;//���������
	TmpArray = nullptr;
}

void Sort::SetStrArrayData(int nSize, int nWidth)
{
	this->nWidth = nWidth;
	this->nLine = nSize / nWidth;
}

void Sort::StringSort(char* Array, SORT_MODE mode) const
{
	int i,j;	//�Y����
	int nGap;	//�M���b�v
	int nTop;	//�����񕔂̐擪�Y����
	int nDigit; //�����̌�
	char* szTmp;//�f�[�^�ꎞ�ۑ��ꏊ
	char* szpKeep;//�|�C���^�[�L�[�v
	char** szTmpArray;//�S�f�[�^�ꎞ�ۑ��ꏊ

	//2�����z��̊m��
	szTmpArray = new char*[nLine];
	for (i = 0; i < nLine; i++)
	{
		szTmpArray[i] = new char[nWidth];
	}
	//�z��m��
	szTmp = new char[nWidth];

	//��ƃX�y�[�X�ւ̊i�[
	for (i = 0, szpKeep = Array; i < nLine; i++,szpKeep += nWidth)
	{
		strcpy_s(szTmpArray[i],nWidth, szpKeep);
		szTmpArray[i][nWidth - 1] = '\0';
	}

	//�l�̏�����
	nGap = 1;
	j = 0;
	nDigit = 0;

	//�M���b�v��ݒ�
	while (nGap * 3 + 1 <= nLine)
	{
		nGap = nGap * 3 + 1;
	}

	while (nGap > 0)	//���񃋁[�v
	{
		for (i = 0; i < nGap; i++)	//�}���@���[�v
		{
			nTop = nGap + i;	//�����񕔂̐擪�v�f�̓Y����
			while (nTop < nLine)	//���񏈗�
			{
				j = nTop;
				while (szTmpArray[j - nGap][nDigit] == szTmpArray[j][nDigit] && nDigit < nWidth - 1)//n�����ڂ����������������ꍇ�A���̕������r
				{
					nDigit++;
				}
				while (j >= nGap && szTmpArray[j - nGap][nDigit] < szTmpArray[j][nDigit])	//�}������
				{
					strcpy_s(szTmp, nWidth, szTmpArray[j]);
					strcpy_s(szTmpArray[j], nWidth, szTmpArray[j - nGap]);
					strcpy_s(szTmpArray[j - nGap], nWidth, szTmp);
					j -= nGap;
				}
				nTop += nGap;
				nDigit = 0;//��r�����ʒu��擪�Ƀ��Z�b�g
			}
		}
		nGap /= 3;
	}

	switch (mode)
	{
	case SORT_MODE::ASCENDING://����
		for (i = 0; i < nLine; i++, Array += nWidth)
		{
			strcpy_s(Array, nWidth, szTmpArray[nLine - i - 1]);
		}
		break;
	case SORT_MODE::DESCENDING://�~��
		for (i = 0; i < nLine; i++, Array += nWidth)
		{
			strcpy_s(Array, nWidth, szTmpArray[i]);
		}
		break;
	}

	//���������
	for (i = 0; i < nLine; i++)
	{
		delete[] szTmpArray[i];
		szTmpArray[i] = nullptr;//�k���|
	}
	delete[] szTmpArray;
	szTmpArray = nullptr;//�k���|
	delete[] szTmp;
	szTmp = nullptr;//�k���|
	szpKeep = nullptr;//�k���|
}

}