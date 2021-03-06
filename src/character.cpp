#include "character.hpp"
#include "behaviouralstate.hpp"
#include <iostream>

Character::Character(std::string characterType, glm::vec2 spritePos, bool interactive, const fea::Texture& texture, glm::vec2 spriteSize, bool scaled) :
    mCharacterType(characterType),
    mScaled(scaled),
    mInteractive(interactive)
{
    (void)mInteractive;

    mSprite.setTexture(texture);
    mSprite.setSize(spriteSize);
    mSprite.setPosition(spritePos);
    mSprite.setOrigin(glm::vec2(spriteSize.x / 2.0f, spriteSize.y));
}

const fea::AnimatedQuad& Character::getSprite() const
{
    return mSprite;
}

fea::AnimatedQuad& Character::getSprite()
{
    return mSprite;
}

std::deque<std::shared_ptr<BehaviouralState>>& Character::getBehaviouralStates()
{
    return mBehaviouralStates;
}

void Character::clearBehaviours()
{
    mBehaviouralStates.clear();
}

void Character::pushBehaviour(std::shared_ptr<BehaviouralState> state)
{
    mBehaviouralStates.push_back(state);
}

glm::vec2 Character::getPosition()
{
    return mSprite.getPosition();
}

void Character::setPosition(glm::vec2 pos)
{
    mSprite.setPosition(pos);
}

void Character::update()
{
    mSprite.tick();

    if(!mBehaviouralStates.empty())
    {
        std::shared_ptr<BehaviouralState> state = mBehaviouralStates.front();
        if(!state->mSwitchedTo)
        {
            state->setOwner(this);
            state->switchTo();
        }
        state->update();
    }
}

bool Character::topBehaviourFinished()
{
    return mBehaviouralStates.front()->mFinished;
}

void Character::popTopBehaviour()
{
    mBehaviouralStates.pop_front();
}
