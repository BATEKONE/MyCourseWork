#pragma once
#include "Circle.h"
#include "DrawingMyFigures.h"
#include "Line.h"
#include "RectangleRec.h"

namespace CourseWork {
	constexpr auto CURSOR = 0;
	constexpr auto CIRCLE = 1;
	constexpr auto RECTANGLE = 2;
	constexpr auto LINE = 3;
	constexpr auto DEL = 4;

	using namespace System;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	
	public ref class GraphicEditor : public System::Windows::Forms::Form
	{
	public:
		GraphicEditor(void)
		{
			InitializeComponent();
			log("Loaded");
			saveFileDialog1->Filter = "(*.xml) | *.xml | (*.jpg) | *.jpg";
			pictureBoxName1->SizeMode = PictureBoxSizeMode::AutoSize;

			maxVecBoxHeight = pictureBoxName1->Height;
			maxVecBoxWidth = pictureBoxName1->Width;
			isDown = false;

			bitmap = gcnew Bitmap(pictureBoxName1->Size.Width, pictureBoxName1->Size.Height);
			graphics = Graphics::FromImage(bitmap);
			graphics->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, pictureBoxName1->Width, pictureBoxName1->Height);
			pictureBoxName1->Image = bitmap;

			drawMyFiguresForGraphicEditors_draw();
			
			cursorType = CURSOR;
		}

	protected:
		~GraphicEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ MenuStripName1;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuName1;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuSaveName1;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuOpenName1;
	private: System::Windows::Forms::PictureBox^ pictureBoxName1;
	private: System::Windows::Forms::Button^ circleButton;
	private: System::Windows::Forms::Button^ rectangleButton;
	private: System::Windows::Forms::Button^ lineButton;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::Button^ cursorButton;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GraphicEditor::typeid));
			this->MenuStripName1 = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuName1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuSaveName1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuOpenName1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBoxName1 = (gcnew System::Windows::Forms::PictureBox());
			this->circleButton = (gcnew System::Windows::Forms::Button());
			this->rectangleButton = (gcnew System::Windows::Forms::Button());
			this->lineButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->cursorButton = (gcnew System::Windows::Forms::Button());
			this->MenuStripName1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxName1))->BeginInit();
			this->SuspendLayout();
			// 
			// MenuStripName1
			// 
			this->MenuStripName1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)));
			resources->ApplyResources(this->MenuStripName1, L"MenuStripName1");
			this->MenuStripName1->ImageScalingSize = System::Drawing::Size(50, 200);
			this->MenuStripName1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuName1 });
			this->MenuStripName1->Name = L"MenuStripName1";
			this->MenuStripName1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &GraphicEditor::MenuStripName1_ItemClicked);
			// 
			// MenuName1
			// 
			this->MenuName1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->MenuSaveName1,
					this->MenuOpenName1
			});
			this->MenuName1->Name = L"MenuName1";
			resources->ApplyResources(this->MenuName1, L"MenuName1");
			this->MenuName1->TextDirection = System::Windows::Forms::ToolStripTextDirection::Horizontal;
			this->MenuName1->Click += gcnew System::EventHandler(this, &GraphicEditor::MenuName1_Click);
			// 
			// MenuSaveName1
			// 
			this->MenuSaveName1->Name = L"MenuSaveName1";
			resources->ApplyResources(this->MenuSaveName1, L"MenuSaveName1");
			this->MenuSaveName1->Click += gcnew System::EventHandler(this, &GraphicEditor::saveFileDialog1_Click);
			// 
			// MenuOpenName1
			// 
			this->MenuOpenName1->Name = L"MenuOpenName1";
			resources->ApplyResources(this->MenuOpenName1, L"MenuOpenName1");
			this->MenuOpenName1->Click += gcnew System::EventHandler(this, &GraphicEditor::openFileDialog1_Click);
			// 
			// pictureBoxName1
			// 
			this->pictureBoxName1->BackColor = System::Drawing::Color::SeaShell;
			resources->ApplyResources(this->pictureBoxName1, L"pictureBoxName1");
			this->pictureBoxName1->Name = L"pictureBoxName1";
			this->pictureBoxName1->TabStop = false;
			this->pictureBoxName1->Click += gcnew System::EventHandler(this, &GraphicEditor::cursorButton_Click);
			this->pictureBoxName1->DoubleClick += gcnew System::EventHandler(this, &GraphicEditor::deleteButton_Click);
			this->pictureBoxName1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseDown);
			this->pictureBoxName1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseMove);
			this->pictureBoxName1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseUp);
			// 
			// circleButton
			// 
			this->circleButton->BackColor = System::Drawing::Color::SeaShell;
			resources->ApplyResources(this->circleButton, L"circleButton");
			this->circleButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->circleButton->Name = L"circleButton";
			this->circleButton->UseVisualStyleBackColor = false;
			this->circleButton->Click += gcnew System::EventHandler(this, &GraphicEditor::circleButton_Click);
			this->circleButton->Enter += gcnew System::EventHandler(this, &GraphicEditor::circleButton_Click);
			this->circleButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseDown);
			this->circleButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseMove);
			this->circleButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseUp);
			// 
			// rectangleButton
			// 
			this->rectangleButton->BackColor = System::Drawing::Color::SeaShell;
			resources->ApplyResources(this->rectangleButton, L"rectangleButton");
			this->rectangleButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->rectangleButton->Name = L"rectangleButton";
			this->rectangleButton->UseVisualStyleBackColor = false;
			this->rectangleButton->Click += gcnew System::EventHandler(this, &GraphicEditor::rectangleButton_Click);
			this->rectangleButton->Enter += gcnew System::EventHandler(this, &GraphicEditor::rectangleButton_Click);
			this->rectangleButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseDown);
			this->rectangleButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseMove);
			this->rectangleButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseUp);
			// 
			// lineButton
			// 
			this->lineButton->BackColor = System::Drawing::Color::SeaShell;
			resources->ApplyResources(this->lineButton, L"lineButton");
			this->lineButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lineButton->Name = L"lineButton";
			this->lineButton->UseVisualStyleBackColor = false;
			this->lineButton->Click += gcnew System::EventHandler(this, &GraphicEditor::lineleButton_Click);
			this->lineButton->Enter += gcnew System::EventHandler(this, &GraphicEditor::lineleButton_Click);
			this->lineButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseDown);
			this->lineButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseMove);
			this->lineButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseUp);
			// 
			// richTextBox1
			// 
			resources->ApplyResources(this->richTextBox1, L"richTextBox1");
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &GraphicEditor::rectangleButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::Color::SeaShell;
			resources->ApplyResources(this->clearButton, L"clearButton");
			this->clearButton->Name = L"clearButton";
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &GraphicEditor::clearButton_Click);
			this->clearButton->Enter += gcnew System::EventHandler(this, &GraphicEditor::clearButton_Click);
			this->clearButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseDown);
			this->clearButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseMove);
			this->clearButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseUp);
			// 
			// cursorButton
			// 
			this->cursorButton->BackColor = System::Drawing::Color::SeaShell;
			resources->ApplyResources(this->cursorButton, L"cursorButton");
			this->cursorButton->Name = L"cursorButton";
			this->cursorButton->UseVisualStyleBackColor = false;
			this->cursorButton->Enter += gcnew System::EventHandler(this, &GraphicEditor::cursorButton_Click);
			this->cursorButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseDown);
			this->cursorButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseMove);
			this->cursorButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphicEditor::pictureBoxName1_MouseUp);
			// 
			// GraphicEditor
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			resources->ApplyResources(this, L"$this");
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)));
			this->Controls->Add(this->cursorButton);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->lineButton);
			this->Controls->Add(this->rectangleButton);
			this->Controls->Add(this->circleButton);
			this->Controls->Add(this->pictureBoxName1);
			this->Controls->Add(this->MenuStripName1);
			this->ForeColor = System::Drawing::Color::Black;
			this->MainMenuStrip = this->MenuStripName1;
			this->MaximizeBox = false;
			this->Name = L"GraphicEditor";
			this->Load += gcnew System::EventHandler(this, &GraphicEditor::GraphicEditor_Load);
			this->Resize += gcnew System::EventHandler(this, &GraphicEditor::GraphicEditor_Resize);
			this->MenuStripName1->ResumeLayout(false);
			this->MenuStripName1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxName1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Graphics^ graphics;
			Bitmap^ bitmap;
			Object^ obj = nullptr;
			Point mouseDownPosition;
			Point mouseCurrentPosition;
			Point mousePrevPosition;
			DrawingMyFigures drawMyFiguresForGraphicEditors;
			int maxVecBoxWidth;
			int maxVecBoxHeight;
			int cursorType;
			RectangleRec^ newRectangleRec;
			Circle^ newCircle;
			Line^ newLine;
			MyFiguresForGraphicEditor^ movingFigure;
			bool isDown;
			MyFiguresForGraphicEditor^ deleteFigure;

			void serialize(String^ filename, MyFiguresForGraphicEditor::Object^ S);
			void deserialize(String^ filename, MyFiguresForGraphicEditor::Object^ S);

			void log(String^ message);

			System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
				drawMyFiguresForGraphicEditors.clearList();
				drawMyFiguresForGraphicEditors_draw();
				richTextBox1->Clear();
			}

			System::Void cursorButton_Click(System::Object^ sender, System::EventArgs^ e) {
				cursorType = CURSOR;
			}

			System::Void rectangleButton_Click(System::Object^ sender, System::EventArgs^ e) {
				cursorType = RECTANGLE;
			}

			System::Void circleButton_Click(System::Object^ sender, System::EventArgs^ e) {
				cursorType = CIRCLE;
			}

			System::Void lineleButton_Click(System::Object^ sender, System::EventArgs^ e) {
				cursorType = LINE;
			}

			System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
				cursorType = DEL;
			}

			System::Void drawMyFiguresForGraphicEditors_draw() {
				Graphics^ graphics = Graphics::FromImage(pictureBoxName1->Image);
				graphics->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, pictureBoxName1->Width, pictureBoxName1->Height);
				drawMyFiguresForGraphicEditors.drawMyFiguresForGraphicEditors(graphics);
				pictureBoxName1->Invalidate();
			}

			System::Void pictureBoxName1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
				isDown = true;
				mouseDownPosition = Point(e->X, e->Y);
				mousePrevPosition = Point(e->X, e->Y);
				drawMyFiguresForGraphicEditors_draw();

				switch (cursorType) {
				case CURSOR:
					movingFigure = drawMyFiguresForGraphicEditors.findMyFiguresForGraphicEditor(e->X, e->Y);
					if (movingFigure != nullptr) {
						switch (movingFigure->type) {
						case CIRCLE:							
							movingFigure = (Circle^)movingFigure;
							log("Создан объект: скамейка");
							break;
						case RECTANGLE:							
							movingFigure = (RectangleRec^)movingFigure;
							log("Создан объект: План вокзала");
							break;
						case LINE:
							movingFigure = (Line^)movingFigure;
							log("Создан объект: рельсы");
							
							break;
						}
					}
					break;
				case CIRCLE:
					newCircle = gcnew Circle(System::Drawing::Rectangle(mouseDownPosition, System::Drawing::Size(1, 1)));
					newCircle->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
					break;
				case RECTANGLE:
					newRectangleRec = gcnew RectangleRec(System::Drawing::Rectangle(mouseDownPosition, System::Drawing::Size(1, 1)));
					newRectangleRec->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
					break;
				case LINE:
					newLine = gcnew Line(mouseDownPosition, mouseDownPosition);
					newLine->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
					break;
				case DEL:
					deleteFigure = drawMyFiguresForGraphicEditors.findMyFiguresForGraphicEditor(e->X, e->Y);
					if (deleteFigure != nullptr) {
						drawMyFiguresForGraphicEditors.deleteMyFiguresForGraphicEditor(deleteFigure);
					}
					deleteFigure = nullptr;
					break;
				}
				pictureBoxName1->Invalidate();
			}

			System::Void pictureBoxName1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
				if (isDown)
				{
					mouseCurrentPosition = Point(e->Location);
					if (movingFigure == nullptr) {
						changeNewFigureSize();
						drawMyFiguresForGraphicEditors_draw();
						switch (cursorType)
						{
						case CURSOR:
							break;
						case RECTANGLE:
							newRectangleRec->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
							break;
						case LINE:
							newLine->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
							break;
						case CIRCLE:
							newCircle->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
							break;
						}
					}
					else
					{
						changeMovingFigurePosition();
						drawMyFiguresForGraphicEditors_draw();
						movingFigure->drawingMyFigures(Graphics::FromImage(pictureBoxName1->Image));
						mousePrevPosition = mouseCurrentPosition;
					}
					pictureBoxName1->Invalidate();
				}
			}
			
			System::Void pictureBoxName1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
				isDown = false;
				switch (cursorType)
				{
				case CURSOR:
					if (movingFigure != nullptr) {
						drawMyFiguresForGraphicEditors.addMyFiguresForGraphicEditor(movingFigure);
						movingFigure = nullptr;
					}
					break;
				case RECTANGLE:
					drawMyFiguresForGraphicEditors.addMyFiguresForGraphicEditor(newRectangleRec);
					break;
				case LINE:
					drawMyFiguresForGraphicEditors.addMyFiguresForGraphicEditor(newLine);					
					break;
				case CIRCLE:
					drawMyFiguresForGraphicEditors.addMyFiguresForGraphicEditor(newCircle);					
					break;
				}
				drawMyFiguresForGraphicEditors_draw();
			}

			System::Void saveFileDialog1_Click(System::Object^ sender, System::EventArgs^ e) {
				if ((int)saveFileDialog1->ShowDialog() != 1) {
					return;
				}
				else {
					pictureBoxName1->Image->Save(saveFileDialog1->FileName);
				}
				MessageBox::Show("Файл успешно сохранен");

				return System::Void();
			}

			System::Void openFileDialog1_Click(System::Object^ sender, System::EventArgs^ e) {
				pictureBoxName1->Image = bitmap;
				pictureBoxName1->BackColor = Color::White;
				openFileDialog1->Title = "Открыть изображение";
				openFileDialog1->Filter = "(*.xml) | *.xml | (*.jpg) | *.jpg";
				if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) {
					pictureBoxName1->ErrorImage;
				}

				return System::Void();
			}

		    System::Void changeNewFigureSize() {
				int dX = mouseCurrentPosition.X - mouseDownPosition.X;
				int dY = mouseCurrentPosition.Y - mouseDownPosition.Y;
				switch (cursorType)
				{
				case CURSOR:
					return;
				case RECTANGLE: {
					System::Drawing::Size s(fabs(mouseCurrentPosition.X - mouseDownPosition.X), fabs(mouseCurrentPosition.Y - mouseDownPosition.Y));
					Point p(fmin(mouseCurrentPosition.X, mouseDownPosition.X), fmin(mouseCurrentPosition.Y, mouseDownPosition.Y));
					if (p.X < 0 || p.X + s.Width > pictureBoxName1->Width || p.Y < 0 || p.Y + s.Height > pictureBoxName1->Height)
						return;
					newRectangleRec->setRec(System::Drawing::Rectangle(p, s));
					break;
				}
				case LINE:
					if (mouseCurrentPosition.X < 0 || mouseCurrentPosition.X > pictureBoxName1->Width || mouseCurrentPosition.Y < 0 || mouseCurrentPosition.Y > pictureBoxName1->Height)
						return;
					newLine->setx1Point(mouseDownPosition);
					newLine->setx2Point(mouseCurrentPosition);
					break;
				case CIRCLE:
					System::Drawing::Size s(fabsl(mouseCurrentPosition.X - mouseDownPosition.X), fabsl(mouseCurrentPosition.Y - mouseDownPosition.Y));
					Point p(fmin(mouseCurrentPosition.X, mouseDownPosition.X), fmin(mouseCurrentPosition.Y, mouseDownPosition.Y));
					if (p.X < 0 || p.X + s.Width > pictureBoxName1->Width || p.Y < 0 || p.Y + s.Height > pictureBoxName1->Height)
						return;
					newCircle->setCircle(System::Drawing::Rectangle(mouseDownPosition.X, mouseDownPosition.Y, dX, dY));
					break;
				}
			}
		   
		    System::Void changeMovingFigurePosition() {
			   System::Drawing::Rectangle rectangleRec;
			   Point x1;
			   Point x2;
			   int dX = mouseCurrentPosition.X - mousePrevPosition.X;
			   int dY = mouseCurrentPosition.Y - mousePrevPosition.Y;
			   switch (movingFigure->type)
			   {
			   case RECTANGLE:
				   rectangleRec = ((RectangleRec^)movingFigure)->getRec();
				   if (rectangleRec.X + dX < 0 || rectangleRec.X + rectangleRec.Width + dX > pictureBoxName1->Width || rectangleRec.Y + dY < 0 || rectangleRec.Y + rectangleRec.Height + dY > pictureBoxName1->Height)
					   return;
				   ((RectangleRec^)movingFigure)->setRec(System::Drawing::Rectangle(rectangleRec.X + dX, rectangleRec.Y + dY, rectangleRec.Width, rectangleRec.Height));
				   break;
			   case LINE:
				   x1 = ((Line^)movingFigure)->getx1Point();
				   x2 = ((Line^)movingFigure)->getx2Point();
				   if (x1.X + dX < 0 || x1.X + dX > pictureBoxName1->Width || x1.Y + dY < 0 || x1.Y + dY > pictureBoxName1->Height)
					   return;
				   if (x2.X + dX < 0 || x2.X + dX > pictureBoxName1->Width || x2.Y + dY < 0 || x2.Y + dY > pictureBoxName1->Height)
					   return;
				   ((Line^)movingFigure)->setx1Point(Point(x1.X + dX, x1.Y + dY));
				   ((Line^)movingFigure)->setx2Point(Point(x2.X + dX, x2.Y + dY));
				   break;
			   case CIRCLE:
				   rectangleRec = ((Circle^)movingFigure)->getCircle();

				   if (rectangleRec.Width < 0 && (rectangleRec.X + dX > pictureBoxName1->Width || rectangleRec.X + rectangleRec.Width + dX < 0))
					   return;
				   else if (rectangleRec.Width > 0 && (rectangleRec.X + rectangleRec.Width + dX > pictureBoxName1->Width || rectangleRec.X + dX < 0))
					   return;
				   if (rectangleRec.Height < 0 && (rectangleRec.Y + dX > pictureBoxName1->Height || rectangleRec.Y + rectangleRec.Height + dX < 0))
					   return;
				   else if (rectangleRec.Height > 0 && (rectangleRec.Y + rectangleRec.Height + dX > pictureBoxName1->Height || rectangleRec.Y + dX < 0))
					   return;

				   ((Circle^)movingFigure)->setCircle(System::Drawing::Rectangle(rectangleRec.X + dX, rectangleRec.Y + dY, rectangleRec.Width, rectangleRec.Height));
				   break;
			   }
		   }
		   
		    System::Void GraphicEditor_Resize(System::Object^ sender, System::EventArgs^ e) {
			   if (maxVecBoxWidth < this->Width || maxVecBoxHeight < this->Height)
			   {
				   pictureBoxName1->Width = this->Width - 40;
				   pictureBoxName1->Width = this->Width - 47;
				   pictureBoxName1->Height = this->Height - 138;
				   Image^ oldImage = pictureBoxName1->Image;
				   Bitmap^ newBitmap = gcnew Bitmap(oldImage, pictureBoxName1->Width, pictureBoxName1->Height);
				   pictureBoxName1->Image = newBitmap;

				   maxVecBoxHeight = pictureBoxName1->Height;
				   maxVecBoxWidth = pictureBoxName1->Width;

				   drawMyFiguresForGraphicEditors_draw();
			   }
			   else
			   {
				   pictureBoxName1->Width = this->Width - 50;
				   pictureBoxName1->Height = this->Height - 150;
			   }
			}

			System::Void GraphicEditor_Load(System::Object^ sender, System::EventArgs^ e) {}
			System::Void MenuStripName1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {} 
			System::Void MenuName1_Click(System::Object^ sender, System::EventArgs^ e) {}
};
}