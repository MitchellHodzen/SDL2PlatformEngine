#include "TestPlayerState.h"
#include <iostream>
TestPlayerState::TestPlayerState()
{
    //nothing
}
TestPlayerState::~TestPlayerState()
{
    //Kill it all
}
void TestPlayerState::Enter(Player& player)
{
    player.AddVelocity(0.0f,0.0f);
    std::cout<<"Enter"<<std::endl;

}
void TestPlayerState::Exit()
{
    //nothing
}
void TestPlayerState::GetInput(Player& player)
{
    //nothing
}
void TestPlayerState::Update(Player& player)
{
    //nothing
}
