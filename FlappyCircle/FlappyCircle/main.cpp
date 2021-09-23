//
//  main.cpp
//  FlappyBirdClone
//
//  Created by Quang Pham on 9/20/21.
//

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/Shape.hpp>


#include "Bird.hpp"
#include "Wall.hpp"
#include "Walls.hpp"
#include <vector>

using namespace std;






int main() {
    
    int screenWidth = 1600;
    int screenHeight = 1200;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "My window");
    window.setFramerateLimit(60);
    
    
    
    Bird bird{};
    Walls walls;
    
    long count = 0;
    
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        
        
        bird.drop();
        
        
        if (bird.hitGround(screenHeight) || bird.hitCeiling()) {
            
            bird.bounce();
            // print out GAME OVER
            
        }
        
        
        if (bird.hitCeiling()) {

            bird.ricochet();
            // print out GAME OVER

        }
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            
            bird.bounce();
            
        }
        
        walls.move(-3);
        
        
        window.clear(sf::Color::White);
        
        bird.draw(window);
        walls.draw(window);
        
        window.display();
        
        
        count ++;
        
    }
    
}
