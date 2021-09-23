//
//  main.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/20/21.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Cat.hpp"
#include "Wall.hpp"
#include "WallQueue.hpp"
#include "HelperFunction.hpp"
#include "Grass.hpp"

using namespace std;

int main() {
    
    // Set up the render window
    int screenWidth = 1600;
    int screenHeight = 1200;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Flappy Cat");
    window.setFramerateLimit(60);
    
    
    // Load the texture for the wall, grass and cat
    sf::Texture wallTexture;
    wallTexture.loadFromFile("brick_texture.png");
    wallTexture.setRepeated(true);
    
    sf::Texture grassTexture;
    grassTexture.loadFromFile("grass_texture.png");
    grassTexture.setRepeated(true);
    
    sf::Texture catTexture;
    catTexture.loadFromFile("cat_texture.png");
    catTexture.setRepeated(true);
    
    
    // Constructor for the walls, cat and grass
    Cat cat{catTexture};
    WallQueue walls (100, 600, wallTexture);
    Grass grass {100, screenWidth, screenHeight, grassTexture};
    
    // Create a variable to track if the game is over
    bool isGameOver = false;
    
    // Start the game
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                // press Escape to exit
                window.close();
            }
        }
        
        if (isGameOver) { // Do these when the game is over
            
            // Display the cat, walls and grass current position (not moving)
            // as the background for the game over message box
            window.clear(sf::Color(4, 156, 216, 150));
            cat.draw(window);
            walls.draw(window);
            grass.draw(window);
            
            
            // Print out the game over message box
            string  message = "GAME OVER!\n\nSCORE: " + to_string(walls.calculateScore(cat));
            printGameOverMessage(message, sf::Color::Red, screenWidth, screenHeight, window);
            
            window.display();
            
        } else {
            
            // Set the background color
            window.clear(sf::Color(4, 156, 216, 150));
            
            
            // If no key is pressed, the cat naturally drops to the ground
            // and the walls move to the left by 3 pixels/frame
            cat.drop();
            walls.move(-3);
            
            // If the Space key is pressed, the cat jumps by 7 pixels/frame
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                cat.jump(7); // bigger number means cat jumping higher
            }
            
            // The game is over when the cat hits the ceiling/ground
            if (cat.hitGrass(grass) || cat.hitCeiling()) {
                isGameOver = true;
            }
            for (Wall & w: walls.walls) {
                if (w.isCollided(cat)) {
                    isGameOver = true;
                }
            }
            
            // Print out everything in the game window
            cat.draw(window);
            walls.draw(window);
            grass.draw(window);
            
            // Print out the score at the lower right of the screen
            string scoreMessage = "SCORE: " + to_string(walls.calculateScore(cat));
            printMessage(scoreMessage, sf::Color::White, 25, screenWidth - 200, screenHeight - 60, window);
            
            // Display
            window.display();
            
        }
    }
}
