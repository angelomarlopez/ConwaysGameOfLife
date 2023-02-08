#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

#define CELL_DIM 6

namespace Conway {
    class Cell {
        public:
            // Default Constructor
            Cell() = default;

            // Overloaded Constructor (status, x coordinate, y coordinate)
            Cell(bool, int, int);

            // Draw Cell onto Screen
            void draw(sf::RenderWindow&);

            // Kill off Cell
            void kill();

            // Revive Cell
            void revive();

            // Return if Cell is alive or not
            bool is_alive();
        
        private:
            bool alive;
            sf::RectangleShape cell;
    };
}

#endif