#pragma once
#include "Texture.h"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <vector>
class Animation
{
public:
	Animation(int totalAnimationFrames, int animationFPS, bool looping);
	~Animation();
	void CutSprite(int posX, int posY, int width, int height);
	SDL_Rect* GetCurrentFrame();
	void Reset();
private:
	Texture* spriteSheet;
	std::vector<SDL_Rect*>* spriteDimensionsList = new std::vector<SDL_Rect*>();
	Uint32 lastFrameTime;
	Uint32 currentFrameTime;
	Uint32 frameTime;
	float mspf;
	int totalAnimationFrames;
	int currentAnimationFrame;
	bool looping;
};

