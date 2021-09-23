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
#include "Cat.hpp"

class Wall {
    
private:
    
    sf::Sprite upperWall_, lowerWall_;
    float upperHeight_, lowerHeight_, width_;
    int xIniPos_;
    friend class Cat;
    
public:
    
    Wall ( float screenHeight, int xIniPos, int width, sf::Texture & texture );
    
    void draw (sf::RenderWindow & window);
    
    void setXPosition(int xPos);
    
    int getXPosition();
    
    void move (float xSpeed);
    
    bool isPastCat (Cat theCat);
    
    bool isCollided (Cat & theCat);

};

#endif /* Wall_hpp */

