#pragma once
#include "MyFiguresForGraphicEditor.h"

ref class RectangleRec :public MyFiguresForGraphicEditor {
private:
	System::Drawing::Rectangle rectangle;
public:
	RectangleRec(System::Drawing::Rectangle rectangle);

	System::Drawing::Rectangle getRec();
	void setRec(System::Drawing::Rectangle rectangle);

	//Наследуем из MyFiguresForGraphicEditor
	virtual void drawingMyFigures(Graphics^ graphics) override;
	virtual MyFiguresForGraphicEditor^ findMyFigures(int x, int y)override;
};