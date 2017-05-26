#pragma once
//#include "State.h"
#include "Actions.h"
class Player;
class PlayerState//: public State
{
public:
	virtual ~PlayerState() {}
	virtual void Enter(Player& player) {}
    virtual void Exit() {}
	virtual PlayerState* GetInput(Player& player, PlayerActions action, InputType type) {}
    virtual void Update(Player& player) {}
	PlayerState* Transition(Player& player, PlayerState* newState);
};