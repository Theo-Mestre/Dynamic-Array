#pragma once

#include <iostream>

#ifdef LOG_TEST
#define LOG(x) std::cout << x
#else
#define LOG(x)
#endif

class Vector2
{
public:
	float x;
	float y;

	Vector2(float _x, float _y)
		: x(_x), y(_y) {}

	Vector2()
		: x(1.0f), y(1.0f) {}

	Vector2(const Vector2& _other)
		: x(_other.x), y(_other.y)
	{
		LOG("Copy\n");
	}

	Vector2(Vector2&& _other) noexcept
		: x(_other.x), y(_other.y)
	{
		LOG("Move\n");
	}

	~Vector2()
	{
		LOG("Destroy\n");
	}

	Vector2& operator=(Vector2&& _other) noexcept
	{
		LOG("Move\n");

		x = _other.x;
		y = _other.y;
		return *this;
	}

	Vector2& operator=(const Vector2& _other)
	{
		LOG("Copy\n");

		x = _other.x;
		y = _other.y;
		return *this;
	}

	bool operator==(const Vector2& _other) const
	{
		return x == _other.x && y == _other.y;
	}

	friend std::ostream& operator<<(std::ostream& _stream, const Vector2& _array)
	{
		_stream << _array.x << " " << _array.y;
		return _stream;
	}
};
