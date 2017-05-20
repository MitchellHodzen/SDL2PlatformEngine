#include "AnimationController.h"



AnimationController::AnimationController()
{
}


AnimationController::~AnimationController()
{
}

void AnimationController::AddAnimation(Animation* animation, std::string name)
{
	if (animationMap.count(name) != 0)
	{
		std::cout << "Name already exists in Animation Map: " << name << std::endl;
	}
	else
	{
		animationMap[name] = animation;
	}
}

void AnimationController::SetCurrentAnimation(std::string animationName)
{
	if (animationMap.count(animationName) != 0)
	{
		currentAnimation = animationMap[animationName];
		currentAnimation->Reset();
	}
	else
	{
		std::cout << "That animation does not exist: " << animationName << std::endl;
	}
}
void AnimationController::SetAnimationMap(std::map<std::string, Animation*> animationMap)
{
	this->animationMap = animationMap;
}
SDL_Rect* AnimationController::GetAnimationFrameRect()
{
	return currentAnimation->GetCurrentFrame();
}
//void AnimationController::SetTexture(Texture* texture)
//{
//	this->texture = texture;
//}
void AnimationController::Render(int entityX, int entityY, SDL_Renderer* renderer)
{
	texture->Render(entityX, entityY, GetAnimationFrameRect(), renderer, rendererFlip);
}
bool AnimationController::CheckCurrentAnimation(std::string animationToCheck)
{
	if (currentAnimation == animationMap[animationToCheck])
	{
		return true;
	}
	return false;
}
void AnimationController::SetDirectionRight(bool isReft)
{
	if (isReft == true)
	{
		rendererFlip = SDL_FLIP_NONE;
	}
	else
	{
		rendererFlip = SDL_FLIP_HORIZONTAL;
	}
}