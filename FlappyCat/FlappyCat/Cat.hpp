//
//  Cat.hpp
//  FlappyCat
//

#ifndef Cat_hpp
#define Cat_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Grass.hpp"

class Cat {
    
public:
    sf::Sprite catRec_;
    int radius_ = 30;
    float velo_ = 0.2;
    float accel_ = 0.2;
    float xPos_ = 100;
    float yPos_ = 100;
    
    
public:
    // Cat (int radius = 30, float velo = 0.2, float accel = 0.2, float xPos = 100, float yPos = 100)
    Cat (sf::Texture & catTexture) {
        
        catRec_.setTexture(catTexture);
        catRec_.setTextureRect(sf::IntRect(0, 0, 70, 55)); // texture image size: 30x23 pixels
     
    }
    
    void drop () {
        
        yPos_ += velo_;
        velo_ += accel_;
        catRec_.setPosition(xPos_, yPos_);
        
    }
    
    void bounce () {
        
        velo_ = -7 ; //hardcoded
        
    }
    
    bool hitCeiling () {
        
        return yPos_ <= 0;
        
    }
    
    bool hitGround (const Grass & grass) {
        
        sf::FloatRect catBound = catRec_.getGlobalBounds();
        sf::FloatRect grassBound = grass.grassRec_.getGlobalBounds();
        
        return (catBound.intersects(grassBound));
    }
    

    void draw (sf::RenderWindow & window) {
        
        window.draw(catRec_);
        
    }
    
    float getXPosition() {
        
        return xPos_;
        
    }
    
    float getYPosition() {
        
        return yPos_;
        
    }
    
};

#endif /* Cat_hpp */
