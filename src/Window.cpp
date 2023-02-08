#include "../include/Window.hpp"

namespace Conway {

    /**
     * @brief Construct a new Window object
     * 
     * @param int Window width 
     * @param int Window height 
     * @param string title 
     */
    Window::Window(int width, int height, std::string title) : 
        sf::RenderWindow(
            sf::VideoMode(width, height), 
            title, 
            sf::Uint32(sf::Style::Titlebar | sf::Style::Close)
        ) {
        world = World();
        infoTab = Tab("Info");
    }

    /**
     * @brief Runs Game Loop
     * 
     */
    void Window::Initiate () {
        while (isOpen()) {
            // Handle Events
            event_handle();

            // Update Cycle
            if (!paused)
                update();

            // Render Cycle
            clear(sf::Color::Black);    // Clear previous Scene

            render();   // Draw current Scene
            
            display();  // Displays Scene
        }
    }

    /**
     * @brief Handles Window Events
     * 
     */
    void Window::event_handle() {
        sf::Event event;

        while (pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                close();
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Up)
                    world.set_sleep(world.get_sleep() + 100);
                else if (event.key.code == sf::Keyboard::Down)
                    world.set_sleep(world.get_sleep() - 100);
                else if (event.key.code == sf::Keyboard::Space)
                    paused = !paused;
                break;         
            default:
                break;
            }
        }
    }

    /**
     * @brief Handles Update Cycle
     * 
     */
    void Window::update() {
        world.run_generation();
    }

    /**
     * @brief Handles Render Cycle
     * 
     */
    void Window::render() {
        world.draw(*this);

        infoTab.update_info("# Dead:", std::to_string(world.get_dead_cells()));
        infoTab.update_info("# Alive:", std::to_string(world.get_alive_cells()));
        infoTab.update_info("Generation:", std::to_string(world.get_generation()));

        infoTab.draw(*this);
    }
}