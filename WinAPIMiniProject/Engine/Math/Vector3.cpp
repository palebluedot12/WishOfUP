#include "framework.h"
#include "Vector2.h"

Vector2 Vector2::zero = Vector2(0, 0, 0);

//생성자
Vector2::Vector2(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}
// 벡터의 크기 계산
float Vector2::Magnitude()
{
	return (float)sqrt(x * x + y * y + z * z);
}
// 벡터의 정규화
Vector2 Vector2::Normalize()
{
	Vector2 normal;
	float magnitude = this->Magnitude();
	normal.x = x / magnitude;
	normal.y = y / magnitude;
	normal.z = z / magnitude;
	return normal;
}
// 두 벡터의 내적 계산
float Vector2::DotProduct(const Vector2& val)
{
	return x * val.x + y * val.y + z * val.z;
}
// 두 벡터의 외적 계산
Vector2 Vector2::CrossProduct(const Vector2& val)
{
	return Vector2(y * val.z - z * val.y,
		           z * val.x - x * val.z,
		           x * val.y - y * val.x);
}

// operator연산자
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
