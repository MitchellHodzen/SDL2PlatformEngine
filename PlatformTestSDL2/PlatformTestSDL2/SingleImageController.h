#pragma once
#include "Texture.h"
#include "VisualComponent.h"
#include <SDL.h>
#include <stdio.h>
class SingleImageController : public VisualComponent
{
public:
	SingleImageController();
	~SingleImageController();
	void Render(int entityX, int entityY, SDL_Renderer* renderer);
	void SetCurrentSpriteRect(int posX, int posY, int width, int height);
private:
	SDL_Rect* currentSpriteRect;
};

