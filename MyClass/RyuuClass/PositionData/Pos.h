/*
 * @file Pos.h
 * @brief 座標データの管理に使用
 * @author 青木雄一郎
 * @date 作成日：04/14/2024
 *
 * @date 04/14 基盤作成
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
		* @brief 2次元の座標設定
		* @param x x座標
		* @param y y座標
		*/
	void SetPos(T x, T y);

	/**
		* @brief 3次元の座標設定
		* @param x x座標
		* @param y y座標
		* @param z z座標
		*/
	void SetPos(T x, T y, T z);

	/**
	 * @brief 既にあるPosクラスの値をそのままコピーする
	 * @param pos Posクラスのインスタンス
	 */
	void SetPos(const Pos pos);

	/**
	* @brief 座標データを1つ取得する
	 * @tparam Argu
	 * @param n データを格納する変数
	 * @param type x,y,zから選ぶ
	 */
	void GetPos(T& n, const char* type) const;

	/**
	 * @brief 座標データを2つ取得する
	 * @tparam Argu
	 * @param n1 1つ目のデータを格納する変数
	 * @param n2 2つ目のデータを格納する変数
	 * @param type xy,xz,yzから選ぶ
	 */
	void GetPos(T& n1, T& n2,const char* type) const;

	/**
	 * @brief 座標データを3つ取得する
	 * @tparam Argu
	 * @param x xの値を格納する変数
	 * @param y yの値を格納する変数
	 * @param z zの値を格納する変数
	 */
	void GetPos(T& x, T& y, T& z) const;

	/**
	 * @brief Pos同士の足し算の結果を返す
	 * @param rhs 右辺側
	 * @return Posクラス
	 */
	Pos operator+(const Pos &rhs);

	/**
	 * @brief 左辺に右辺を足した結果を代入する
	 * @param rhs 右辺側
	 */
	void operator+=(const Pos &rhs);

	/**
	 * @brief Pos同士の引き算の結果を返す
	 * @param rhs 右辺側
	 * @return Posクラス
	 */
	Pos operator-(const Pos &rhs);

	/**
	 * @brief 左辺から右辺を引いた結果を左辺に代入する
	 * @param rhs 右辺側
	 */
	void operator-=(const Pos &rhs);

	/**
	 * @brief Pos同士を比較する
	 * @param rhs 右辺側
	 * @return 比較した結果を整数型で0,1,2,3のいずれかを返す
	 * @memo	0:x,y,z全て等しくない
	 *			1:x,y,zいずれか1つだけ等しい
	 *			2:x,y,zいずれか2つだけ等しい
	 *			3:x,y,z全てが等しい
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