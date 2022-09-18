#ifndef VECTOR_H
#define VECTOR_H

#include <SFML/Graphics.hpp>

#include "CoordinateSystem.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Vector
{
public:
	Vector(double x, double y);

	Vector();

	double Length();

	double GetX();
	double GetY();
	void SetX(double value);
	void SetY(double value);

	friend Vector operator + (const Vector& left, const Vector& right);

	friend Vector operator - (const Vector& left, const Vector& right);

	friend Vector operator * (const Vector& vec, double number);

	friend Vector operator * (double number, const Vector& vec);

	friend Vector operator / (const Vector& vec, double number);

	friend Vector& operator += (Vector& left, const Vector& right);

	friend Vector& operator -= (Vector& left, const Vector& right);

	friend Vector& operator *= (Vector& vec, double number);

	friend Vector& operator /= (Vector& vec, double number);

	double len = NAN;

private:
	double x;
	double y;
};

class VectorRender
{
public:
	VectorRender(sf::RenderWindow& window, Vector& vector);

	void DrawCoord(sf::RenderWindow& window, CoordinateSystem& sc, double x0, double y0, sf::Color color = sf::Color::Black);

	void DrawPixel(sf::RenderWindow& window, double x0, double y0, double arrowWidth, double arrowHeight, sf::Color color = sf::Color::Black);

	Vector Vector;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !VECTOR_H