#ifndef CLOCK_H
#define CLOCK_H

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Clock
{
public:
	Clock(double x0, double y0, double radius);

	void DrawClocks(sf::RenderWindow& window, double x0, double y0);

private:
	const size_t circlePoints = 12;

	sf::CircleShape circle;
	Vector hour;
	Vector minute;
	Vector second;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !CLOCK_H