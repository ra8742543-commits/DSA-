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
    
    // Floyd's Cycle Detection Algorithm
    // धीमा pointer (slow) = 1 step
    // तेज़ pointer (fast) = 2 steps
    // अगर cycle है → दोनों meet करेंगे
    // अगर cycle नहीं है → fast pointer NULL पर पहुंचेगा
    
    bool hasCycle() {
        Node* slow = head;      // धीमा pointer
        Node* fast = head;      // तेज़ pointer
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;              // 1 step
            fast = fast->next->next;        // 2 steps
            
            if (slow == fast) {
                return true;  // Cycle found!
            }
        }
        
        return false;  // No cycle
    }
    
    // List में cycle बनाने के लिए (testing)
    void createCycle() {
        if (head == NULL) return;
        
        Node* temp = head;
        Node* lastNode = head;
        
        // Last node तक जाओ
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        
        // temp को position 2 पर move करो (example)
        temp = temp->next;
        if (temp != NULL) {
            // Last node का next = temp (cycle बनाओ)
            lastNode->next = temp;
        }
    }
    
    void display() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL && count < 10) {  // 10 limit ताकि infinite loop न हो
            cout << temp->data << " → ";
            temp = temp->next;
            count++;
        }
        if (count == 10) cout << "(Cycle detected)";
        else cout << "NULL";
        cout << "\n";
    }
};

int main() {
    LinkedList list1;
    
    // Without Cycle
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    
    cout << "List 1: ";
    list1.display();
    cout << "Has Cycle? " << (list1.hasCycle() ? "YES ❌" : "NO ✅") << "\n\n";
    
    // Create cycle
    list1.createCycle();
    cout << "After creating cycle:\n";
    cout << "Has Cycle? " << (list1.hasCycle() ? "YES ❌" : "NO ✅") << "\n";
    
    return 0;
}

/*
Output:
List 1: 1 → 2 → 3 → NULL
Has Cycle? NO ✅

After creating cycle:
Has Cycle? YES ❌

Floyd's Algorithm (Tortoise & Hare):
  1. slow = head (1 step)
  2. fast = head (2 steps)
  3. While fast != NULL:
     - slow = slow→next
     - fast = fast→next→next
     - if slow == fast: CYCLE FOUND!
  4. If loop ends without match: NO CYCLE

Time Complexity: O(n)
Space Complexity: O(1)
Why O(n)? धीमा pointer को cycle के साथ n steps चाहिए।
*/