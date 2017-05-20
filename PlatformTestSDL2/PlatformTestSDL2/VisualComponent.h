#pragma once
#include <SDL.h>
#include <stdio.h>
#include "Texture.h"
class VisualComponent
{
public:
	VisualComponent();
	~VisualComponent();
	virtual void Render(int entityX, int entityY, SDL_Renderer* renderer) = 0;
	void SetTexture(Texture* texture);
protected:
	Texture* texture;
};

