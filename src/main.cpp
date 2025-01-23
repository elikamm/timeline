#include <state/state.hpp>
#include <window/window.hpp>

int main(int argc, char **argv)
{
    state state({});
    window window;

    while(!state.should_quit() && !window.should_quit())
    {
        state.update();
        window.render(&state);
    }

    return 0;
}