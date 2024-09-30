#pragma once
class Y_LaserBeamDown : public Script
{
private:
	Transform* tr;
	RectCollider* rc;
	Spriterenderer* sp;

	// 바람 애니메이션 전용
	GameObject* Laser;
	Transform* Laser_tr;
	Animator* Laser_an;
public:

	void Start()
	{
		tr = gameobject->GetComponent<Transform>();
		rc = gameobject->AddComponent<RectCollider>();
		sp = gameobject->AddComponent<Spriterenderer>();

		Laser = gameobject->CreateChild("Laser_Down_Ani");
		Laser_an = Laser->AddComponent<Animator>();
		Laser_tr = Laser->AddComponent<Transform>();

		Laser_an->AddAnimation(L"LaserDownAnimation", resource->Find<Animation>(L"LaserDownAni"));
		Laser_an->ActiveAnimation(L"LaserDownAnimation", true);


		tr->scale = { (float)sp->GetSprite()->GetWidth(),(float)sp->GetSprite()->GetHeight() };
		rc->size.x = tr->scale.x / 6;
		rc->offset.x = tr->scale.x - tr->scale.x / 1.8f;

		int _hei = Laser_an->GetActiveAnimation()->GetImage()->GetHeight();
		int _wid = Laser_an->GetActiveAnimation()->GetImage()->GetWidth();
		Laser_tr->scale = { (float)_wid, (float)_hei };
		Laser_tr->position = { 0, 0 };
	}

	void SetPos(Vector2 _pos)
	{
		tr->position = _pos;
	}

};

