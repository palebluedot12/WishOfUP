#pragma once

class RectCollider;
class CircleCollider;

class Collider : public Component
{
public:

	virtual void Render() = 0;

	bool isActive;

	Vector2 offset = { 0,0 };
	Vector2 size;
private:
};

class RectCollider : public Collider
{ 
public:

	RectCollider();
	~RectCollider();

	virtual void Initialize()override;
	virtual void Render()override;

private:
};

class CircleCollider : public Collider
{
public:

	CircleCollider();
	~CircleCollider();

	virtual void Initialize()override;


	virtual void Render()override;

private:

	float radius;

};
