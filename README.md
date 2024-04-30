<h1>Sql-Test with Cpp windows forms app</h1>

<h3>Connect to server</h3>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/6d370f68-0699-4d8f-b092-884c638fbe0d"></img>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/a795a225-1eec-4943-9111-b67d74c02dbf"></img>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/9ad5e8f8-a404-4bed-970c-e5153b21e06f"></img>

<h3>Create or Connect to databse</h3>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/7ad16cb2-8de1-4c32-90dc-b45d7a5d5623"></img>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/4cf6fb0f-6163-4c11-b2b6-faf1860466c4"></img>

<h3>Create Tabale</h3>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/0f91ade7-27f8-4eed-852b-fcb6119c98cd"></img>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/49fc2e0e-157d-4ca7-b4f6-168bdd134d35"></img>

<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/20b679fb-7f40-4d61-a159-a5b6de7a1389"></img>

<h3>Create TestTableClass</h3>
<a href="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/blob/master/MyForm.h"></a>
<h6>
    #pragma once

using namespace System;

ref class TestTableClass
{
private:
    int id;
    String^ test_string;
    int test_int;
    bool test_bool;

public:
    //Constructors
    
    TestTableClass() : id(0), test_string(""), test_int(0), test_bool(false) {}

    TestTableClass(int id, String^ test_string, int test_int, bool test_bool) {
        this->id = id;
        this->test_string = test_string;
        this->test_int = test_int;
        this->test_bool = test_bool;
    }

    // Getters
    int GetId() {
        return id;
    }

    String^ GetTestString() {
        return test_string;
    }

    int GetTestInt() {
        return test_int;
    }

    bool GetTestBool() {
        return test_bool;
    }

    // Setters
    void SetId(int id) {
        this->id = id;
    }

    void SetTestString(String^ test_string) {
        this->test_string = test_string;
    }

    void SetTestInt(int test_int) {
        this->test_int = test_int;
    }

    void SetTestBool(bool test_bool) {
        this->test_bool = test_bool;
    }
};
</h6>

<h3>Show Button</h3>
<a href="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/blob/master/MyForm.h"></a>
<img src="https://github.com/samandarmaxsutov/SQL-TEST-with-C-forms-app/assets/101328871/758b8878-6ceb-4971-94de-8e69be238978"></img>

<h6>
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
</h6>

