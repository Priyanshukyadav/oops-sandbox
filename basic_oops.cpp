#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int age;

    void display()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    Student s1;

    s1.name = "Priyanshu";
    s1.age = 20;

    s1.display();
}