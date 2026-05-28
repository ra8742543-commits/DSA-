#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    
    // Parent, left child, right child के indices
    int getParent(int i) { return (i - 1) / 2; }
    int getLeft(int i) { return 2 * i + 1; }
    int getRight(int i) { return 2 * i + 2; }
    
    // Swap करो
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Bubble up (insertion के बाद)
    void bubbleUp(int i) {
        while (i > 0 && heap[getParent(i)] < heap[i]) {
            swap(heap[i], heap[getParent(i)]);
            i = getParent(i);
        }
    }
    
    // Bubble down (deletion के बाद)
    void bubbleDown(int i) {
        int largest = i;
        int left = getLeft(i);
        int right = getRight(i);
        
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(heap[i], heap[largest]);
            bubbleDown(largest);
        }
    }
    
public:
    // Insert element
    void push(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
        cout << val << " inserted\n";
    }
    
    // Remove max element
    void pop() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }
        
        cout << "Removed: " << heap[0] << "\n";
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        if (!heap.empty()) {
            bubbleDown(0);
        }
    }
    
    // Get max element
    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    // Check if empty
    bool empty() {
        return heap.empty();
    }
    
    // Display heap
    void display() {
        cout << "Heap: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << "\n";
    }
};

int main() {
    MaxHeap maxHeap;
    
    cout << "--- Building Max Heap ---\n";
    int values[] = {10, 20, 15, 30, 5, 25};
    
    for (int val : values) {
        maxHeap.push(val);
    }
    
    cout << "\n";
    maxHeap.display();
    
    cout << "\nMax element: " << maxHeap.top() << "\n\n";
    
    cout << "--- Removing Elements ---\n";
    maxHeap.pop();
    maxHeap.display();
    
    maxHeap.pop();
    maxHeap.display();
    
    return 0;
}

/*
Output:
--- Building Max Heap ---
10 inserted
20 inserted
15 inserted
30 inserted
5 inserted
25 inserted

Heap: 30 20 25 10 5 15

Max element: 30

--- Removing Elements ---
Removed: 30
Heap: 25 20 15 10 5
Removed: 25
Heap: 20 10 15 5

Heap Structure (Array):
       30
      /  \
     20  25
    / \ /
   10  5 15

Array: [30, 20, 25, 10, 5, 15]

Time Complexity:
  - Push: O(log n) - bubbleUp
  - Pop: O(log n) - bubbleDown
  - Top: O(1)

Space Complexity: O(n)
*/
