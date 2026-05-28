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

class Queue {
private:
    Node* front;  // Front node
    Node* rear;   // Rear node
    
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    
    // Element को rear में add करो (Enqueue)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        
        // अगर queue empty है
        if (rear == NULL) {
            front = rear = newNode;
            cout << val << " enqueued\n";
            return;
        }
        
        // अगर queue खाली नहीं है
        rear->next = newNode;  // पुराने rear का next = नया node
        rear = newNode;        // Rear को update करो
        cout << val << " enqueued\n";
    }
    
    // Front element को remove करो (Dequeue)
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty (Underflow)!\n";
            return;
        }
        
        Node* temp = front;
        cout << temp->data << " dequeued\n";
        front = front->next;
        
        // अगर queue खाली हो गया
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
    }
    
    // Front element को देखो
    int getFront() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }
    
    // Queue empty है या नहीं
    bool isEmpty() {
        return front == NULL;
    }
    
    // Queue को display करो
    void display() {
        Node* temp = front;
        cout << "Queue (Front to Rear): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    
    cout << "--- Enqueuing Elements ---\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    cout << "\n--- Display Queue ---\n";
    q.display();
    
    cout << "\n--- Front Element ---\n";
    cout << "Front: " << q.getFront() << "\n";
    
    cout << "\n--- Dequeueing Elements ---\n";
    q.dequeue();
    q.dequeue();
    
    cout << "\n--- Display Queue After Dequeue ---\n";
    q.display();
    
    return 0;
}

/*
Output:
--- Enqueuing Elements ---
10 enqueued
20 enqueued
30 enqueued
40 enqueued

--- Display Queue ---
Queue (Front to Rear): 10 20 30 40

--- Front Element ---
Front: 10

--- Dequeueing Elements ---
10 dequeued
20 dequeued

--- Display Queue After Dequeue ---
Queue (Front to Rear): 30 40

Time Complexity:
  - Enqueue: O(1)
  - Dequeue: O(1)
  - getFront: O(1)

Space Complexity: O(n)
*/
