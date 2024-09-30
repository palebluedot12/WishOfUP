#pragma once

class Y_DashEffectScript : public Script
{
private:
	
public:

	Spriterenderer* sp;
	int tick_Count = 30;

	void Start()
	{
		sp = gameobject->GetComponent<Spriterenderer>();
	}

	void FixedUpdate()
	{
		float _alpha = ((float)tick_Count / (float)60);
		sp->SetColor(1, 1, 1, _alpha, false);
		if (tick_Count > 0)
			tick_Count--;
	}
};