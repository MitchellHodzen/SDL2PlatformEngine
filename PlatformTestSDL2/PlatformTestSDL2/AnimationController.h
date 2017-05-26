#pragma once
#include <iostream>
#include "Animation.h"
#include <map>
#include "AnimationNames.h"
//#include <string>
#include <SDL.h>
#include <stdio.h>
#include "VisualComponent.h"

class AnimationController: public VisualComponent
{
public:
	AnimationController();
	~AnimationController();
	void SetCurrentAnimation(Animations::AnimationType animationName);
	void AddAnimation(Animation* animation, Animations::AnimationType  name);
	void SetAnimationMap(std::map<Animations::AnimationType , Animation*> animationMap);
	SDL_Rect* GetAnimationFrameRect();
	void Render(int entityX, int entityY, SDL_Renderer* renderer);
	bool CheckCurrentAnimation(Animations::AnimationType  animationToCheck);
	void SetDirectionRight(bool isReft);
private:
	Animation* currentAnimation;
	std::map<Animations::AnimationType , Animation*>animationMap;
	SDL_RendererFlip rendererFlip;

};

