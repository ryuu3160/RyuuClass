 /*+===================================================================
	 File: Pos.hpp
	 Summary: ���W�f�[�^�̊Ǘ��Ɏg�p
	 Author: AT12C192 01 �ؗY��Y
	 Date: 04/14/2024 ����쐬
 ===================================================================+*/
#pragma once

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

	/// <summary>
	/// 2�����̍��W�ݒ�
	/// </summary>
	/// <param name="[x]">x���W</param>
	/// <param name="[y]">y���W</param>
	void SetPos(T x, T y);

	/// <summary>
	/// 3�����̍��W�ݒ�
	/// </summary>
	/// <param name="[x]">x���W</param>
	/// <param name="[y]">y���W</param>
	/// <param name="[z]">z���W</param>
	void SetPos(T x, T y, T z);

	/// <summary>
	/// ���ɂ���Pos�N���X�̒l�����̂܂܃R�s�[����
	/// </summary>
	/// <param name="[pos]">Pos�N���X�̃C���X�^���X</param>
	void SetPos(const Pos pos);

	/// <summary>
	/// ���W�f�[�^��1�擾����
	/// </summary>
	/// <param name="[n]">�f�[�^���i�[����ϐ�</param>
	/// <param name="[type]">x,y,z����I��</param>
	void GetPos(T& n, const char* type) const;

	/// <summary>
	/// ���W�f�[�^��2�擾����
	/// </summary>
	/// <param name="[n1]">1�ڂ̃f�[�^���i�[����ϐ�</param>
	/// <param name="[n2]">2�ڂ̃f�[�^���i�[����ϐ�</param>
	/// <param name="[type]">xy,xz,yz����I��</param>
	void GetPos(T& n1, T& n2,const char* type) const;

	/// <summary>
	/// ���W�f�[�^��3�擾����
	/// </summary>
	/// <param name="[x]">x�̒l���i�[����ϐ�</param>
	/// <param name="[y]">y�̒l���i�[����ϐ�</param>
	/// <param name="[z]">z�̒l���i�[����ϐ�</param>
	void GetPos(T& x, T& y, T& z) const;

	/// <summary>
	/// Pos���m�̑����Z�̌��ʂ�Ԃ�
	/// </summary>
	/// <param name="[rhs]">�E�ӑ�</param>
	/// <returns>Pos�N���X</returns>
	Pos operator+(const Pos &rhs);

	/// <summary>
	/// ���ӂɉE�ӂ𑫂������ʂ�������
	/// </summary>
	/// <param name="[rhs]">�E�ӑ�</param>
	void operator+=(const Pos &rhs);

	/// <summary>
	/// Pos���m�̈����Z�̌��ʂ�Ԃ�
	/// </summary>
	/// <param name="[rhs]">�E�ӑ�</param>
	/// <returns>Pos�N���X</returns>
	Pos operator-(const Pos &rhs);

	/// <summary>
	/// ���ӂ���E�ӂ����������ʂ����ӂɑ������
	/// </summary>
	/// <param name="[rhs]">�E�ӑ�</param>
	void operator-=(const Pos &rhs);

	/// <summary>
	/// Pos���m���r����
	/// </summary>
	/// <param name="[rhs]">�E�ӑ�</param>
	/// <returns>��r�������ʂ𐮐��^��0,1,2,3�̂����ꂩ��Ԃ�</returns>
	/// <memo>0:x,y,z�S�ē������Ȃ�
	///		  1:x,y,z�����ꂩ1����������
	///		  2:x,y,z�����ꂩ2����������
	///		  3:x,y,z�S�Ă�������
	/// </memo>
	int operator ==(const Pos &rhs);
};

template<typename T>
Pos<T>::Pos() : m_x(0), m_y(0), m_z(0)
{
}
template<typename T>
inline Pos<T>::~Pos()
{
}

template <typename T>
void Pos<T>::SetPos(T x, T y)
{
	m_x = x;
	m_y = y;
}
template <typename T>
void Pos<T>::SetPos(T x, T y, T z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

template<typename T>
void Pos<T>::SetPos(const Pos pos)
{
	this->m_x = pos.m_x;
	this->m_y = pos.m_y;
	this->m_z = pos.m_z;
}

template<typename T>
inline void Pos<T>::GetPos(T& n,const char* type) const
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
inline void Pos<T>::GetPos(T& n1, T& n2, const char* type) const
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
inline void Pos<T>::GetPos(T& x, T& y, T& z) const
{
	x = m_x;
	y = m_y;
	z = m_z;
}

template<typename T>
Pos<T> Pos<T>::operator+(const Pos &rhs)
{
	Pos Return;

	Return.m_x = this->m_x + rhs.m_x;
	Return.m_y = this->m_y + rhs.m_y;
	Return.m_z = this->m_z + rhs.m_z;

	return Return;
}

template<typename T>
void Pos<T>::operator+=(const Pos &rhs)
{
	this->m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	this->m_z += rhs.m_z;
}

template<typename T>
Pos<T> Pos<T>::operator-(const Pos &rhs)
{
	Pos Return;

	Return.m_x = this->m_x - rhs.m_x;
	Return.m_y = this->m_y - rhs.m_y;
	Return.m_z = this->m_z - rhs.m_z;

	return Return;
}

template<typename T>
void Pos<T>::operator-=(const Pos& rhs)
{
	this->m_x -= rhs.m_x;
	this->m_y -= rhs.m_y;
	this->m_z -= rhs.m_z;
}

template<typename T>
int Pos<T>::operator==(const Pos& rhs)
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