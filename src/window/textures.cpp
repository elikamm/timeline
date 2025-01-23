#include <window/window.hpp>
#include <window/textures.hpp>

void window::load_textures()
{
    texture_ptr = new texture_list();
    texture_list *textures = (texture_list *)texture_ptr;

    Image logo = LoadImageFromMemory(".png", resources::test.data, resources::test.size);

    textures->logo = LoadTextureFromImage(logo);
}

void window::unload_textures()
{
    texture_list *textures = (texture_list *)texture_ptr;

    UnloadTexture(textures->logo);

    delete textures;
}