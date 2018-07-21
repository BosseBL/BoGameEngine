/*
 *  BO_GraphicsCORE.cpp
 *  BO
 *
 *  Created by Daniel Lindfors on 6/8/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#include "BO_GraphicsCore.h"


BO_Animation::BO_Animation() {}
BO_Animation::~BO_Animation() {}

void BO_Animation::update() {}
void BO_Animation::setRepetitions(int reps) {}
void BO_Animation::pause() {}
void BO_Animation::resume() {}
void BO_Animation::reset() {}
void BO_Animation::jumpToFrame(int frame) {}
void BO_Animation::setTexture(int frame, int texture) {}
void BO_Animation::setDelay(int frame, Uint32 delay) {}
void BO_Animation::draw(float x, float y) {}



BO_AnimationManager::BO_AnimationManager() {}
BO_AnimationManager::~BO_AnimationManager() {}
int BO_AnimationManager::createAnimation(vector<int> frames, vector<Uint32> delay) {}
int BO_AnimationManager::createAnimation(vector<int> frames, Uint32 delay) {}
void BO_AnimationManager::remove(int animation) {}
void BO_AnimationManager::removeAll() {}
void BO_AnimationManager::play(int animation) {}
void BO_AnimationManager::playAll() {}
void BO_AnimationManager::update(int animation) {}
void BO_AnimationManager::updateAll() {}
void BO_AnimationManager::resume(int animation) {}
void BO_AnimationManager::resumeAll() {}
void BO_AnimationManager::setRepetitions(int animation, int repetitions) {}
void BO_AnimationManager::reset(int animation) {}
void BO_AnimationManager::resetAll() {}
void BO_AnimationManager::jumpToFrame(int animation, int frame) {}
void BO_AnimationManager::drawAnimation(int animation, float x, float y) {}



BO_TextureManager::BO_TextureManager() {}
BO_TextureManager::~BO_TextureManager() {}
int BO_TextureManager::loadTextureFromFile(string filename) {}
int BO_TextureManager::loadTextureFromMemory(SDL_Surface* surface) {}
vector<int> BO_TextureManager::loadTexturesByFileList(string filelist) {}
void BO_TextureManager::reloadTextures() {}
int BO_TextureManager::createTextureSection(int textureID, SDL_Rect section) {}
void BO_TextureManager::removeTexture(int textureID) {}
void BO_TextureManager::removeAllTextures() {}
void BO_TextureManager::removeTextureSection(int textureSectionID) {}
void BO_TextureManager::remveAllTextureSections() {}
void BO_TextureManager::drawTexture(int textureID, int x, int y) {}
void BO_TextureManager::drawTextureSection(int textureSectionID, int x, int y) {}
int BO_TextureManager::getTextureWidth(int textureID) {}
int BO_TextureManager::getTextureHeight(int textureID) {}



BO_Camera::BO_Camera() {}
BO_Camera::~BO_Camera() {}
void BO_Camera::move(int dX, int dY) {}
void BO_Camera::setPosition(int x, int y) {}




BO_Graphics::BO_Graphics() {}
BO_Graphics::~BO_Graphics() {}
void BO_Graphics::initialize(int width, int height) {}
void BO_Graphics::shutDown() {}




