#pragma once
#include "PlayerState.h"

class TestPlayerState: public PlayerState
{
public:
	TestPlayerState();
	~TestPlayerState();
	void Enter(Player& player);
    void Exit();
	void GetInput(Player& player);
    void Update(Player& player);
};