#pragma once
#include "activitystate.hpp"
#include <fea/render2d.hpp>

class TakeNoteAState : public ActivityState
{
    public:
        TakeNoteAState(fea::MessageBus& bus, fea::Renderer2D& renderer);
        virtual void update() override;
        virtual void render() override;
        virtual void handleMouseMove(const glm::uvec2& position) override;
        virtual void handleMouseClick(const glm::uvec2& position) override;
        virtual void handleMouseRelease(const glm::uvec2& position) override;
    private:
        fea::Texture mBackgroundTexture;
        fea::Quad mBackground;
        fea::Texture mBackButtonTexture;
        fea::Quad mBackButton;
        fea::Texture mNoteTexture;
        fea::Quad mNoteQuad;
        fea::Texture mNoteNumberTexture;
        fea::AnimatedQuad mFirstNumber;
        fea::AnimatedQuad mSecondNumber;
};
