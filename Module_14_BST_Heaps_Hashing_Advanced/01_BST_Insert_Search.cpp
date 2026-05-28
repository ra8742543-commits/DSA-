#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;
    
    BST() {
        root = NULL;
    }
    
    // Insert element in BST
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    Node* insertHelper(Node* node, int val) {
        // अगर tree empty है
        if (node == NULL) {
            return new Node(val);
        }
        
        // अगर val < node->data, left में insert करो
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        }
        // अगर val > node->data, right में insert करो
        else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        // अगर val == node->data, ignore (no duplicates)
        
        return node;
    }
    
    // Search element in BST
    bool search(int val) {
        return searchHelper(root, val);
    }
    
    bool searchHelper(Node* node, int val) {
        if (node == NULL) {
            return false;
        }
        
        if (val == node->data) {
            return true;
        }
        else if (val < node->data) {
            return searchHelper(node->left, val);
        }
        else {
            return searchHelper(node->right, val);
        }
    }
    
    // Inorder traversal (sorted order)
    void inorder(Node* node) {
        if (node == NULL) return;
        
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST bst;
    
    cout << "--- Building BST ---\n";
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    
    for (int val : values) {
        bst.insert(val);
        cout << "Inserted: " << val << "\n";
    }
    
    cout << "\nBST (Inorder - sorted): ";
    bst.inorder(bst.root);
    cout << "\n\n";
    
    cout << "--- Searching Elements ---\n";
    int searchVals[] = {40, 25, 60, 100};
    
    for (int val : searchVals) {
        bool found = bst.search(val);
        cout << "Search " << val << ": " << (found ? "Found ✅" : "Not Found ❌") << "\n";
    }
    
    return 0;
}

/*
Output:
--- Building BST ---
Inserted: 50
Inserted: 30
Inserted: 70
Inserted: 20
Inserted: 40
Inserted: 60
Inserted: 80

BST (Inorder - sorted): 20 30 40 50 60 70 80

--- Searching Elements ---
Search 40: Found ✅
Search 25: Not Found ❌
Search 60: Found ✅
Search 100: Not Found ❌

BST Tree Structure:
        50
       /  \
      30  70
     / \  / \
    20 40 60 80

Time Complexity:
  - Insert (Average): O(log n)
  - Insert (Worst): O(n) - if tree becomes skewed
  - Search (Average): O(log n)
  - Search (Worst): O(n)

Space Complexity: O(n)
*/
