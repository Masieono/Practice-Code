#include <iostream>

/*
    struct = structure that groups related variables under one name.

    can contain many different data types

    variables within a struct are called members.

    members are accessed with . "class member access operator"
*/

using namespace std;

struct student
{
    string first_name;
    string last_name;
    double gpa;
    bool is_enrolled = true;
};

int main () {

    student student1;
    student1.first_name = "Dooby";
    student1.last_name = "Zooby";
    student1.gpa = 3.9;

    student student2;
    student2.first_name = "Manzo";
    student2.last_name = "Bautista";
    student2.gpa = 3.2;

    student student3;
    student3.first_name = "Borp";
    student3.last_name = "Zorp";
    student3.gpa = 1.7;
    student3.is_enrolled = false;

    cout << student1.first_name << " " << student1.last_name << "   " << student1.gpa << endl;
    cout << student2.first_name << " " << student2.last_name << "   " << student2.gpa << endl;
    cout << student3.first_name << " " << student3.last_name << "   " << student3.gpa << endl;
    

    return 0;
}