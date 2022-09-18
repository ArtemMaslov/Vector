#ifndef COORDIATE_SYSTEM_H
#define COORDIATE_SYSTEM_H

#include <SFML/Graphics.hpp>

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

struct Point
{
	double x;
	double y;
};

struct Segment
{
	double min;
	double max;
};

class CoordinateSystem
{
public:
	CoordinateSystem(const Point p1, const Point p2, const Segment x, const Segment y);

	Point CalcPoint(const Point coordinate);

	void DrawBounds(sf::RenderWindow& window);

	void DrawAxes(sf::RenderWindow& window);

private:
	Segment x;
	Segment y;

	// Левый верхний угол.
	Point p1;
	// Правый нижний угол.
	Point p2;

	Point origin;

	// Коэффициент перевода из координат в пиксели. xConvert_ = (x_.max - x_.min) / (p2.x - p1.x);
	double xConvert;

	// Коэффициент перевода из координат в пиксели. yConvert_ = (y_.max - y_.min) / (p2.y - p1.y);
	double yConvert;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !COORDIATE_SYSTEM_H