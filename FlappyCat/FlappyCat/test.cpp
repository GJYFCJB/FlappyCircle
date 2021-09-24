//
//  test.cpp
//  FlappyCat
//
//  Created by 谷金 on 9/23/21.
//

#include "test.hpp"
#include "Wall.hpp"


bool Wall::isCollided_test (Cat & theCat) {
    
    sf::FloatRect catBound = theCat.catRec_.getGlobalBounds();
    sf::FloatRect upperWallBound = upperWall_.getGlobalBounds();
    sf::FloatRect lowerWallBound = lowerWall_.getGlobalBounds();
    
    return 0;
    
}
