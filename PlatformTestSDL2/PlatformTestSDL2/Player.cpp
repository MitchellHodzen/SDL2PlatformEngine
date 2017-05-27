#include "Player.h"
#include <iostream>

Player::Player(float x, float y, int width, int height, float collXOffset, float collYOffset) : Entity(x, y, width, height, collXOffset, collYOffset, false)
{
	velocityX = 0;
	velocityY = 0;
	newVelocityX = 0;
	newVelocityY = 0;
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
}

void Player::Initialize()
{
	currentState = new PlayerState_Idle();
	currentState->Enter(*this);
}

void Player::AddVelocity(float x, float y)
{
	velocityX += x;
	velocityY += y;
	if (velocityX > maxSpeed)
	{
		velocityX = maxSpeed;
	}
	if (velocityY > terminalVelocity)
	{
		velocityY = terminalVelocity;
	}
	if (velocityX < -maxSpeed)
	{
		velocityX = -maxSpeed;
	}
	if (velocityY < -maxJumpSpeed)
	{
		velocityY = -maxJumpSpeed;
	}
}
void Player::AddNewVelocity(float x, float y)
{
	newVelocityX += x;
	newVelocityY += y;
}
void Player::Update(std::vector<Entity*> entityList)
{
	currentState->Update(*this, deltaTime);
	DecideMovement(entityList);
	DecideAnimation();
	CheckJumpTimer();
}
void Player::DecideAnimation()
{
	if (isWallSlidingLeft || isWallSlidingRight)
	{
		SetAnimation(Animations::PlayerAnimations::WallSlide);
	}
	else if (isFalling == true)
	{
		SetAnimation(Animations::PlayerAnimations::Fall);
	}
	else if (isJumping == true)
	{
		SetAnimation(Animations::PlayerAnimations::Jump);
	}
	else if (isRunning == false)
	{
		SetAnimation(Animations::PlayerAnimations::Idle);
	}
	else if (isRunning == true)
	{
		SetAnimation(Animations::PlayerAnimations::Run);
	}
}
void Player::SetAnimation(Animations::AnimationType animationName)
{
	if (!GetAnimationController()->CheckCurrentAnimation(animationName))
	{
		GetAnimationController()->SetCurrentAnimation(animationName);
	}
}
void Player::ApplyExternalForces()
{
	if (isRunning == false || (isRunningLeft && velocityX > 0) || (isRunningRight && velocityX < 0))
	{
		ApplyHorizontalFriction();
	}
	ApplyGravity();
}
void Player::ApplyInternalForces()
{
	AddVelocity(newVelocityX, newVelocityY);
	newVelocityX = 0;
	newVelocityY = 0;
}
void Player::HandleWallSliding()
{
	if (isWallJumping == false)
	{
		if (isWallSlidingLeft == true)
		{
			//AddVelocity(-wallSlideCorrection, 0);
			SetPosX(GetPosX() - 0.5f);
		}
		else if (isWallSlidingRight == true)
		{
			//AddVelocity(wallSlideCorrection, 0);
			SetPosX(GetPosX() + 0.5f);
		}
	}
}
void Player::DecideMovement(std::vector<Entity*> entityList)
{
	ApplyExternalForces();

	ApplyInternalForces();
	HandleWallSliding();
	
	float movementX = velocityX * deltaTime;
	SetPosX(GetPosX() + movementX);
	HandleHorizontalCollisions(entityList);
	float movementY = velocityY * deltaTime;
	SetPosY(GetPosY() + movementY);
	HandleVerticalCollisions(entityList);
	if (velocityY > 0)
	{
		isFalling = true;
		canJump = false;
	}
	else
	{
		isFalling = false;
	}
}

void Player::HandleHorizontalCollisions(std::vector<Entity*> entityList)
{
	bool collided = false;
	for (unsigned i = 0; i < entityList.size(); ++i)
	{
		if (this != entityList[i] && entityList[i]->GetCollider()->GetIsTrigger() == false)
		{
			if (CheckCollisions(entityList[i]->GetCollider()))
			{
				if (GetCollider()->GetPosX() > entityList[i]->GetCollider()->GetPosX())
				{
					SetPosX(entityList[i]->GetCollider()->GetPosX() + entityList[i]->GetCollider()->GetWidth() + collisionResolutionOffset - this->GetCollXOffset());
					if (isFalling == true && jumpHeld == false && isRunningLeft == true)
					{
						isWallSlidingLeft = true;
						velocityY = wallSlideSpeed;
						canWallJump = true;
					}
				}
				else
				{
					SetPosX(entityList[i]->GetCollider()->GetPosX() - GetCollider()->GetWidth() - collisionResolutionOffset - this->GetCollXOffset());
					if (isFalling == true && jumpHeld == false && isRunningRight == true)
					{
						isWallSlidingRight= true;
						velocityY = wallSlideSpeed;
						canWallJump = true;
					}
				}
				velocityX = 0;
				collided = true;
				isWallJumping = false;
			}
		}
	}
	if (collided == false || isFalling == false)
	{
		isWallSlidingLeft = false;
		isWallSlidingRight = false;
		canWallJump = false;
	}
}
void Player::HandleVerticalCollisions(std::vector<Entity*> entityList)
{
	for (unsigned i = 0; i < entityList.size(); ++i)
	{
		if (this != entityList[i] && entityList[i]->GetCollider()->GetIsTrigger() == false)
		{
			if (CheckCollisions(entityList[i]->GetCollider()))
			{
				if (GetCollider()->GetPosY() > (entityList[i]->GetCollider()->GetPosY() + (entityList[i]->GetCollider()->GetHeight()/2)))
				{
					SetPosY(entityList[i]->GetCollider()->GetPosY() + entityList[i]->GetCollider()->GetHeight() + collisionResolutionOffset -this->GetCollYOffset());
				}
				else
				{
					SetPosY(entityList[i]->GetCollider()->GetPosY() - GetCollider()->GetHeight() - collisionResolutionOffset - this->GetCollYOffset());

					isJumping = false;
					canJump = true;
					jumpTimer = 0;
					isWallJumping = false;
				}
				jumpHeld = false;
				velocityY = 0;
			}
		}
	}
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
	if (velocityX < 0)
	{
		velocityX += friction * deltaTime;
		if (velocityX > 0)
		{
			velocityX = 0;
		}
	}
	else if (velocityX > 0)
	{
		velocityX -= friction * deltaTime;
		if (velocityX < 0)
		{
			velocityX = 0;
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

void Player::StopMoving(Direction direction)
{
	switch (direction)
	{
	case Direction::UP:
		//isMovingUp = false;
		break;
	case Direction::DOWN:
		//isMovingDown = false;
		break;
	case Direction::LEFT:
		//isMovingLeft = false;
		isRunningLeft = false;
		break;
	case Direction::RIGHT:
		//isMovingRight = false;
		isRunningRight = false;
		break;
	}
	if (isRunningRight == false && isRunningLeft == false)
	{
		isRunning = false;
	}

}

void Player::ActionKeyPressed(PlayerActions action)
{
	switch (action)
	{
	case PlayerActions::JUMP:
		//std::cout << "Jump: " << canJump << ", " << canWallJump << std::endl;
		if (canJump == true || canWallJump == true)//&& isJumping == false)
		{
			jumpTimer = 0;
			jumpHeld = true;
			isJumping = true;
			canJump = false;
		}
		break;
	}
}
void Player::ActionKeyHeld(PlayerActions action)
{
	switch (action)
	{
	case PlayerActions::MOVE_LEFT:
		Move(action);
		break;
	case PlayerActions::MOVE_RIGHT:
		Move(action);
		break;
	case PlayerActions::JUMP:
		Move(action);
		break;
	}
}
void Player::ActionKeyReleased(PlayerActions action)
{
	switch (action)
	{
	case PlayerActions::MOVE_LEFT:
		StopMoving(Direction::LEFT);
		break;
	case PlayerActions::MOVE_RIGHT:
		StopMoving(Direction::RIGHT);
	case PlayerActions::JUMP:
		//isJumping = false;
		jumpHeld = false;
		StopMoving(Direction::UP);
		break;
	}
}
void Player::Move(PlayerActions action)
{
	switch (action)
	{
	case PlayerActions::JUMP:
		HandleJump();
		break;
	case PlayerActions::MOVE_LEFT:
		//AddVelocity(-acel * deltaTime, 0);
		//newVelocityX += -acel * deltaTime;
		//GetAnimationController()->SetDirectionRight(false);
		//isMovingLeft = true;
		isRunning = true;
		isRunningLeft = true;
		break;
	case PlayerActions::MOVE_RIGHT:
		//AddVelocity(acel * deltaTime, 0);
		//newVelocityX += acel * deltaTime;
		//GetAnimationController()->SetDirectionRight(true);
		//isMovingRight = true;
		isRunning = true;
		isRunningRight = true;
		break;
	}
	//isMoving = true;
}

void Player::HandleJump()
{
	if (jumpHeld == true)
	{
		if (canWallJump == false)
		{
			newVelocityY = -maxJumpSpeed;
		}
		else
		{
			newVelocityY = -maxJumpSpeed;
			isWallJumping = true;
			if (isWallSlidingRight)
			{
				newVelocityX = -maxJumpSpeed;
			}
			else
			{
				newVelocityX = maxJumpSpeed;
			}

		}
	}
}

void Player::GetTiming(Uint32 lastFrameTime, Uint32 currentFrameTime, float deltaTime)
{
	this->deltaTime = deltaTime;
	this->lastFrameTime = lastFrameTime;
	this->currentFrameTime = currentFrameTime;
}
void Player::CheckJumpTimer()
{
	if (isJumping)
	{
		jumpTimer += currentFrameTime - lastFrameTime;
		if (jumpTimer >= maxJumpTime)
		{
			jumpHeld = false;
		}
	}
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
float Player::GetAcceleration()
{
	return acel;
}