#include <iostream>
#include "Game.h"


int main()
{
    sf::RenderWindow window({1420, 1080, 32}, "Pong");

    sf::RectangleShape rightBox;
    sf::RectangleShape leftBox;
    sf::CircleShape ball;
    sf::RectangleShape rightCounterBox;
    sf::RectangleShape leftCounterBox;
    sf::String leftPaddleScore;
    sf::String rightPaddleScore;


    rightBox.setSize({50, 300});
    rightBox.setPosition({1100, 700});
    rightBox.getGlobalBounds();

    leftBox.setSize({50, 300});
    leftBox.setPosition({240, 700});

    ball.setRadius(50);
    ball.setPosition(500, 100);

    rightCounterBox.setSize({50, 1080});
    rightCounterBox.setPosition({1370, 0});
    rightCounterBox.setFillColor(sf::Color::Green);

    leftCounterBox.setSize({50, 1080});
    leftCounterBox.setPosition({0, 0});
    leftCounterBox.setFillColor(sf::Color::Green);

    leftPaddleScore = "0";

    rightPaddleScore = "0";

    sf::Text rightTextScore;
    sf::Font rightFont;
    rightFont.loadFromFile("font/OpenSans-Regular.ttf");
    rightTextScore.setFont(rightFont);
    rightTextScore.setFillColor(sf::Color::Red);
    rightTextScore.setPosition(1100, 100);
//    rightTextScore.setString(rightCounter);

    sf::Text leftTextScore;
    sf::Font leftFont;
    leftFont.loadFromFile("font/OpenSans-Regular.ttf");
    leftTextScore.setFont(leftFont);
    leftTextScore.setFillColor(sf::Color::Red);
    leftTextScore.setPosition(240, 100);

    //sets the speed of the ball
    float x=1, y=1;
    //sets the bounds of the walls
    int length = window.getSize().x-(ball.getRadius()*2);
    int width = window.getSize().y-(ball. getRadius()*2);

    while(window.isOpen())
    {
        sf::Event event;

        //moves the ball diagonally from its starting position
        ball.move(x, y);

        //all this below sets the logic for the ball
        //if the ball hits x or y, move the opposite direction
        float x1 = ball.getPosition().x;
        float y1 = ball.getPosition().y;

        if (x1 == 0 || x1 >= length)
            x = -x;
        else if (y1 == 0 || y1 >= width)
            y = -y;

        //if the red button or escape key is hit,
        //close the program window
        while (window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

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

        window.clear();
        window.draw(rightBox);
        window.draw(leftBox);
        window.draw(ball);
        window.draw(rightCounterBox);
        window.draw(leftCounterBox);

        window.display();
    }
    return 0;
}
