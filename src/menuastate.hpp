#pragma once
#include "activitystate.hpp"
#include <fea/render2d.hpp>

class MenuAState : public ActivityState
{
    public:
        MenuAState(fea::MessageBus& bus, fea::Renderer2D& renderer);
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
};
