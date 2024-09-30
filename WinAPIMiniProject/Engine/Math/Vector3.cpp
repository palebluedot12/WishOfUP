#include "framework.h"
#include "Vector2.h"

Vector2 Vector2::zero = Vector2(0, 0, 0);

//������
Vector2::Vector2(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}
// ������ ũ�� ���
float Vector2::Magnitude()
{
	return (float)sqrt(x * x + y * y + z * z);
}
// ������ ����ȭ
Vector2 Vector2::Normalize()
{
	Vector2 normal;
	float magnitude = this->Magnitude();
	normal.x = x / magnitude;
	normal.y = y / magnitude;
	normal.z = z / magnitude;
	return normal;
}
// �� ������ ���� ���
float Vector2::DotProduct(const Vector2& val)
{
	return x * val.x + y * val.y + z * val.z;
}
// �� ������ ���� ���
Vector2 Vector2::CrossProduct(const Vector2& val)
{
	return Vector2(y * val.z - z * val.y,
		           z * val.x - x * val.z,
		           x * val.y - y * val.x);
}

// operator������
void Vector2::operator+=(const Vector2& val)
{
	x += val.x;
	y += val.y;
	z += val.z;
}
void Vector2::operator+=(const float val)
{
	x += val;
	y += val;
	z += val;
}

void Vector2::operator-=(const Vector2& val)
{
	x -= val.x;
	y -= val.y;
	z -= val.z;
}
void Vector2::operator-=(const float val)
{
	x -= val;
	y -= val;
	z -= val;
}
Vector2 Vector2::operator+(Vector2 val)
{
	return Vector2(x + val.x, y + val.y, z + val.z);
}

Vector2 Vector2::operator-(Vector2 val)
{
	return Vector2(x - val.x, y - val.y, z - val.z);
}

Vector2 Vector2::operator*(Vector2 val)
{
	return Vector2(x * val.x, y * val.y, z * val.z);
}
Vector2 Vector2::operator*(float val)
{
	return Vector2(x * val, y * val, z * val);
}
Vector2 Vector2::operator/(Vector2 val)
{
	return Vector2(x / val.x, y / val.y, z / val.z);
}
Vector2 Vector2::operator/(float val)
{
	return Vector2(x / val, y / val, z / val);
}
void Vector2::operator=(Vector2 val)
{
	x = val.x;
	y = val.y;
	z = val.z;
}
bool Vector2::operator==(const Vector2& val)
{
	return (x == val.x && y == val.y && z == val.z);
}
