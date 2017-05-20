#pragma once
#include <iostream>
#include "Animation.h"
#include <map>
#include <string>
#include <SDL.h>
#include <stdio.h>
#include "VisualComponent.h"

class AnimationController: public VisualComponent
{
public:
	AnimationController();
	~AnimationController();
	void SetCurrentAnimation(std::string animationName);
	void AddAnimation(Animation* animation, std::string name);
	void SetAnimationMap(std::map<std::string, Animation*> animationMap);
	SDL_Rect* GetAnimationFrameRect();
	void Render(int entityX, int entityY, SDL_Renderer* renderer);
	bool CheckCurrentAnimation(std::string animationToCheck);
	void SetDirectionRight(bool isReft);
private:
	Animation* currentAnimation;
	std::map<std::string, Animation*>animationMap;
	SDL_RendererFlip rendererFlip;

};

