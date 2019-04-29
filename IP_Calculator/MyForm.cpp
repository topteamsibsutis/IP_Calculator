#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^> ^argv) {
	setlocale(LC_ALL, "Rus");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	IPCalculator::MyForm form;
	Application::Run(%form);
}