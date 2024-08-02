#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define the Patient class to hold information about each patient
class Patient {
public:
    int age;

    // Constructor to initialize the age of the patient
    Patient(int a) : age(a) {}

    // Overload the less-than operator to define the priority of patients
    bool operator<(const Patient& other) const {
        // Patients aged 60 or above have the highest priority
        if (age >= 60) {
            // If the other patient is also 60 or above, compare ages
            if (other.age >= 60) return age < other.age;
            // Otherwise, this patient has higher priority
            return false;
        } else if (age > 50) {
            // Patients aged 51-60 have the second highest priority
            if (other.age >= 60) return true;
            if (other.age > 50) return age < other.age;
            return false;
        } else if (age > 40) {
            // Patients aged 41-50 have the third highest priority
            if (other.age > 50) return true;
            if (other.age > 40) return age < other.age;
            return false;
        } else if (age > 30) {
            // Patients aged 31-40 have the fourth highest priority
            if (other.age > 40) return true;
            if (other.age > 30) return age < other.age;
            return false;
        } else {
            // Patients aged 30 or below have the lowest priority
            if (other.age > 30) return true;
            return age < other.age;
        }
    }
};

// Define the Hospital class to manage the priority queue of patients
class Hospital {
private:
    // Use a priority queue to manage patients
    priority_queue<Patient> pq;

public:
    // Method to add a patient to the queue
    void addPatient(int age) {
        pq.push(Patient(age)); // Add the patient to the priority queue
        cout << "Patient aged " << age << " added to the queue.\n";
    }

    // Method to delete the highest priority patient from the queue
    void deletePatient() {
        if (!pq.empty()) {
            cout << "Patient aged " << pq.top().age << " removed from the queue.\n";
            pq.pop(); // Remove the patient from the queue
        } else {
            cout << "No patients in the queue.\n";
        }
    }

    // Method to display all patients in the queue
    void displayPatients() {
        if (pq.empty()) {
            cout << "No patients in the queue.\n";
            return;
        }

        // Create a temporary priority queue to display patients
        priority_queue<Patient> temp_pq = pq;
        vector<Patient> patients;

        // Transfer patients from the temporary queue to a vector for display
        while (!temp_pq.empty()) {
            patients.push_back(temp_pq.top());
            temp_pq.pop();
        }

        // Display patients in order of priority
        cout << "Patients in the queue (in order of priority):\n";
        for (const auto& patient : patients) {
            cout << "Patient age: " << patient.age << "\n";
        }
    }
};

// Main function to drive the program
int main() {
    Hospital hospital; // Create a Hospital object
    int choice, age; // Variables to store user choice and patient age
    cout << "Welcome to patient information system\n";

    // Loop to display menu and perform actions based on user choice
    do {
        cout << "1. Add patient\n";
        cout << "2. Delete patient\n";
        cout << "3. Display patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read user choice

        switch (choice) {
        case 1:
            cout << "Enter patient's age: ";
            cin >> age; // Read patient's age
            hospital.addPatient(age); // Add patient to the queue
            break;
        case 2:
            hospital.deletePatient(); // Remove the highest priority patient
            break;
        case 3:
            hospital.displayPatients(); // Display all patients
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // Handle invalid choices
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0; // End of the program
}
