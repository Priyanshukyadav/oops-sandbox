// Runtime Polymorphism (Dynamic / Late Binding)
// Isme program jab run (execute) ho raha hota hai, 
// tab faisla hota hai ki kaun sa function call hoga.
//  Yeh thoda slow hota hai compile-time se, 
//  lekin bohot flexible hota hai.

// Yeh Function Overriding aur Virtual Functions ke zariye
//  achieve kiya jata hai:

// Function Overriding (Same name, same parameters, different classes)
// Jab Parent class aur Child class dono mein exact same 
// function (same name, same parameters) hota hai. 
// Jab hum Child class ka object banakar use call karte hain, 
// toh Child class waala function Parent waale function ko
//  override (daba) deta hai.

Note: Yahan virtual keyword lagana zaroori hota hai, taaki compiler runtime par sahi decision le sake.

#include <iostream>
using namespace std;

class Animal {
public:
    // Base class function
    virtual void makeSound() { 
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    // Derived class function (Overriding)
    void makeSound() override { 
        cout << "Dog barks! Woof Woof!" << endl;
    }
};

int main() {
    Animal* a;
    Dog d;
    a = &d; // Parent pointer pointing to Child object

    a->makeSound(); // Runtime par tai hoga ki Dog ka sound chalna chahiye
    return 0;
}