//
// Created by Edward Eckelberry on 1/11/23.
//

#ifndef PONG_MECHANICS_H
#define PONG_MECHANICS_H
#include <SFML/Graphics.hpp>
#include <iostream>

struct Mechanics : sf::Drawable
{
    explicit Mechanics();
    void draw(sf::RenderTarget &window, sf::RenderStates states) const; //override?

    void setPosition(const sf::Vector2f &position);
    void setSize(const sf::Vector2f &size_of_input_box);

//    sf::RenderTarget window = 0;
//
//    int length = window.getSize().x-(ball.getRadius()*2);
//    int width = window.getSize().y-(ball. getRadius()*2);

    // Getters
    std::string getText() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2<float> getPosition() const;
    sf::RectangleShape rightBox;
    sf::RectangleShape leftBox;
    sf::CircleShape ball;
    sf::RectangleShape rightCounterBox;
    sf::RectangleShape leftCounterBox;
    sf::String leftPaddleScore;
    sf::String rightPaddleScore;

};


#endif //PONG_MECHANICS_H
