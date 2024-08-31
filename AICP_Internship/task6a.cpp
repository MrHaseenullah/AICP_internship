#include <iostream>
#include <vector>
using namespace std;

class Circle {
private:
    int radius;

public:
    // Constructor
    Circle(int r = 0) : radius(r) {}

    // Setter function
    void setRadius(int r) {
        radius = r;
    }

    // Getter function
    int getRadius() const {
        return radius;
    }

    // Overloading the + operator
    Circle operator+(const Circle &c) const {
        return Circle(this->radius + c.radius);
    }
};

int main() {
    int a,b;
    // Using a vector to manage Circle objects
    vector<Circle> circles;
    cout<<"Enter the value of 1st circle radius : ";
    cin>>a;
    circles.push_back(Circle(a));  // c1
    cout<<"Enter the value of 2nd circle radius : ";
    cin>>b;
    circles.push_back(Circle(b)); // c2

    // Adding c1 and c2, storing the result in c3
    Circle c3 = circles[0] + circles[1];
    circles.push_back(c3);

    // Displaying the radius of the third circle
    cout << "Radius of 3rd Circle : " << circles[2].getRadius() << endl;

    return 0;
}
