 /*+===================================================================
	 File: Random.hpp
	 Summary: �����_�����W���[���v���O�����̃w�b�_
	 Author: AT12C192 01 �ؗY��Y
	 Date: 03/17/2024 ����쐬
 ===================================================================+*/
#pragma once

#include <string>
#include <vector>
#include <list>
#include <initializer_list>
#include <random>
#include <Windows.h>

class Random
{
public:

	/// <summary>
	/// <para>�����Ȃ��R���X�g���N�^</para>
	/// <para>�Ăяo�����̎��Ԃ��V�[�h�l�Ƃ��ċL�^�����</para>
	/// </summary>
	/// <memo>�V�[�h�l����Ɍ��߂Ȃ��ꍇ�͂��̃R���X�g���N�^���g�p����</memo>
	Random();
	/// <summary>
	/// <para>��������R���X�g���N�^</para>
	/// <para>�������V�[�h�l�Ƃ��ċL�^�����</para>
	/// </summary>
	/// <param name="[nSeed]">�V�[�h�l</param>
	/// <memo>�V�[�h�l���w�肵�����ꍇ�͂��̃R���X�g���N�^���g�p����</memo>
	Random(unsigned int nSeed);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Random();

	/// <summary>
	/// �����Z���k�E�c�C�X�^�\�̗L����
	/// </summary>
	void enableMT();

	/// <summary>
	/// �����Z���k�E�c�C�X�^�\�̖�����
	/// </summary>
	void disableMT();

	/// <summary>
	/// �Ăяo�����̎��Ԃ��g�p���ăV�[�h�l��ݒ肷��
	/// </summary>
	/// <memo>�ݒ肵���V�[�h�l�̓����o�ϐ�nSeed�ɋL�^�����</memo>
	void SetSeedTime();

	/// <summary>
	/// �������g�p���ăV�[�h�l��ݒ肷��
	/// </summary>
	/// <param name="[nSeed]">�ݒ肵���������l</param>
	/// <memo>�ݒ肵���V�[�h�l�̓����o�ϐ�nSeed�ɋL�^�����</memo>
	void SetSeed(unsigned int nSeed);

	/// <summary>
	/// �Ăяo�����ɐݒ肳��Ă���V�[�h�l��\������
	/// </summary>
	/// <returns>�V�[�h�l</returns>
	/// <memo>�����o�ϐ�nSeed�ɋL�^����Ă���l��Ԃ�</memo>
	unsigned int GetSeed(void) const;

	/// <summary>
	/// �����l�̗����𐶐�����
	/// </summary>
	/// <param name="[nMax]">�������闐���̍ő�l</param>
	/// <param name="[bIncludeZero]">�������闐���̍ŏ��l��0�����w��(true:0 | false:1)</param>
	/// <returns>��������������int�^�ŕԂ�</returns>
	/// <memo>�V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���</memo>
	int GetInteger(int nMax, bool bIncludeZero) const;

	/// <summary>
	/// �w��͈͂Ő����l�̗����𐶐�����
	/// </summary>
	/// <param name="[nMax]">�������闐���̍ő�l</param>
	/// <param name="[nMin]">�������闐���̍ŏ��l</param>
	/// <returns>��������������int�^�ŕԂ�</returns>
	/// <memo>�V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���</memo>
	int GetIntegerRange(int nMax, int nMin) const;

	/// <summary>
	/// �����l�̗����𐶐�����
	/// </summary>
	/// <param name="[nMax]">�������闐���̍ő吮���l</param>
	/// <param name="[nPointPos]">�������闐���̏����_�ʒu | ��F�����_��1�� �� 1 | ��2�� �� 2</param>
	/// <param name="[bIncludeZero]">�������闐���̍ŏ��l��0�����w��(true:0 | false:1)</param>
	/// <returns>��������������float�^�ŕԂ�</returns>
	/// <memo>�V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���</memo>
	float GetDecimal(int nMax, int nPointPos, bool bIncludeZero) const;

	/// <summary>
	/// �w��͈͂ŏ����_�l�̗����𐶐�����
	/// </summary>
	/// <param name="[fMax]">�������闐���̍ő�l</param>
	/// <param name="[fMin]">�������闐���̍ŏ��l</param>
	/// <param name="[nPointPos]">�������闐���̏����_�ʒu | ��F�����_��1�� �� 1 | ��2�� �� 2</param>
	/// <returns>��������������float�^�ŕԂ�</returns>
	/// <memo>�V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���</memo>
	float GetDecimalRange(float fMax, float fMin, int fPointPos) const;

	/// <summary>
	/// �^���������̕����񂩂烉���_����1��Ԃ�
	/// </summary>
	/// <param name="[...args]">�����̈������w��\�A�������^�����邱�Ƃ�z�肵�Ă���</param>
	/// <returns>std::string�^</returns>
	/// <memo>�V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���</memo>
	/// <memo>�����ɕ�����ȊO��n���ƃG���[�ɂȂ�</memo>
	template<typename ...A>
	std::string Choice(A... args) const;

	/// <summary>
	/// �����̃f�[�^���i�[���ꂽvector���烉���_����1��Ԃ�
	/// </summary>
	/// <param name="[aray]">vector�̃C���X�^���X�ւ̎Q��</param>
	/// <returns>vector�̌^�Ɠ����^</returns>
	template<typename T>
	T Choice(const std::vector<T>& aray) const;

	/// <summary>
	/// �����̃f�[�^���i�[���ꂽlist���烉���_����1��Ԃ�
	/// </summary>
	/// <param name="[aray]">list�̃C���X�^���X�ւ̎Q��</param>
	/// <returns>list�̌^�Ɠ����^</returns>
	template<typename T>
	T Choice(const std::list<T>& aray) const;

	/// <summary>
	/// <para>�����ŗ^����vector�̃f�[�^���烉���_���ɕ����̗v�f��I������vector�Ƃ��ĕԂ�</para>
	/// <para>�v�f�̏d���͂Ȃ�</para>
	/// </summary>
	/// <param name="[aray]">vector�̃C���X�^���X�ւ̎Q��</param>
	/// <param name="[num]">�擾�������v�f�̌�</param>
	/// <returns>vector�N���X</returns>
	/// <memo>�擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ͏o���Ȃ�</memo>
	template<typename T>
	std::vector<T> Sample(const std::vector<T> &aray, int num) const;

	/// <summary>
	/// <para>�����ŗ^����list�̃f�[�^���烉���_���ɕ����̗v�f��I������list�Ƃ��ĕԂ�</para>
	/// <para>�v�f�̏d���͂Ȃ�</para>
	/// </summary>
	/// <param name="[aray]">list�̃C���X�^���X�ւ̎Q��</param>
	/// <param name="[num]">�擾�������v�f�̌�</param>
	/// <returns>list�N���X</returns>
	/// <memo>�擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ͏o���Ȃ�</memo>
	template<typename T>
	std::list<T> Sample(const std::list<T>& aray, int num) const;

	/// <summary>
	/// <para>�����ŗ^����vector�̃f�[�^���烉���_���ɕ����̗v�f��I������vector�Ƃ��ĕԂ�</para>
	/// <para>�v�f�̏d������</para>
	/// </summary>
	/// <param name="[aray]">vector�̃C���X�^���X�ւ̎Q��</param>
	/// <param name="[k]">�擾����v�f��</param>
	/// <returns>vector�N���X</returns>
	/// <memo>�擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ��o����</memo>
	template<typename T>
	std::vector<T> Choices(const std::vector<T>& aray, int k) const;

	/// <summary>
	/// <para>�����ŗ^����list�̃f�[�^���烉���_���ɕ����̗v�f��I������list�Ƃ��ĕԂ�</para>
	/// <para>�v�f�̏d������</para>
	/// </summary>
	/// <param name="[aray]">list�̃C���X�^���X�ւ̎Q��</param>
	/// <param name="[k]">�擾����v�f��</param>
	/// <returns>list�N���X</returns>
	/// <memo>�擾����v�f���͌���vector�̗v�f�����傫�����邱�Ƃ��o����</memo>
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
