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
	int i,j;	//�Y����
	int nTmp;	//�f�[�^�ꎞ�ۑ��ꏊ
	int nGap;	//�M���b�v
	int roop;	//�v�f��
	int nTop;	//�����񕔂̐擪�v�f�Y����
	int* TmpArray;	//�S�f�[�^�̈ꎞ�ۑ��ꏊ

	roop = size / static_cast<int>(sizeof(*Array));//�v�f��

	TmpArray = new int[roop];//�z��m��

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

	delete[] TmpArray;//���
}