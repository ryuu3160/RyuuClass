 /*+===================================================================
	 File: Pos.hpp
	 Summary: 座標データの管理に使用
	 Author: AT12C192 01 青木雄一郎
	 Date: 04/14/2024 初回作成
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
	/// 2次元の座標設定
	/// </summary>
	/// <param name="[x]">x座標</param>
	/// <param name="[y]">y座標</param>
	void SetPos(T x, T y);

	/// <summary>
	/// 3次元の座標設定
	/// </summary>
	/// <param name="[x]">x座標</param>
	/// <param name="[y]">y座標</param>
	/// <param name="[z]">z座標</param>
	void SetPos(T x, T y, T z);

	/// <summary>
	/// 既にあるPosクラスの値をそのままコピーする
	/// </summary>
	/// <param name="[pos]">Posクラスのインスタンス</param>
	void SetPos(const Pos pos);

	/// <summary>
	/// 座標データを1つ取得する
	/// </summary>
	/// <param name="[n]">データを格納する変数</param>
	/// <param name="[type]">x,y,zから選ぶ</param>
	void GetPos(T& n, const char* type) const;

	/// <summary>
	/// 座標データを2つ取得する
	/// </summary>
	/// <param name="[n1]">1つ目のデータを格納する変数</param>
	/// <param name="[n2]">2つ目のデータを格納する変数</param>
	/// <param name="[type]">xy,xz,yzから選ぶ</param>
	void GetPos(T& n1, T& n2,const char* type) const;

	/// <summary>
	/// 座標データを3つ取得する
	/// </summary>
	/// <param name="[x]">xの値を格納する変数</param>
	/// <param name="[y]">yの値を格納する変数</param>
	/// <param name="[z]">zの値を格納する変数</param>
	void GetPos(T& x, T& y, T& z) const;

	/// <summary>
	/// Pos同士の足し算の結果を返す
	/// </summary>
	/// <param name="[rhs]">右辺側</param>
	/// <returns>Posクラス</returns>
	Pos operator+(const Pos &rhs);

	/// <summary>
	/// 左辺に右辺を足した結果を代入する
	/// </summary>
	/// <param name="[rhs]">右辺側</param>
	void operator+=(const Pos &rhs);

	/// <summary>
	/// Pos同士の引き算の結果を返す
	/// </summary>
	/// <param name="[rhs]">右辺側</param>
	/// <returns>Posクラス</returns>
	Pos operator-(const Pos &rhs);

	/// <summary>
	/// 左辺から右辺を引いた結果を左辺に代入する
	/// </summary>
	/// <param name="[rhs]">右辺側</param>
	void operator-=(const Pos &rhs);

	/// <summary>
	/// Pos同士を比較する
	/// </summary>
	/// <param name="[rhs]">右辺側</param>
	/// <returns>比較した結果を整数型で0,1,2,3のいずれかを返す</returns>
	/// <memo>0:x,y,z全て等しくない
	///		  1:x,y,zいずれか1つだけ等しい
	///		  2:x,y,zいずれか2つだけ等しい
	///		  3:x,y,z全てが等しい
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