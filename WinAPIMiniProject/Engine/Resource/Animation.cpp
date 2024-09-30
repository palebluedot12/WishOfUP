#include "Framework.h"

Animation::Animation()
	: GameResource(ResourceType::Animation)
	, owner(nullptr)
	, image(nullptr)
	, animationClip{}
{
}

Animation::~Animation()
{
}

bool Animation::Load(Sprite* _sprite, std::vector<std::pair<int, float>>& _arr)
{
	image = _sprite;
	animationClip = _arr;
	return true;
}

void Animation::CopyAnimation(Animation* _ani)
{
	this->owner = _ani->owner;
	this->image = _ani->image;
	this->animationClip = _ani->animationClip;
}
