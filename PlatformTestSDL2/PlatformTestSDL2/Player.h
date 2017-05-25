#pragma once
#include "Entity.h"
#include <vector>
#include "AnimationController.h"
#include "Actions.h"
//Player States:
#include "PlayerState_Idle.h"

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
	//void AddNewVelocity(float x, float y);
	//void SetNewVelocityX(float newVelocityX);
	//void SetNewVeloityY(float newVelocityY);

	void DecideMovement(std::vector<Entity*> entityList);
	void DecideAnimation();

	void Update(std::vector<Entity*> entityList);
	AnimationController* GetAnimationController();

	void ApplyHorizontalFriction();
	void ApplyGravity();

	void StopMoving(Direction direction);

	void ActionKeyPressed(PlayerActions action);
	void ActionKeyHeld(PlayerActions action);
	void ActionKeyReleased(PlayerActions action);
	void Move(PlayerActions action);
	void GetTiming(Uint32 lastFrameTime, Uint32 currentFrameTime, float deltaTime);


private:
	PlayerState* currentState;
	float velocityX;
	float velocityY;
	float newVelocityX;
	float newVelocityY;
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

	void HandleHorizontalCollisions(std::vector<Entity*> entityList);
	void HandleVerticalCollisions(std::vector<Entity*> entityList);
	void ApplyExternalForces();
	void ApplyInternalForces();

	void HandleWallSliding();
	float wallSlideCorrection;
	float wallSlideSpeed;
	bool canWallJump = false;
	bool isWallJumping = false;
	void HandleJump();
	void CheckJumpTimer();

};

