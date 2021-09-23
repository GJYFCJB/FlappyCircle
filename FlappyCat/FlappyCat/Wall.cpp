//
//  Wall.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "Wall.hpp"

#include <SFML/Graphics.hpp>
#include "Cat.hpp"

Wall::Wall (float screenHeight, int xIniPos, int width, sf::Texture & texture ) { // randomly generate a wall with a hole = 25% the wall height
    
    xIniPos_ = xIniPos;
    width_ = width;
    
    // randomly generate a hole in the wall (25% wall height)
    // generate a random number from 1 to 70 and divide it by 100
    // this random number should represent the height of the upper wall in percentage of the total screen height
    float upperHeightPct = ((float) (rand() % 70))/100;
    upperHeight_ = screenHeight*upperHeightPct;
    lowerHeight_ = screenHeight*(1 - upperHeightPct - 0.25);
    
    //set the walls' textrue and size
    upperWall_.setTexture(texture);
    upperWall_.setTextureRect(sf::IntRect(0, 0, width, upperHeight_));
    lowerWall_.setTexture(texture);
    lowerWall_.setTextureRect(sf::IntRect(0, 0, width, lowerHeight_));
    
    //set the walls' x and y position
    upperWall_.setPosition(xIniPos_, 0);
    lowerWall_.setPosition(xIniPos_, screenHeight - lowerHeight_);
}

   //draw the objects to the render window
void Wall::draw (sf::RenderWindow & window) {
    
    window.draw(std::move(upperWall_));
    window.draw(std::move(lowerWall_));
    
}
 //set wall's x positon
void Wall::setXPosition(int xPos) {
    
    upperWall_.setPosition(xPos, 0);
    lowerWall_.setPosition(xPos, 1200 - lowerHeight_);
    
}

// get wall's x position
int Wall::getXPosition() {
    
    return upperWall_.getPosition().x;
    
}

 //set the walls' speed
void Wall::move (float xSpeed) {
    
    upperWall_.move(xSpeed, 0);
    lowerWall_.move(xSpeed, 0);
    
}

// Cat went throught the wall, then got the score.
bool Wall::isPastCat (Cat theCat) {
    
    return getXPosition() < theCat.getXPosition() - width_;
    
}

//when the cat hits the wall or ground or ceiling,then game is over.
bool Wall::isCollided (Cat & theCat) {
    
    sf::FloatRect catBound = theCat.catRec_.getGlobalBounds();
    sf::FloatRect upperWallBound = upperWall_.getGlobalBounds();
    sf::FloatRect lowerWallBound = lowerWall_.getGlobalBounds();
    
    return (catBound.intersects(upperWallBound) || catBound.intersects(lowerWallBound));
    
}
