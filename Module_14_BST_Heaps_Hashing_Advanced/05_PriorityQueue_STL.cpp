#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;  // Max heap
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min heap
    
    cout << "--- Priority Queue (Max Heap) ---\n\n";
    
    // Insert
    cout << "Inserting: 10, 20, 15, 30, 5\n";
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(30);
    maxHeap.push(5);
    
    cout << "\nRemoving in order:\n";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << "\n\n";
    
    cout << "--- Priority Queue (Min Heap) ---\n\n";
    
    // Insert
    cout << "Inserting: 10, 20, 15, 30, 5\n";
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(30);
    minHeap.push(5);
    
    cout << "\nRemoving in order:\n";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << "\n";
    
    return 0;
}

/*
Output:
--- Priority Queue (Max Heap) ---

Inserting: 10, 20, 15, 30, 5

Removing in order:
30 20 15 10 5

--- Priority Queue (Min Heap) ---

Inserting: 10, 20, 15, 30, 5

Removing in order:
5 10 15 20 30

STL Priority Queue Methods:
  - push(val): Insert element → O(log n)
  - pop(): Remove top element → O(log n)
  - top(): Get top element → O(1)
  - empty(): Check if empty → O(1)
  - size(): Get size → O(1)
*/
