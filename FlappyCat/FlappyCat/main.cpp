//
//  main.cpp
//  FlappyCatClone
//
//  Created by Quang Pham on 9/20/21.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cat.hpp"
#include "Wall.hpp"
#include "WallQueue.hpp"
#include "HelperFunction.hpp"
#include "Grass.hpp"
#include <vector>

using namespace std;

int main() {
    
    int screenWidth = 1600;
    int screenHeight = 1200;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Flappy Cat");
    window.setFramerateLimit(60);
    
    sf::Texture texture;
    texture.loadFromFile("brick_texture.png");
    texture.setRepeated(true);
    
    sf::Texture grassTexture;
    grassTexture.loadFromFile("grass_texture.png");
    grassTexture.setRepeated(true);
    
    sf::Texture catTexture;
    catTexture.loadFromFile("cat_texture.png");
    catTexture.setRepeated(true);
    
    Cat cat{catTexture};
    WallQueue walls (100, 600, texture);
    Grass grass {100, screenWidth, screenHeight, grassTexture};
    
    bool isGameOver = false;
    
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
        
        if (isGameOver) {

            window.clear(sf::Color(4, 156, 216, 150));
            cat.draw(window);
            walls.draw(window);
            grass.draw(window);

            string  message = "GAME OVER!\n\nSCORE: " + to_string(walls.calculateScore(cat));
            
            printGameOverMessage(message, sf::Color::Red, screenWidth, screenHeight, window);
            window.display();
            

        } else {
            window.clear(sf::Color(4, 156, 216, 150));
            
            cat.drop();
            
            if (cat.hitGround(grass) || cat.hitCeiling()) {
                isGameOver = true;
            }
            
            for (Wall & w: walls.walls) {
                if (w.isCollided(cat)) {
                    isGameOver = true;
                }
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                cat.bounce();
            }
            
            walls.move(-3);
            
            cat.draw(window);
            walls.draw(window);
            grass.draw(window);
            
            string scoreMessage = "SCORE: " + to_string(walls.calculateScore(cat));
            printMessage(scoreMessage, sf::Color::White, 25, screenWidth - 200, screenHeight - 60, window);
            window.display();
            
        }
    }
}
