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
