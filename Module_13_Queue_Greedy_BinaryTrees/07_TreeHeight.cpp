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

class BinaryTree {
public:
    Node* root;
    
    BinaryTree() {
        root = NULL;
    }
    
    // Height of binary tree
    int height(Node* node) {
        // Base case: अगर node NULL है
        if (node == NULL) {
            return 0;
        }
        
        // Left और right subtree की height निकालो
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // Max height + 1 (current node के लिए)
        return 1 + max(leftHeight, rightHeight);
    }
    
    // Binary tree बनाओ
    void buildTree() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->right = new Node(6);
    }
};

int main() {
    BinaryTree bt;
    bt.buildTree();
    
    cout << "Binary Tree:\n";
    cout << "        1\n";
    cout << "       / \\\n";
    cout << "      2   3\n";
    cout << "     / \\   \\\n";
    cout << "    4   5   6\n\n";
    
    int h = bt.height(bt.root);
    cout << "Height of Binary Tree: " << h << "\n";
    
    return 0;
}

/*
Output:
Binary Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

Height of Binary Tree: 3

Explanation:
  Longest path: 1 → 2 → 4 (or 1 → 2 → 5)
  Count of nodes = 3

Time Complexity: O(n) - सभी nodes को visit
Space Complexity: O(h) - recursion stack height
*/
