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

<h3>create TestTableClass</h3>
<h6>#pragma once

using namespace System;

ref class TestTableClass
{
private:
    int id;
    String^ test_string;
    int test_int;
    bool test_bool;

public:
    // Constructor
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


