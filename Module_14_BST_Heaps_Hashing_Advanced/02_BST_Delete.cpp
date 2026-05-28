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
    
    // Delete element from BST
    void deleteNode(int val) {
        root = deleteHelper(root, val);
    }
    
    Node* deleteHelper(Node* node, int val) {
        if (node == NULL) {
            return NULL;
        }
        
        // अगर val < node->data, left में search करो
        if (val < node->data) {
            node->left = deleteHelper(node->left, val);
        }
        // अगर val > node->data, right में search करो
        else if (val > node->data) {
            node->right = deleteHelper(node->right, val);
        }
        // अगर val == node->data, delete करो
        else {
            // Case 1: कोई children नहीं (Leaf node)
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            
            // Case 2: सिर्फ एक child है
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Case 3: दोनों children हैं
            // Inorder successor खोजो (right subtree का minimum)
            Node* minNode = findMin(node->right);
            node->data = minNode->data;  // Value को replace करो
            node->right = deleteHelper(node->right, minNode->data);  // Successor को delete करो
        }
        
        return node;
    }
    
    // Right subtree का minimum element खोजो
    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    
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
    }
    
    cout << "Original BST (Inorder): ";
    bst.inorder(bst.root);
    cout << "\n\n";
    
    cout << "--- Deleting Nodes ---\n\n";
    
    // Delete leaf node
    cout << "Delete 20 (Leaf node)\n";
    bst.deleteNode(20);
    cout << "After deletion: ";
    bst.inorder(bst.root);
    cout << "\n\n";
    
    // Delete node with one child
    cout << "Delete 30 (One child)\n";
    bst.deleteNode(30);
    cout << "After deletion: ";
    bst.inorder(bst.root);
    cout << "\n\n";
    
    // Delete node with two children
    cout << "Delete 50 (Two children - Root)\n";
    bst.deleteNode(50);
    cout << "After deletion: ";
    bst.inorder(bst.root);
    cout << "\n";
    
    return 0;
}

/*
Output:
--- Building BST ---
Original BST (Inorder): 20 30 40 50 60 70 80

--- Deleting Nodes ---

Delete 20 (Leaf node)
After deletion: 30 40 50 60 70 80

Delete 30 (One child)
After deletion: 40 50 60 70 80

Delete 50 (Two children - Root)
After deletion: 40 60 70 80

Deletion Algorithm:
  Case 1: No children (Leaf)
    - Simply delete and return NULL
  
  Case 2: One child
    - Replace node with its child
  
  Case 3: Two children
    - Find inorder successor (min in right subtree)
    - Replace data with successor's data
    - Delete the successor

Time Complexity: O(log n) to O(n)
Space Complexity: O(n)
*/
