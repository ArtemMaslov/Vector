#include "Vector.h"
#include "Drawing.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector::Vector(double x, double y) :
	x(x),
	y(y)
{
}

Vector::Vector() : Vector::Vector(0, 0)
{
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

double Vector::Length()
{
	if (!_isnan(len))
	{
		return len;
	}
	else
	{
		len = sqrt(x * x + y * y);

		return len;
	}
}

double Vector::GetX() { return x; }
double Vector::GetY() { return y; }

void Vector::SetX(double value)
{
	len = NAN;
	x   = value;
}

void Vector::SetY(double value)
{
	len = NAN;
	y   = value;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

Vector operator + (const Vector& left, const Vector& right)
{
	return Vector(left.x + right.x, left.y + right.y);
}

Vector operator - (const Vector& left, const Vector& right)
{
	return Vector(left.x - right.x, left.y - right.y);
}

Vector operator * (const Vector& vec, double number)
{
	return Vector(vec.x * number, vec.y * number);
}

Vector operator * (double number, const Vector& vec)
{
	return Vector(vec.x * number, vec.y * number);
}

Vector operator / (const Vector& vec, double number)
{
	if (number == 0)
		throw new std::exception("Деление на 0.");

	return Vector(vec.x / number, vec.y / number);
}

Vector& operator += (Vector& left, const Vector& right)
{
	left.x += right.x;
	left.y += right.y;
	return left;
}

Vector& operator -= (Vector& left, const Vector& right)
{
	left.x -= right.x;
	left.y -= right.y;
	return left;
}

Vector& operator *= (Vector& vec, double number)
{
	vec.x *= number;
	vec.y *= number;
	return vec;
}

Vector& operator /= (Vector& vec, double number)
{
	if (number == 0)
		throw new std::exception("Деление на 0.");

	vec.x /= number;
	vec.y /= number;
	return vec;
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

void Vector::Draw(sf::RenderWindow& window, CoordinateSystem& sc, double x0, double y0, sf::Color color)
{
	double c2x = x0 + x;
	double c2y = y0 + y;
	Point p1 = sc.CalcPoint(Point{x0, y0});
	Point p2 = sc.CalcPoint(Point{c2x, c2y});

	double len = Length();

	double arrowHeight = len * 0.02;
	double arrowWidth  = len * 0.08;

	double wa = arrowWidth  * x;
	double wb = arrowWidth  * y;
	double ha = arrowHeight * x;
	double hb = arrowHeight * y;

	double arrow1X = (- wa - hb) / len;
	double arrow1Y = (- wb + ha) / len;
	Point  arrowP1 = sc.CalcPoint(Point{c2x + arrow1X, c2y + arrow1Y});
	DrawLine(window, p2.x, p2.y, arrowP1.x, arrowP1.y, color);

	double arrow2X = (- wa + hb) / len;
	double arrow2Y = (- wb - ha) / len;
	Point  arrowP2 = sc.CalcPoint(Point{c2x + arrow2X, c2y + arrow2Y});
	DrawLine(window, p2.x, p2.y, arrowP2.x, arrowP2.y, color);

	DrawLine(window, p1.x, p1.y, p2.x, p2.y, color);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 