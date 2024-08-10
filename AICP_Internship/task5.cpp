#include <iostream>
#include <string>

using namespace std;

// Student class (acts as a Node in the linked list)
class Student {
private:
    string name;           // To store the student's name
    int marks;             // To store the student's marks
    Student* nextStudent;  // Pointer to the next student in the linked list

public:
    // Constructor to initialize the student's name and marks
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
        this->nextStudent = nullptr; // Initialize the next pointer to null
    }

    // Setter for the student's name
    void setName(string name) {
        this->name = name;
    }

    // Getter for the student's name
    string getName() {
        return name;
    }

    // Setter for the student's marks
    void setMarks(int marks) {
        this->marks = marks;
    }

    // Getter for the student's marks
    int getMarks() {
        return marks;
    }

    // Setter for the next student pointer
    void setNextStudent(Student* next) {
        this->nextStudent = next;
    }

    // Getter for the next student pointer
    Student* getNextStudent() {
        return nextStudent;
    }
};

// Stack class that uses the linked list to store students
class Stack {
private:
    Student* headStudent;  // Pointer to the top student in the stack

public:
    // Constructor to initialize the stack
    Stack() {
        headStudent = nullptr; // Initially, the stack is empty
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return headStudent == nullptr;
    }

    // Method to push a new student onto the stack
    void push(string name, int marks) {
        // Create a new student object
        Student* newStudent = new Student(name, marks);
        // Point the new student to the current top student
        newStudent->setNextStudent(headStudent);
        // Update the top of the stack to the new student
        headStudent = newStudent;
    }

    // Method to pop the top student from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        // Save the top student to a temporary variable
        Student* temp = headStudent;
        // Move the top of the stack to the next student
        headStudent = headStudent->getNextStudent();
        // Delete the previous top student
        delete temp;
    }

    // Method to get the top student without removing it
    Student* top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return nullptr;
        }
        return headStudent;
    }

    // Method to display all students in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        // Start from the top of the stack
        Student* temp = headStudent;
        // Traverse the stack and display each student
        while (temp != nullptr) {
            cout << "Name: " << temp->getName() << ", Marks: " << temp->getMarks() << endl;
            temp = temp->getNextStudent();
        }
    }
};

// Function to sort the stack and display the top 3 students
void sortStack(Stack& mainStack) {
    Stack sortedStack; // Create a secondary stack to hold sorted students

    // Transfer students from the main stack to the sorted stack in sorted order
    while (!mainStack.isEmpty()) {
        // Get the top student from the main stack
        Student* topStudent = mainStack.top();
        // Remove the top student from the main stack
        mainStack.pop();

        // Transfer students from the sorted stack back to the main stack
        // until we find the correct position for the top student
        while (!sortedStack.isEmpty() && sortedStack.top()->getMarks() < topStudent->getMarks()) {
            mainStack.push(sortedStack.top()->getName(), sortedStack.top()->getMarks());
            sortedStack.pop();
        }

        // Push the top student into the sorted stack
        sortedStack.push(topStudent->getName(), topStudent->getMarks());
    }

    // Display the top 3 students from the sorted stack
    for (int i = 0; i < 3 && !sortedStack.isEmpty(); ++i) {
        Student* topStudent = sortedStack.top();
        cout << "Top " << i + 1 << ": " << topStudent->getName() << " - " << topStudent->getMarks() << endl;
        sortedStack.pop();
    }
}

// Main function
int main() {
    Stack mainStack; // Create the main stack to store all students
    int choice;      // Variable to store user's choice

    // Continue until the user decides to exit
    do {
        // Display menu options
        cout << "1. Add Student\n2. Remove Student\n3. Display All Students\n4. Display Top 3 Students\n5. Exit\nEnter your choice: ";
        cin >> choice;

        // Handle the user's choice
        if (choice == 1) {
            string name;
            int marks;
            cout << "Enter student name: ";
            cin >> name; // Get the student's name
            cout << "Enter student marks(Total : 500): ";
            cin >> marks; // Get the student's marks
            mainStack.push(name, marks); // Add the student to the stack
        } else if (choice == 2) {
            mainStack.pop(); // Remove the top student from the stack
        } else if (choice == 3) {
            mainStack.display(); // Display all students in the stack
        } else if (choice == 4) {
            sortStack(mainStack); // Display the top 3 students with the highest marks
        }
    } while (choice >= 1 && choice <= 4); // Repeat until the user chooses to exit

    return 0;
}
