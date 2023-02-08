#include "../include/Cell.hpp"

namespace Conway {

    /**
     * @brief Construct a new Cell:: Cell object
     * 
     * @param bool alive status 
     * @param int x coordinate 
     * @param int y coordinate
     */
    Cell::Cell(bool status, int x, int y) 
    : alive(status) {
        cell = sf::RectangleShape(sf::Vector2f(CELL_DIM, CELL_DIM));
        cell.setPosition(sf::Vector2f(x, y));
        alive ? 
            cell.setFillColor(sf::Color::Red) 
            :
            cell.setFillColor(sf::Color::White); 
    }

    /**
     * @brief Draw Cell onto Screen
     * 
     * @param sf::RenderWindow& window 
     */
    void Cell::draw(sf::RenderWindow& window) {
        window.draw(cell);
    }

    /**
     * @brief Kill off Cell and set fillColor to White
     * 
     */
    void Cell::kill() {
        alive = false;
        cell.setFillColor(sf::Color::White);
    }

    /**
     * @brief Revive Cell and set fillColor to Red
     * 
     */
    void Cell::revive() {
        alive = true;
        cell.setFillColor(sf::Color::Red);
    }

    /**
     * @brief Return if Cell is alive or not
     * 
     * @return true | false 
     */
    bool Cell::is_alive() { return alive; }
}