#pragma once

class Y_FanObjectScript : public Script
{
private:

	Transform* tr;
	Animator* an;
	RectCollider* rc;

	// 바람 애니메이션 전용
	GameObject* Wind;
	Transform* Wind_tr;
	Animator* Wind_an;

public:

	void Start()
	{
		tr = gameobject->GetComponent<Transform>();
		an = gameobject->AddComponent<Animator>();
		rc = gameobject->AddComponent<RectCollider>();

		an->AddAnimation(L"Fan", resource->Find<Animation>(L"Fan_Ani"));
		an->ActiveAnimation(L"Fan", true);
		int _wid = an->GetActiveAnimation()->GetImage()->GetWidth();
		int _hei = an->GetActiveAnimation()->GetImage()->GetHeight();
		tr->scale = { (float)_wid,(float)_hei };

		Wind = gameobject->CreateChild("Wind_Ani");
		Wind_an = Wind->AddComponent<Animator>();
		Wind_tr = Wind->AddComponent<Transform>();
		Wind_an->AddAnimation(L"Wind", resource->Find<Animation>(L"Wind_Ani"));
		Wind_an->ActiveAnimation(L"Wind", true);
		_hei = Wind_an->GetActiveAnimation()->GetImage()->GetHeight();
		Wind_tr->scale = { (float)_wid, (float)_hei };
		Wind_tr->position = { 0, -(float)_hei };
		rc->size = { (float)_wid, (float)_hei+30.0f };
		rc->offset = { 0, -Wind_tr->scale.y+16.0f };
	}

	void SetPos(Vector2 _pos)
	{
		tr->position = _pos;
	}
};