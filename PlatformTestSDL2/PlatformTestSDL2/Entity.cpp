#include "Entity.h"
#include <iostream>


Entity::Entity(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset, bool isTrigger)
{
	//rect = new SDL_Rect{ (int)x, (int)y, width, height };
	//this->collSizeOffset = collOffset * 2;
	col = new Collider(x + collXOffset, y + collYOffset, collWidth, collHeight, isTrigger);
	posX = x;
	posY = y;
	//this->width = width;
	//this->height = height;
	this->collXOffset = collXOffset;
	this->collYOffset = collYOffset;
	//std::cout << GetCollider()->GetWidth() << std::endl;
}


Entity::~Entity()
{
	//delete rect;
	//rect = nullptr;
	delete col;
	col = nullptr;
	//delete animationController;
	//animationController = nullptr;
	delete visualComponent;
	visualComponent = nullptr;
}

//void Entity::Render(SDL_Renderer* renderer)
//{
//	if (texture != nullptr)
//	{
//		texture->Render((int)posX, (int)posY, renderer);
//	}
//	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	//(renderer, GetCollider()->GetRect()); //Debug: Draws the colliders
//}

void Entity::SetPosX(float x)
{
	posX = x;
	col->SetPosX(x + collXOffset);
}
void Entity::SetPosY(float y)
{
	posY = y;
	col->SetPosY(y + collYOffset);
}
void Entity::SetColliderWidth(int width)
{
	//this->width = width;
	col->SetWidth(width);
}
void Entity::SetColliderHeight(int height)
{
	//this->height = height;
	col->SetHeight(height);
}

float Entity::GetPosX()
{
	return posX;
}
float Entity::GetPosY()
{
	return posY;
}
//int Entity::GetWidth()
//{
//	return width;
//}
//int Entity::GetHeight()
//{
//	return height;
//}
float Entity::GetCollXOffset()
{
	return collXOffset;
}
float Entity::GetCollYOffset()
{
	return collYOffset;
}
Collider* Entity::GetCollider()
{
	return col;
}
//SDL_Rect* Entity::GetRect()
//{
//	return rect;
//}

//void Entity::ResetRect()
//{
//	delete rect;
//	rect = new SDL_Rect{ (int)posX, (int)posY, width, height };
//}

//void Entity::SetTexture(Texture* texture)
//{
//	this->texture = texture;
//}
//Texture* Entity::GetTexture()
//{
//	return texture;
//}

//AnimationController* Entity::GetAnimationController()
//{
//	return animationController;
//}
VisualComponent* Entity::GetVisualComponent()
{
	return visualComponent;
}