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
    
    // Height of tree
    int height(Node* node) {
        if (node == NULL) return 0;
        int leftH = height(node->left);
        int rightH = height(node->right);
        return 1 + max(leftH, rightH);
    }
    
    // Count total nodes
    int countNodes(Node* node) {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
    
    // Sum of all nodes
    int sumOfNodes(Node* node) {
        if (node == NULL) return 0;
        return node->data + sumOfNodes(node->left) + sumOfNodes(node->right);
    }
    
    // Find maximum element
    int findMax(Node* node) {
        if (node == NULL) return INT_MIN;
        int maxVal = node->data;
        maxVal = max(maxVal, findMax(node->left));
        maxVal = max(maxVal, findMax(node->right));
        return maxVal;
    }
    
    // Check if tree is balanced
    bool isBalanced(Node* node) {
        if (node == NULL) return true;
        
        int leftH = height(node->left);
        int rightH = height(node->right);
        
        if (abs(leftH - rightH) > 1) return false;
        
        return isBalanced(node->left) && isBalanced(node->right);
    }
    
    // Build tree
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
    
    cout << "--- Tree Properties ---\n\n";
    
    cout << "Height: " << bt.height(bt.root) << "\n";
    cout << "Total Nodes: " << bt.countNodes(bt.root) << "\n";
    cout << "Sum of Nodes: " << bt.sumOfNodes(bt.root) << "\n";
    cout << "Maximum Element: " << bt.findMax(bt.root) << "\n";
    cout << "Is Balanced: " << (bt.isBalanced(bt.root) ? "YES" : "NO") << "\n";
    
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

--- Tree Properties ---

Height: 3
Total Nodes: 6
Sum of Nodes: 21
Maximum Element: 6
Is Balanced: YES

Time Complexity:
  - Height: O(n)
  - countNodes: O(n)
  - sumOfNodes: O(n)
  - findMax: O(n)
  - isBalanced: O(n)

Space Complexity: O(h) - h = height (recursion)
*/
