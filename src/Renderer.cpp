#include <Renderer.hpp>
#include <iostream>

Renderer::Renderer(GameState *state) : state(state)
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

void Renderer::load_textures()
{
    Image logo_image = LoadImageFromMemory(".png", Resources::Test.data, Resources::Test.size);

    logo = LoadTextureFromImage(logo_image);
}

bool Renderer::should_quit()
{
    return false;
}

void Renderer::render()
{
    BeginDrawing();

    ClearBackground(WHITE);

    DrawTexture(logo, 0, 0, WHITE);

    EndDrawing();
}

void Renderer::quit()
{
    UnloadTexture(logo);

    CloseWindow();
}