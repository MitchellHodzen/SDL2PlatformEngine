#pragma once
#include "PlayerState.h"
#include "Player.h"

class PlayerState_Airborne: public PlayerState
{
public:
	PlayerState_Airborne(){}
	virtual ~PlayerState_Airborne(){}
	virtual void Enter(Player& player){}
    virtual void Exit(){}
	virtual PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    virtual PlayerState* Update(Player& player, std::vector<Entity*> entityList);
protected:
    bool movingHorizontal = false;
	Direction currentDirection;
};