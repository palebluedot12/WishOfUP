#pragma once

class GameResource;

class Animation : public GameResource
{
public:

	Animation();
	~Animation();

	bool Load(Sprite* _sprite, std::vector<std::pair<int, float>>& _arr);

	void SetOwner(Animator* _ptr) { owner = _ptr; }
	Animator* GetOwner() { return owner; }
	Sprite* GetImage() { return image; }
	std::vector<std::pair<int, float>>& GetClip() { return animationClip; }

	void CopyAnimation(Animation* _ani);

private:
	// 나중에 확인하고 지워 필요없어
	Animator* owner;
	Sprite* image;
	// 프레임별로 스프라이트 인덱스랑 프레임카운트를 저장합니다
	std::vector<std::pair<int, float>> animationClip;

};