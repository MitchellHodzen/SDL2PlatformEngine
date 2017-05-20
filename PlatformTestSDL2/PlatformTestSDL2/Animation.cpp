#include "Animation.h"

#include <iostream>

Animation::Animation(int totalAnimationFrames, int animationFPS, bool looping)
{
	this->mspf = 1000.0f / animationFPS;
	lastFrameTime = 0;
	currentFrameTime = 0;
	currentAnimationFrame = 0;
	this->totalAnimationFrames = totalAnimationFrames;
	this->looping = looping;
}


Animation::~Animation()
{
	for (unsigned i = 0; i < spriteDimensionsList->size(); ++i)
	{
		delete (*spriteDimensionsList)[i];
	}
	delete spriteDimensionsList;
}

void Animation::CutSprite(int posX, int posY, int width, int height)
{
	SDL_Rect* sprite = new SDL_Rect{ posX, posY, width, height };
	spriteDimensionsList->push_back(sprite);
}
void Animation::Reset()
{
	lastFrameTime = SDL_GetTicks();
	currentFrameTime = SDL_GetTicks();
	currentAnimationFrame = 0;
}

SDL_Rect* Animation::GetCurrentFrame()
{
	lastFrameTime = currentFrameTime;
	currentFrameTime = SDL_GetTicks();
	frameTime += currentFrameTime - lastFrameTime;
	std::cout << frameTime << std::endl;
	if (frameTime >= mspf)
	{
		while (frameTime >= mspf)
		{
			frameTime -= (int)mspf;
			currentAnimationFrame++;
		}
		if (currentAnimationFrame >= totalAnimationFrames)
		{
			if (looping == true)
			{
				currentAnimationFrame = 0;
			}
			else
			{
				currentAnimationFrame = totalAnimationFrames - 1;
			}
		}
		//std::cout << currentAnimationFrame << std::endl;

	}
	return (*spriteDimensionsList)[currentAnimationFrame];
}
