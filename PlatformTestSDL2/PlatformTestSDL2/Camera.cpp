#include "Camera.h"

#include <iostream>

Camera::Camera(float posX, float posY, int width, int height, int levelWidth, int levelHeight)
{
	//this->posX = posX;
	//this->posY = posY;
	this->position = new Vector2(posX, posY);
	this->width = width;
	this->height = height;
	this->levelWidth = levelWidth;
	this->levelHeight = levelHeight;
	target = nullptr;
}

Camera::~Camera()
{
}

void Camera::SetPosX(float posX)
{
	//this->posX = posX;
	this->position->SetX(posX);
}

void Camera::SetPosY(float posY)
{
	//this->posY = posY;
	this->position->SetY(posY);
}

void Camera::SetWidth(int width)
{
	this->width = width;
}

void Camera::SetHeight(int height)
{
	this->height = height;
}

float Camera::GetPosX()
{
	//return posX;
	return this->position->GetX();
}

float Camera::GetPosY()
{
	return this->position->GetY();
	//return posY;
}

int Camera::GetWidth()
{
	return width;
}

int Camera::GetHeight()
{
	return height;
}

void Camera::SetTarget(Entity* newTarget)
{
	target = newTarget;
}

void Camera::Reset()
{
	//Camera currently centers on the targets collider position
	if (target != nullptr)
	{
		position->SetX(((target->GetCollider()->GetPosX() + (float)target->GetCollider()->GetWidth() / 2) - ((float)width / 2)));
		
		position->SetY(((target->GetCollider()->GetPosY() + (float)target->GetCollider()->GetHeight() / 2) - ((float)height / 2)));
	}
	if (position->GetX() < 0)
	{
		position->SetX(0.0f);
	}
	if (position->GetX() + width > levelWidth)
	{
		position->SetX((float)levelWidth - width);
	}
	if (position->GetY() < 0)
	{
		position->SetY(0.0f);
	}
	if (position->GetY() + height > levelHeight)
	{
		position->SetY((float)levelHeight - height);
	}
}
