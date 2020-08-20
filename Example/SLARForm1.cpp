#include "SLARForm1.h"
#include"Functions.h"
#include"Graph1.h"

SLAR slar1;
Solution funct;


System::Void Example::SLARForm1::проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Програма розроблена студентом\nКПІ Прошином Н.А.\nПрограма розв'язує СЛАР\n3 методами", "СЛАР.Інформація");
}

System::Void Example::SLARForm1::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
//створення масивів
System::Void Example::SLARForm1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	//обновляємо параметри матриць
	slar1.setsize(Convert::ToInt32(numericUpDown1->Value));
	slar1.Matrix = slar1.createMatrix(slar1.getsize());
	slar1.Result = slar1.createResult(slar1.getsize());
	slar1.answer = slar1.createanswer(slar1.getsize());
	//обновляємо параметри матриць
	dataGridView1->RowCount = slar1.getsize();
	dataGridView1->ColumnCount = slar1.getsize();
	ShowM();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();
	//обновляємо параметри матриць
	dataGridView2->RowCount = slar1.getsize();
	dataGridView2->ColumnCount = 1;
	ShowV();
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();

	return System::Void();
}
//випадкове заповнення
System::Void Example::SLARForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int size = Convert::ToInt32(numericUpDown1->Value);
	if (size == slar1.getsize()) {
		//обновляємо параметри матриць
		slar1.Matrix = slar1.RandomMatrix(slar1.getsize());
		slar1.Result = slar1.RandomResult(slar1.getsize());
		//обновляємо параметри матриць
		ShowM();
		dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridView1->AutoResizeColumns();
		//обновляємо параметри матриць
		ShowV();
		dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridView2->AutoResizeColumns();
	}
	else { MessageBox::Show("Створи матрицю відповідного розміру!", "Оголошення!"); }
	return System::Void();
}
//радіобатони
System::Void Example::SLARForm1::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	slar1.setmethod("Kramer");
	return System::Void();
}
System::Void Example::SLARForm1::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	slar1.setmethod("gauss");
	return System::Void();
}
System::Void Example::SLARForm1::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	slar1.setmethod("gaussM");
	return System::Void();
}

//розв'язання
System::Void Example::SLARForm1::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	int size = Convert::ToInt32(numericUpDown1->Value);
	if (size == slar1.getsize()) {
		//обновляємо параметри матриць
		slar1.setsize(Convert::ToInt32(numericUpDown1->Value));
		//обновляємо параметри матриць
		slar1.answer = slar1.Menu(funct);
		dataGridView3->RowCount = slar1.getsize();
		dataGridView3->ColumnCount = 1;

		if (slar1.determ(slar1.Matrix, slar1.getsize()) != 0) {
			//обновляємо параметри матриць
			ShowA();
			dataGridView3->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			dataGridView3->AutoResizeColumns();

		}
	}

	else { MessageBox::Show("Створи матрицю відповідного розміру!", "Оголошення!"); }

	return System::Void();

}
//обновлення інформації
System::Void Example::SLARForm1::button5_Click(System::Object^ sender, System::EventArgs^ e)
{

	for (int i = 0; i < slar1.getsize(); i++) {
		for (int j = 0; j < slar1.getsize(); j++) {
			//нові значення
			slar1.Matrix[i][j] = Convert::ToDouble(dataGridView1->Rows[i]->Cells[j]->Value->ToString());

		}
	}
	for (int i = 0; i < slar1.getsize(); i++) {

		slar1.Result[i] = Convert::ToDouble(dataGridView2->Rows[i]->Cells[0]->Value->ToString());

	}

	ShowM();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	ShowV();
	dataGridView2->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView2->AutoResizeColumns();

	return System::Void();
}
//збереження 1 файлу
System::Void Example::SLARForm1::зберегтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	slar1.vuvid2();
}
//збереження інформації
System::Void Example::SLARForm1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	slar1.vuvid3();
}
//перейти в іншу форму
System::Void Example::SLARForm1::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	Graph1^ form = gcnew Graph1();
	this->Hide();
	form->Show();
}
//додаткова інформація
System::Void Example::SLARForm1::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	int size = Convert::ToInt32(numericUpDown1->Value);
	if (size == slar1.getsize()) {

		int deter;

		deter = slar1.determ(slar1.Matrix, slar1.getsize());

		string geterm, row;

		geterm = "Детермінант матриці=";

		row = '0' + deter;

		row.clear();

		MessageBox::Show(Convert_string_to_String(geterm), "ІНФОРМАЦІЯ");
	}
	else { MessageBox::Show("Створи матрицю відповідного розміру!", "Оголошення!"); }

	return System::Void();
}

//обновляємо параметри матриць
void Example::SLARForm1::ShowM()
{
	string name;
	int a = 0;
	for (int i = 0; i < slar1.getsize(); i++) {

		for (int j = 0; j < slar1.getsize(); j++) {
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
			dataGridView1->Rows[i]->Cells[j]->Value = slar1.Matrix[i][j];

		}

	}
}
//обновляємо параметри матриць
void Example::SLARForm1::ShowV()
{
	string name;
	int a = 0;
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < slar1.getsize(); j++) {
			name = "RES";
			//обновляємо параметри матриць
			dataGridView2->TopLeftHeaderCell->Value = Convert_string_to_String(name);

			name.clear();
			a = i + 1;
			name = '0' + a;

			dataGridView2->Columns[i]->HeaderCell->Value = Convert_string_to_String(name);

			name.clear();
			a = j + 1;
			name = '0' + a;

			dataGridView2->Rows[j]->HeaderCell->Value = Convert_string_to_String(name);

			dataGridView2->Rows[j]->Cells[i]->Value = slar1.Result[j];;

		}

	}
}
//обновляємо параметри матриць
void Example::SLARForm1::ShowA()

{
	string name;
	int a = 0;
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < slar1.getsize(); j++) {
			name = "ANS";

			dataGridView3->TopLeftHeaderCell->Value = Convert_string_to_String(name);

			name.clear();
			a = i + 1;
			name = '0' + a;

			dataGridView3->Columns[i]->HeaderCell->Value = Convert_string_to_String(name);

			name.clear();
			a = j + 1;
			name = '0' + a;

			dataGridView3->Rows[j]->HeaderCell->Value = Convert_string_to_String(name);

			dataGridView3->Rows[j]->Cells[i]->Value = slar1.answer[j];

		}

	}
}


