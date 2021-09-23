//
//  HelperFunction.cpp
//  FlappyCat
//
//  Created by Quang Pham on 9/23/21.
//

#include "HelperFunction.hpp"
#include "WallQueue.hpp"
#include "Cat.hpp"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>

void printGameOverMessage (std::string message, sf::Color fontColor, int scrWidth, int scrHeight, sf::RenderWindow & window) {
    
    // create a translucent layer over the screen
    sf::RectangleShape translucentLayer;
    translucentLayer.setFillColor(sf::Color(255, 255, 255, 200));
    translucentLayer.setOutlineColor(sf::Color::White);
    translucentLayer.setSize(sf::Vector2<float>(scrWidth, scrHeight));
    translucentLayer.setPosition(0, 0);
    window.draw(translucentLayer);
    
    // create the message box
    sf::RectangleShape messBox;
    messBox.setFillColor(sf::Color(255, 255, 255));
    messBox.setOutlineColor(sf::Color::Red);
    messBox.setOutlineThickness(20);
    messBox.setSize(sf::Vector2<float>(scrWidth/3, scrHeight/3));
    messBox.setPosition(scrWidth/3, scrHeight/3);
    window.draw(messBox);
    
    
    // displaying the message
    sf::Text text;

    // select the font
    sf::Font font;
    std::string fontPath = "RetroGaming.ttf";
    font.loadFromFile(fontPath);
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(message);

    // set the character size
    text.setCharacterSize(40); // in pixels, not points!

    // set the color
    text.setFillColor(fontColor);

    // set the text style
    text.setStyle(sf::Text::Bold);
    
    text.setPosition(scrWidth/3 + 50, scrHeight/3 + 50);

    // inside the main loop, between window.clear() and window.display()
    window.draw(text);
    
}

void printMessage (std::string message, sf::Color fontColor, int fontSize, int xPos, int yPos, sf::RenderWindow & window) {
    
    // displaying the message
    sf::Text text;

    // select the font
    sf::Font font;
    std::string fontPath = "RetroGaming.ttf";
    font.loadFromFile(fontPath);
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(message);

    // set the character size
    text.setCharacterSize(fontSize); // in pixels, not points!

    // set the color
    text.setFillColor(fontColor);

    // set the text style
    text.setStyle(sf::Text::Bold);
    
    text.setPosition(xPos, yPos);

    // inside the main loop, between window.clear() and window.display()
    window.draw(text);
}

