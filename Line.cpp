#include "Line.h"
#include <cmath>

Line::Line(Point x1, Point x2)
{
	type = 1;
}


Point Line::getx1Point()
{
	return x1;
}

Point Line::getx2Point()
{
	return x2;
}

void Line::setx1Point(Point x)
{
	this->x1 = x;
}

void Line::setx2Point(Point x)
{
	this->x2 = x;
}

void Line::drawingMyFigures(Graphics^ graphics)
{
	graphics->DrawLine(gcnew Pen(Color::Black, 3), x1, x2);
}

MyFiguresForGraphicEditor^ Line::findMyFigures(int x, int y)
{
	if (x < fmin(x1.X, x2.X) - 3 || x > fmax(x1.X, x2.X) + 3 || y < fmin(x1.Y, x2.Y) - 3 || y > fmax(x1.Y, x2.Y) + 3) {
		return nullptr;
	}

	int ab = abs((x1.Y - x2.Y) * x + (x2.X - x1.X) * y + (x1.X * x2.Y - x2.X * x1.Y));

	if (sqrt(abs((x1.Y - x2.Y) * x + (x2.X - x1.X) * y + (x1.X * x2.Y - x2.X * x1.Y))) <= 49) {
		return this;
	}
	return nullptr;
}
