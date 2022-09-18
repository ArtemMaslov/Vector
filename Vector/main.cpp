#include <stdio.h>

#include <SFML/Graphics.hpp>

#include "CoordinateSystem.h"
#include "Vector.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

int main(int argc, char* argv[])
{
    const double padding = 10;
    const double width   = 400;
    const double height  = 400;

    sf::RenderWindow window(sf::VideoMode(width * 2 + padding * 3, height + padding * 2), "Vector");

    CoordinateSystem sc1(Point{padding, padding},
                         Point{width + padding, height + padding},
                         Segment{-10, 10},
                         Segment{-10, 10});

    CoordinateSystem sc2(Point{padding * 2 + width, padding},
                         Point{padding * 2 + width * 2, height + padding},
                         Segment{-10, 10},
                         Segment{-10, 10});

    Vector v1(10, 0);
    Vector v2(0, 10);
    Vector v3(10, 10);

    while (window.isOpen())
    {
        sf::Event event = {};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        const double x0 = 0;
        const double y0 = 0;
        v1.Draw(window, sc1, x0, y0);
        v2.Draw(window, sc1, x0, y0);
        v3.Draw(window, sc1, x0, y0);

        sc1.DrawBounds(window);
        sc1.DrawAxes(window);

        sc2.DrawBounds(window);
        sc2.DrawAxes(window);

        window.display();
    }

	return 0;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 