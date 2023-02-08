#include "include/Window.hpp"

#define WIDTH 1200
#define HEIGHT 800

int main() {

    // Create Window Instance
    Conway::Window window(WIDTH, HEIGHT, "Conway's Game of Life");

    // Game Loop
    window.Initiate();

    return 0;
}