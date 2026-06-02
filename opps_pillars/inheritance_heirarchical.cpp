#include <iostream>
using namespace std;

// Parent Class
class Parent {
public:
    void surname() {
        cout << "Surname is Sharma." << endl;
    }
};

// Child Class 1
class Son : public Parent {
public:
    void cricket() {
        cout << "Son loves Cricket." << endl;
    }
};

// Child Class 2
class Daughter : public Parent {
public:
    void music() {
        cout << "Daughter loves Music." << endl;
    }
};

int main() {
    Son s;
    Daughter d;

    s.surname(); // Son got Parent's surname
    s.cricket();

    d.surname(); // Daughter also got Parent's surname
    d.music();

    // s.music(); -> Yeh ERROR dega, kyunki Son aur Daughter aapas mein connected nahi hain!
    return 0;
}