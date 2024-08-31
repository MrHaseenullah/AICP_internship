#include <iostream>
#include <list>
using namespace std;

class Complex {
private:
    int real;
    int imaginary;

public:
    // Constructor
    Complex(int r = 0, int i = 0) : real(r), imaginary(i) {}

    // Overload stream extraction operator >>
    friend istream& operator>>(istream &input, Complex &c) {
        cout << "Please enter real part of complex number: ";
        input >> c.real;
        cout << "Please enter imaginary part of complex number: ";
        input >> c.imaginary;
        return input;
    }

    // Overload stream insertion operator <<
    friend ostream& operator<<(ostream &output, const Complex &c) {
        output << c.real << "+" << c.imaginary << "i";
        return output;
    }
};

int main() {
    // Using a list to manage Complex objects
    list<Complex> complexNumbers;

    // Creating and inputting the first Complex object
    Complex com1;
    cin >> com1;
    complexNumbers.push_back(com1);

    // Displaying the Complex object using the overloaded << operator
    cout << "The complex object is: " << complexNumbers.front() << endl;

    return 0;
}
