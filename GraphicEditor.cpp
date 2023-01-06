#include "GraphicEditor.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace CourseWork;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew GraphicEditor);
	return 0;
}

void GraphicEditor::log(String^ message) {
	richTextBox1->Text += message + "\n";
}

void GraphicEditor::serialize(String^ filename, MyFiguresForGraphicEditor::Object^ S) {
	XmlSerializer^ formatter = gcnew XmlSerializer(S->GetType());

	FileStream^ fs = gcnew FileStream(filename, FileMode::OpenOrCreate);
	formatter->Serialize(fs, S);

	fs->Close();
}

void GraphicEditor::deserialize(String^ filename, MyFiguresForGraphicEditor::Object^ S) {
	XmlSerializer^ formatter = gcnew XmlSerializer(S->GetType());
	FileStream^ fs = gcnew FileStream(filename, FileMode::OpenOrCreate);
	obj = (Object^)formatter->Deserialize(fs);

	fs->Close();
}
