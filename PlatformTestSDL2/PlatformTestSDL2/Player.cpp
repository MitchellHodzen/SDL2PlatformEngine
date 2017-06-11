#include "Player.h"

//Beginning state
#include "PlayerState_Idle.h"

Player::Player(float x, float y, int width, int height, float collXOffset, float collYOffset) : Entity(x, y, width, height, collXOffset, collYOffset, false)
{
	velocity = new Vector2(0.0f, 0.0f);
	newVelocity = new Vector2(0.0f, 0.0f);
	maxSpeed = 300.0f;
	friction = 1500.0f;
	gravity = 1500.0f;
	terminalVelocity = 700.0f;
	acel = 700.0f;
	maxJumpSpeed = 300.0f;
	maxJumpTime = 0.2f * 1000.0f;
	visualComponent = new AnimationController();
	velocityZeroingBounds = 5.0f;
	collisionResolutionOffset = .0001f;
	wallSlideCorrection = 10.0f;
	wallSlideSpeed = 80.0f;
	jumpTimer = 0;
	GetAnimationController()->SetDirectionRight(true);
}


Player::~Player()
{
	delete velocity;
	velocity = nullptr;
	delete newVelocity;
	newVelocity = nullptr;
}

void Player::Initialize()
{
	currentState = new PlayerState_Idle();
	currentState->Enter(*this);
}

void Player::SetState(PlayerState* state)
{
	currentState = state;
}

PlayerState* Player::GetState()
{
	return currentState;
}

void Player::AddVelocity(float x, float y)
{
	velocity->Add(x, y);	
	if (velocity->GetX() > maxSpeed)
	{
		velocity->SetX(maxSpeed);
	}
	else if (velocity->GetX() < -maxSpeed)
	{
		velocity->SetX(-maxSpeed);
	}
	if (velocity->GetY() > terminalVelocity)
	{
		velocity->SetY(terminalVelocity);
	}
	else if (velocity->GetY() < -maxJumpSpeed)
	{
		velocity->SetY(-maxJumpSpeed);
	}
}
void Player::AddNewVelocity(float x, float y)
{
	newVelocity->Add(x, y);
}
void Player::SetVelocityX(float x)
{
	velocity->SetX(x);
}

void Player::SetVelocityY(float y)
{
	velocity->SetY(y);
}
float Player::GetVelocityY()
{
	return velocity->GetY();
}
void Player::SetNewVelocityY(float y)
{
	newVelocity->SetY(y);
}
void Player::SetNewVelocityX(float x)
{
	newVelocity->SetX(x);
}
void Player::Update(std::vector<Entity*> entityList)
{
	PlayerState* newState = currentState->Update(*this, entityList);
	if (newState != nullptr)
	{
		delete currentState;
		currentState = newState;
	}
}

void Player::SetAnimation(Animations::AnimationType animationName)
{
	if (!GetAnimationController()->CheckCurrentAnimation(animationName))
	{
		GetAnimationController()->SetCurrentAnimation(animationName);
	}
}

void Player::ApplyInternalForces()
{
	AddVelocity(newVelocity->GetX(), newVelocity->GetY());
	newVelocity->SetX(0.0f);
	newVelocity->SetY(0.0f);
}
void Player::HandleWallSliding(PlayerState::Direction direction)
{
	if (direction == PlayerState::Direction::LEFT)
	{
		SetPosX(GetPosX() - 0.5f);
	}
	else
	{
		SetPosX(GetPosX() + 0.5f);
	}
}
PlayerState::Direction Player::MoveHorizontal(std::vector<Entity*> entityList)
{
	float movementX = velocity->GetX() * deltaTime;
	SetPosX(GetPosX() + movementX);
	return HandleHorizontalCollisions(entityList);
}
PlayerState::Direction Player::MoveVertical(std::vector<Entity*> entityList)
{
	float movementY = velocity->GetY() * deltaTime;
	SetPosY(GetPosY() + movementY);
	return HandleVerticalCollisions(entityList);	
}


PlayerState::Direction Player::HandleHorizontalCollisions(std::vector<Entity*> entityList)
{
	PlayerState::Direction direction = PlayerState::Direction::NONE;
	for (unsigned i = 0; i < entityList.size(); ++i)
	{
		if (this != entityList[i] && entityList[i]->GetCollider()->GetIsTrigger() == false)
		{
			if (CheckCollisions(entityList[i]->GetCollider()))
			{
				if (GetCollider()->GetPosX() > entityList[i]->GetCollider()->GetPosX())
				{
					SetPosX(entityList[i]->GetCollider()->GetPosX() + entityList[i]->GetCollider()->GetWidth() + collisionResolutionOffset - this->GetCollXOffset());
					direction = PlayerState::Direction::LEFT;
				}
				else
				{
					SetPosX(entityList[i]->GetCollider()->GetPosX() - GetCollider()->GetWidth() - collisionResolutionOffset - this->GetCollXOffset());
					direction = PlayerState::Direction::RIGHT;
				}
				//velocityX = 0;
				SetVelocityX(0);
			}
		}
	}
	return direction;
}
PlayerState::Direction Player::HandleVerticalCollisions(std::vector<Entity*> entityList)
{
	PlayerState::Direction direction = PlayerState::Direction::NONE;
	for (unsigned i = 0; i < entityList.size(); ++i)
	{
		if (this != entityList[i] && entityList[i]->GetCollider()->GetIsTrigger() == false)
		{
			if (CheckCollisions(entityList[i]->GetCollider()))
			{
				if (GetCollider()->GetPosY() > (entityList[i]->GetCollider()->GetPosY() + (entityList[i]->GetCollider()->GetHeight()/2)))
				{
					SetPosY(entityList[i]->GetCollider()->GetPosY() + entityList[i]->GetCollider()->GetHeight() + collisionResolutionOffset -this->GetCollYOffset());
					direction = PlayerState::Direction::TOP;
				}
				else
				{
					SetPosY(entityList[i]->GetCollider()->GetPosY() - GetCollider()->GetHeight() - collisionResolutionOffset - this->GetCollYOffset());
					direction = PlayerState::Direction::BOTTOM;
				}
				SetVelocityY(0);
			}
		}
	}
	return direction;
}

bool Player::CheckCollisions(Collider* other)
{
	if ((GetCollider()->GetPosX() + GetCollider()->GetWidth() < other->GetPosX()) || (GetCollider()->GetPosX() > (other->GetPosX() + other->GetWidth())) ||
		(GetCollider()->GetPosY() + GetCollider()->GetHeight() < other->GetPosY()) || (GetCollider()->GetPosY() > (other->GetPosY() + other->GetHeight())))
	{
		return false;
	}
	return true;
}

void Player::ApplyHorizontalFriction()
{
	if (velocity->GetX() < 0)
	{
		velocity->Add(friction * deltaTime, 0.0f);
		if (velocity->GetX() > 0)
		{
			velocity->SetX(0.0f);
		}
	}
	else if (velocity->GetX() > 0)
	{
		velocity->Add(-(friction * deltaTime), 0.0f);
		if (velocity->GetX() < 0)
		{
			velocity->SetX(0.0f);
		}
	}
}
void Player::ApplyGravity()
{
	AddVelocity(0, gravity * deltaTime);
}

AnimationController* Player::GetAnimationController()
{
	return (AnimationController*)visualComponent;
}

void Player::GetTiming(Uint32 lastFrameTime, Uint32 currentFrameTime, float deltaTime)
{
	this->deltaTime = deltaTime;
	this->lastFrameTime = lastFrameTime;
	this->currentFrameTime = currentFrameTime;
}

void Player::GetInput(PlayerActions action, InputType type)
{
	PlayerState* newState = currentState->GetInput(*this, action, type);
	if (newState != nullptr)
	{
		delete currentState;
		currentState = newState;
	}
}
void Player::Accelerate(PlayerState::Direction direction)
{
	//Accelerates the player in the horizontal direction 
	if (direction == PlayerState::Direction::RIGHT)
	{	
		//If the player is switching directions, make them change directions faster
		if (velocity->GetX() < 0)
		{
			ApplyHorizontalFriction();
		}
        	AddNewVelocity(acel * deltaTime, 0.0f);
	    	GetAnimationController()->SetDirectionRight(true);
	}
    	else
    	{
		if (velocity->GetX() > 0)
		{
			ApplyHorizontalFriction();
		}
       		 AddNewVelocity(-acel * deltaTime, 0.0f);
	    	GetAnimationController()->SetDirectionRight(false);
    	}
}

float Player::GetMaxJumpSpeed()
{
	return maxJumpSpeed;
}
float Player::GetWallSlideSpeed()
{
	return wallSlideSpeed;
}
Uint32 Player::GetLastFrameTime()
{
	return lastFrameTime;
}
Uint32 Player::GetCurrentFrameTime()
{
	return currentFrameTime;
}
