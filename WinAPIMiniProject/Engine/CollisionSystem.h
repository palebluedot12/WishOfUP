#pragma once
class CollisionSystem : public Singleton<CollisionSystem>
{

private:
	friend class Singleton;
	CollisionSystem() = default;
	~CollisionSystem() = default;

public:

	bool AABB(RectCollider* left, RectCollider* right);
	POINT AABB_Dir(RectCollider* left, RectCollider* right);

private:
};

