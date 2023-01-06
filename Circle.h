#pragma once
#include "MyFiguresForGraphicEditor.h"

ref class Circle :public MyFiguresForGraphicEditor {
private:
	System::Drawing::Rectangle circle;
public:
	Circle(System::Drawing::Rectangle circle);

	System::Drawing::Rectangle getCircle();
	void setCircle(System::Drawing::Rectangle circle);

	//Наследуем из MyFiguresForGraphicEditor
	virtual void drawingMyFigures(System::Drawing::Graphics^ graphics) override;
	virtual MyFiguresForGraphicEditor^ findMyFigures(int x, int y) override;
};