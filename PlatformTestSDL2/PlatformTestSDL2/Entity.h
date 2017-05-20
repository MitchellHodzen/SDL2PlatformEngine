#pragma once
#include <SDL.h>
#include <stdio.h>
#include"Collider.h"
#include "Texture.h"
#include "VisualComponent.h"
class Entity
{
public:
	Entity(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset, bool isTrigger);
	~Entity();

	//void Render(SDL_Renderer* renderer);
	void SetPosX(float x);
	void SetPosY(float y);
	void SetColliderWidth(int width);
	void SetColliderHeight(int height);

	float GetPosX();
	float GetPosY();
	//int GetWidth();
	//int GetHeight();
	float GetCollXOffset();
	float GetCollYOffset();
	Collider* GetCollider();
	//void SetTexture(Texture* texture);
	//Texture* GetTexture();
	//AnimationController* GetAnimationController();
	VisualComponent* GetVisualComponent();
	//SDL_Rect* GetRect(); 

private:
	//SDL_Rect* rect;
	Collider* col;
	float posX;
	float posY;
	//int width;
	//int height;
	float collXOffset;
	float collYOffset;
	float collSizeOffset;

	//Texture* texture;
	//void ResetRect();
	//AnimationController* animationController = new AnimationController();
protected:
	VisualComponent* visualComponent;
};

