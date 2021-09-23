//
//  HelperFunction.hpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#ifndef HelperFunction_hpp
#define HelperFunction_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "WallQueue.hpp"
#include "Cat.hpp"
#include <string>

void printGameOverMessage (std::string message, sf::Color fontColor, int scrWidth, int scrHeight, sf::RenderWindow & window);

void printMessage (std::string message, sf::Color fontColor, int fontSize, int xPos, int yPos, sf::RenderWindow & window);

#endif /* HelperFunction_hpp */
