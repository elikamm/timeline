#pragma once

#include <state/state.hpp>

class window {
    void *texture_ptr;

    void load_textures();
    void unload_textures();

public:
    window();
    ~window();

    bool should_quit();
    void render(state *);
};