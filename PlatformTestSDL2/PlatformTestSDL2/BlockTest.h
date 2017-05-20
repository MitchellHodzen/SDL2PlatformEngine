#pragma once
#include "Entity.h"
#include "SingleImageController.h"
class BlockTest : public Entity
{
public:
	BlockTest(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset, bool isTrigger);
	~BlockTest();
	SingleImageController* GetSingleImageController();
};

