#pragma once
#include "PlayerState_Airborne.h"

class PlayerState_Jump: public PlayerState_Airborne
{
public:
	PlayerState_Jump();
	virtual ~PlayerState_Jump();
	virtual void Enter(Player& player);
    virtual void Exit();
	virtual PlayerState* GetInput(Player& player, PlayerActions action, InputType type);
    virtual PlayerState* Update(Player& player, std::vector<Entity*> entityList);
private:
    Uint32 jumpTimer;
    float maxJumpTime;
};