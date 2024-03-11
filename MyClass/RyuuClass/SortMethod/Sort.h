/*
 * @file Sort.h
 * @brief �\�[�g�v���O�����̃w�b�_
 * @author �ؗY��Y
 * @date �쐬���F03 / 10 / 2024
 * 
 * @date 03/10 �֐��̒ǉ� [IntegerSort]
 */

#ifndef _____SORT_H_____
#define _____SORT_H_____

class SORT
{
public:
	enum class SORT_MODE : unsigned int
	{
		ASCENDING,	//����
		DESCENDING,	//�~��
	};

	SORT();	//�R���X�g���N�^
	~SORT();//�f�X�g���N�^

	/**
	 * @fn
	 * @brief �����^�̔z����\�[�g����
	 * @param [*Array] �\�[�g�������z��
	 * @param [size] �z��̑S�̃T�C�Y �L������:sizeof(�z��)
	 * @return �Ȃ�
	 * @detail	�\�[�g�̕����̓V�F���\�[�g
	 * @memo	�z��̗v�f���͔z��̃T�C�Y���狁�߂邽�߁A�v�f����������Ȃ��z��ł����Ă��g�p�\
	 *			�v�f���𒼐ڈ����Ƃ��ēn���Ȃ��̂Ŏ኱��Ԃ�������
	 */
	void IntegerSort(int* Array,int size,SORT_MODE mode) const;

};

#endif // !_____SORT_H_____
