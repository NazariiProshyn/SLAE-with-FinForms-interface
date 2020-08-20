#include "Graph1.h"
#include"Functions.h"
#include"SLARForm1.h"
#include"MyForm.h"
SLAR slar2;
//SLAR slar2;
Solution funct12;
System::Void Example::Graph1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	//обновляємо значення матриці
	for (int i = 0; i < slar2.getsize(); i++) {
		for (int j = 0; j < slar2.getsize(); j++) {

			slar2.Matrix[i][j] = Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value->ToString());

		}
	}
	for (int i = 0; i < slar2.getsize(); i++) {

		slar2.Result[i] = Convert::ToDouble(dataGridView2->Rows[i]->Cells[0]->Value->ToString());
	}
	//обновляємо параметри матриць
	ShowM();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
	//обновляємо параметри матриць
	ShowV();
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();

	slar2.answer = slar2.Menu(funct12);

	if (slar2.determ(slar2.Matrix, slar2.getsize()) != 0) {

		dataGridView3->RowCount = slar2.getsize();

		dataGridView3->ColumnCount = 1;
		//обновляємо параметри матриць
		ShowA();

		dataGridView3->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);

		dataGridView3->AutoResizeColumns();
	}

	//задаємо параметри графіка
	double a = -10, b = 10, h = 0.1, x1, y1, x2, y2;

	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();

	x1 = a; x2 = a;
	//створюємо графіки
	while (x1 <= b) {

		y1 = (slar2.Result[0] - x1 * slar2.Matrix[0][0]) / slar2.Matrix[0][1];
		y2 = (slar2.Result[1] - x2 * slar2.Matrix[1][0]) / slar2.Matrix[1][1];

		this->chart1->Series[0]->Points->AddXY(x1, y1);
		this->chart1->Series[1]->Points->AddXY(x2, y2);

		x1 += h;
		x2 += h;
	}
	return System::Void();
}

System::Void Example::Graph1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	slar2.setsize(2);

	//обновляємо параметри матриць
	slar2.Matrix = slar2.createMatrix(slar2.getsize());
	slar2.Result = slar2.createResult(slar2.getsize());
	slar2.answer = slar2.createanswer(slar2.getsize());

	//обновляємо параметри матриць
	dataGridView1->RowCount = slar2.getsize();
	dataGridView1->ColumnCount = slar2.getsize();
	ShowM();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	//обновляємо параметри матриць
	dataGridView2->RowCount = slar2.getsize();
	dataGridView2->ColumnCount = 1;
	ShowV();
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();


	return System::Void();
}
//обновляємо параметри матриць,виводимо матриці
//матриця Основна
void Example::Graph1::ShowM()
{
	string name;
	int a = 0;
	for (int i = 0; i < slar2.getsize(); i++) {

		for (int j = 0; j < slar2.getsize(); j++) {
			//заповнення основної матриці
			name = "SLAR";
			dataGridView1->TopLeftHeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			a = j + 1;
			name = '0' + a;

			dataGridView1->Columns[j]->HeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			a = i + 1;
			name = '0' + a;
			dataGridView1->Rows[i]->HeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			dataGridView1->Rows[i]->Cells[j]->Value = slar2.Matrix[i][j];

		}

	}
}
//матриця ВІльних
void Example::Graph1::ShowV()
{
	string name;
	int a = 0;
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < slar2.getsize(); j++) {
			//заповнення вектора-відповідей
			name = "RES";
			dataGridView2->TopLeftHeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			a = i + 1;
			name = '0' + a;
			//MessageBox::Show("name", "!");
			dataGridView2->Columns[i]->HeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			a = j + 1;
			name = '0' + a;
			dataGridView2->Rows[j]->HeaderCell->Value = Convert_string_to_String(name);

			dataGridView2->Rows[j]->Cells[i]->Value = slar2.Result[j];;

		}

	}
}
//матриця Вектор
void Example::Graph1::ShowA()

{
	string name;
	int a = 0;
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < slar2.getsize(); j++) {
			//заповненння полей матриць
			name = "ANS";
			dataGridView3->TopLeftHeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			a = i + 1;
			name = '0' + a;
			//MessageBox::Show("name", "!");
			dataGridView3->Columns[i]->HeaderCell->Value = Convert_string_to_String(name);
			name.clear();
			a = j + 1;
			name = '0' + a;
			dataGridView3->Rows[j]->HeaderCell->Value = Convert_string_to_String(name);

			dataGridView3->Rows[j]->Cells[i]->Value = slar2.answer[j];

		}

	}
}

System::Void Example::Graph1::повернутисьВМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm();
	this->Hide();
	form->Show();
}

System::Void Example::Graph1::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Example::Graph1::проПрограмуToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Програма розроблена студентом\nКПІ Прошином Н.А.\nПрограма розв'язує СЛАР\n3 методами", "СЛАР.Інформація");
}

