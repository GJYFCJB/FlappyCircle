//
//  TestFunctions.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/24/21.
//

#ifndef TestFunctions_hpp
#define TestFunctions_hpp

#include <stdio.h>
#include <iostream>
#include "Cat.hpp"
#include "Wall.hpp"

void testCollision () {
    
    sf::Texture catTexture, wallTexture;
    Cat theCat(catTexture);
    Wall theWall(1200, 100, 100, wallTexture);
    
    // Set the cat and the wall at the same position - guarantee to crash
    theCat.setXPosition(100);
    theCat.setYPosition(0);
    theWall.setXPosition(100);
    
    if (!theWall.isCollided(theCat)) {
        std::cout << "Collision test failed.";
        exit (1);
    }
    
}

#endif /* TestFunctions_hpp */
