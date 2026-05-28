#include<bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int capacity;
    
public:
    CircularQueue(int cap) {
        capacity = cap;
        arr.resize(cap);
        front = -1;  // Empty queue
        rear = -1;   // Empty queue
        size = 0;
    }
    
    // Element को rear में add करो
    void enqueue(int val) {
        // अगर queue full है
        if (size == capacity) {
            cout << "Queue is Full (Overflow)!\n";
            return;
        }
        
        // अगर queue empty है
        if (front == -1) {
            front = 0;
        }
        
        // Rear को circular तरीके से move करो
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
        
        cout << val << " enqueued\n";
    }
    
    // Front element को remove करो
    void dequeue() {
        // अगर queue empty है
        if (size == 0) {
            cout << "Queue is Empty (Underflow)!\n";
            return;
        }
        
        cout << arr[front] << " dequeued\n";
        
        // अगर सिर्फ एक element था
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Front को circular तरीके से move करो
            front = (front + 1) % capacity;
        }
        
        size--;
    }
    
    // Front element को देखो
    int getFront() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }
    
    // Queue empty है या नहीं
    bool isEmpty() {
        return size == 0;
    }
    
    // Queue की current size
    int getSize() {
        return size;
    }
    
    // Queue को display करो
    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        
        cout << "Queue: ";
        int count = 0;
        int i = front;
        
        while (count < size) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
            count++;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq(5);  // Capacity = 5
    
    cout << "--- Enqueuing Elements ---\n";
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    
    cout << "\n--- Display Queue ---\n";
    cq.display();
    
    cout << "\n--- Dequeueing Elements ---\n";
    cq.dequeue();
    cq.dequeue();
    
    cout << "\n--- Display Queue After Dequeue ---\n";
    cq.display();
    
    cout << "\n--- Adding More Elements (Reusing Space) ---\n";
    cq.enqueue(60);
    cq.enqueue(70);
    
    cout << "\n--- Final Queue ---\n";
    cq.display();
    
    cout << "\nQueue Size: " << cq.getSize() << "\n";
    
    return 0;
}

/*
Output:
--- Enqueuing Elements ---
10 enqueued
20 enqueued
30 enqueued
40 enqueued
50 enqueued

--- Display Queue ---
Queue: 10 20 30 40 50

--- Dequeueing Elements ---
10 dequeued
20 dequeued

--- Display Queue After Dequeue ---
Queue: 30 40 50

--- Adding More Elements (Reusing Space) ---
60 enqueued
70 enqueued

--- Final Queue ---
Queue: 30 40 50 60 70

Queue Size: 5

Time Complexity:
  - Enqueue: O(1)
  - Dequeue: O(1)

Space Complexity: O(capacity)

Why Circular?
  - Linear queue में rear खत्म हो जाता है
  - Circular में rear फिर से शुरू से आ सकता है
  - Space efficient ✅
*/
