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
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    Node* insertHelper(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        
        return node;
    }
    
    // Validate BST (हर node के लिए check करो)
    bool isValidBST() {
        return isValidHelper(root, INT_MIN, INT_MAX);
    }
    
    // Min और max range के साथ validate करो
    bool isValidHelper(Node* node, int minVal, int maxVal) {
        if (node == NULL) {
            return true;
        }
        
        // अगर node की value range में नहीं है
        if (node->data <= minVal || node->data >= maxVal) {
            return false;
        }
        
        // Left subtree को validate करो (max update करो)
        // Right subtree को validate करो (min update करो)
        return isValidHelper(node->left, minVal, node->data) &&
               isValidHelper(node->right, node->data, maxVal);
    }
    
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST bst1, bst2;
    
    cout << "--- Valid BST ---\n";
    int validValues[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : validValues) {
        bst1.insert(val);
    }
    
    cout << "BST 1 (Inorder): ";
    bst1.inorder(bst1.root);
    cout << "\n";
    cout << "Is Valid BST? " << (bst1.isValidBST() ? "YES ✅" : "NO ❌") << "\n\n";
    
    cout << "--- Invalid BST (Manual construction) ---\n";
    // Manually create an invalid BST
    bst2.root = new Node(50);
    bst2.root->left = new Node(30);
    bst2.root->right = new Node(70);
    bst2.root->left->right = new Node(65);  // Invalid! 65 > 50
    
    cout << "BST 2 (Inorder): ";
    bst2.inorder(bst2.root);
    cout << "\n";
    cout << "Is Valid BST? " << (bst2.isValidBST() ? "YES ✅" : "NO ❌") << "\n";
    
    return 0;
}

/*
Output:
--- Valid BST ---
BST 1 (Inorder): 20 30 40 50 60 70 80
Is Valid BST? YES ✅

--- Invalid BST (Manual construction) ---
BST 2 (Inorder): 30 65 50 70
Is Valid BST? NO ❌

Validation Logic:
  - हर node के लिए min और max range maintain करो
  - Left subtree: maxVal = node->data
  - Right subtree: minVal = node->data
  - अगर कोई node इस range में नहीं है, invalid है

Invalid Example:
       50
      /  \
    30   70
     \
      65  <- Invalid! (should be < 50)

Time Complexity: O(n)
Space Complexity: O(h) - recursion stack
*/
