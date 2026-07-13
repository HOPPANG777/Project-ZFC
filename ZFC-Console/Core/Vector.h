//=============================================================================
// File:        Vector.h
//
// Description: 2D 벡터 타입 Vector2 정의.
//
// History:     12/07/2026 + Created -- VicZero, 사용하지 않음(사유: SimpleMath 추가됨)
//
//=============================================================================

#pragma once

//=============================================================================
//
// Synopsis:    Vector2;
//                - 임의로 작성한 2D 벡터 타입.
//                - 벡터/스칼라 사칙연산과 복합대입 연산을 제공한다.
//
//=============================================================================

class Vector2
{
	///////////////////////////////////////////////////////////////////////
	// Member Data
	///////////////////////////////////////////////////////////////////////
public:
	float x;
	float y;

	///////////////////////////////////////////////////////////////////////
	// Constructors
	///////////////////////////////////////////////////////////////////////
public:
	Vector2() : Vector2(0.0f, 0.0f) {}
	Vector2(float x, float y) : x(x), y(y) {}
	Vector2(int x, int y) : Vector2(float(x), float(y)) {}
	Vector2(int x, float y) : Vector2(float(x), y) {}
	Vector2(float x, int y) : Vector2(x, float(y)) {}
	Vector2(const Vector2& other) { *this = other; }

	///////////////////////////////////////////////////////////////////////
	// Assignment Operator
	///////////////////////////////////////////////////////////////////////
public:
	Vector2& operator=(const Vector2& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	///////////////////////////////////////////////////////////////////////
	// Vector Arithmetic Operators
	///////////////////////////////////////////////////////////////////////
public:
	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	///////////////////////////////////////////////////////////////////////
	// Scalar Arithmetic Operators
	///////////////////////////////////////////////////////////////////////
public:
	Vector2 operator*(const float scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	Vector2 operator/(const float scalar) const
	{
		return Vector2(x / scalar, y / scalar);
	}

	///////////////////////////////////////////////////////////////////////
	// Component-wise Arithmetic Operators
	///////////////////////////////////////////////////////////////////////
public:
	// Vector 끼리의 곱셈
	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	// Vector 끼리의 나눗셈
	Vector2 operator/(const Vector2& other) const
	{
		return Vector2(x / other.x, y / other.y);
	}

	///////////////////////////////////////////////////////////////////////
	// Compound Assignment Operators
	///////////////////////////////////////////////////////////////////////
public:
	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

public:
	Vector2& operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2& operator/=(const float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

public:
	// Vector 끼리의 곱셈
	Vector2& operator*=(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	// Vector 끼리의 나눗셈
	Vector2& operator/=(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

};
