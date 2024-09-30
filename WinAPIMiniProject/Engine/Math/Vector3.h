#pragma once

class Vector2 {
private:

public:

	float x = 0.f;
	float y = 0.f;
	float z = 0.f;

	static Vector2 zero;

	// ������
	Vector2(float _x = 0, float _y = 0, float _z = 0);
	~Vector2() {}

	// ������ ũ�� ���
	float Magnitude();
	// ������ ����ȭ
	Vector2 Normalize();
	// �� ������ ���� ���
	float DotProduct(const Vector2& val);
	// �� ������ ���� ���
	Vector2 CrossProduct(const Vector2& val);

	// ���۷����� ����
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