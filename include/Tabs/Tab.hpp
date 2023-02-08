#ifndef TAB_HPP
#define TAB_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

#define TEXT_SIZE 50

namespace Conway {
    class Tab {
        public:
            // Default Constructor
            Tab() = default;

            Tab(std::string);

            // Destructor
            ~Tab();

            void draw(sf::RenderWindow&);

            // Updates infoData
            void update_info(std::string, std::string);

            
        private:
            std::string tabTitle;
            std::unordered_map<std::string, std::string> info;
    };
}

#endif