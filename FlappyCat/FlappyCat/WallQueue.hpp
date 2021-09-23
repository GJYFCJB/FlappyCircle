//
//  WallQueue.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef Walls_hpp
#define Walls_hpp

#include <stdio.h>
#include "Wall.hpp"
#include <vector>

using namespace std;

class WallQueue {
    
public:
    vector <Wall> walls;
    int numWalls_;
    int gap_;
    
public:
    
    WallQueue (int numWalls, int gap, sf::Texture & texture);
    
    void draw (sf::RenderWindow & window);
    
    void move (float xSpeed);
    
    int calculateScore (Cat & theCat);
};

#endif /* Walls_hpp */

