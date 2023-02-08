#include "../include/World.hpp"

namespace Conway {

    /**
     * @brief Runs a game iteration
     * 
     */
    void World::run_generation() {
        alive = dead = 0;
        generation++;

        for (int i = 0; i < gridLength; i++) {
            bool alive = grid[i].is_alive();
            int n = get_neighbors(i);

            if (alive) {
                if (n <= 1 || n >= 4)
                    newGrid[i] = false;
            } 
            else {
                if (n == 3)
                    newGrid[i] = true;
            }
        }

        for (int i = 0; i < gridLength; i++) {

            if (newGrid[i]) {
                alive++;
                grid[i].revive();
            } else {
                dead++;
                grid[i].kill();
            }
        }
    }

    /**
     * @brief Draw Grid onto Screen
     * 
     * @param sf::RenderWindow& window 
     */
    void World::draw(sf::RenderWindow& window) {
        for (int i = 0; i < gridLength; i++) {
            grid[i].draw(window);
        }

        draw_borders(window);
        sf::sleep(sf::milliseconds(sleepInterval));
    }

    /**
     * @brief Generates Cells to populate World
     * 
     */
    void World::generate_data() {
        grid = new Cell[gridLength];
        newGrid = new bool[gridLength];
        alive = dead = 0;
        
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, gridLength);

        for (int i = 0; i < gridLength; i++) {
            int val = dist(rng);

            int x = get_x_coordinate(i);
            int y = get_y_coordinate(i);

            if (val % 2 == 0) {
                alive++;
                newGrid[i] = true;
            } else {
                dead++;
                newGrid[i] = false;
            }

            newGrid[i] ? 
                grid[i] = Cell(true, x, y) 
                : 
                grid[i] = Cell(false, x,  y);
        }
    }

    /**
     * @brief Draw Borders onto Screen
     * 
     * @param sf::RenderWindow& window 
     */
    void World::draw_borders(sf::RenderWindow& window) {
        sf::RectangleShape borders[2];

        // Bottom Border
        borders[0].setSize(sf::Vector2f(WORLD_DIM, BORDER_DIM));
        borders[0].setPosition(sf::Vector2f(0, WORLD_DIM-BORDER_DIM));
        
        // Right Border
        borders[1].setSize(sf::Vector2f(WORLD_DIM, BORDER_DIM));
        borders[1].setPosition(sf::Vector2f(WORLD_DIM, 0));
        borders[1].rotate(90);

        // Draw Borders
        for (int i = 0; i < 2; i++) {
            borders[i].setFillColor(sf::Color::Black);
            window.draw(borders[i]);
        }

        sf::RectangleShape linesV[((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM))];

        for (int i = 0; i < ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM)); i++) {
            linesV[i].setSize(sf::Vector2f(WORLD_DIM, BORDER_DIM));
            linesV[i].setPosition(sf::Vector2f(BORDER_DIM + ((CELL_DIM+BORDER_DIM)*i), 0));
            linesV[i].setFillColor(sf::Color::Black);
            linesV[i].rotate(90);
        }
        for (int i = 0; i < ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM)); i++) {
            window.draw(linesV[i]);
        }

        sf::RectangleShape linesH[((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM))];

        for (int i = 0; i < ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM)); i++) {
            linesH[i].setSize(sf::Vector2f(WORLD_DIM, BORDER_DIM));
            linesH[i].setPosition(sf::Vector2f(0, (CELL_DIM+BORDER_DIM)*i));
            linesH[i].setFillColor(sf::Color::Black);
        }
        for (int i = 0; i < ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM)); i++) {
            window.draw(linesH[i]);
        }
    }

    /**
     * @brief Returns the number of neighbors of the cell
     * 
     * @param int index 
     * @return int number of neighbors 
     */
    int World::get_neighbors(int index) {
        int count = 0;

        // (x,y) coordinates
        int x = get_x_coordinate(index);
        int y = get_y_coordinate(index);

        // 8 possible neighbor locations
        count += is_alive(x - (CELL_DIM + BORDER_DIM), y - (CELL_DIM + BORDER_DIM));
        count += is_alive(x, y - (CELL_DIM + BORDER_DIM));
        count += is_alive(x + (CELL_DIM + BORDER_DIM), y - (CELL_DIM + BORDER_DIM));
        count += is_alive(x + (CELL_DIM + BORDER_DIM), y);
        count += is_alive(x + (CELL_DIM + BORDER_DIM), y + (CELL_DIM + BORDER_DIM));
        count += is_alive(x - (CELL_DIM + BORDER_DIM), y + (CELL_DIM + BORDER_DIM));
        count += is_alive(x, y + (CELL_DIM + BORDER_DIM));
        count += is_alive(x - (CELL_DIM + BORDER_DIM), y);

        return count;
    }

    /**
     * @brief 
     * 
     * @param int x coordinate 
     * @param int y coordinate
     * @return true | false 
     */
    bool World::is_alive(int x, int y) {
        if (x >= 0 && x < WORLD_DIM) {
            if (y >= 0 && y < WORLD_DIM) {
                int index = get_index(x, y);
                return grid[index].is_alive();
            }
        }
        return false;
    }

    /**
     * @brief Returns the index of the cell at the current coordinates
     * 
     * @param int x coordinate 
     * @param int y coordinate 
     * @return int index
     */
    int World::get_index(int x, int y) {
        return ((x-BORDER_DIM)/(CELL_DIM + BORDER_DIM)) + ((y/(CELL_DIM + BORDER_DIM)*((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM))));
    }

    /**
     * @brief Returns X Coordinate
     * 
     * @param int index 
     * @return int x Coordinate 
     */
    int World::get_x_coordinate(int index) {
        return BORDER_DIM + (BORDER_DIM + CELL_DIM)*(index%((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM)));
    }

    /**
     * @brief Returns Y Coordinate
     * 
     * @param int index
     * @return int y Coordinate 
     */
    int World::get_y_coordinate(int index) {
        return BORDER_DIM + (BORDER_DIM + CELL_DIM)*(index/((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM)));
    }
}