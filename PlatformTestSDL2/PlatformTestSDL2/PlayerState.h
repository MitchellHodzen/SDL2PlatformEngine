#pragma once
//#include "State.h"
#include <vector>
#include "Actions.h"
#include "AnimationNames.h"

class Player;
class Entity;
class PlayerState//: public State
{
public:
	enum class Direction {LEFT, RIGHT, TOP, BOTTOM, NONE};
	virtual ~PlayerState() {}
	virtual void Enter(Player& player) {}
    virtual void Exit() {}
	virtual PlayerState* GetInput(Player& player, PlayerActions action, InputType type) {return nullptr;}
    virtual PlayerState* Update(Player& player, std::vector<Entity*> entityList) {return nullptr;}
	PlayerState* Transition(Player& player, PlayerState* newState);
};