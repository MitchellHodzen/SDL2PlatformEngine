#pragma once
//#include "State.h"
#include "Player.h"
class Player;
class PlayerState//: public State
{
public:
	PlayerState() {};
	virtual ~PlayerState() {};
	virtual void Enter(Player& player) = 0;
    virtual void Exit() = 0;
	virtual void GetInput(Player& player)= 0;
    virtual void Update(Player& player) = 0;
	void Transition(Player& player, PlayerState* newState);
};