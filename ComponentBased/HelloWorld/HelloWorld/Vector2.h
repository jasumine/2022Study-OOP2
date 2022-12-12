#pragma once
// 직접 vector2를 구현하기

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Vector2
{
	// 자료형이 T인 변수
	T x;
	T y;

public:
	// Vector2(T x, T y) = delete; // 이런 기능은 쓰지않겠다는 의미
	Vector2(T x, T y) : x(x), y(y) {};
	// Vector2(const T& x, const T& y) : x(x), y(y) {}; // 자료형이 T 인 x, y 를 입력받아서 x, y에 넣어준다. (복사 생성자를 방지하기위해 const & 를 사용)
	// Vector2() : x(0), y(0) {}; // constructor / Vector2() : Vector(0, 0) {}; // 위랑 의미임
	Vector2() : Vector2((T)0, (T)0) {};
	Vector2(const Vector2& other) = default; // copy constructor , 컴파일러가 알아서 만들어주는걸 쓰겠다.
	virtual ~Vector2() {} // destructor , virtual은 상속할때만 쓰기

	// u형을 t형으로 바꿔서 T형의 생성자 함수를 써서 값을 return
	/* template<typename U>
	Vector2(const Vector2<U>& other)
		: x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) 
	{} */

	void set(T x, T y) { this->x = x, this->y = y; }

	Vector2 operator+ (const Vector2& other) const
	{
		/* 다 같은 결과이지만, 다른 방식
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
	
	
	template<typename U> // 원래는 밖에 선언해야하지만 x,y 에 직접접근하기 위해서 안에서 선언
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

