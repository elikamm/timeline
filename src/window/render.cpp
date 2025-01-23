#include <window/window.hpp>
#include <window/textures.hpp>

void window::render(state *state)
{
    texture_list *textures = (texture_list *)texture_ptr;


    BeginDrawing();

    ClearBackground(WHITE);

    DrawTexture(textures->logo, 0, 0, WHITE);

    EndDrawing();
}