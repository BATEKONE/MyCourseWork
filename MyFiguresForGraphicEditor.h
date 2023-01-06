#pragma once

using namespace System::Drawing;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization;

[XmlRootAttribute("MyFiguresForGraphicEditor")]
ref class MyFiguresForGraphicEditor abstract {
public:
	[XmlAttributeAttribute]
	int type;
	virtual void drawingMyFigures(Graphics^ graphics) = 0;
	virtual MyFiguresForGraphicEditor^ findMyFigures(int x, int y) = 0;
}; 