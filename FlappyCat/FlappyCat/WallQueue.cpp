//
//  WallQueue.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "WallQueue.hpp"
#include "Wall.hpp"
#include <vector>

//Construct a WallQueue, including the number of walls, gap length between walls, and texture
WallQueue::WallQueue (int numWalls, int gap, sf::Texture & texture) {
    
    gap_ = gap;
    numWalls_ = numWalls;
//vector: walls
    for (int i = 0; i < numWalls_; i++) {
        
//newWall{screenHeight: 1200, xIniPos: 500, 1100, 1700, int width: 100, texture}
        Wall newWall{1200, 500 + i*gap_, 100, texture};
        walls.push_back (std::move(newWall));
        
    }
    
}

//draw all walls
void WallQueue::draw (sf::RenderWindow & window) {
//for each loop
    for (Wall & wall: walls) {
        wall.draw(window);
    }
    
}

//move left (x position)
void WallQueue::move (float xSpeed) {
    for (int i = 0; i < numWalls_; i++) {
        walls[i].move(xSpeed);
    }
}

int WallQueue::calculateScore (Cat & theCat) {
    
    int score = 0;
//for each loop
    for (Wall & w: walls) {
//wall x position < cat x position
        if (w.isPastCat(theCat)) {
            score++;
        }
        
    }
    
    return score;
    
}
