#pragma once
#include <iostream>
#include <string>
#include "marshal.h"

namespace IPCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  ip_input;
	private: System::Windows::Forms::ComboBox^  netmask_input;
	private: System::Windows::Forms::Button^  calculation_button;
	private: System::Windows::Forms::TextBox^  wildcard_output;
	private: System::Windows::Forms::TextBox^  network_adress_output;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ip_input = (gcnew System::Windows::Forms::TextBox());
			this->netmask_input = (gcnew System::Windows::Forms::ComboBox());
			this->calculation_button = (gcnew System::Windows::Forms::Button());
			this->wildcard_output = (gcnew System::Windows::Forms::TextBox());
			this->network_adress_output = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP-адрес";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(177, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Маска подсети";
			// 
			// ip_input
			// 
			this->ip_input->Location = System::Drawing::Point(12, 27);
			this->ip_input->Name = L"ip_input";
			this->ip_input->Size = System::Drawing::Size(118, 22);
			this->ip_input->TabIndex = 2;
			// 
			// netmask_input
			// 
			this->netmask_input->FormattingEnabled = true;
			this->netmask_input->Location = System::Drawing::Point(158, 27);
			this->netmask_input->Name = L"netmask_input";
			this->netmask_input->Size = System::Drawing::Size(144, 24);
			this->netmask_input->TabIndex = 3;
			// 
			// calculation_button
			// 
			this->calculation_button->Location = System::Drawing::Point(12, 71);
			this->calculation_button->Name = L"calculation_button";
			this->calculation_button->Size = System::Drawing::Size(290, 28);
			this->calculation_button->TabIndex = 4;
			this->calculation_button->Text = L"Рассчитать данные сети";
			this->calculation_button->UseVisualStyleBackColor = true;
			this->calculation_button->Click += gcnew System::EventHandler(this, &MyForm::calculation_button_Click);
			// 
			// wildcard_output
			// 
			this->wildcard_output->Location = System::Drawing::Point(12, 139);
			this->wildcard_output->Name = L"wildcard_output";
			this->wildcard_output->Size = System::Drawing::Size(290, 22);
			this->wildcard_output->TabIndex = 5;
			// 
			// network_adress_output
			// 
			this->network_adress_output->Location = System::Drawing::Point(12, 203);
			this->network_adress_output->Name = L"network_adress_output";
			this->network_adress_output->Size = System::Drawing::Size(290, 22);
			this->network_adress_output->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(96, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(123, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Инверсная маска";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(116, 183);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Адрес сети";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 506);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->network_adress_output);
			this->Controls->Add(this->wildcard_output);
			this->Controls->Add(this->calculation_button);
			this->Controls->Add(this->netmask_input);
			this->Controls->Add(this->ip_input);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void calculation_button_Click(System::Object^  sender, System::EventArgs^  e) {
		msclr::interop::marshal_context context;
		string ip_input_string = context.marshal_as<string>(ip_input->Text);
		string netmask_input_string = context.marshal_as<string>(netmask_input->Text);

		String^ network_adress_String = gcnew System::String(network_adress(ip_input_string, netmask_input_string).c_str());
		String^ wildcard_String = gcnew System::String(wildcard(netmask_input_string).c_str());

		wildcard_output->Text = wildcard_String;
		network_adress_output->Text = network_adress_String;
	}
};
}
