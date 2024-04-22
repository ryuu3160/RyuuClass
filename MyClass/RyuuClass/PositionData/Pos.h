/*
 * @file Pos.h
 * @brief ���W�f�[�^�̊Ǘ��Ɏg�p
 * @author �ؗY��Y
 * @date �쐬���F04/14/2024
 *
 * @date 04/14 ��Ս쐬
 */
#ifndef _____POS_H_____
#define _____POS_H_____

namespace RYUU
{
template <typename T>
class Pos
{
private:
	T m_x;
	T m_y;
	T m_z;
public:
	Pos();
	~Pos();

	/**
		* @brief 2�����̍��W�ݒ�
		* @param x x���W
		* @param y y���W
		*/
	void SetPos(T x, T y);

	/**
		* @brief 3�����̍��W�ݒ�
		* @param x x���W
		* @param y y���W
		* @param z z���W
		*/
	void SetPos(T x, T y, T z);

	/**
	 * @brief ���ɂ���Pos�N���X�̒l�����̂܂܃R�s�[����
	 * @param pos Pos�N���X�̃C���X�^���X
	 */
	void SetPos(const Pos pos);

	/**
	* @brief ���W�f�[�^��1�擾����
	 * @tparam Argu
	 * @param n �f�[�^���i�[����ϐ�
	 * @param type x,y,z����I��
	 */
	void GetPos(T& n, const char* type) const;

	/**
	 * @brief ���W�f�[�^��2�擾����
	 * @tparam Argu
	 * @param n1 1�ڂ̃f�[�^���i�[����ϐ�
	 * @param n2 2�ڂ̃f�[�^���i�[����ϐ�
	 * @param type xy,xz,yz����I��
	 */
	void GetPos(T& n1, T& n2,const char* type) const;

	/**
	 * @brief ���W�f�[�^��3�擾����
	 * @tparam Argu
	 * @param x x�̒l���i�[����ϐ�
	 * @param y y�̒l���i�[����ϐ�
	 * @param z z�̒l���i�[����ϐ�
	 */
	void GetPos(T& x, T& y, T& z) const;

	/**
	 * @brief Pos���m�̑����Z�̌��ʂ�Ԃ�
	 * @param rhs �E�ӑ�
	 * @return Pos�N���X
	 */
	Pos operator+(const Pos &rhs);

	/**
	 * @brief ���ӂɉE�ӂ𑫂������ʂ�������
	 * @param rhs �E�ӑ�
	 */
	void operator+=(const Pos &rhs);

	/**
	 * @brief Pos���m�̈����Z�̌��ʂ�Ԃ�
	 * @param rhs �E�ӑ�
	 * @return Pos�N���X
	 */
	Pos operator-(const Pos &rhs);

	/**
	 * @brief ���ӂ���E�ӂ����������ʂ����ӂɑ������
	 * @param rhs �E�ӑ�
	 */
	void operator-=(const Pos &rhs);

	/**
	 * @brief Pos���m���r����
	 * @param rhs �E�ӑ�
	 * @return ��r�������ʂ𐮐��^��0,1,2,3�̂����ꂩ��Ԃ�
	 * @memo	0:x,y,z�S�ē������Ȃ�
	 *			1:x,y,z�����ꂩ1����������
	 *			2:x,y,z�����ꂩ2����������
	 *			3:x,y,z�S�Ă�������
	 */
	int operator ==(const Pos &rhs);


};
}

template<typename T>
RYUU::Pos<T>::Pos() : m_x(0), m_y(0), m_z(0)
{
}
template<typename T>
inline RYUU::Pos<T>::~Pos()
{
}

template <typename T>
void RYUU::Pos<T>::SetPos(T x, T y)
{
	m_x = x;
	m_y = y;
}
template <typename T>
void RYUU::Pos<T>::SetPos(T x, T y, T z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

template<typename T>
void RYUU::Pos<T>::SetPos(const Pos pos)
{
	this->m_x = pos.m_x;
	this->m_y = pos.m_y;
	this->m_z = pos.m_z;
}

template<typename T>
inline void RYUU::Pos<T>::GetPos(T& n,const char* type) const
{
	int num;
	if (type == "x")
	{
		num = 0;
	}
	else if (type == "y")
	{
		num = 1;
	}
	else if (type == "z")
	{
		num = 2;
	}
	else
	{
		num = 3;
	}

	switch (num)
	{
	case 0:
		n = m_x;
		break;
	case 1:
		n = m_y;
		break;
	case 2:
		n = m_z;
		break;
		
	default:break;
	}
}

template<typename T>
inline void RYUU::Pos<T>::GetPos(T& n1, T& n2, const char* type) const
{
	int num;
	if (type == "xy")
	{
		num = 0;
	}
	else if (type == "xz")
	{
		num = 1;
	}
	else if (type == "yz")
	{
		num = 2;
	}
	else
	{
		num = 3;
	}

	switch (num)
	{
	case 0:
		n1 = m_x;
		n2 = m_y;
		break;
	case 1:
		n1 = m_x;
		n2 = m_z;
		break;
	case 2:
		n1 = m_y;
		n2 = m_z;
		break;
	default:break;
	}
}

template<typename T>
inline void RYUU::Pos<T>::GetPos(T& x, T& y, T& z) const
{
	x = m_x;
	y = m_y;
	z = m_z;
}

template<typename T>
RYUU::Pos<T> RYUU::Pos<T>::operator+(const Pos &rhs)
{
	Pos Return;

	Return.m_x = this->m_x + rhs.m_x;
	Return.m_y = this->m_y + rhs.m_y;
	Return.m_z = this->m_z + rhs.m_z;

	return Return;
}

template<typename T>
void RYUU::Pos<T>::operator+=(const Pos &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	this->m_z += rhs.m_z;
}

template<typename T>
RYUU::Pos<T> RYUU::Pos<T>::operator-(const Pos &rhs)
{
	Pos Return;

	Return.m_x = this->m_x - rhs.m_x;
	Return.m_y = this->m_y - rhs.m_y;
	Return.m_z = this->m_z - rhs.m_z;

	return Return;
}

template<typename T>
void RYUU::Pos<T>::operator-=(const Pos& rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	this->m_z -= rhs.m_z;
}

template<typename T>
int RYUU::Pos<T>::operator==(const Pos& rhs)
{
	int result = 0;

	if (this->m_x == rhs.m_x)
		result++;
	if (this->m_y == rhs.m_y)
		result++;
	if (this->m_z == rhs.m_z)
		result++;

	return result;
}

#endif // !_____POS_H_____