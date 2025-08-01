#pragma once

#include <Windows.h>

#include "Core.h"

class Engine_API Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2();

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	bool operator==(const Vector2& other) const;

	// 형변환 연산자 오버로딩 (반환형이 없음)
	operator COORD();
	operator COORD() const;

	const char* ToString();

	static Vector2 Zero;
	static Vector2 One;
	static Vector2 Up;
	static Vector2 Right;

public:
	int x = 0;
	int y = 0;
	
private:
	char* buffer = nullptr;

};