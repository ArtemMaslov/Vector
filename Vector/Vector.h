#ifndef VECTOR_H
#define VECTOR_H

#include <SFML/Graphics.hpp>

#include "CoordinateSystem.h"

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

class Vector
{
public:
	double len = NAN;

	Vector(double x, double y);

	Vector();

	void Draw(sf::RenderWindow& window, CoordinateSystem& sc, double x0, double y0, sf::Color color = sf::Color::Black);

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

private:
	double x;
	double y;
};

//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 
//***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***\\ 

#endif // !VECTOR_H