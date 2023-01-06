#include "DrawingMyFigures.h"

void DrawingMyFigures::addMyFiguresForGraphicEditor(MyFiguresForGraphicEditor^ figure)
{
    figures.push_front(figure);
}

void DrawingMyFigures::drawMyFiguresForGraphicEditors(Graphics^ graphics)
{
    if (!figures.empty()) {
        for each (MyFiguresForGraphicEditor ^ figure in figures) {
            figure->drawingMyFigures(graphics);
        }
    }
}

MyFiguresForGraphicEditor^ DrawingMyFigures::findMyFiguresForGraphicEditor(int x, int y)
{
    MyFiguresForGraphicEditor^ result = nullptr;
    for each (MyFiguresForGraphicEditor ^ figure in figures) {
        if (figure->findMyFigures(x, y) != nullptr)
        {
            result = figure;
            figures.remove(figure);
            break;
        }
    }
    return result;
}

list<MyFiguresForGraphicEditor^> DrawingMyFigures::getMyFiguresForGraphicEditors()
{
    return figures;
}

void DrawingMyFigures::clearList()
{
    figures.clear();
}

void DrawingMyFigures::setMyFiguresForGraphicEditors(list<MyFiguresForGraphicEditor^> figures)
{
    this->figures = figures;
}

void DrawingMyFigures::deleteMyFiguresForGraphicEditor(MyFiguresForGraphicEditor^ figure)
{
    figures.remove(figure);
}
