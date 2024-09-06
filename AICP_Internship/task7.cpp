#include <iostream>
using namespace std;

// Base Class
class Base {
protected:
    int secret;   // Protected member
    int protect;  // Protected member
public:
    int access;   // Public member

    // Default Constructor to initialize data members
    Base() : secret(10), protect(20), access(30) {}

    // Virtual show function to display base class members (to be overridden in derived classes)
    virtual void show() {
        cout << "Base Class:" << endl;
        cout << "secret: " << secret << endl;
        cout << "protect: " << protect << endl;
        cout << "access: " << access << endl;
    }
};

// Derived Class with Private Inheritance
class Derived_Private : private Base {
public:
    // Override show() to display Base members
    void show() override {
        cout << "Derived_Private Class (Private Inheritance):" << endl;
        // Accessing secret and protect is allowed because they are protected in Base class
        cout << "secret: " << secret << endl;   // Accessible (protected)
        cout << "protect: " << protect << endl; // Accessible (protected)
        cout << "access: " << access << endl;   // Accessible (public in Base class)
    }
};

// Derived Class with Protected Inheritance
class Derived_Protected : protected Base {
public:
    // Override show() to display Base members
    void show() override {
        cout << "Derived_Protected Class (Protected Inheritance):" << endl;
        // Accessing secret and protect is allowed because they are protected in Base class
        cout << "secret: " << secret << endl;   // Accessible (protected)
        cout << "protect: " << protect << endl; // Accessible (protected)
        cout << "access: " << access << endl;   // Accessible (public in Base class)
    }
};

// Derived Class with Public Inheritance
class Derived_Public : public Base {
public:
    // Override show() to display Base members
    void show() override {
        cout << "Derived_Public Class (Public Inheritance):" << endl;
        // Accessing secret and protect is allowed because they are protected in Base class
        cout << "secret: " << secret << endl;   // Accessible (protected)
        cout << "protect: " << protect << endl; // Accessible (protected)
        cout << "access: " << access << endl;   // Accessible (public in Base class)
    }
};

// Main Function
int main() {
    Base baseObj;
    Derived_Private privateObj;
    Derived_Protected protectedObj;
    Derived_Public publicObj;

    cout << "Base Object:" << endl;
    baseObj.show(); // Calls Base class show

    cout << "\nDerived Private Object:" << endl;
    privateObj.show(); // Calls Derived_Private show

    cout << "\nDerived Protected Object:" << endl;
    protectedObj.show(); // Calls Derived_Protected show

    cout << "\nDerived Public Object:" << endl;
    publicObj.show(); // Calls Derived_Public show

    return 0;
}
