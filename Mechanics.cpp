//
// Created by Edward Eckelberry on 1/11/23.
//

#include "Mechanics.h"

Mechanics::Mechanics()
{
    rightCounterBox.setFillColor(sf::Color::Green);

    leftCounterBox.setFillColor(sf::Color::Green);

    leftBox.setPosition({240, 700});

    ball.setFillColor(sf::Color::Blue);

    float x=1, y=1;
    //sets the bounds of the walls
//    int length = window.getSize().x-(ball.getRadius()*2);
//    int width = window.getSize().y-(ball. getRadius()*2);

    ball.move(x, y);

    //all this below sets the logic for the ball
    //if the ball hits x or y, move the opposite direction
    float x1 = ball.getPosition().x;
    float y1 = ball.getPosition().y;

//    if (x1 == 0 || x1 >= length)
//        x = -x;
//    else if (y1 == 0 || y1 >= width)
//        y = -y;

    //sets the controls for the left box
    float yBox = 3;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        leftBox.move(0, -yBox);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        leftBox.move(0, yBox);

    //sets the controls for the right box
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        rightBox.move(0, -yBox);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        rightBox.move(0, yBox);



    //if the ball hits either paddle, move the opposite direction
    if(ball.getGlobalBounds().intersects(leftBox.getGlobalBounds())
       || ball.getGlobalBounds().intersects(rightBox.getGlobalBounds())) {
        x = -x;
        y = -y;
    }

    //if the ball hits the left box,
    //move the opposite way and count up
    static int rightCounter = 0;

    if(ball.getGlobalBounds().intersects(rightCounterBox.getGlobalBounds())) {
        rightCounter += 1;

        x = -x ;
        y = -y;
        std::cout << "Right Counter: " << rightCounter << std::endl;
    }

    //if the ball hits the left box,
    //move the opposite way and count up
    static int leftCounter = 0;

    if(ball.getGlobalBounds().intersects(leftCounterBox.getGlobalBounds()))
    {
        x = -x;
        y = -y;
        leftCounter++;
        std::cout << "Left Counter: " << leftCounter << std::endl;
    }


    //put rest of setSize here
    leftPaddleScore = "0";

    rightPaddleScore = "0";

}

void Mechanics::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(rightCounterBox),
    window.draw(leftCounterBox),
    window.draw(rightBox),
    window.draw(leftBox),
    window.draw(ball);

}

void Mechanics::setPosition(const sf::Vector2f &position)
{
    rightBox.setPosition({1100, 700});
    leftBox.setPosition({240, 700});
    ball.setPosition(500, 100);
    rightCounterBox.setPosition({1370, 0});
    leftCounterBox.setPosition({0, 0});

}

void Mechanics::setSize(const sf::Vector2f &size_of_input_box)
{
    rightBox.setSize({50, 300});
    leftBox.setSize({50, 300});
    ball.setRadius(50);
    rightCounterBox.setSize({50, 1080});
    leftCounterBox.setSize({50, 1080});
}

std::string Mechanics::getText() const
{
    return std::string();
}

sf::FloatRect Mechanics::getGlobalBounds() const
{
    return rightBox.getGlobalBounds(),
    leftBox.getGlobalBounds(),
    ball.getGlobalBounds(),
    leftCounterBox.getGlobalBounds(),
    rightCounterBox.getGlobalBounds();
}

sf::Vector2<float> Mechanics::getPosition() const
{
    return rightBox.getPosition(),
    leftBox.getPosition(),
    ball.getPosition(),
    leftCounterBox.getPosition(),
    rightCounterBox.getPosition();
}


