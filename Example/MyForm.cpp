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
//������� �� ����'����
System::Void Example::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	SLARForm1^ form = gcnew SLARForm1();
	this->Hide();
	form->Show();
}

System::Void Example::MyForm::�����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("�������� ���������� ���������\n�ϲ �������� �.�.\n�������� ����'��� ����\n3 ��������", "����.����������");
}
