#pragma once

struct Vector2
{
	float x = 0.f, y = 0.f;

	Vector2() = default;

	Vector2(float valX, float valY)
	{
		x = valX;
		y = valY;
	}

	//x,y에 value만큼 연산
	const Vector2& operator+ (int val)
	{
		return Vector2(x + val, y + val);
	}

	const Vector2& operator- (int val)
	{
		return Vector2(x - val, y - val);
	}

	const Vector2& operator*(int val)
	{
		return Vector2(x * val, y * val);
	}

	const Vector2& operator/(int val)
	{
		return Vector2(x / val, y / val);
	}


	//x,y에 value만큼 operator=연산
	const Vector2& operator+=(int val)
	{
		return Vector2(x += val, y += val);
	}

	const Vector2& operator-=(int val)
	{
		return Vector2(x -= val, y -= val);
	}

	const Vector2& operator*=(int val)
	{
		return Vector2(x *= val, y *= val);
	}

	const Vector2& operator/=(int val)
	{
		return Vector2(x /= val, y /= val);
	}


	//x,y에 Vector2의 x,y만큼 operater= 연산
	const Vector2& operator+= (const Vector2& val)
	{
		return Vector2(x += val.x, y += val.y);
	}

	const Vector2& operator-= (const Vector2& val)
	{
		return Vector2(x -= val.x, y -= val.y);
	}

	const Vector2& operator*=(const Vector2& val)
	{
		return Vector2(x *= val.x, y *= val.y);
	}

	const Vector2& operator/=(Vector2& val)
	{
		return Vector2(x /= val.x, y /= val.y);
	}


	//x,y에 Vector2의 x,y만큼 연산
	const Vector2& operator+ (const Vector2& val)
	{
		return Vector2(x + val.x, y + val.y);
	}

	const Vector2& operator- (const Vector2& val)
	{
		return Vector2(x - val.x, y - val.y);
	}

	const Vector2& operator*(const Vector2& val)
	{
		return Vector2(x * val.x, y * val.y);
	}

	const Vector2& operator/(Vector2& val)
	{
		return Vector2(x / val.x, y / val.y);
	}


	//뒤에 const vector와 연산
	Vector2 operator+ (const Vector2& val)const
	{
		return Vector2(x + val.x, y + val.y);
	}

	Vector2 operator- (const Vector2& val)const
	{
		return Vector2(x - val.x, y - val.y);
	}

	Vector2 operator*(const Vector2& val)const
	{
		return Vector2(x * val.x, y * val.y);
	}

	Vector2 operator*(float scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	Vector2 operator/(Vector2& val)const
	{
		return Vector2(x / val.x, y / val.y);
	}
	Vector2 operator/(const Vector2& val)
	{
		return Vector2(x / val.x, y / val.y);
	}

	bool operator==(const Vector2& other) const {
		return (x == other.x) && (y == other.y);
	}

	float Length() const
	{
		return sqrt(x * x + y * y);
	}

	void Normalize()
	{
		float length = Length();

		x /= length;
		y /= length;
	}

	Vector2 GetNormalized()const
	{
		float length = Length();
		return Vector2(x / length, y / length);
	}

	Vector2 Lerp(const Vector2& start, const Vector2& end, float t)
	{
		return start * (1 - t) + end * t;
	}
};