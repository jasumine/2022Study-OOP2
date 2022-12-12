#pragma once
// ���� vector2�� �����ϱ�

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Vector2
{
	// �ڷ����� T�� ����
	T x;
	T y;

public:
	// Vector2(T x, T y) = delete; // �̷� ����� �����ʰڴٴ� �ǹ�
	Vector2(T x, T y) : x(x), y(y) {};
	// Vector2(const T& x, const T& y) : x(x), y(y) {}; // �ڷ����� T �� x, y �� �Է¹޾Ƽ� x, y�� �־��ش�. (���� �����ڸ� �����ϱ����� const & �� ���)
	// Vector2() : x(0), y(0) {}; // constructor / Vector2() : Vector(0, 0) {}; // ���� �ǹ���
	Vector2() : Vector2((T)0, (T)0) {};
	Vector2(const Vector2& other) = default; // copy constructor , �����Ϸ��� �˾Ƽ� ������ִ°� ���ڴ�.
	virtual ~Vector2() {} // destructor , virtual�� ����Ҷ��� ����

	// u���� t������ �ٲ㼭 T���� ������ �Լ��� �Ἥ ���� return
	/* template<typename U>
	Vector2(const Vector2<U>& other)
		: x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) 
	{} */

	void set(T x, T y) { this->x = x, this->y = y; }

	Vector2 operator+ (const Vector2& other) const
	{
		/* �� ���� ���������, �ٸ� ���
		Vector2 temporary;
		temporary.set(this->x + other.x, this->y + other.y);
		temporary.x = this->x + other.x;
		tmeporary.y = this->y + other.y;
		*/
		return Vector2(this->x + other.x, this->y + other.y);
	}
	/*
	template <typename U> /*
	auto operator* (int scale)
	{
		return Vector2{ this->x * scale, this->y * scale };
	}
	Vector2 operator*(U scale) const
	{
		// return Vector2{ this->X * scale ,this->y * sclale };
		return Vector2{ static_cast<T>(this->x * scale), static_cast<T>(this->y * scale) };
	}
	*/

	template<typename U>
	Vector2 operator*(U scale) const
	{
		return Vector2{ static_cast<T>(this->x * scale), static_cast<T>(this->y * scale) };
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Vector2{ this->x * other.x, this->y * other.y };
	}

	template<typename U>
	Vector2 operator/ (U scale) const
	{
		return Vector2{ static_cast<T>(this->x / scale), static_cast<T>(this->y / scale) };
	}

	Vector2 operator- (const Vector2& other) const
	{
		return Vector2(this->x - other.x, this->y - other.y);
	}
	
	
	template<typename U> // ������ �ۿ� �����ؾ������� x,y �� ���������ϱ� ���ؼ� �ȿ��� ����
	friend Vector2 operator*(U scale, const Vector2& other)
	{
		return other.operator*<U>(scale);
	}

	void reset() { set(0, 0); }

	template<typename U>
	Vector2& operator=(U factor) 
	{
		set(factor, factor);
		return *this; // cahining
	}

	friend ostream& operator<<(ostream& os, const Vector2& pos)
	{
		os << "(" << pos.x << ", " << pos.y << ")";
		return os;
	}
	
	friend istream& operator>>(istream& is,  Vector2& v)
	{
		is >> v.x >> v.y;
		return is;
	}

	auto sqrMagnitude() const
	{
		return (this->x * this->x + this->y * this->y);
	}


	double magnitude() const
	{
		return sqrt(this->sqrMagnitude());
	}
	

	static Vector2<int> zero;
	static Vector2<int> one;

};

