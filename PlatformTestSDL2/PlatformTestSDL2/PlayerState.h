#pragma once
//#include "State.h"
class Player;
class PlayerState//: public State
{
public:
	virtual ~PlayerState() {}
	virtual void Enter(Player& player) {}
    virtual void Exit() {}
	virtual void GetInput(Player& player) {}
    virtual void Update(Player& player) {}
	PlayerState* Transition(Player& player, PlayerState* newState);
};