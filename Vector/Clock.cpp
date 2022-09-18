#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "CoordinateSystem.h"
#include "Vector.h"
#include "Clock.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Clock::Clock(double x0, double y0, double radius) :
    circle(radius, circlePoints),
    hour(0, radius * 0.9),
    hourLen(radius * 0.8),
    minuteLen(radius * 0.9),
    secondLen(radius)
{
    circle.setOrigin(radius, radius);
    circle.setPosition(x0, y0);

    circle.setOutlineThickness(1.0f);
    circle.setOutlineColor(sf::Color::Black);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void Clock::DrawClocks(sf::RenderWindow& window, double x0, double y0)
{
    window.draw(circle);
}


//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 