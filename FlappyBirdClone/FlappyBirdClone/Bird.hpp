//
//  Bird.hpp
//  FlappyBirdClone
//
//  Created by Quang Pham on 9/20/21.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Bird {
    
public:
    sf::CircleShape circle_;
    int radius_;
    float velo_, accel_, xPos_, yPos_; // velo_ : velocity, accel_ : acceleration
    
    
public:
    
    Bird (float radius = 30.f, float velo = 0.2, float accel = 0.2, float xPos = 100, float yPos = 100) {
        
        circle_.setFillColor(sf::Color::Black);

        circle_.setRadius(30.f);

        velo_   = velo;
        accel_  = accel;
        xPos_   = xPos;
        yPos_   = yPos;
    
    }
    
    void drop () {
        
        yPos_ += velo_;
        velo_ += accel_;
        circle_.setPosition(xPos_, yPos_);
        
    }
    
    void bounce () {
        
        velo_ = -7 ; //hardcoded
        
    }
    
    bool hitCeiling () {
        
        return yPos_ <= 0;
        
    }
    
    void ricochet () {
        
        yPos_ = 0;
        velo_ = - velo_;
        
    }
    
    bool hitGround (const int screenHeight) {
        
        return yPos_ >= screenHeight - radius_ - 60;
        
    }
    

    void draw (sf::RenderWindow & window) {
        
        window.draw(circle_);
        
    }
};

#endif /* Bird_hpp */
