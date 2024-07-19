#include <iostream>
#include <string>

using namespace std;

// Base class 'Person' represents common attributes and behaviors of a person
class Person {
protected:
    // Data members common to all persons
    string name;
    int age;
    string gender;
    string address;
    string phone;

public:
    // Default constructor initializes data members to default values
    Person() : name(""), age(0), gender(""), address(""), phone("") {}

    // Setter and getter functions for each data member
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(string g) { gender = g; }
    void setAddress(string addr) { address = addr; }
    void setPhone(string p) { phone = p; }

    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
    string getAddress() { return address; }
    string getPhone() { return phone; }

    // Virtual function to save information of a person
    virtual void Save_Information() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter gender: ";
        getline(cin, gender);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter phone: ";
        getline(cin, phone);
    }

    // Virtual function to display information of a person
    virtual void Display_Information() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Derived class 'Teacher' inherits from 'Person' and adds additional attributes
class Teacher : public Person {
private:
    // Data members specific to teachers
    string qualification;
    double salary;

public:
    // Default constructor initializes data members to default values
    Teacher() : Person(), qualification(""), salary(0.0) {}

    // Setter and getter functions for each data member
    void setQualification(string q) { qualification = q; }
    void setSalary(double s) { salary = s; }

    string getQualification() { return qualification; }
    double getSalary() { return salary; }

    // Override function to save information of a teacher
    void Save_Information() override {
        Person::Save_Information();  // Call base class function to save common data
        cout << "Enter qualification: ";
        getline(cin, qualification);
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();
    }

    // Override function to display information of a teacher
    void Display_Information() override {
        Person::Display_Information();  // Call base class function to display common data
        cout << "Qualification: " << qualification << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived class 'Student' inherits from 'Person' and adds additional attributes
class Student : public Person {
private:
    // Data members specific to students
    string previousEducation;
    double obtainedMarks;
    double totalMarks;

public:
    // Default constructor initializes data members to default values
    Student() : Person(), previousEducation(""), obtainedMarks(0.0), totalMarks(0.0) {}

    // Setter and getter functions for each data member
    void setPreviousEducation(string pe) { previousEducation = pe; }
    void setObtainedMarks(double om) { obtainedMarks = om; }
    void setTotalMarks(double tm) { totalMarks = tm; }

    string getPreviousEducation() { return previousEducation; }
    double getObtainedMarks() { return obtainedMarks; }
    double getTotalMarks() { return totalMarks; }

    // Override function to save information of a student
    void Save_Information() override {
        Person::Save_Information();  // Call base class function to save common data
        cout << "Enter previous education: ";
        getline(cin, previousEducation);
        cout << "Enter obtained marks: ";
        cin >> obtainedMarks;
        cout << "Enter total marks: ";
        cin >> totalMarks;
        cin.ignore();
    }

    // Override function to display information of a student
    void Display_Information() override {
        Person::Display_Information();  // Call base class function to display common data
        cout << "Previous Education: " << previousEducation << endl;
        cout << "Obtained Marks: " << obtainedMarks << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

// Main function to demonstrate polymorphism and object management
int main() {
    string choice;
    do {
        Person* person;  // Pointer to base class 'Person'
        Teacher teacher;  // Teacher object
        Student student;  // Student object

        // Prompt user to choose between entering data for a teacher or a student
        cout << "Enter 'T' to input data for a Teacher or 'S' for a Student: ";
        cin >> choice;
        cin.ignore();

        // Polymorphically assign the appropriate object to the base class pointer
        if (choice == "T" || choice == "t") {
            person = &teacher;
        } else if (choice == "S" || choice == "s") {
            person = &student;
        } else {
            cout << "Invalid choice!" << endl;
            return 1;
        }

        // Use polymorphism to call the appropriate 'Save_Information' function
        person->Save_Information();

        // Display the entered information
        cout << endl << "Displaying Information:" << endl;
        person->Display_Information();

        // Ask if the user wants to enter more data
        cout << "Do you want to enter more data? (Y/N): ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left in the buffer
    } while (choice == "Y" || choice == "y" || choice == "yes" || choice == "Yes" || choice == "YES");

    return 0;
}
