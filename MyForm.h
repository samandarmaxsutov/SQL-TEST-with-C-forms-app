#pragma once
#include "TestTableClass.h"

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(40, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"...";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button1->Location = System::Drawing::Point(371, 407);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 68);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Show";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(293, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(178, 37);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Test Table";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 502);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Create a new SqlConnection
			String^ connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=MyTestDatabase;Integrated Security=True";
			SqlConnection^ sqlConn = gcnew SqlConnection(connectionString);
			sqlConn->Open(); // Open the connection

			// Prepare SQL command
			String^ query = "SELECT * FROM TestTable";
			SqlCommand^ command = gcnew SqlCommand(query, sqlConn);
			SqlDataReader^ reader = command->ExecuteReader();

			// Create a list 
			List<TestTableClass^>^ list = gcnew List<TestTableClass^>;

			// Read each row from the database
			while (reader->Read()) {
				int id = reader->GetInt32(0); // Assuming the first column is 'id'
				String^ testString = reader->GetString(1); // Assuming the second column is 'test_string'
				int testInt = reader->GetInt32(2); // Assuming the third column is 'test_int'
				bool testBool = reader->GetBoolean(3); // Assuming the fourth column is 'test_bool'

				// Create a new TestTableClass
				TestTableClass^ newItem = gcnew TestTableClass(id, testString, testInt, testBool);

				// Add  to the list
				list->Add(newItem);
			}

			String^ text = "";
			for (int i = 0; i < list->Count; i++) {
				TestTableClass^ a = list[i]; 

				text += "ID: " + a->GetId() + ", String: " + a->GetTestString() + ", Int: " + a->GetTestInt().ToString() + ", Bool: " + a->GetTestBool().ToString() + ";\n";
			}
			label1->Text = text;
			reader->Close(); // Close the SqlDataReader
			sqlConn->Close(); // Close the SqlConnection
		}
		catch (Exception^ e) {
			MessageBox::Show("Error: " + e->Message);
		}

	}

	};
}
