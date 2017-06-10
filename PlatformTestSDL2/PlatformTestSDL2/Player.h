#pragma once
#include "Entity.h"
#include <vector>
#include <string>
#include "AnimationController.h"
#include "Actions.h"
#include "AnimationNames.h"
#include "PlayerState.h"
#include "Vector2.h"
class Player : public Entity
{
public:
	enum class Direction {UP, DOWN, LEFT, RIGHT};
	//enum class Action {RUNLEFT, RUNRIGHT, JUMP};
	Player(float x, float y, int width, int height, float collXOffset, float collYOffset);
	~Player();

	void AddVelocity(float x, float y);
	void SetVelocityX(float velocityX);
	void SetVelocityY(float velocityY);
	float GetVelocityY();
	void AddNewVelocity(float x, float y);
	void SetNewVelocityX(float newVelocityX);
	void SetNewVelocityY(float newVelocityY);

	void Update(std::vector<Entity*> entityList);
	AnimationController* GetAnimationController();

	void ApplyHorizontalFriction();
	void ApplyGravity();

	void GetTiming(Uint32 lastFrameTime, Uint32 currentFrameTime, float deltaTime);

	void GetInput(PlayerActions action, InputType type);

	void SetAnimation(Animations::AnimationType animationName);

	void Initialize();
	void SetState(PlayerState* state);
	PlayerState* GetState();
	void Accelerate(PlayerState::Direction direction);
	PlayerState::Direction MoveHorizontal(std::vector<Entity*> entityList);
	PlayerState::Direction MoveVertical(std::vector<Entity*> entityList);
	
	PlayerState::Direction HandleHorizontalCollisions(std::vector<Entity*> entityList);
	PlayerState::Direction HandleVerticalCollisions(std::vector<Entity*> entityList);
	void ApplyInternalForces();

	void HandleWallSliding(PlayerState::Direction direction);

	float GetMaxJumpSpeed();
	float GetWallSlideSpeed();
	Uint32 GetLastFrameTime();
	Uint32 GetCurrentFrameTime();

private:
	PlayerState* currentState;
	//float velocityX;
	//float velocityY;
	Vector2* velocity;
	float newVelocityX;
	float newVelocityY;
	Vector2* newVelocity;
	float velocityZeroingBounds;
	float maxSpeed;
	float terminalVelocity;
	float gravity;
	float friction;
	float acel;
	bool CheckCollisions(Collider* other);
	float collisionResolutionOffset;

	bool isRunningLeft = false, isRunningRight = false;
	bool isRunning = false;
	bool isJumping = false;
	bool isFalling = true;
	bool canJump = false;
	bool jumpHeld = false;
	float maxJumpSpeed;
	float maxJumpTime;
	Uint32 jumpTimer;
	bool isWallSlidingRight = false;
	bool isWallSlidingLeft = false;

	float deltaTime;
	Uint32 lastFrameTime;
	Uint32 currentFrameTime;

	float wallSlideCorrection;
	float wallSlideSpeed;
	bool canWallJump = false;
	bool isWallJumping = false;
	void HandleJump();
	void CheckJumpTimer();

};

