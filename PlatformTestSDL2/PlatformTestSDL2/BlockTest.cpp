#include "BlockTest.h"



BlockTest::BlockTest(float x, float y, int collWidth, int collHeight, float collXOffset, float collYOffset, bool isTrigger) : Entity(x, y, collWidth, collHeight, collXOffset, collYOffset, isTrigger)
{
	visualComponent = new SingleImageController();
}


BlockTest::~BlockTest()
{
}

SingleImageController* BlockTest::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}