#pragma once

#include <raylib.h>

class GameState {

public:
    bool should_quit();
    void update();
    void quit();
};