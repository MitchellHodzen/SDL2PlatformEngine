/*
#pragma once

class State
{
public:
	virtual ~State() {};
	virtual void Enter() {}
    virtual void Exit() = 0;
    virtual void Update() = 0;
	virtual void Transition(State* newState) = 0;
};