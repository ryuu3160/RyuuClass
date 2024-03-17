/*
 * @file Random.h
 * @brief �����_�����W���[���v���O�����̃w�b�_
 * @author �ؗY��Y
 * @date �쐬���F03/17.2024
 *
 * @date 03/10 �֐��̒ǉ� [IntegerRandom]
 */
#ifndef _____RANDOM_MODULE_H_____
#define _____RANDOM_MODULE_H_____

class RANDOM
{
private:
	unsigned int nSeed;

public:

	/**
	 * @fn
	 * @brief �����Ȃ��R���X�g���N�^
	 * @brief �Ăяo�����̎��Ԃ��V�[�h�l�Ƃ��ċL�^�����
	 * @detail	�V�[�h�l����Ɍ��߂Ȃ��ꍇ�͂��̃R���X�g���N�^���g�p����
	 */
	RANDOM();
	/**
	 * @fn
	 * @brief ��������R���X�g���N�^
	 * @brief �������V�[�h�l�Ƃ��ċL�^�����
	 * @detail	�V�[�h�l���w�肵�����ꍇ�͂��̃R���X�g���N�^���g�p����
	 */
	RANDOM(unsigned int nSeed);

	~RANDOM();//�f�X�g���N�^

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
	int RandomInt(int nMax, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief �w��͈͂Ő����l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő�l
	 * @param [nMin] �������闐���̍ŏ��l
	 * @return ��������������int�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	int RandomIntRange(int nMax, int nMin) const;

	/**
	 * @fn
	 * @brief �����l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő吮���l
	 * @param [nPointPos] �������闐���̏����_�ʒu | ��F�����_��1�� �� 1 | ��2�� �� 2
	 * @param [bIncludeZero] �������闐���̍ŏ��l��0�����w��(true:0 | false:1)
	 * @return ��������������float�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	float RandomFloat(int nMax, int nPointPos, bool bIncludeZero) const;

	/**
	 * @fn
	 * @brief �w��͈͂ŏ����_�l�̗����𐶐�����
	 * @param [nMax] �������闐���̍ő�l
	 * @param [nMin] �������闐���̍ŏ��l
	 * @param [nPointPos] �������闐���̏����_�ʒu | ��F�����_��1�� �� 1 | ��2�� �� 2
	 * @return ��������������float�^�ŕԂ�
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 */
	float RandomFloatRange(int nMax, int nMin, int nPointPos) const;

	/**
	 * @fn
	 * @brief �����Ƃ��ė^���������̕�����������_����1��char�^�z��Ɋi�[
	 * @param [pszInput] �I�΂ꂽ��������󂯎��ׂ�char�^�z�񖼁��z��̑傫����255 + 1�܂�
	 * @param [...] �����̈������w��\�A�������^�����邱�Ƃ�z�肵�Ă���
	 * @param �Ō�ɕK��NULL�������Ƃ��ēn��(��̓v���g�^�C�v�錾�̃R�����g���Q��)
	 * @detail �V�[�h�l�͕K���ݒ肳��Ă���̂ŁA���̊֐������s���邱�Ƃ͖���
	 *
	 *			�g�p��Fint main(void)
	 *					{
	 *						char szTest[255 + 1];
	 *						random_choice(szTest,"�e�X�g1","�e�X�g2","�e�X�g3",NULL);
	 *					}
	 */
	void RandomChoice(char* pszInput, ...) const;
};

#endif // !_____RANDOM_MODULE_H_____