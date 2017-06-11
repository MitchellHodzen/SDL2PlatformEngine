#pragma once
#include "Entity.h"
#include "Vector2.h"
class Camera
{
public:
	Camera(float posX, float posY, int width, int height, int levelWidth, int levelHeight);
	~Camera();
	void SetPosX(float posX);
	void SetPosY(float posY);
	float GetPosX();
	float GetPosY();
	void SetWidth(int width);
	void SetHeight(int height);
	int GetWidth();
	int GetHeight();
	void SetTarget(Entity* newTarget);
	void Reset();
private:
	Entity* target;
	//float posX;
	//float posY;
	Vector2* position;
	int width;
	int height;
	int levelWidth;
	int levelHeight;
};

