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
	// ���߿� Ȯ���ϰ� ���� �ʿ����
	Animator* owner;
	Sprite* image;
	// �����Ӻ��� ��������Ʈ �ε����� ������ī��Ʈ�� �����մϴ�
	std::vector<std::pair<int, float>> animationClip;

};