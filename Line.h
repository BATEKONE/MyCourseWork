#pragma once
#include "MyFiguresForGraphicEditor.h"

ref class Line :public MyFiguresForGraphicEditor {
private:
	Point x1, x2;
public:
	Line(Point x1, Point x2);

	Point getx1Point();
	Point getx2Point();

	void setx1Point(Point x);
	void setx2Point(Point x);

	////Наследуем из MyFiguresForGraphicEditor
	virtual void drawingMyFigures(Graphics^ graphics) override;
	virtual MyFiguresForGraphicEditor^ findMyFigures(int x, int y) override;
};