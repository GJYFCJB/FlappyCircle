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
    
    WallQueue (int numWalls, int gap, sf::Texture & texture) {
        
        gap_ = gap;
        numWalls_ = numWalls;
        for (int i = 0; i < numWalls_; i++) {
            
            Wall newWall{1200, 500 + i*gap_, 100, texture};
            walls.push_back (std::move(newWall));
            
        }
        
    }
    
    void draw (sf::RenderWindow & window) {
        
        for (Wall & wall: walls) {
            wall.draw(window);
        }
        
    }
    
    void move (float xSpeed) {
        
        for (int i = 0; i < numWalls_; i++) {
            walls[i].move(xSpeed);
        }
    }
    
    int calculateScore (Cat & theCat) {
        
        int score = 0;
        
        for (Wall & w: walls) {
            
            if (w.isPastCat(theCat)) {
                score++;
            }
            
        }
        
        return score;
        
    }
};

#endif /* Walls_hpp */

