#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <Windows.h>

template<typename T>
struct Position { // Vector2 �� ����� �ݿ� (template �ڵ�)
	T x;
	T y;

	Position(T x, T y) : x(x), y(y) {}

	template<typename U>
	Position(const Position<U>& another) : x(static_cast<T>(another.x)), y(static_cast<T>(another.y)) {}

	size_t size() const { return ((size_t)x * y); }

	auto operator+(const Position& other) const
	{
		return Position{ this->x + other.x, this->y + other.y };
	}

	auto operator-(const Position& other) const
	{
		return Position{ this->x - other.x, this->y - other.y };
	}

	template<typename U>
	Position<T>& operator=(const Position<U>& other)
	{
		x = static_cast<T>(other.x); y = static_cast<T>(other.y);
		return *this;
	}

	Position operator*(float scale)
	{
		return Position{ static_cast<T>(x * scale), static_cast<T>(y * scale) };
	}

	Position operator/(float scale)
	{
		return this->operator*(1.0f / scale);
	}

	auto sqrMagnitude() const
	{
		return (double)x * x + y * y;
	}

	auto magnitude() const // �Լ� ��� ���캸��
	{
		return sqrt(sqrMagnitude());
	}

	auto unit() const // ������ ���� vector =  unit vector
	{
		// mag ���� 0.5 ���ϸ� 1�� ������ִ� �ڵ�(����)
		auto mag = static_cast<float>(this->magnitude()); 
		if (mag <= 0.5f) mag = 1.0f;
		return Position{ x, y } / mag;
	}

	auto moveForward(const Position& target, float speed)
	{
		// target �������� �����̱� 
		// direction ���� ���ư���(�ӵ��� ������ �����ϱ�)
		Position pos (*this);
		auto dirUnit = (target - pos).unit();
		pos = pos + dirUnit * speed;
		return pos;
	}

	bool operator==(const Position& other);

	bool operator!=(const Position& other) const
	{
		return !this->operator==(other);
	}

	static Position<T> InvalidPosition;

	friend std::ostream& operator<<(std::ostream& os, const Position& pos)
	{
		os << "(" << pos.x << "," << pos.y << ")";
		return os;
	}
};

typedef Position<int> Dimension;

class Borland {

	static Position<int> CurrentPos;
	static unsigned int MaxWidth;
	static unsigned int MaxHeight;

public:
	static void Initialize(unsigned int n_cols)
	{
		CONSOLE_CURSOR_INFO cci = { 0 };
		cci.dwSize = 25;
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
		SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

		MaxWidth = n_cols;
		MaxHeight = 10;
	}

	static int WhereX()
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.X;
	}
	static int WhereY()
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.Y;
	}
	static void GotoXY(int x, int y)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _COORD{ (SHORT)x, (SHORT)y });
	}
	static void GotoXY(const Position<int>* pos)
	{
		if (!pos) return;
		GotoXY( (*pos).x, (*pos).y);
	}
	static void GotoXY(const Position<int>& pos)
	{
		GotoXY( pos.x, pos.y);
	}
	static void printf(const char* fmt, ...) // �������� �Լ�
	{
		// �ֱٿ� ���� ��ϵ��� Ȯ���ϴ� �뵵(��Ͽ�)
		static char cleaningBuffer[100 + 1];

		GotoXY(CurrentPos.x, 30 + (CurrentPos.y % 10));
		memset(cleaningBuffer, ' ', 100);
		cleaningBuffer[100] = NULL;
		::printf("%s\r[%7d] ", cleaningBuffer, CurrentPos.y);

		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);

		CurrentPos.y++;
	}
};

#endif 
