#include <iostream>
#include <vector>
using namespace std;

// TreeNode class for BST (Binary Search Tree)
class TreeNode {
public:
    int data;           // Value of the node
    TreeNode* left;     // Pointer to the left child
    TreeNode* right;    // Pointer to the right child

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}  // Constructor to initialize a node
};

// Heap class for Min-Heap
class Heap {
private:
    vector<int> heapArray;  // Array to store heap elements
    int currentSize;        // Current number of elements in the heap

    // Function to maintain heap order property by percolating down
    void percolateDown(int hole) {
        int child;
        int tmp = heapArray[hole];

        // Move down the heap, swapping with smaller children
        for (; hole * 2 + 1 < currentSize; hole = child) {
            child = hole * 2 + 1;
            if (child != currentSize - 1 && heapArray[child + 1] < heapArray[child])
                child++;
            if (heapArray[child] < tmp)
                heapArray[hole] = heapArray[child];
            else
                break;
        }
        heapArray[hole] = tmp;
    }

public:
    Heap() : currentSize(0) {}  // Constructor to initialize an empty heap

    // Check if the heap is empty
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Insert a new element into the heap
    void insert(int x) {
        heapArray.push_back(x);  // Add the new element to the end of the array
        int hole = currentSize++;  // Hole is the index where the new element should be placed
        for (; hole > 0 && x < heapArray[(hole - 1) / 2]; hole = (hole - 1) / 2)
            heapArray[hole] = heapArray[(hole - 1) / 2];  // Move the hole up the heap
        heapArray[hole] = x;  // Place the new element in the correct position
    }

    // Build the heap from an array of elements
    void buildHeap(const vector<int>& data) {
        currentSize = data.size();  // Set the current size of the heap
        heapArray = data;  // Initialize the heap array with the data
        for (int i = currentSize / 2 - 1; i >= 0; i--)  // Percolate down from the first non-leaf node
            percolateDown(i);
    }

    // Display the heap elements
    void displayHeap() const {
        for (int i : heapArray)
            cout << i << " ";
        cout << endl;
    }
};

// Function to insert a node into BST
TreeNode* addNode(TreeNode* root, int data, bool& isRoot) {
    if (root == nullptr) {  // If the tree is empty
        if (isRoot) {
            cout << data << " is inserted as root in BST" << endl;  // Root node insertion message
            isRoot = false;
        } else {
            cout << data << " inserted in BST" << endl;  // Non-root node insertion message
        }
        return new TreeNode(data);  // Create and return the new node
    }
    if (data < root->data) {
        root->left = addNode(root->left, data, isRoot);  // Recursively insert into the left subtree
    } else {
        root->right = addNode(root->right, data, isRoot);  // Recursively insert into the right subtree
    }
    return root;
}

// Function for post-order traversal of BST
void postOrder(TreeNode* root, vector<int>& result) {
    if (root == nullptr)
        return;
    postOrder(root->left, result);  // Traverse left subtree
    postOrder(root->right, result);  // Traverse right subtree
    result.push_back(root->data);  // Visit the node
}

// Function for pre-order traversal of BST
void preOrder(TreeNode* root, vector<int>& result) {
    if (root == nullptr)
        return;
    result.push_back(root->data);  // Visit the node
    preOrder(root->left, result);  // Traverse left subtree
    preOrder(root->right, result);  // Traverse right subtree
}

// Function to populate BST from given data
TreeNode* populateTree(const vector<int>& data) {
    TreeNode* root = nullptr;  // Initialize the root as null
    bool isRoot = true;  // Flag to check if the current node is root
    for (int val : data)  // Insert each element into the BST
        root = addNode(root, val, isRoot);
    return root;
}

int main() {
    int n;
    cout << "How many nodes you want to insert into BST: ";
    cin >> n;  // Input the number of nodes

    vector<int> data(n);  // Vector to store the node values
    cout << "Enter " << n << " values to insert into BST: ";
    for (int i = 0; i < n; ++i) {
        cin >> data[i];  // Input each node value
    }

    // Step 1: Build BST
    TreeNode* root = populateTree(data);  // Create the BST

    // Step 2: Post-order traversal and construct min-heap using insert method
    vector<int> postOrderData;
    postOrder(root, postOrderData);  // Perform post-order traversal
    cout << "\nPost-Order Traversal of BST: ";
    for (int val : postOrderData)
        cout << val << " ";  // Print the post-order traversal result
    cout << endl;

    Heap minHeap1;
    for (int val : postOrderData)
        minHeap1.insert(val);  // Insert elements into the min-heap
    cout << "Min Heap using Insert method: ";
    minHeap1.displayHeap();  // Display the min-heap

    // Step 4: Pre-order traversal and construct min-heap using buildHeap method
    vector<int> preOrderData;
    preOrder(root, preOrderData);  // Perform pre-order traversal
    cout << "\nPre-Order Traversal of BST: ";
    for (int val : preOrderData)
        cout << val << " ";  // Print the pre-order traversal result
    cout << endl;

    Heap minHeap2;
    minHeap2.buildHeap(preOrderData);  // Build the min-heap from the pre-order data
    cout << "Min Heap using Build method: ";
    minHeap2.displayHeap();  // Display the min-heap

    return 0;
}
