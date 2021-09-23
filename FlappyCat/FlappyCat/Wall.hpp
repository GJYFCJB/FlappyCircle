//
//  Wall.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Cat.hpp"

class Wall {
    
private:
    float upperHeight_, lowerHeight_, width_;
    sf::Sprite upperWall_, lowerWall_;
    int xIniPos_;
    friend class Cat;
    //sf::Texture texture;
    
    
    
public:
    
    Wall (float screenHeight, int xIniPos, int width, sf::Texture & texture ) { // randomly generate a wall with a hole = 25% the wall height
        
        xIniPos_ = xIniPos;
        
        float upperHeightPct = ((float) (rand() % 70))/100;
        upperHeight_ = screenHeight*upperHeightPct;
        lowerHeight_ = screenHeight*(1 - upperHeightPct - 0.25);
        width_ = width;
        
        //texture.loadFromFile("brick_texture.png");
        
        upperWall_.setTexture(texture);
        upperWall_.setTextureRect(sf::IntRect(0, 0, width, upperHeight_));
        
        lowerWall_.setTexture(texture);
        lowerWall_.setTextureRect(sf::IntRect(0, 0, width, lowerHeight_));
        
        upperWall_.setPosition(xIniPos_, 0);
        lowerWall_.setPosition(xIniPos_, screenHeight - lowerHeight_);
    }
    
    void draw (sf::RenderWindow & window) {
        
        window.draw(std::move(upperWall_));
        window.draw(std::move(lowerWall_));
        
        
    }
    
    void setXPosition(int xPos) {
        
        upperWall_.setPosition(xPos, 0);
        lowerWall_.setPosition(xPos, 1200 - lowerHeight_);
        
    }
    
    int getXPosition() {
        
        return upperWall_.getPosition().x;
        
    }
    
    void move (float xSpeed) {
        
        upperWall_.move(xSpeed, 0);
        lowerWall_.move(xSpeed, 0);
        
    }
    
//    Wall & operator= (Wall wall2) {
//
//        upperHeight_ = wall2.upperHeight_;
//        lowerHeight_ = wall2.lowerHeight_;
//        width_       = wall2.width_;
//
//        upperWall_   = wall2.upperWall_;
//        lowerWall_   = wall2.lowerWall_;
//        xIniPos_     = 0;
//
//        return *this;
//
//    }
    
    bool isPastCat (Cat theCat) {
        
        return getXPosition() < theCat.getXPosition() - width_;
        
    }
    
    bool isCollided (Cat & theCat) {
        
        sf::FloatRect catBound = theCat.catRec_.getGlobalBounds();
        sf::FloatRect upperWallBound = upperWall_.getGlobalBounds();
        sf::FloatRect lowerWallBound = lowerWall_.getGlobalBounds();
        
        return (catBound.intersects(upperWallBound) || catBound.intersects(lowerWallBound));
        
    }

};

#endif /* Wall_hpp */

