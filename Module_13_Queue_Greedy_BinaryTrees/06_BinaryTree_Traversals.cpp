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
    
    // Preorder Traversal: Root → Left → Right
    void preorder(Node* node) {
        if (node == NULL) return;
        
        cout << node->data << " ";           // Root
        preorder(node->left);                // Left
        preorder(node->right);               // Right
    }
    
    // Inorder Traversal: Left → Root → Right
    void inorder(Node* node) {
        if (node == NULL) return;
        
        inorder(node->left);                 // Left
        cout << node->data << " ";           // Root
        inorder(node->right);                // Right
    }
    
    // Postorder Traversal: Left → Right → Root
    void postorder(Node* node) {
        if (node == NULL) return;
        
        postorder(node->left);               // Left
        postorder(node->right);              // Right
        cout << node->data << " ";           // Root
    }
    
    // Level Order Traversal (BFS)
    void levelOrder(Node* node) {
        if (node == NULL) return;
        
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }
    
    // Binary tree बनाओ
    void buildTree() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
    }
};

int main() {
    BinaryTree bt;
    bt.buildTree();
    
    cout << "Binary Tree:\n";
    cout << "       1\n";
    cout << "      / \\\n";
    cout << "     2   3\n";
    cout << "    / \\\n";
    cout << "   4   5\n\n";
    
    cout << "Preorder (Root-Left-Right): ";
    bt.preorder(bt.root);
    cout << "\n";
    
    cout << "Inorder (Left-Root-Right): ";
    bt.inorder(bt.root);
    cout << "\n";
    
    cout << "Postorder (Left-Right-Root): ";
    bt.postorder(bt.root);
    cout << "\n";
    
    cout << "Level Order (BFS): ";
    bt.levelOrder(bt.root);
    cout << "\n";
    
    return 0;
}

/*
Output:
Binary Tree:
       1
      / \
     2   3
    / \
   4   5

Preorder (Root-Left-Right): 1 2 4 5 3
Inorder (Left-Root-Right): 4 2 5 1 3
Postorder (Left-Right-Root): 4 5 2 3 1
Level Order (BFS): 1 2 3 4 5

Time Complexity: O(n) - सभी nodes को visit करना पड़ता है
Space Complexity: O(h) - h = height (recursion stack)
                        O(n) for level order (queue)
*/
