#pragma once

#include <level/level.hpp>
#include <vector>

class state {
public:
    state(std::vector<level *>);
    ~state();

    bool should_quit();
    void update();
};