#include <window/window.hpp>
#include <config.hpp>
#include <raylib.h>

window::window()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow
    (
        DEFAULT_WINDOW_WIDTH * DEFAULT_WINDOW_SCALE,
        DEFAULT_WINDOW_HEIGHT * DEFAULT_WINDOW_SCALE,
        WINDOW_TITLE
    );

    SetTargetFPS(TARGET_FPS);

    load_textures();
}

window::~window()
{
    unload_textures();

    CloseWindow();
}

bool window::should_quit()
{
    return WindowShouldClose();
}