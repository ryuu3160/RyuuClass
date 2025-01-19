 /*+===================================================================
	 File: Random.hpp
	 Summary: �����_�����W���[���v���O�����̃w�b�_
	 Author: AT12C192 01 �ؗY��Y
	 Date: 03/17.2024 ����쐬
 ===================================================================+*/
#pragma once

#include <string>
#include <vector>
#include <list>
#include <initializer_list>
#include <random>
#include <debugapi.h>

class Random
{
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
	 * @brief �����Z���k�E�c�C�X�^�\�̗L����
	 * @param  ����
	 */
	void enableMT(void);

	/**
	 * @brief �����Z���k�E�c�C�X�^�\�̖�����
	 * @param  ����
	 */
	void disableMT(void);

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
	float GetDecimalRange(float fMax, float fMin, int fPointPos) const;

	/**
	 * @fn
	 * @brief �^���������̕����񂩂烉���_����1��Ԃ�
	 * @param [...args] �����̈������w��\�A�������^�����邱�Ƃ�z�肵�Ă���
	 * @return std::string�^
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 * @memo �����ɕ�����ȊO��n���ƃG���[�ɂȂ�
	 */
	template<typename ...A>
	std::string Choice(A... args) const;

	/**
	 * @brief �����̃f�[�^���i�[���ꂽvector���烉���_����1��Ԃ�
	 * @tparam T vector�̌^��
	 * @param aray vector�̕ϐ���
	 * @return vector�̌^�Ɠ����^
	 */
	template<typename T>
	T Choice(const std::vector<T>& aray) const;

	/**
	 * @brief �����̃f�[�^���i�[���ꂽvector���烉���_����1��Ԃ�
	 * @tparam T vector�̌^��
	 * @param aray vector�̕ϐ���
	 * @return vector�̌^�Ɠ����^
	 */
	template<typename T>
	T Choice(const std::list<T>& aray) const;

	/**
	 * @brief �����ŗ^����vector�̃f�[�^���烉���_���ɕ����̗v�f��I������vector�Ƃ��ĕԂ�
	 * @brief �v�f�̏d���͂Ȃ�
	 * @tparam T �n��vector�̌^��
	 * @param &aray vector�̕ϐ���
	 * @param num �擾�������v�f�̌�
	 * @return vector�N���X
	 * @memo �擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ͏o���Ȃ�
	 */
	template<typename T>
	std::vector<T> Sample(const std::vector<T> &aray, int num) const;

	/**
	 * @brief �����ŗ^����list�̃f�[�^���烉���_���ɕ����̗v�f��I������list�Ƃ��ĕԂ�
	 * @brief �v�f�̏d���͂Ȃ�
	 * @tparam T �n��list�̌^��
	 * @param &aray list�̕ϐ���
	 * @param num �擾�������v�f�̌�
	 * @return list�N���X
	 * @memo �擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ͏o���Ȃ�
	 */
	template<typename T>
	std::list<T> Sample(const std::list<T>& aray, int num) const;

	/**
	 * @brief �����ŗ^����vector�̃f�[�^���烉���_���ɕ����̗v�f��I������vector�Ƃ��ĕԂ�
	 * @brief �v�f�̏d������
	 * @tparam T �n��vector�̌^��
	 * @param &aray vector�̕ϐ���
	 * @param k �擾����v�f��
	 * @return vector�N���X
	 * @memo �擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ��o����
	 */
	template<typename T>
	std::vector<T> Choices(const std::vector<T>& aray, int k) const;

	/**
	 * @brief �����ŗ^����list�̃f�[�^���烉���_���ɕ����̗v�f��I������list�Ƃ��ĕԂ�
	 * @brief �v�f�̏d������
	 * @tparam T �n��list�̌^��
	 * @param &aray list�̕ϐ���
	 * @param k �擾����v�f��
	 * @return list�N���X
	 * @memo �擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ��o����
	 */
	template<typename T>
	std::list<T> Choices(const std::list<T>& aray, int k) const;

	private:
		unsigned int m_nSeed;
		bool m_bMT;//�����Z���k�c�C�X�^�[���g�p���邩
		std::random_device* m_rd;//�񌈒�I�ȗ�������
		std::mt19937* m_mt;//�����Z���k�c�C�X�^�[
		std::uniform_real_distribution<float>* m_dist;//��l���z������
};




//Random.Choice�̒�`
template<typename ...A>
std::string Random::Choice(A... args) const
{
	int nRandom;
	int nCount = 0;
	int i;
	std::string strReturn;

	//�����̃J�E���g
	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		nCount++;
	}

	for (std::string ss : std::initializer_list<std::string>{args... })
	{
		if (ss.size() >= ss.max_size())
		{
			strReturn = "error";
			return strReturn;
		}
	}

	//�Ԃ�������̔ԍ�����
	if (m_bMT)
	{
		nRandom = static_cast<int>((*m_dist)(*m_mt)) % nCount + 1;
	}
	else
	{
		nRandom = rand() % nCount + 1;
	}

	i = 1;//�J�E���^

	for (std::string ss : std::initializer_list<std::string>{args...})
	{
		if (nRandom == i)
		{
			strReturn = ss;
			return strReturn;
		}
		i++;
	}

	return strReturn;
}

//Random.Choice�̒�`(vector)
template<typename T>
T Random::Choice(const std::vector<T>& aray) const
{
	T put;
	int nRandom;
	int nCount = 0;

	//�v�f���Ȃ��ꍇ�̃G���[
	if (aray.empty())
	{
		put = -1;
	}

	//�Ԃ�������̔ԍ�����
	if (m_bMT)
	{
		nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
	}
	else
	{
		nRandom = rand() % aray.size();
	}

	put = aray[nRandom];

	return put;
}

//Random.Choice�̒�`(list)
template<typename T>
T Random::Choice(const std::list<T>& aray) const
{
	T put;
	int nRandom;
	int nCount = 0;
	auto itr = aray.begin();

	//�v�f���Ȃ��ꍇ�̃G���[
	if (aray.empty())
	{
		put = -1;
	}

	//�Ԃ�������̔ԍ�����
	if (m_bMT)
	{
		nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
	}
	else
	{
		nRandom = rand() % aray.size();
	}

	for (int i = 0; i < nRandom; i++)
	{
		itr++;
	}
	put = *itr;

	return put;
}

//Random.Sample�̒�`(vector)
template<typename T>
std::vector<T> Random::Sample(const std::vector<T> &aray, int num) const
{
	std::vector<T> sample;
	std::vector<int> Already;
	int nRandom;	//�v�b�V������f�[�^�̗v�f�ԍ�
	int nPushCount = 0;
	bool bPush = true;

	//�v�f�����z��̃T�C�Y�����傫���ꍇ�̃G���[
	if (aray.size() < num)
	{
		OutputDebugStringA("error : Too many elements to retrieve");
		sample.clear();
		return sample;
	}

	//�v�b�V������
	while (nPushCount < num)
	{
		//��������
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}

		//�d���r��
		for (int i = 0; i < Already.size(); i++)
		{
			if (Already[i] == nRandom)
			{
				bPush = false;
				break;
			}
			else
			{
				bPush = true;
			}
		}

		//�l�̑}��
		if (bPush)
		{
			sample.push_back(aray[nRandom]);
			Already.push_back(nRandom);
			nPushCount++;
		}
	}

	return sample;
}

//Random.Sample�̒�`(list)
template<typename T>
std::list<T> Random::Sample(const std::list<T>& aray, int num) const
{
	std::list<T> sample;
	std::vector<int> Already;
	int nRandom;	//�v�b�V������f�[�^�̗v�f�ԍ�
	int nPushCount = 0;
	bool bPush = true;

	//�v�f�����z��̃T�C�Y�����傫���ꍇ�̃G���[
	if (aray.size() < num)
	{
		OutputDebugStringA("error : Too many elements to retrieve");
		sample.clear();
		return sample;
	}

	//�v�b�V������
	while (nPushCount < num)
	{
		//��������
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}

		//�d���r��
		for (int i = 0; i < Already.size(); i++)
		{
			if (Already[i] == nRandom)
			{
				bPush = false;
				break;
			}
			else
			{
				bPush = true;
			}
		}

		//�l�̑}��
		if (bPush)
		{
			auto itr = aray.begin();
			for (int i = 0; i < nRandom; i++)
			{
				itr++;
			}
			sample.push_back(*itr);
			Already.push_back(nRandom);
			nPushCount++;
		}
	}

	return sample;
}

//Random.Choices�̒�`(vector)
template<typename T>
std::vector<T> Random::Choices(const std::vector<T>& aray, int k) const
{
	std::vector<T> choices;
	int nRandom;	//�v�b�V������f�[�^�̗v�f�ԍ�

	//�v�b�V������
	for (int i = 0;i < k;i++)
	{
		//��������
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}
		//�v�b�V��
		choices.push_back(aray[nRandom]);
	}

	return choices;
}

//Random.Choices�̒�`(list)
template<typename T>
std::list<T> Random::Choices(const std::list<T>& aray, int k) const
{
	std::list<T> choices;
	int nRandom;	//�v�b�V������f�[�^�̗v�f�ԍ�

	//�v�b�V������
	for (int i = 0; i < k; i++)
	{
		//�擪�C�e���[�^�[�擾
		auto itr = aray.begin();
		//��������
		if (m_bMT)
		{
			nRandom = static_cast<int>((*m_dist)(*m_mt)) % aray.size();
		}
		else
		{
			nRandom = rand() % aray.size();
		}

		for (int j = 0; j < nRandom; j++)
		{
			itr++;
		}
		//�v�b�V��
		choices.push_back(*itr);
	}
	return choices;
}
