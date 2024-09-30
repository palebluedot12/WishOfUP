#pragma once

class Vector2 {
private:

public:

	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

	static Vector2 zero;

	// 생성자
	Vector2(float _x = 0, float _y = 0, float _z = 0);
	~Vector2() {}

	// 벡터의 크기 계산
	float Magnitude();
	// 벡터의 정규화
	Vector2 Normalize();
	// 두 벡터의 내적 계산
	float DotProduct(const Vector2& val);
	// 두 벡터의 외적 계산
	Vector2 CrossProduct(const Vector2& val);

	// 오퍼레이터 연산
	void operator+=(const Vector2& val);
	void operator+=(const float val);
	void operator-=(const Vector2& val);
	void operator-=(const float val);

	Vector2 operator+(Vector2 val);

	Vector2 operator-(Vector2 val);

	Vector2 operator*(Vector2 val);
	Vector2 operator*(float val);

	Vector2 operator/(Vector2 val);
	Vector2 operator/(float val);

	void operator=(Vector2 val);
	bool operator==(const Vector2& val);
};