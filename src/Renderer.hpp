#pragma once

#include <raylib.h>
#include <CONFIG.hpp>
#include <GameState.hpp>
#include <Resources.hpp>

class Renderer {
    GameState *state;

    Texture2D logo;

    void load_textures();

public:
    Renderer(GameState *);

    bool should_quit();
    void render();
    void quit();
};