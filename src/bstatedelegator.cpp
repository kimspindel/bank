#include "bstatedelegator.hpp"
#include <iostream>

BehaviouralStateDelegator::BehaviouralStateDelegator(fea::MessageBus& bus, std::list<Character>& characters) :
    mBus(bus),
    mCharacters(characters)
{
}

void BehaviouralStateDelegator::playerWalk(glm::vec2 destination)
{
    mCharacters.front().clearBehaviours();

    std::shared_ptr<WalkingBState> walkState = std::make_shared<WalkingBState>(mBus, destination, 3.0f);
    std::shared_ptr<IdleBState> idleState = std::make_shared<IdleBState>(mBus);

    mCharacters.front().pushBehaviour(walkState);
    mCharacters.front().pushBehaviour(idleState);
}

void BehaviouralStateDelegator::gameBehaviour(glm::vec2 destination, std::string game)
{
    mCharacters.front().clearBehaviours();

    std::shared_ptr<WalkingBState> walkState = std::make_shared<WalkingBState>(mBus, destination, 3.0f);
    std::shared_ptr<IdleBState> idleState = std::make_shared<IdleBState>(mBus);
    std::shared_ptr<BehaviouralState> gameState;
    if(game == "ticket_machine")
    {
        gameState = std::make_shared<TicketBState>(mBus);
    }
    else if(game == "painting")
    {
        gameState = std::make_shared<PaintingBState>(mBus);
    }
    else if(game == "crossword")
    {
        gameState = std::make_shared<CrosswordBState>(mBus);
    }
    else if(game == "sudoku")
    {
        gameState = std::make_shared<SudokuBState>(mBus);
    }
    else if(game == "check")
    {
        gameState = std::make_shared<CheckBState>(mBus);
    }
    else if(game == "viewnote")
    {
        gameState = std::make_shared<SelfBState>(mBus);
    }
    else if(game == "cashier")
    {
        gameState = std::make_shared<CashierBState>(mBus);
    }
    else if(game == "outdoors")
    {
        gameState = std::make_shared<OutdoorBState>(mBus);
    }

    if(game != "viewnote")
    {
        mCharacters.front().pushBehaviour(walkState);
    }
    mCharacters.front().pushBehaviour(gameState);
    mCharacters.front().pushBehaviour(idleState);
}

void BehaviouralStateDelegator::update()
{
    for(auto& iter : mCharacters)
    {
        if(iter.topBehaviourFinished())
        {
            iter.popTopBehaviour();
        }
    }
}
