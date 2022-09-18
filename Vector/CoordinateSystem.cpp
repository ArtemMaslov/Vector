#include "CoordinateSystem.h"
#include "Drawing.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

static const sf::Color BoundsColor(0, 0, 0);
static const sf::Color AxesColor(0, 0, 0);

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

CoordinateSystem::CoordinateSystem(const Point p1, const Point p2, const Segment x, const Segment y) :
	p1(p1),
	p2(p2),
	x(x),
	y(y),
	arrowHeight(0),
	arrowWidth(0)
{
	xConvert = (p2.x - p1.x) / (x.max - x.min);
	yConvert = (p2.y - p1.y) / (y.max - y.min);

	origin   = {};
	origin.x = p1.x + (-x.min) * xConvert;
	origin.y = p1.y + (-y.min) * yConvert;
}

Point CoordinateSystem::CalcPoint(const Point coordinate)
{
	Point pixel = {};

	// Для CoordinateSystem Ox направлена вправо, Oy вверх.
	// При прорисовке Ox направлена вправо, Oy вниз.
	// Поэтому появляется минус в формуле ниже:
	pixel.x = origin.x + coordinate.x * xConvert;
	pixel.y = origin.y - coordinate.y * yConvert;

	return pixel;
}

void CoordinateSystem::DrawBounds(sf::RenderWindow& window)
{
	// левая вертикальная 
	DrawLine(window, p1.x, p1.y, p1.x, p2.y, BoundsColor);
	// правая вертикальная
	DrawLine(window, p2.x, p1.y, p2.x, p2.y, BoundsColor);
	// верхняя горизонтальная
	DrawLine(window, p1.x, p1.y, p2.x, p1.y, BoundsColor);
	// нижняя горизонтальная
	DrawLine(window, p1.x, p2.y, p2.x, p2.y, BoundsColor);
}

void CoordinateSystem::DrawAxes(sf::RenderWindow& window)
{
	// Ox
	DrawLine(window, p1.x, origin.y, p2.x, origin.y, AxesColor);
	// Oy
	DrawLine(window, origin.x, p1.y, origin.x, p2.y, AxesColor);
}

Point CoordinateSystem::GetOrigin()
{
	return origin;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 