#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
#include <random>

#include "Cell.hpp"

#define WORLD_DIM 800
#define BORDER_DIM 1


namespace Conway {
    class World {
        public:
            // Default Constructor
            World() 
            : gridLength(
                ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM))
                *
                ((WORLD_DIM-BORDER_DIM)/(BORDER_DIM+CELL_DIM))
            ){
                sleepInterval = 500;
                
                generate_data();
            }

            // Runs Generation on World
            void run_generation();

            // Draw Grid onto Screen
            void draw(sf::RenderWindow&);

            /**
             * @brief Get the cells object
             * 
             * @return int Number of Cells
             */
            int get_cells() { return gridLength; }

            /**
             * @brief Get the alive cells object
             * 
             * @return int Alive Cells
             */
            int get_alive_cells() { return alive; }

            /**
             * @brief Get the dead cells object
             * 
             * @return int Dead Cells
             */
            int get_dead_cells() { return dead; }

            /**
             * @brief Get the generation object
             * 
             * @return int Current Generation
             */
            int get_generation() { return generation; }

            /**
             * @brief Get the sleep object - milliseconds
             * 
             * @return Current Sleep Time in Milliseconds
             */
            int get_sleep() { return sleepInterval; }
            
            /**
             * @brief Set the sleep object - milliseconds
             * 
             * @param int t - Sleep Time in Milliseconds
             */
            void set_sleep(int t) { sleepInterval = t; }

        private:
            Cell *grid;
            bool *newGrid;
            int gridLength;

            int generation; // Current Generation
            int alive;      // Current Alive Cells
            int dead;       // Current Dead Cells

            int sleepInterval;  // Sleep Interval

            // Generate Random Grid
            void generate_data();

            // Draw Borders
            void draw_borders(sf::RenderWindow&);

            // Return the number of neighbors
            int get_neighbors(int);

            // Return if Cell is alive at given coordinates
            bool is_alive(int, int);

            // Returns the index with the current coordinates
            int get_index(int, int);

            // Return X Coordinate
            int get_x_coordinate(int);
            
            // Return Y Coordinate
            int get_y_coordinate(int);
    };
}

#endif