#include <main.hpp>

int main(int argc, char **argv)
{
    GameState *state = new GameState();
    Renderer *renderer = new Renderer(state);

    while (!state->should_quit() && !renderer->should_quit())
    {
        state->update();
        renderer->render();
    }

    renderer->quit();
    state->quit();

    return 0;
}