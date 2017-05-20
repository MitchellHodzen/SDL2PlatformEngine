#include "Camera.h"

#include <iostream>

Camera::Camera(float posX, float posY, int width, int height, int levelWidth, int levelHeight)
{
	this->posX = posX;
	this->posY = posY;
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
	this->posX = posX;
}

void Camera::SetPosY(float posY)
{
	this->posY = posY;
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
	return posX;
}

float Camera::GetPosY()
{
	return posY;
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
		posX = ((target->GetCollider()->GetPosX() + (float)target->GetCollider()->GetWidth() / 2) - ((float)width / 2));
		posY = ((target->GetCollider()->GetPosY() + (float)target->GetCollider()->GetHeight() / 2) - ((float)height / 2));
	}
	if (posX < 0)
	{
		posX = 0;
	}
	if (posX + width > levelWidth)
	{
		posX = (float)levelWidth - width;
	}
	if (posY < 0)
	{
		posY = 0;
	}
	if (posY + height > levelHeight)
	{
		posY = (float)levelHeight - height;
	}
}