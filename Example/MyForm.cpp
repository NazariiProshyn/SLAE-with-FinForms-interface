#include "MyForm.h"
#include "SLARForm1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Example::MyForm form;
	Application::Run(% form);

}
//перейти до розв'язку
System::Void Example::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	SLARForm1^ form = gcnew SLARForm1();
	this->Hide();
	form->Show();
}

System::Void Example::MyForm::проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Програма розроблена студентом\nКПІ Прошином Н.А.\nПрограма розв'язує СЛАР\n3 методами", "СЛАР.Інформація");
}
