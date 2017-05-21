#pragma once
#include "Entity.h"
#include <vector>
#include "AnimationController.h"
class Player : public Entity
{
public:
	enum class Direction {UP, DOWN, LEFT, RIGHT};
	enum class Action {RUNLEFT, RUNRIGHT, JUMP};
	Player(float x, float y, int width, int height, float collXOffset, float collYOffset);
	~Player();
	void AddVelocity(float x, float y);
	void DecideMovement(std::vector<Entity*> entityList);
	void DecideAnimation();
	void Update(std::vector<Entity*> entityList);
	AnimationController* GetAnimationController();
	void ApplyHorizontalFriction();
	void ApplyGravity();
	void StopMoving(Direction direction);

	void ActionKeyPressed(Action action);
	void ActionKeyHeld(Action action);
	void ActionKeyReleased(Action action);
	void Move(Action action);
	void GetTiming(Uint32 lastFrameTime, Uint32 currentFrameTime, float deltaTime);
	float velocityY;

private:
	float velocityX;
	//float velocityY;
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
	bool isRunningLeft, isRunningRight;
	bool isRunning;

	bool isJumping;
	bool isFalling;
	bool canJump;
	bool jumpHeld;
	float maxJumpSpeed;
	float maxJumpTime;
	Uint32 jumpTimer;

	bool isWallSlidingRight;
	bool isWallSlidingLeft;

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
	bool canWallJump;
	bool isWallJumping;
	void HandleJump();
	void CheckJumpTimer();
};

