//
//  Grass.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef Grass_hpp
#define Grass_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace std;

class Grass {
    
private:
    
    // the rectangle that contains the grasss picture
    sf::Sprite grassRec_;
    
    int width, height; // in pixels
    friend class Cat;
    
public:
    
    // the grass portion on the screen is to the bottom starting from the left edge to the right edge
    // width should be equal to screen width
    
    Grass (int grassHeight, int scrWidth, int scrHeight, sf::Texture & grassTexture);
    
    void draw (sf::RenderWindow & window);
    
};

#endif /* Grass_hpp */

