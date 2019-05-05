#pragma once
#include "calculations.h"
#include "marshal.h"
#include "marshal_cppstd.h"
#include <iostream>
#include <string>

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
public
ref class MyForm : public System::Windows::Forms::Form {
public:
  MyForm(void) {
    InitializeComponent();
    //
    // TODO: Add the constructor code here
    //
  }

protected:
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  ~MyForm() {
    if (components) {
      delete components;
    }
  }

private:
  System::Windows::Forms::Label ^ label1;

protected:
private:
  System::Windows::Forms::Label ^ label2;

private:
  System::Windows::Forms::TextBox ^ ip_input;

private:
  System::Windows::Forms::ComboBox ^ netmask_input;

private:
  System::Windows::Forms::Button ^ calculation_button;

private:
  System::Windows::Forms::TextBox ^ wildcard_output;

private:
  System::Windows::Forms::TextBox ^ network_adress_output;

private:
  System::Windows::Forms::Label ^ label3;

private:
  System::Windows::Forms::Label ^ label4;

private:
  System::Windows::Forms::Button ^ clear_all;

private:
  System::Windows::Forms::Label ^ label5;

private:
  System::Windows::Forms::Label ^ label6;

private:
  System::Windows::Forms::Label ^ label7;

private:
  System::Windows::Forms::TextBox ^ broadcast_output;

private:
  System::Windows::Forms::TextBox ^ last_host_output;

private:
  System::Windows::Forms::TextBox ^ first_host_output;

private:
  System::Windows::Forms::TextBox ^ quan_ip_all_output;

private:
  System::Windows::Forms::TextBox ^ quan_ip_aviable_output;

private:
  System::Windows::Forms::Label ^ label8;

private:
  System::Windows::Forms::Label ^ label9;

private:
  /// <summary>
  /// Required designer variable.
  /// </summary>
  System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
  /// <summary>
  /// Required method for Designer support - do not modify
  /// the contents of this method with the code editor.
  /// </summary>
  void InitializeComponent(void) {
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->label2 = (gcnew System::Windows::Forms::Label());
    this->ip_input = (gcnew System::Windows::Forms::TextBox());
    this->netmask_input = (gcnew System::Windows::Forms::ComboBox());
    this->calculation_button = (gcnew System::Windows::Forms::Button());
    this->wildcard_output = (gcnew System::Windows::Forms::TextBox());
    this->network_adress_output = (gcnew System::Windows::Forms::TextBox());
    this->label3 = (gcnew System::Windows::Forms::Label());
    this->label4 = (gcnew System::Windows::Forms::Label());
    this->clear_all = (gcnew System::Windows::Forms::Button());
    this->label5 = (gcnew System::Windows::Forms::Label());
    this->label6 = (gcnew System::Windows::Forms::Label());
    this->label7 = (gcnew System::Windows::Forms::Label());
    this->broadcast_output = (gcnew System::Windows::Forms::TextBox());
    this->last_host_output = (gcnew System::Windows::Forms::TextBox());
    this->first_host_output = (gcnew System::Windows::Forms::TextBox());
    this->quan_ip_all_output = (gcnew System::Windows::Forms::TextBox());
    this->quan_ip_aviable_output = (gcnew System::Windows::Forms::TextBox());
    this->label8 = (gcnew System::Windows::Forms::Label());
    this->label9 = (gcnew System::Windows::Forms::Label());
    this->SuspendLayout();
    //
    // label1
    //
    this->label1->AutoSize = true;
    this->label1->Location = System::Drawing::Point(37, 9);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(68, 17);
    this->label1->TabIndex = 0;
    this->label1->Text = L"IP-adress";
    //
    // label2
    //
    this->label2->AutoSize = true;
    this->label2->Location = System::Drawing::Point(199, 9);
    this->label2->Name = L"label2";
    this->label2->Size = System::Drawing::Size(63, 17);
    this->label2->TabIndex = 1;
    this->label2->Text = L"Netmask";
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
    this->netmask_input->DropDownHeight = 200;
    this->netmask_input->DropDownStyle =
        System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->netmask_input->FormattingEnabled = true;
    this->netmask_input->IntegralHeight = false;
    this->netmask_input->Items->AddRange(gcnew cli::array<System::Object ^>(33){
        L"255.255.255.255", L"255.255.255.254", L"255.255.255.252",
        L"255.255.255.248", L"255.255.255.240", L"255.255.255.224",
        L"255.255.255.192", L"255.255.255.128", L"255.255.255.0",
        L"255.255.254.0",   L"255.255.252.0",   L"255.255.248.0",
        L"255.255.240.0",   L"255.255.224.0",   L"255.255.192.0",
        L"255.255.128.0",   L"255.255.0.0",     L"255.254.0.0",
        L"255.252.0.0",     L"255.248.0.0",     L"255.240.0.0",
        L"255.224.0.0",     L"255.192.0.0",     L"255.128.0.0",
        L"255.0.0.0",       L"254.0.0.0",       L"252.0.0.0",
        L"248.0.0.0",       L"240.0.0.0",       L"224.0.0.0",
        L"192.0.0.0",       L"128.0.0.0",       L"0.0.0.0"});
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
    this->calculation_button->Text = L"Calculate network data";
    this->calculation_button->UseVisualStyleBackColor = true;
    this->calculation_button->Click +=
        gcnew System::EventHandler(this, &MyForm::calculation_button_Click);
    //
    // wildcard_output
    //
    this->wildcard_output->Location = System::Drawing::Point(12, 185);
    this->wildcard_output->Name = L"wildcard_output";
    this->wildcard_output->Size = System::Drawing::Size(290, 22);
    this->wildcard_output->TabIndex = 5;
    //
    // network_adress_output
    //
    this->network_adress_output->Location = System::Drawing::Point(12, 248);
    this->network_adress_output->Name = L"network_adress_output";
    this->network_adress_output->Size = System::Drawing::Size(290, 22);
    this->network_adress_output->TabIndex = 6;
    //
    // label3
    //
    this->label3->AutoSize = true;
    this->label3->Location = System::Drawing::Point(126, 165);
    this->label3->Name = L"label3";
    this->label3->Size = System::Drawing::Size(63, 17);
    this->label3->TabIndex = 7;
    this->label3->Text = L"Wildcard";
    //
    // label4
    //
    this->label4->AutoSize = true;
    this->label4->Location = System::Drawing::Point(104, 228);
    this->label4->Name = L"label4";
    this->label4->Size = System::Drawing::Size(106, 17);
    this->label4->TabIndex = 8;
    this->label4->Text = L"Network adress";
    //
    // clear_all
    //
    this->clear_all->Location = System::Drawing::Point(12, 118);
    this->clear_all->Name = L"clear_all";
    this->clear_all->Size = System::Drawing::Size(290, 28);
    this->clear_all->TabIndex = 9;
    this->clear_all->Text = L"Clear all text fields";
    this->clear_all->UseVisualStyleBackColor = true;
    this->clear_all->Click +=
        gcnew System::EventHandler(this, &MyForm::clear_all_Click);
    //
    // label5
    //
    this->label5->AutoSize = true;
    this->label5->Location = System::Drawing::Point(120, 293);
    this->label5->Name = L"label5";
    this->label5->Size = System::Drawing::Size(72, 17);
    this->label5->TabIndex = 10;
    this->label5->Text = L"Broadcast";
    //
    // label6
    //
    this->label6->AutoSize = true;
    this->label6->Location = System::Drawing::Point(100, 356);
    this->label6->Name = L"label6";
    this->label6->Size = System::Drawing::Size(113, 17);
    this->label6->TabIndex = 11;
    this->label6->Text = L"First host adress";
    //
    // label7
    //
    this->label7->AutoSize = true;
    this->label7->Location = System::Drawing::Point(100, 418);
    this->label7->Name = L"label7";
    this->label7->Size = System::Drawing::Size(113, 17);
    this->label7->TabIndex = 12;
    this->label7->Text = L"Last host adress";
    //
    // broadcast_output
    //
    this->broadcast_output->Location = System::Drawing::Point(12, 313);
    this->broadcast_output->Name = L"broadcast_output";
    this->broadcast_output->Size = System::Drawing::Size(289, 22);
    this->broadcast_output->TabIndex = 13;
    //
    // last_host_output
    //
    this->last_host_output->Location = System::Drawing::Point(12, 438);
    this->last_host_output->Name = L"last_host_output";
    this->last_host_output->Size = System::Drawing::Size(289, 22);
    this->last_host_output->TabIndex = 14;
    //
    // first_host_output
    //
    this->first_host_output->Location = System::Drawing::Point(12, 376);
    this->first_host_output->Name = L"first_host_output";
    this->first_host_output->Size = System::Drawing::Size(289, 22);
    this->first_host_output->TabIndex = 15;
    //
    // quan_ip_all_output
    //
    this->quan_ip_all_output->Location = System::Drawing::Point(12, 501);
    this->quan_ip_all_output->Name = L"quan_ip_all_output";
    this->quan_ip_all_output->Size = System::Drawing::Size(289, 22);
    this->quan_ip_all_output->TabIndex = 16;
    //
    // quan_ip_aviable_output
    //
    this->quan_ip_aviable_output->Location = System::Drawing::Point(12, 568);
    this->quan_ip_aviable_output->Name = L"quan_ip_aviable_output";
    this->quan_ip_aviable_output->Size = System::Drawing::Size(289, 22);
    this->quan_ip_aviable_output->TabIndex = 17;
    //
    // label8
    //
    this->label8->AutoSize = true;
    this->label8->Location = System::Drawing::Point(80, 481);
    this->label8->Name = L"label8";
    this->label8->Size = System::Drawing::Size(152, 17);
    this->label8->TabIndex = 18;
    this->label8->Text = L"Quanity of IP-adresses";
    //
    // label9
    //
    this->label9->AutoSize = true;
    this->label9->Location = System::Drawing::Point(56, 548);
    this->label9->Name = L"label9";
    this->label9->Size = System::Drawing::Size(201, 17);
    this->label9->TabIndex = 19;
    this->label9->Text = L"Quanity of aviable IP-adresses";
    //
    // MyForm
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(314, 610);
    this->Controls->Add(this->label9);
    this->Controls->Add(this->label8);
    this->Controls->Add(this->quan_ip_aviable_output);
    this->Controls->Add(this->quan_ip_all_output);
    this->Controls->Add(this->first_host_output);
    this->Controls->Add(this->last_host_output);
    this->Controls->Add(this->broadcast_output);
    this->Controls->Add(this->label7);
    this->Controls->Add(this->label6);
    this->Controls->Add(this->label5);
    this->Controls->Add(this->clear_all);
    this->Controls->Add(this->label4);
    this->Controls->Add(this->label3);
    this->Controls->Add(this->network_adress_output);
    this->Controls->Add(this->wildcard_output);
    this->Controls->Add(this->calculation_button);
    this->Controls->Add(this->netmask_input);
    this->Controls->Add(this->ip_input);
    this->Controls->Add(this->label2);
    this->Controls->Add(this->label1);
    this->MaximizeBox = false;
    this->Name = L"MyForm";
    this->Text = L"MyForm";
    this->ResumeLayout(false);
    this->PerformLayout();
  }
#pragma endregion
private:
  System::Void calculation_button_Click(System::Object ^ sender,
                                        System::EventArgs ^ e) {
    msclr::interop::marshal_context context;
    string ip_input_string = context.marshal_as<string>(ip_input->Text);
    string netmask_input_string =
        context.marshal_as<string>(netmask_input->Text);

    String ^ network_adress_String = gcnew System::String(
        network_adress(ip_input_string, netmask_input_string).c_str());
    String ^ wildcard_String =
        gcnew System::String(wildcard(netmask_input_string).c_str());

    string network_adress_string =
        context.marshal_as<string>(network_adress_String);
    string wildcard_string = context.marshal_as<string>(wildcard_String);

    String ^ broadcast_String = gcnew System::String(
        broadcast(network_adress_string, wildcard_string).c_str());
    String ^ first_host_String = gcnew System::String(
        first_host(network_adress_string, netmask_input_string).c_str());
    String ^ last_host_String = gcnew System::String(
        last_host(wildcard_string, network_adress_string).c_str());

    string broadcast_string = context.marshal_as<string>(broadcast_String);
    String ^ quan_ip_all_String = gcnew System::String(
        quan_ip(broadcast_string, network_adress_string).c_str());

    string quan_ip_all_string = context.marshal_as<string>(quan_ip_all_String);
    String ^ quan_ip_aviable_String =
        gcnew System::String(quan_aviable(quan_ip_all_string).c_str());

    wildcard_output->Text = wildcard_String;
    network_adress_output->Text = network_adress_String;
    broadcast_output->Text = broadcast_String;
    first_host_output->Text = first_host_String;
    last_host_output->Text = last_host_String;
    quan_ip_all_output->Text = quan_ip_all_String;
    quan_ip_aviable_output->Text = quan_ip_aviable_String;
  }

private:
  System::Void clear_all_Click(System::Object ^ sender, System::EventArgs ^ e) {
    ip_input->Clear();
    wildcard_output->Clear();
    network_adress_output->Clear();
    broadcast_output->Clear();
    first_host_output->Clear();
    last_host_output->Clear();
    quan_ip_all_output->Clear();
    quan_ip_aviable_output->Clear();
  }
};
} // namespace IPCalculator
