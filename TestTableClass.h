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

