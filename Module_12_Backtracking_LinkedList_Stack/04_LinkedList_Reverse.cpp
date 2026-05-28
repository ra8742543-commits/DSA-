#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() {
        head = NULL;
    }
    
    void pushBack(int val) {
        Node* newNode = new Node(val);
        
        if (head == NULL) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // Linked List को reverse करो (Iterative)
    void reverse() {
        Node* prev = NULL;      // पिछला node
        Node* curr = head;      // Current node
        Node* next = NULL;      // अगला node
        
        while (curr != NULL) {
            // Step 1: अगला node save करो (ताकि हार न जाएं)
            next = curr->next;
            
            // Step 2: Current के links को reverse करो
            curr->next = prev;
            
            // Step 3: Pointers को आगे बढ़ाओ
            prev = curr;
            curr = next;
        }
        
        // Step 4: Head को update करो
        head = prev;
    }
    
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
    
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    
    cout << "Original: ";
    list.display();  // 1 → 2 → 3 → 4 → NULL
    
    list.reverse();  // Reverse करो
    
    cout << "Reversed: ";
    list.display();  // 4 → 3 → 2 → 1 → NULL
    
    return 0;
}

/*
Output:
Original: 1 → 2 → 3 → 4 → NULL
Reversed: 4 → 3 → 2 → 1 → NULL

Algorithm Logic:
  - prev = NULL
  - curr = head
  - next = NULL
  
  While curr is not NULL:
    1. Save next: next = curr→next
    2. Reverse link: curr→next = prev
    3. Move pointers: prev = curr, curr = next
  
  head = prev

Time Complexity: O(n)
Space Complexity: O(1)
*/