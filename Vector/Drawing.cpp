#include "Drawing.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void DrawLine(sf::RenderWindow& window,
			  const double x1, const double y1, const double x2, const double y2,
			  const sf::Color& color)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f((float)x1, (float)y1), color),
		sf::Vertex(sf::Vector2f((float)x2, (float)y2), color)
	};
	const size_t lineSize = sizeof(line) / sizeof(sf::Vertex);

	window.draw(line, lineSize, sf::Lines);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 