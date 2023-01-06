#include "RectangleRec.h"
#include <cmath>

RectangleRec::RectangleRec(Rectangle rectangle) {
	type = 2;
}

Rectangle RectangleRec::getRec() {
	return rectangle;
}

void RectangleRec::setRec(Rectangle rectangle) {
	this->rectangle = rectangle;
}

void RectangleRec::drawingMyFigures(Graphics^ graphics) {
	graphics->DrawRectangle(gcnew Pen(Color::Black, 8), rectangle);
}

MyFiguresForGraphicEditor^ RectangleRec::findMyFigures(int x, int y) {
    if (abs(rectangle.Top - y) <= 5 || abs(rectangle.Bottom - y) <= 5) {
        if (rectangle.Left - 2 <= x && rectangle.Right + 2 >= x) {
            return this;
        }
    }
    else if (abs(rectangle.Left - x) <= 7 || abs(rectangle.Right - x) <= 7)
    {
        if (rectangle.Bottom + 2 >= y && rectangle.Top - 2 <= y) {
            return this;
        }
    }

    return nullptr;

}