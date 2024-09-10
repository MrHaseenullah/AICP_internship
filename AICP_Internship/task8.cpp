#include <iostream>
using namespace std;

// Class representing a node in the binary search tree (BST)
class Node {
public:
    int marks;       // To store the marks of the student
    string gender;   // To store the gender of the student
    Node* left;      // Pointer to the left child in the BST
    Node* right;     // Pointer to the right child in the BST

    // Constructor to initialize the node with marks and gender
    Node(int m, string g) {
        marks = m;
        gender = g;
        left = right = nullptr; // Set left and right pointers to null initially
    }
};

// Class for the Binary Search Tree (BST)
class BST {
public:
    Node* root;  // Root node of the BST

    // Constructor for initializing the BST
    BST() {
        root = nullptr;  // Initially the tree is empty, so root is null
    }

    // Public method to insert a new student into the BST
    void insert(int marks, string gender) {
        // Call the recursive insert function and pass the root
        root = insertRec(root, marks, gender);
    }

    // Private helper function for recursive node insertion
    Node* insertRec(Node* node, int marks, string gender) {
        // Base case: If the current node is null, insert a new node here
        if (node == nullptr) {
            return new Node(marks, gender);  // Create and return the new node
        }

        // Recursive case: Recur down the left or right subtree
        // If the student's marks are less than the current node's marks, insert into the left subtree
        if (marks < node->marks) {
            node->left = insertRec(node->left, marks, gender);
        } 
        // If the student's marks are greater than the current node's marks, insert into the right subtree
        else if (marks > node->marks) {
            node->right = insertRec(node->right, marks, gender);
        }

        // Return the current node pointer after insertion
        return node;
    }

    // Public method to perform in-order traversal of the BST
    void inorder() {
        // Call the recursive inorder traversal function starting from the root
        inorderRec(root);
    }

    // Private helper function for recursive in-order traversal
    void inorderRec(Node* node) {
        if (node != nullptr) {  // If the current node is not null
            inorderRec(node->left);  // Recur on the left subtree
            // Print the current node's data (marks and gender)
            cout << "Marks: " << node->marks << ", Gender: " << node->gender << endl;
            inorderRec(node->right);  // Recur on the right subtree
        }
    }
};

// Main function to execute the program
int main() {
    // Arrays containing students' marks and gender information
    int marks[] = {85, 60, 75, 90, 45};  // Marks of 5 students
    string gender[] = {"male", "female", "male", "female", "male"};  // Gender of 5 students

    // Create two Binary Search Trees (BSTs): 
    // One for male students and another for female students
    BST maleBST, femaleBST;

    // Loop over the data arrays to insert students' information into the correct BST
    for (int i = 0; i < 5; i++) {
        // If the student's gender is "male", insert into the maleBST
        if (gender[i] == "male") {
            maleBST.insert(marks[i], gender[i]);
        } 
        // If the student's gender is "female", insert into the femaleBST
        else {
            femaleBST.insert(marks[i], gender[i]);
        }
    }

    // Display the in-order traversal of the male students' BST
    cout << "Male Students BST (In-order Traversal):" << endl;
    maleBST.inorder();

    // Display the in-order traversal of the female students' BST
    cout << "\nFemale Students BST (In-order Traversal):" << endl;
    femaleBST.inorder();

    return 0;  // End of program
}
