//
// Created by Erik Karlsson on 10/18/16.
//


#include "String.h"

void test_constructor_and_print()
{
    cout << "--------------------- Test Constructor 1 and print() ---------------------" << endl;
    String s("Hello World");
    cout << s << endl;
}

void test_constructor2_and_print()
{
    cout << "--------------------- Test Constructor 2 and Print() ---------------------" << endl;
    String s("A Whole new world");
    String s2(s);
    cout << s << endl;
}

void test_read()
{
    cout << "--------------------- Test read() ---------------------" << endl;
    String s("");
    cout << "Input > ";
    cin >> s;
    cout << "Input Read : " << s << endl;
}

void test_operator_assignment()
{
    cout << "--------------------- Test Operator = (Assignment) ---------------------" << endl;
    String s("Original Sentence");
    cout << "s : " << s << endl;
    cout << "s = \"some silly string\"" << endl;
    s = "some silly string";
    cout << "s : " << s << endl;
}

void test_size()
{
    cout << "--------------------- Test size() ---------------------" << endl;
    String s("Merp");
    cout << "s : " << s << " has the size " << s.size() << endl;
}

void test_reverse()
{
    cout << "--------------------- Test reverse() ---------------------" << endl;
    String s("Farfignugen");
    String reversed = s.reverse();
    cout << "s : " << s << " is " << reversed << " reversed " << endl;
}

void test_indexOf()
{
    cout << "--------------------- Test indexOf() ---------------------" << endl;
    String s("Farfignugen");
    cout << "Index of f is " << s.indexOf('f') << endl;
    cout << "Index of nugen " << s.indexOf("nugen") << endl;
}

void test_operator_equal()
{
    cout << "--------------------- Test Operator == (Equal) ---------------------" << endl;
    String s1("Apple");
    String s2("apple");
    String s3("APPLE");
    cout << s1 << " == " << s2 << " is " << (s1 == s2);
    cout << endl;
    cout << s2 << " == " << s1 << " is " << (s2 == s1);
    cout << endl;
    cout << s2 << " == " << s3 << " is " << (s2 == s3);
    cout << endl;
    cout << s2 << " == " << s2 << " is " << (s2 == s2);
    cout << endl;
}

void test_operator_not_equal()
{
    cout << "--------------------- Test Operator != (Not Equal) ---------------------" << endl;
    String s1("Frank");
    String s2("Furter");
    String s3("franky");
    cout << s1 << " != " << s2 << " is " << (s1 != s2);
    cout << endl;
    cout << s2 << " != " << s1 << " is " << (s2 != s1);
    cout << endl;
    cout << s2 << " != " << s3 << " is " << (s2 != s3);
    cout << endl;
    cout << s2 << " != " << s2 << " is " << (s2 != s2);
    cout << endl;
}

void test_operator_greater()
{
    cout << "--------------------- Test Operator > (Greater Than) ---------------------" << endl;
    String s1("car");
    String s2("Car");
    String s3("CAR");
    cout << s1 << " > " << s2 << " is " << (s1 > s2);
    cout << endl;
    cout << s2 << " > " << s1 << " is " << (s2 > s1);
    cout << endl;
    cout << s2 << " > " << s3 << " is " << (s2 > s3);
    cout << endl;
    cout << s2 << " > " << s2 << " is " << (s2 > s2);
    cout << endl;
}

void test_operator_less()
{
    cout << "--------------------- Test Operator < (Less Than) ---------------------" << endl;
    String s1("car");
    String s2("Car");
    String s3("CAR");
    cout << s1 << " < " << s2 << " is " << (s1 < s2);
    cout << endl;
    cout << s2 << " < " << s1 << " is " << (s2 < s1);
    cout << endl;
    cout << s2 << " < " << s3 << " is " << (s2 < s3);
    cout << endl;
    cout << s2 << " < " << s2 << " is " << (s2 < s2);
    cout << endl;
}

void test_operator_greater_or_equal()
{
    cout << "--------------------- Test Operator >= (Greater Than or Equal) ---------------------" << endl;
    String s1("car");
    String s2("Car");
    String s3("CAR");
    cout << s1 << " >= " << s2 << " is " << (s1 >= s2);
    cout << endl;
    cout << s2 << " >= " << s1 << " is " << (s2 >= s1);
    cout << endl;
    cout << s2 << " >= " << s3 << " is " << (s2 >= s3);
    cout << endl;
    cout << s2 << " >= " << s2 << " is " << (s2 >= s2);
    cout << endl;
}


void test_operator_less_or_equal()
{
    cout << "--------------------- Test Operator <= (Less Than or Equal) ---------------------" << endl;
    String s1("car");
    String s2("Car");
    String s3("CAR");
    cout << s1 << " <= " << s2 << " is " << (s1 <= s2);
    cout << endl;
    cout << s2 << " <= " << s1 << " is " << (s2 <= s1);
    cout << endl;
    cout << s2 << " <= " << s3 << " is " << (s2 <= s3);
    cout << endl;
    cout << s2 << " <= " << s2 << " is " << (s2 <= s2);
    cout << endl;
}

void test_operator_plus()
{
    cout << "--------------------- Test Operator + (Plus) ---------------------" << endl;
    String s1("Hello");
    String s2("World");
    String s3 = (s1 + s2);
    cout << s1 << " + " << s2 << " = " << s3 << endl;
}


void test_operator_plus_equal()
{
    cout << "--------------------- Test Operator += (Plus Equal) ---------------------" << endl;
    String s1("Goodbye");
    String s2("World");
    cout << s1 << " += " << s2 << endl << "s1 is now " ;
    s1 += s2;
    cout << s1 << endl;
}
int main()
{
    test_constructor_and_print();

//    test_constructor2_and_print();
//    test_read();
//    test_operator_assignment();
//    test_size();
//    test_reverse();
//    test_indexOf();
//    test_operator_equal();
//    test_operator_not_equal();
//    test_operator_greater();
//    test_operator_less();
//    test_operator_greater_or_equal();
//    test_operator_less_or_equal();
//    test_operator_plus();
//    test_operator_plus_equal();

    return 0;
}

