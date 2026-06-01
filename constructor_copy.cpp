#include <iostream>
using namespace std;

class Student
{
public:
    string name;

    Student(string n)
    {
        name=n;
    }

    Student(const Student &other)
    {
        name=other.name;
    }
};

int main()
{
    Student s1("Priyanshu");

    Student s2=s1;

    cout<<s2.name;
}