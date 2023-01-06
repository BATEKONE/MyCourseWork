#include "Circle.h"
#include <cmath>

Circle::Circle(Rectangle circle) {
	type = 1;
}

Rectangle Circle::getCircle() {
	return circle;
}

void Circle::setCircle(Rectangle circle) {
	this->circle = circle;
}

void Circle::drawingMyFigures(System::Drawing::Graphics^ graphics) {
	graphics->DrawEllipse(gcnew Pen(Color::Black, 4), circle);
}

MyFiguresForGraphicEditor^ Circle::findMyFigures(int x, int y) {
	int center_x = (circle.Left + circle.Right) / 2;
	int center_y = (circle.Top + circle.Bottom) / 2;
	int rad_w = circle.Width / 2;
	int rad_h = circle.Height / 2;
	double formula = pow((double)(x - center_x) / rad_w, 2) + pow((double)(y - center_y) / rad_h, 2);
	if (formula >= 0.8 && formula <= 1.17) {
		return this;
	}

	return nullptr;
}