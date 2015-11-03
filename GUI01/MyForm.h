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
	bool dead = false;
	
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
			this->button1->Font = (gcnew System::Drawing::Font(L"Mistral", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(154, 402);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(446, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tempus Sans ITC", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(746, 294);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Welcome to this adventure story.  Press \"Play\" to begin.";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Magneto", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"RUN!!!", L"Fight" });
			this->comboBox1->Location = System::Drawing::Point(154, 312);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(446, 33);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Visible = false;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 492);
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
		//if nothing is selected, nothing is messed up.
		if (comboBox1->Text == "" && times != 1 && times != 3 && times != 5)
			times--;
		if (times == 1)
		{
			comboBox1->Visible = true;
			textBox1->Text = L"On your walk through the forrest, you encounter a mama bear protecting her cubs. "
				L" She looks quite hostile.  You have a dull sward with you.\r\n\r\nWHAT DO YOU DO\? \r\n";
			comboBox1->Items->Clear();
			comboBox1->Text = "";
			comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"RUN!!!", L"Fight" });
			button1->Text = L"Countinue";
			
		}

		if (comboBox1->SelectedItem == L"Fight" && times == 2 || times == 3 && comboBox1->SelectedItem == L"Fight")
		{
			textBox1->Text = "The mother bear ripped you to shreads and made you unrecognizeable. You are dead. ";
			comboBox1->Visible = false;
			button1->Text = "Play Again";
			dead = true;
			if (times == 3)
			{
				times = 0;
				button1->Text = L"Play";
				textBox1->Text = L"Welcome to this adventure story.  Press \"Play\" to begin.";
				comboBox1->Items->Clear();
				comboBox1->Text = "";
				comboBox1->Visible = false;
				comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"RUN!!!", L"Fight" });
				dead = false;
			}
			
		}
		else
			if (dead == false && comboBox1->SelectedItem == L"RUN!!!" && times == 2)
		{
			button1->Text = "OK";
			textBox1->Text = "You got away!\r\n\r\n(PRESS \"OK\" TO CONTINUE) ";
			comboBox1->Items->Clear();
			comboBox1->Text = "";
			comboBox1->Visible = false;
		}
		if (dead == false && times == 3 && comboBox1->Text == "")
		{
			button1->Text = "continue";
			textBox1->Text = "You take a break from running and you realize you are very hungry and thirsty.";
			textBox1->Text = textBox1->Text + "  You feel as if you might die if you do not get food or water soon.";
			textBox1->Text = textBox1->Text + "  You do not have anything on you, and your sword is too dull to kill anything.";
			textBox1->Text = textBox1->Text + "  You see smoke comming from a building not far away. \r\n\r\nWHAT DO YOU DO ? ";
			comboBox1->Visible = true;
			comboBox1->Items->Clear();
			comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Go to the building", L"Search for food somewhere else"});
		}
		if (times == 4 && comboBox1->SelectedItem == L"Search for food somewhere else" || times == 5 && comboBox1->SelectedItem == L"Search for food somewhere else")
		{
			textBox1->Text = "After searching for food for an hour, you collapse from exastion.  You die. ";
			comboBox1->Visible = false;
			button1->Text = "Play Again";
			dead = true;
			if (times == 5)
			{
				times = 0;
				button1->Text = L"Play";
				textBox1->Text = L"Welcome to this adventure story.  Press \"Play\" to begin.";
				comboBox1->Items->Clear();
				comboBox1->Text = "";
				comboBox1->Visible = false;
				comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"RUN!!!", L"Fight" });
				dead = false;
			}
		}
		else
			if (dead == false && comboBox1->SelectedItem == L"Go to the building" && times == 4)
			{
				textBox1->Text = "You walk up to the building and read the sign: \r\n\r\n \"Berdan's Blacksmith Shop\" \r\n\r\n You smell a pleasant smell inside.  You enter. ";
				comboBox1->Visible = false;
				button1->Text = "Continue";
			}
		if (dead == false && times == 5)
		{
			textBox1->Text = "You enter and see many wepons and armor hanging around the shop.  \r\n\r\t \"Hello?\" you call. \r\n\r\nA muscular man appears from the backroom door.";
			textBox1->Text = textBox1->Text + "\r\n\r\t\"Hello!  I haven't seen a customer in a while.\" he proclames.  His deep voice startles you.\r\n\r\n ";
			textBox1->Text = textBox1->Text + "WHAT DO YOU SAY TO HIM?";
			comboBox1->Visible = true;
			comboBox1->Items->Clear();
			comboBox1->Text = "";
			comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Be polite", L"Be strait forward", L"Never mind"});
			
		}
		if (dead == false && times == 6 && comboBox1->SelectedItem == L"Be strait forward")
		{
			textBox1->Text = "\r\t\"Hi. I will buy some equiptment from you if you feed me\" ";
			comboBox1->Visible = false;
			comboBox1->Items->Clear();
			comboBox1->Text = "";
			textBox1->Text = textBox1->Text + "\r\n\r\n\r\t\"If you want some of my food, equiptment will be extra.\"";
		}
		else
			if (dead == false && times == 6 && comboBox1->SelectedItem == L"Be polite")
			{
				textBox1->Text = "\r\t\"Please, Sir.  Can I have some food?  I am very hungry.  I have some money if you want me to pay.\"";
				comboBox1->Visible = false;
				comboBox1->Items->Clear();
				comboBox1->Text = "";
				textBox1->Text = textBox1->Text + "\r\n\r\t\"Ok.  I guess I can give you some food. But if you can, please buy some equiptment.  I'll give you a discount.\"";
				textBox1->Text = textBox1->Text + "\r\nHe gives you some food.  You thank him, and look at how much money you have.  You only have enough money to buy one thing. ";
			}
			else
				if (dead == false && times == 6 && comboBox1->SelectedItem == L"Never mind")
				{
					textBox1->Text = "\r\t\"Never Mind.\"";
					comboBox1->Visible = false;
					comboBox1->Items->Clear();
					comboBox1->Text = "";
					textBox1->Text = textBox1->Text + "|r\n\r\t\"Awwwwwwwwww.\"";
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