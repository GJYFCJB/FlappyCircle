//
//  Walls.hpp
//  FlappyBirdClone
//
//  Created by Quang Pham on 9/20/21.
//

#ifndef Walls_hpp
#define Walls_hpp

#include <stdio.h>
#include "Wall.hpp"
#include <vector>

using namespace std;

class Walls {
    
private:
    
    vector <Wall> walls;
    int numWalls_;
    float wallGap_;
    
public:
    
    Walls (int numWalls = 100, float wallGap = 450) {
        
        numWalls_ = numWalls;
        for (int i = 0; i < numWalls; i++) {
            walls.push_back(Wall(1200, 1000 + wallGap*i));
        }
        
        wallGap_ = wallGap;
        
    }
    
    void draw (sf::RenderWindow & window) {
        
        for (Wall & wall: walls) {
            wall.draw(window);
        }
        
    }
    
    void move (float xSpeed) {
        
        for (Wall & wall: walls) {
            wall.move(xSpeed);
        }
        
    }
    
};

#endif /* Walls_hpp */
