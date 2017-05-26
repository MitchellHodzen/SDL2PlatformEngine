#pragma once
#include "Texture.h"
#include <vector>
#include <string>
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <map>
#include "Animation.h"
#include "AnimationNames.h"
class MediaManager
{
public:
	MediaManager();
	~MediaManager();
	void CreateTexture(std::string path, SDL_Renderer* renderer);
	Texture* GetTexture(int index);
	void GeneratePlayerAnimations();
	std::map<Animations::AnimationType, Animation*> GetPlayerAnimations();
private:
	std::vector<Texture*> textureVector;
	std::map<Animations::AnimationType, Animation*> playerAnimations;
	int textureAmount;
};

