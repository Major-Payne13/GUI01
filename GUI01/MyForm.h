#pragma once

namespace GUI01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int times = 0;
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
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::ComboBox^  comboBox1;




	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(77, 207);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Countinue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(310, 139);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"On your walk through the forrest, you encounter a mama bear protecting her cubs. "
				L" She looks quite hostile.  You have a dull sward with you.\r\n\r\nWHAT DO YOU DO\? \r\n"
				L"";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"RUN!!!", L"Fight" });
			this->comboBox1->Location = System::Drawing::Point(105, 157);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(352, 346);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		times++; 
		
		if (comboBox1->SelectedItem == L"Fight" && times == 2)
		{
			textBox1->Text = "You died.";
			times = 0;
			comboBox1->Items->Clear();

		}
		else
			if (comboBox1->SelectedItem == L"RUN!!!" && times == 2)
		{
			button1->Text = "OK";
			textBox1->Text = "You got away!\r\n\r\n(PRESS \"OK\" TO CONTINUE) ";
			comboBox1->Items->Clear();
			comboBox1->Text = "";
		}
		if (times == 2 && comboBox1->Text == "")
		{
			button1->Text = "continue";
			textBox1->Text = "You take a break from running and you realize you are very hungry and thirsty.";
			textBox1->Text = textBox1->Text + "  You feel as if you might die if you do not get food or water soon.";
			textBox1->Text = textBox1->Text + "  You do not have anything on you, and your sword is too dull to kill anything.";
			textBox1->Text = textBox1->Text + "  You see smoke comming from a building not far away. \r\n\r\nWHAT DO YOU DO ? ";
			
			comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Go to the house", L"Stay put"});
		}
	

		
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
		
	}
	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	
}	
};
}
