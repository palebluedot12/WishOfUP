#pragma once

class Y_RainScript : public Script
{
private:

	float DropSpeed = 250.f;
	Transform* tr;

public:

	void Start()
	{
		tr = gameobject->GetComponent<Transform>();
	}

	void FixedUpdate()
	{
		tr->position.y += DropSpeed * DELTA;
	}

};