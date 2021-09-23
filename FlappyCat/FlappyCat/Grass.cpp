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
    grassRec_.setTextureRect(sf::IntRect(0, 0, scrWidth, grassHeight));
    grassRec_.setPosition(0, scrHeight - grassHeight);
    
}

void Grass::draw (sf::RenderWindow & window) {
    
    window.draw(grassRec_);
    
}
