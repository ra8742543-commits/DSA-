# Module 13: Queue, Greedy & Binary Trees

## Complete Learning Guide for SIGMA-9 CPP DSA

---

## 📚 Topics Covered

### Part 1: Queue
- [x] Introduction to Queue (FIFO Principle)
- [x] Queue Implementation Using LinkedList
- [x] Circular Queue Using Array
- [x] Queue STL (Standard Template Library)

### Part 2: Greedy Algorithms
- [x] Introduction to Greedy Approach
- [x] Activity Selection Problem
- [x] Fractional Knapsack Problem

### Part 3: Binary Trees
- [x] Introduction to Binary Trees
- [x] Tree Traversals (Preorder, Inorder, Postorder, Level Order)
- [x] Height of Binary Tree
- [x] Tree Properties (Count, Sum, Max, Balanced Check)

---

## 📁 File Structure

```
Module_13_Queue_Greedy_BinaryTrees/
├── 01_Queue_LinkedList.cpp          (Queue using LinkedList)
├── 02_CircularQueue_Array.cpp       (Circular Queue using Array)
├── 03_Queue_STL.cpp                 (Queue STL)
├── 04_ActivitySelection.cpp          (Activity Selection - Greedy)
├── 05_FractionalKnapsack.cpp        (Fractional Knapsack - Greedy)
├── 06_BinaryTree_Traversals.cpp     (All 4 Traversals)
├── 07_TreeHeight.cpp                (Height of Tree)
├── 08_TreeProperties.cpp            (Tree Properties)
└── README.md                         (This file)
```

---

## 🎯 Quick Reference

### Time & Space Complexity

| Topic | Time Complexity | Space Complexity | Key Learning |
|-------|-----------------|------------------|---------------|
| Queue (LinkedList) | O(1) all ops | O(n) | FIFO principle |
| Circular Queue | O(1) all ops | O(capacity) | Space reuse |
| Activity Selection | O(n log n) | O(1) | Greedy choice |
| Fractional Knapsack | O(n log n) | O(1) | Profit density |
| Preorder Traversal | O(n) | O(h) | Root-Left-Right |
| Inorder Traversal | O(n) | O(h) | Left-Root-Right |
| Postorder Traversal | O(n) | O(h) | Left-Right-Root |
| Level Order (BFS) | O(n) | O(n) | Queue based |
| Tree Height | O(n) | O(h) | Recursion |

---

## 📝 Key Concepts

### QUEUE (FIFO)
```
Enqueue: Add at rear   → O(1)
Dequeue: Remove from front → O(1)
Front: Peek → O(1)

Applications:
  - BFS traversal
  - Task scheduling
  - Printer queue
```

### GREEDY ALGORITHMS
```
Approach: Local optimal choice → Global optimum

When to use:
  ✅ Activity Selection
  ✅ Huffman Coding
  ✅ Fractional Knapsack
  ❌ 0-1 Knapsack (Use DP)

Advantage: Fast (O(n log n))
Disadvantage: Doesn't always work
```

### BINARY TREES
```
Traversals:
  - Preorder: Root → Left → Right
  - Inorder: Left → Root → Right
  - Postorder: Left → Right → Root
  - Level Order: Level by level (BFS)

Properties:
  - Height: Longest path from root to leaf
  - Balanced: |leftHeight - rightHeight| ≤ 1
  - Complete: All levels filled except last
```

---

## 🔍 Detailed Explanations

### 1️⃣ Queue Operations

**LinkedList Implementation:**
```cpp
void enqueue(int val) {
    newNode = Node(val)
    if (rear == NULL):
        front = rear = newNode
    else:
        rear->next = newNode
        rear = newNode
}

void dequeue() {
    if (front == NULL): return
    temp = front
    front = front->next
    if (front == NULL): rear = NULL
    delete temp
}
```

**Complexity:** O(1) for all operations

---

### 2️⃣ Activity Selection (Greedy)

**Algorithm:**
1. Sort activities by end time
2. Select first activity
3. For each remaining activity:
   - If start >= lastEnd: Select it
   - Update lastEnd

**Example:**
```
Activities: (1,3), (2,5), (3,9), (4,6), (6,8), (8,10)
Sorted by end: (1,3), (4,6), (6,8), (2,5), (3,9), (8,10)

Selection:
  - (1,3): Select
  - (4,6): 4 >= 3? YES → Select
  - (6,8): 6 >= 6? YES → Select
  - (8,10): 8 >= 8? YES → Select

Total: 4 activities ✅
```

---

### 3️⃣ Binary Tree Traversals

**Preorder (Root-Left-Right):**
```cpp
void preorder(Node* node) {
    if (node == NULL) return;
    print node->data;        // Root
    preorder(node->left);    // Left
    preorder(node->right);   // Right
}
```

**Inorder (Left-Root-Right):**
```cpp
void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);     // Left
    print node->data;        // Root
    inorder(node->right);    // Right
}
```

**Level Order (BFS):**
```cpp
void levelOrder(Node* node) {
    if (node == NULL) return;
    queue<Node*> q;
    q.push(node);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        print current->data;
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
```

---

### 4️⃣ Tree Height

**Algorithm:**
```cpp
int height(Node* node) {
    if (node == NULL) return 0;
    
    int leftH = height(node->left);
    int rightH = height(node->right);
    
    return 1 + max(leftH, rightH);
}
```

**Complexity:** O(n) - Visit all nodes

---

## 💡 Learning Tips

1. **Dry Run करो:** हर algorithm को manually trace करो
2. **Visualize करो:** Tree diagrams बनाओ
3. **Code करो:** सभी examples को implement करो
4. **Test करो:** Different inputs के साथ test करो
5. **Compare करो:** Different approaches को compare करो

---

## 📚 Practice Problems

### Easy
1. Print queue elements
2. Tree height calculation
3. Count nodes in tree

### Medium
1. All tree traversals
2. Activity selection
3. Sum of tree nodes

### Hard
1. Serialize/Deserialize tree
2. Least activity problem variation
3. Maximum independent set in tree

---

## 🚀 How to Run

```bash
# Compile
g++ -o 01_Queue 01_Queue_LinkedList.cpp
g++ -o 02_CircularQueue 02_CircularQueue_Array.cpp
# ... and so on

# Run
./01_Queue
./02_CircularQueue
# ... and so on
```

---

## 📖 Reference Links

- Queue: [GeeksforGeeks - Queue](https://www.geeksforgeeks.org/queue-data-structure/)
- Greedy: [InterviewBit - Greedy](https://www.interviewbit.com/courses/programming/topics/greedy/)
- Binary Trees: [GeeksforGeeks - Binary Trees](https://www.geeksforgeeks.org/binary-tree-data-structure/)

---

## ✅ Checklist

- [x] Understand queue concept (FIFO)
- [x] Implement queue with LinkedList
- [x] Implement circular queue
- [x] Learn greedy approach
- [x] Solve activity selection
- [x] Solve fractional knapsack
- [x] Learn all tree traversals
- [x] Calculate tree height
- [x] Understand tree properties
- [x] Practice with different inputs

---

## 🎉 Next Steps

👉 Move to **Module 14: BST, Heaps, Hashing & Advanced DS**

---

**Happy Learning! 🚀**

*Made with ❤️ for SIGMA-9 CPP DSA Course*
