/*
 * @file Random.h
 * @brief �����_�����W���[���v���O�����̃w�b�_
 * @author �ؗY��Y
 * @date �쐬���F03/17.2024
 *
 * @date 03/10 �֐��̒ǉ� [IntegerRandom]
 */
#pragma once

#include <string>
#include <initializer_list>

namespace RYUU
{
class Random
{
private:
	unsigned int m_nSeed;

public:

	/**
	 * @fn
	 * @brief �����Ȃ��R���X�g���N�^
	 * @brief �Ăяo�����̎��Ԃ��V�[�h�l�Ƃ��ċL�^�����
	 * @detail	�V�[�h�l����Ɍ��߂Ȃ��ꍇ�͂��̃R���X�g���N�^���g�p����
	 */
	Random();
	/**
	 * @fn
	 * @brief ��������R���X�g���N�^
	 * @brief �������V�[�h�l�Ƃ��ċL�^�����
	 * @detail	�V�[�h�l���w�肵�����ꍇ�͂��̃R���X�g���N�^���g�p����
	 */
	Random(unsigned int nSeed);

	~Random();//�f�X�g���N�^

	/**
	 * @fn
	 * @brief �Ăяo�����̎��Ԃ��g�p���ăV�[�h�l��ݒ肷��
	 * @return �Ȃ�
	 * @detail�@�ݒ肵���V�[�h�l�̓����o�ϐ�nSeed�ɋL�^�����
	 */
	void SetSeedTime(void);

	/**
	 * @fn
	 * @brief �������g�p���ăV�[�h�l��ݒ肷��
	 * @param [nSeed] �ݒ肵���������l
	 * @return �Ȃ�
	 * @detail�@�ݒ肵���V�[�h�l�̓����o�ϐ�nSeed�ɋL�^�����
	 */
	void SetSeed(unsigned int nSeed);

	/**
	 * @fn
	 * @brief �Ăяo�����ɐݒ肳��Ă���V�[�h�l��\������
	 * @return unsigned int�^�̐��l
	 * @detail�@�����o�ϐ�nSeed�ɋL�^����Ă���l��Ԃ�
	 */
	unsigned int GetSeed(void) const;

	/**
	 * @fn
	 * @brief �����l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő�l
	 * @param [bIncludeZero] �������闐���̍ŏ��l��0�����w��(true:0 | false:1)
	 * @return ��������������int�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	int GetInteger(int nMax, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief �w��͈͂Ő����l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő�l
	 * @param [nMin] �������闐���̍ŏ��l
	 * @return ��������������int�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	int GetIntegerRange(int nMax, int nMin) const;

	/**
	 * @fn
	 * @brief �����l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő吮���l
	 * @param [nPointPos] �������闐���̏����_�ʒu | ��F�����_��1�� �� 1 | ��2�� �� 2
	 * @param [bIncludeZero] �������闐���̍ŏ��l��0�����w��(true:0 | false:1)
	 * @return ��������������float�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	float GetDecimal(int nMax, int nPointPos, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief �w��͈͂ŏ����_�l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő�l
	 * @param [nMin] �������闐���̍ŏ��l
	 * @param [nPointPos] �������闐���̏����_�ʒu | ��F�����_��1�� �� 1 | ��2�� �� 2
	 * @return ��������������float�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	float GetDecimalRange(int nMax, int nMin, int nPointPos) const;

	/**
	 * @fn
	 * @brief �����Ƃ��ė^���������̕�����������_����1��Ԃ�
	 * @param [...args] �����̈������w��\�A�������^�����邱�Ƃ�z�肵�Ă���
	 * @return std::string�^
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 * @memo �����ɕ�����ȊO��n���ƃG���[�ɂȂ�
	 */
	template<typename ...A>
	std::string Choice(A... args) const;
};

//Random.Choice�̒�`
template<typename ...A>
std::string Random::Choice(A... args) const
{
	int nRandom;
	int nCount = 0;
	int i;
	std::string ssReturn;

	//�����̃J�E���g
	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		nCount++;
	}

	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		if (ss.size() >= ss.max_size())
		{
			ssReturn = "error";
			return ssReturn;
		}
	}

	//�Ԃ�������̔ԍ�����
	nRandom = rand() % nCount + 1;

	i = 1;//�J�E���^

	for (std::string ss : std::initializer_list<std::string>{args...})
	{
		if (nRandom == i)
		{
			ssReturn = ss;
			return ssReturn;
		}
		i++;
	}

	return ssReturn;
}

}