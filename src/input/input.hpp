#pragma once

#include <config.hpp>
#include <geometry/geometry.hpp>

class input_reader {
    point direction;

    bool jump_pressed;

public:
    input_reader();

    void update();

    point get_direction();
    bool was_jump_pressed();
};