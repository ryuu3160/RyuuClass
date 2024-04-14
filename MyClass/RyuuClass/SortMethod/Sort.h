/*
 * @file Sort.h
 * @brief �\�[�g�v���O�����̃w�b�_
 * @author �ؗY��Y
 * @date �쐬���F03/10.2024
 * 
 * @date 03/10 �֐��̒ǉ� [IntegerSort]
 * @date 03/11 �֐��̒ǉ� [SetStrArrayData,StringSort]
 */

#ifndef _____SORT_H_____
#define _____SORT_H_____

namespace RYUU
{
class Sort
{
private:
	int nWidth;	//2�����z���1��̕�
	int nLine;	//2�����z��̍s��
public:
	enum class SORT_MODE : unsigned int
	{
		ASCENDING,	//����
		DESCENDING,	//�~��
	};

	Sort();	//�R���X�g���N�^
	/**
		* @fn
		* @brief ��������R���X�g���N�^
		* @param [nWidth] 2�����z���1��̕�
		* @param [nLine] 2�����z��̍s��
		* @detail	�\�[�g���镶����^2�����z��̑傫�����ς��Ȃ��ꍇ�A�R���X�g���N�^�Ŏw�肵������������ǂ�����
		* @memo	���̃R���X�g���N�^���Ăяo�����ꍇ�́ASetStrArrayData�֐����Ăяo���K�v�͂Ȃ�
		*/
	Sort(int nLine, int nWidth);
	~Sort();//�f�X�g���N�^

	/**
		* @fn
		* @brief �����^�̔z����\�[�g����
		* @param [*Array] �\�[�g�������z��
		* @param [size] �z��̑S�̃T�C�Y �L������:sizeof(�z��)
		* @param [mode] ����or�~���̎w�� �L������:Sort::SORT_MODE::ASCENDING or DESCENDING
		* @return �Ȃ�
		* @detail	�\�[�g�̕����̓V�F���\�[�g
		* @memo	�z��̗v�f���͔z��̃T�C�Y���狁�߂邽�߁A�v�f����������Ȃ��z��ł����Ă��g�p�\
		*			�v�f���𒼐ڈ����Ƃ��ēn���Ȃ��̂Ŏ኱��Ԃ�������
		*/
	void IntegerSort(int* Array, int size, SORT_MODE mode) const;

	/**
		* @fn
		* @brief ������^�z��̑傫����ݒ肷��
		* @brief StringSort�֐������s����O�ɕK�����̊֐����Ăяo������
		* @param [size] 2�����z��̑S�̃T�C�Y �L������:sizeof(�z��)
		* @param [width] 2�����z���1�񕪂̑傫�� �L������:sizeof(�z��[0])
		* @return �Ȃ�
		* @detail	StringSort���g�p���鎞�́A�K�����̊֐����ɌĂяo���Ȃ��Ă͂Ȃ�Ȃ�
		*/
	void SetStrArrayData(int size, int width);

	/**
		* @fn
		* @brief ������^��2�����z����\�[�g����(1�s1���Ƃ݂Ȃ�)
		* @brief ���̊֐����Ăяo���O�ɁA�K��SetStrArrayData�֐����Ăяo������
		* @param [*Array] 2�����z��ւ̃|�C���^ �L������:�z��[0]
		* @param [mode] ����or�~���̎w�� �L������:Sort::SORT_MODE::ASCENDING or DESCENDING
		* @return �Ȃ�
		* @detail	�\�[�g�̕����̓V�F���\�[�g
		* @memo	�z��̗v�f����񐔂Ȃǂ͐��SetStrArrayData�֐��Őݒ肷�邽�߁A�����Ƃ��ė^����K�v�͂Ȃ�
		*/
	void StringSort(char* Array, SORT_MODE mode) const;

};
}

#endif // !_____SORT_H_____
