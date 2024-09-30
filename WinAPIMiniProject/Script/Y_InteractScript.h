#pragma once

class Y_InteractScript : public Script
{
private:
public:

	RectCollider* col;
	Transform* tr;
	Spriterenderer* sp;

	void Start()
	{
		col = gameobject->AddComponent<RectCollider>();
		tr = gameobject->GetComponent<Transform>();
		sp = gameobject->GetComponent<Spriterenderer>();
	}
};