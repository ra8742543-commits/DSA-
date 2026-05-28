#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;  // STL queue
    
    cout << "--- Using STL Queue ---\n\n";
    
    // Enqueue
    cout << "Enqueuing: 10, 20, 30, 40\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    // Display size
    cout << "Size: " << q.size() << "\n\n";
    
    // Front element
    cout << "Front: " << q.front() << "\n";
    cout << "Rear: " << q.back() << "\n\n";
    
    // Dequeue
    cout << "--- Dequeueing Elements ---\n";
    while (!q.empty()) {
        cout << q.front() << " dequeued\n";
        q.pop();
    }
    
    // isEmpty
    cout << "\nIs empty? " << (q.empty() ? "YES" : "NO") << "\n";
    
    return 0;
}

/*
Output:
--- Using STL Queue ---

Enqueuing: 10, 20, 30, 40
Size: 4

Front: 10
Rear: 40

--- Dequeueing Elements ---
10 dequeued
20 dequeued
30 dequeued
40 dequeued

Is empty? YES

STL Queue Methods:
  - push(val): Add element at rear → O(1)
  - pop(): Remove from front → O(1)
  - front(): Get front element → O(1)
  - back(): Get rear element → O(1)
  - size(): Get queue size → O(1)
  - empty(): Check if empty → O(1)
*/
