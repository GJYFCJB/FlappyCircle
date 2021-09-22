//
//  Wall.hpp
//  FlappyBirdClone
//
//  Created by Quang Pham on 9/20/21.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Wall {
    
private:
    float upperHeight_, lowerHeight_, width_;
    sf::RectangleShape upperWall_, lowerWall_;
    int xIniPos_;
    
    
public:
    Wall (float upperHeight, float lowerHeight, float width) {
        
        upperHeight_ = upperHeight;
        lowerHeight_ = lowerHeight;
        width_       = width;
        
        upperWall_.setSize(sf::Vector2<float>(width_, upperHeight_));
        lowerWall_.setSize(sf::Vector2<float>(width_, lowerHeight_));
        
        upperWall_.setFillColor(sf::Color::Green);
        lowerWall_.setFillColor(sf::Color::Green);
        
        upperWall_.setPosition(xIniPos_, 0);
        lowerWall_.setPosition(xIniPos_, 1200 - lowerHeight_);
    }
    
    Wall (float screenHeight = 1200, int xIniPos= 1000) { // randomly generate a wall with a hole = 25% the wall height
        
        xIniPos_ = xIniPos;
        
        float upperHeightPct = ((float) (rand() % 70))/100;
        upperHeight_ = screenHeight*upperHeightPct;
        lowerHeight_ = screenHeight*(1 - upperHeightPct - 0.25);
        width_ = 70;
        
        //Wall (upperHeight, lowerHeight, 70);
        upperWall_.setSize(sf::Vector2<float>(width_, upperHeight_));
        lowerWall_.setSize(sf::Vector2<float>(width_, lowerHeight_));
        
        upperWall_.setFillColor(sf::Color::Green);
        lowerWall_.setFillColor(sf::Color::Green);
        
        upperWall_.setPosition(xIniPos_, 0);
        lowerWall_.setPosition(xIniPos_, 1200 - lowerHeight_);
    }
    
    void draw (sf::RenderWindow & window) {
        
        //window.clear(sf::Color::White);
        window.draw(upperWall_);
        window.draw(lowerWall_);
        //window.display();
        
        
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
    
    Wall & operator= (Wall wall2) {
        
        upperHeight_ = wall2.upperHeight_;
        lowerHeight_ = wall2.lowerHeight_;
        width_       = wall2.width_;
        
        upperWall_   = wall2.upperWall_;
        lowerWall_   = wall2.lowerWall_;
        xIniPos_     = 0;
        
        return *this;
        
    }

};

#endif /* Wall_hpp */
