#include<bits/stdc++.h>
using namespace std;

// Node की definition
struct Node {
    int data;           // Data store करने के लिए
    Node* next;         // अगले node का address
    
    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;  // List का first node
    
    LinkedList() {
        head = NULL;  // शुरुआत में list empty है
    }
    
    // Element को शुरुआत में add करो
    void pushFront(int val) {
        Node* newNode = new Node(val);  // नया node बनाओ
        newNode->next = head;           // नए का next = पुराना head
        head = newNode;                 // Head को update करो
    }
    
    // Element को अंत में add करो
    void pushBack(int val) {
        Node* newNode = new Node(val);  // नया node बनाओ
        
        // अगर list empty है
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        // Last node तक traverse करो
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;  // अगले node पर जाओ
        }
        
        // Last node का next = नया node
        temp->next = newNode;
    }
    
    // List को print करो
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " → ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    
    // Push Front examples
    cout << "Using Push Front:\n";
    list.pushFront(3);
    list.pushFront(2);
    list.pushFront(1);
    cout << "List: ";
    list.display();  // Output: 1 → 2 → 3 → NULL
    
    // Push Back examples
    LinkedList list2;
    cout << "\nUsing Push Back:\n";
    list2.pushBack(1);
    list2.pushBack(2);
    list2.pushBack(3);
    cout << "List: ";
    list2.display();  // Output: 1 → 2 → 3 → NULL
    
    return 0;
}

/*
Output:
Using Push Front:
List: 1 → 2 → 3 → NULL

Using Push Back:
List: 1 → 2 → 3 → NULL

Time Complexity:
  - Push Front: O(1)
  - Push Back: O(n)
Space Complexity: O(1)
*/