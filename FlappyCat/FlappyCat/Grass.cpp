//
//  Grass.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "Grass.hpp"
#include <SFML/Graphics.hpp>

Grass::Grass (int grassHeight, int scrWidth, int scrHeight, sf::Texture & grassTexture) {
    
    grassRec_.setTexture(grassTexture);
    //grassTexture is a sf::grassTexture
    
    grassRec_.setTextureRect(sf::IntRect(0, 0, scrWidth, grassHeight));
    //setTextureRect: Shapes can also be textured, just like sprites. To specify a part of the texture to be mapped to the shape, use the setTextureRect function.
    
    grassRec_.setPosition(0, scrHeight - grassHeight);
    //set the position of the grass
    
    
}

void Grass::draw (sf::RenderWindow & window) {
    
    window.draw(grassRec_);
    // draw the grass on the screen 
    
}
