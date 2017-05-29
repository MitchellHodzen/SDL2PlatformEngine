#pragma once
#include "PlayerState.h"
#include "Player.h"

class PlayerState_WallSlide: public PlayerState
{
public:
	PlayerState_WallSlide(Direction direction);
	~PlayerState_WallSlide();
	void Enter(Player& player);
    void Exit();
	PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    PlayerState* Update(Player& player, std::vector<Entity*> entityList);
protected:
	Direction currentDirection;
};