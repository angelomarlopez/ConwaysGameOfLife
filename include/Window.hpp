#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "World.hpp"
#include "Tabs/Tab.hpp"

namespace Conway {
    class Window : public sf::RenderWindow {
        public:
            // Overloaded Constructor
            Window(int, int, std::string);
            
            // Runs Game Loop
            void Initiate();
        
        private:
            World world;    // World Instance
            Tab infoTab;

            bool paused;

            // Handle Window Events
            void event_handle();

            // Handles Update Cycle
            void update();

            // Handles Render Cycle
            void render();
    };
}

#endif