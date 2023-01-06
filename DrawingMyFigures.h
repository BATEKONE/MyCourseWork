#pragma once
#include "MyFiguresForGraphicEditor.h"
#include <cliext/list>

using namespace cliext;

ref class DrawingMyFigures {
private:
	list<MyFiguresForGraphicEditor^> figures;
public:
	void addMyFiguresForGraphicEditor(MyFiguresForGraphicEditor^ figure);
	void drawMyFiguresForGraphicEditors(Graphics^ graphics);
	void setMyFiguresForGraphicEditors(list<MyFiguresForGraphicEditor^> figures);
	void deleteMyFiguresForGraphicEditor(MyFiguresForGraphicEditor^ figure);
	void clearList();

	MyFiguresForGraphicEditor^ findMyFiguresForGraphicEditor(int x, int y);
	list<MyFiguresForGraphicEditor^> getMyFiguresForGraphicEditors();
};