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

void Vector::Draw(sf::RenderWindow& window, double x0, double y0, double arrowWidth, double arrowHeight, sf::Color color, bool coorMode)
{
	double c2x = x0 + x;
	double c2y = y0 + y;
	Point p1 = sc.CalcPoint(Point{x0, y0});
	Point p2 = sc.CalcPoint(Point{c2x, c2y});



	// Рисуем линию вектора.
	DrawLine(window, p1.x, p1.y, p2.x, p2.y, color);

	// Рисуем стрелочку.
	// Все расчёты выполняются в пикселях.
	double arrowHeight = sc.arrowHeight;
	double arrowWidth  = sc.arrowWidth;

	double pixVecWidth  = p2.x - p1.x;
	double pixVecHeight = p2.y - p1.y;

	// Длина вектора в пикселях.
	double pixLen = sqrt(pixVecWidth * pixVecWidth + pixVecHeight * pixVecHeight);

	// Переходим в новый базис {e1, e2}. e1 коллинеарен вектору, e2 перпендикулярен ему.
	double wa = arrowWidth  * pixVecWidth;
	double wb = arrowWidth  * pixVecHeight;
	double ha = arrowHeight * pixVecWidth;
	double hb = arrowHeight * pixVecHeight;

	double arrow1X = (- wa - hb) / pixLen;
	double arrow1Y = (- wb + ha) / pixLen;
	DrawLine(window, p2.x, p2.y, p2.x + arrow1X, p2.y + arrow1Y, color);

	double arrow2X = (- wa + hb) / pixLen;
	double arrow2Y = (- wb - ha) / pixLen;
	DrawLine(window, p2.x, p2.y, p2.x + arrow2X, p2.y + arrow2Y, color);
}

void Vector::DrawCoord(sf::RenderWindow& window, CoordinateSystem& sc, double x0, double y0, sf::Color color)
{
	double c2x = x0 + x;
	double c2y = y0 + y;
	Point p1 = sc.CalcPoint(Point{x0, y0});
	Point p2 = sc.CalcPoint(Point{c2x, c2y});

	// Рисуем линию вектора.
	DrawLine(window, p1.x, p1.y, p2.x, p2.y, color);

	// Рисуем стрелочку.
	// Все расчёты выполняются в пикселях.
	double arrowHeight = sc.arrowHeight;
	double arrowWidth  = sc.arrowWidth;

	double pixVecWidth  = p2.x - p1.x;
	double pixVecHeight = p2.y - p1.y;

	// Длина вектора в пикселях.
	double pixLen = sqrt(pixVecWidth * pixVecWidth + pixVecHeight * pixVecHeight);

	// Переходим в новый базис {e1, e2}. e1 коллинеарен вектору, e2 перпендикулярен ему.
	double wa = arrowWidth  * pixVecWidth;
	double wb = arrowWidth  * pixVecHeight;
	double ha = arrowHeight * pixVecWidth;
	double hb = arrowHeight * pixVecHeight;

	double arrow1X = (- wa - hb) / pixLen;
	double arrow1Y = (- wb + ha) / pixLen;
	DrawLine(window, p2.x, p2.y, p2.x + arrow1X, p2.y + arrow1Y, color);

	double arrow2X = (- wa + hb) / pixLen;
	double arrow2Y = (- wb - ha) / pixLen;
	DrawLine(window, p2.x, p2.y, p2.x + arrow2X, p2.y + arrow2Y, color);
}

void Vector::DrawPixel(sf::RenderWindow& window, double x0, double y0, double arrowWidth, double arrowHeight, sf::Color color)
{
	double c2x = x0 + x;
	double c2y = y0 + y;
	Point p1   = {x0, y0};
	Point p2   = {c2x, c2y};

	// Рисуем линию вектора.
	DrawLine(window, p1.x, p1.y, p2.x, p2.y, color);

	// Рисуем стрелочку.
	// Все расчёты выполняются в пикселях.
	double pixVecWidth  = p2.x - p1.x;
	double pixVecHeight = p2.y - p1.y;

	// Длина вектора в пикселях.
	double pixLen = sqrt(pixVecWidth * pixVecWidth + pixVecHeight * pixVecHeight);

	// Переходим в новый базис {e1, e2}. e1 коллинеарен вектору, e2 перпендикулярен ему.
	double wa = arrowWidth  * pixVecWidth;
	double wb = arrowWidth  * pixVecHeight;
	double ha = arrowHeight * pixVecWidth;
	double hb = arrowHeight * pixVecHeight;

	double arrow1X = (- wa - hb) / pixLen;
	double arrow1Y = (- wb + ha) / pixLen;
	DrawLine(window, p2.x, p2.y, p2.x + arrow1X, p2.y + arrow1Y, color);

	double arrow2X = (- wa + hb) / pixLen;
	double arrow2Y = (- wb - ha) / pixLen;
	DrawLine(window, p2.x, p2.y, p2.x + arrow2X, p2.y + arrow2Y, color);
}

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 