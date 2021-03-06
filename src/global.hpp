#pragma once
#include <string>
#include <unordered_map>
#include "texturemaker.hpp"

extern std::unordered_map<std::string, std::string> gTextures;
extern std::unordered_map<std::string, std::unordered_map<std::string, fea::Animation>> gAnimations;
extern bool gPaintingRuined;
extern bool gMenuOver;
extern bool gChequeDone;
extern int32_t gPlayerQueueNumber;
extern int32_t gQueueCounter;
extern int32_t gNoteBrokenState;
extern int32_t gBrokenNotes;

void setupGlobals();
const fea::Animation& getAnimation(const std::string& character, const std::string& animation);
