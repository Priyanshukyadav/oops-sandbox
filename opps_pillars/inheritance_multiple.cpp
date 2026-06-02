#include <iostream>
using namespace std;

// Parent Class 1
class Father {
public:
    void height() {
        cout << "Tall height from Father." << endl;
    }
};

// Parent Class 2
class Mother {
public:
    void eyes() {
        cout << "Brown eyes from Mother." << endl;
    }
};

// Child Class inheriting from both Father and Mother
class Child : public Father, public Mother {
public:
    void skinColor() {
        cout << "Fair skin color." << endl;
    }
};

int main() {
    Child c;
    c.height();    // Father ki property
    c.eyes();      // Mother ki property
    c.skinColor(); // Apni khud ki property
    return 0;
}