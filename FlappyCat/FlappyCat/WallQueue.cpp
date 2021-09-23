//
//  WallQueue.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "WallQueue.hpp"
#include "Wall.hpp"
#include <vector>


WallQueue::WallQueue (int numWalls, int gap, sf::Texture & texture) {
    
    gap_ = gap;
    numWalls_ = numWalls;
    for (int i = 0; i < numWalls_; i++) {
        
        Wall newWall{1200, 500 + i*gap_, 100, texture};
        walls.push_back (std::move(newWall));
        
    }
    
}

void WallQueue::draw (sf::RenderWindow & window) {
    
    for (Wall & wall: walls) {
        wall.draw(window);
    }
    
}

void WallQueue::move (float xSpeed) {
    
    for (int i = 0; i < numWalls_; i++) {
        walls[i].move(xSpeed);
    }
}

int WallQueue::calculateScore (Cat & theCat) {
    
    int score = 0;
    
    for (Wall & w: walls) {
        
        if (w.isPastCat(theCat)) {
            score++;
        }
        
    }
    
    return score;
    
}
