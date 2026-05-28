# Module 14: BST, Heaps, Hashing & Advanced DS

## Complete Learning Guide for SIGMA-9 CPP DSA

---

## 📚 Topics Covered

### Part 1: Binary Search Trees (BST)
- [x] BST Introduction & Properties
- [x] Insert & Search Operations
- [x] Delete Operations (3 Cases)
- [x] Validate BST

### Part 2: Heaps & Priority Queue
- [x] Heap Implementation (Max Heap)
- [x] Heap Operations (Push, Pop, Bubble Up/Down)
- [x] Priority Queue STL

### Part 3: Hashing
- [x] Introduction to Hashing
- [x] Hash Tables & Collisions
- [x] Unordered Map (STL)
- [x] Unordered Set (STL)

### Part 4: Advanced Data Structures
- [x] Tries (Prefix Tree)
- [x] Graphs (Adjacency List)
- [x] BFS & DFS Traversals

---

## 📁 File Structure

```
Module_14_BST_Heaps_Hashing_Advanced/
├── 01_BST_Insert_Search.cpp          (Insert & Search in BST)
├── 02_BST_Delete.cpp                 (Delete from BST - 3 cases)
├── 03_BST_Validate.cpp               (Validate if tree is BST)
├── 04_Heap_Implementation.cpp         (MaxHeap from scratch)
├── 05_PriorityQueue_STL.cpp          (Priority Queue STL)
├── 06_Hashing_STL.cpp                (Unordered Map & Set)
├── 07_Trie.cpp                       (Trie Data Structure)
├── 08_Graph_BFS_DFS.cpp              (Graph Traversals)
└── README.md                          (This file)
```

---

## 🎯 Quick Reference

### Time & Space Complexity

| Data Structure | Operation | Avg Time | Worst Time | Space |
|---|---|---|---|---|
| **BST** | Insert | O(log n) | O(n) | O(n) |
| **BST** | Search | O(log n) | O(n) | O(n) |
| **BST** | Delete | O(log n) | O(n) | O(n) |
| **Max Heap** | Push | O(log n) | O(log n) | O(n) |
| **Max Heap** | Pop | O(log n) | O(log n) | O(n) |
| **Hash Table** | Insert | O(1) | O(n) | O(n) |
| **Hash Table** | Search | O(1) | O(n) | O(n) |
| **Trie** | Insert | O(m) | O(m) | O(m×Σ) |
| **Trie** | Search | O(m) | O(m) | O(m×Σ) |
| **Graph BFS** | Traversal | O(V+E) | O(V+E) | O(V) |
| **Graph DFS** | Traversal | O(V+E) | O(V+E) | O(V) |

*m = word length, Σ = alphabet size, V = vertices, E = edges*

---

## 🔍 Detailed Explanations

### 1️⃣ Binary Search Tree (BST)

**Properties:**
```
- Left child < Parent
- Right child > Parent
- Left & Right subtrees are also BST

Example:
        50
       /  \
      30  70
     / \ / \
    20 40 60 80

Inorder traversal gives sorted order: 20 30 40 50 60 70 80
```

**Insert Algorithm:**
```cpp
void insert(int val) {
    if (val < node->data):
        insert in left subtree
    else if (val > node->data):
        insert in right subtree
    else:
        skip (no duplicates)
}
```

**Delete Cases:**
```
Case 1: Leaf node → Simply delete
Case 2: One child → Replace with child
Case 3: Two children → Replace with inorder successor
                       (minimum in right subtree)
```

---

### 2️⃣ Heaps

**Max Heap Property:**
```
Parent >= Children

Array Representation:
       30
      /  \
     20  25
    / \ /
   10  5 15

Array: [30, 20, 25, 10, 5, 15]

Index Relations:
  Parent: (i-1)/2
  Left Child: 2*i + 1
  Right Child: 2*i + 2
```

**Operations:**
```
Push (Bubble Up):
  1. Add element at end
  2. Compare with parent
  3. Swap if parent is smaller
  4. Repeat until property satisfied

Pop (Bubble Down):
  1. Replace root with last element
  2. Remove last element
  3. Compare with children
  4. Swap with larger child
  5. Repeat until property satisfied
```

---

### 3️⃣ Hashing

**Hash Function:**
```
Hash = function(key) → Index

Example:
key = "apple"
hash("apple") = 3 → stores at index 3
```

**Collision Handling:**
```
1. Chaining (Linked List)
2. Open Addressing (Linear Probing)
3. Double Hashing
```

**STL Containers:**
```
unordered_map<Key, Value>    // Hash Table
unordered_set<Key>            // Hash Table (no duplicates)
map<Key, Value>               // Balanced BST
set<Key>                      // Balanced BST
```

---

### 4️⃣ Tries

**Structure:**
```
Each node has children for each letter
EndMarker indicates end of word

Example: Insert "apple", "app", "apricot"

       root
        |
        a
       /|\
      p r
     /|  \
    p  i  c
    |  |   \
    l  c   o
    |  |    \
    e  o   t
    |  |    |
   END t  END
    |  |
   END END
```

**Time Complexity:**
```
Insert: O(m)     - m = word length
Search: O(m)
StartsWith: O(m)
```

---

### 5️⃣ Graphs

**Representations:**
```
Adjacency List (Space Efficient):
  0: [1, 2]
  1: [0, 3]
  2: [0, 4]
  3: [1]
  4: [2]

Adjacency Matrix (Dense Graphs):
     0  1  2  3  4
  0 [0  1  1  0  0]
  1 [1  0  0  1  0]
  2 [1  0  0  0  1]
  3 [0  1  0  0  0]
  4 [0  0  1  0  0]
```

**BFS (Breadth First Search):**
```cpp
void bfs(int start) {
    queue<int> q;
    vector<bool> visited(n, false);
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        process(v);
        
        for (int neighbor : adjacentTo(v)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

**DFS (Depth First Search):**
```cpp
void dfs(int v, vector<bool>& visited) {
    visited[v] = true;
    process(v);
    
    for (int neighbor : adjacentTo(v)) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}
```

---

## 💡 Key Learnings

### BST Advantages
✅ Efficient searching in sorted data
✅ In-place sorting (inorder)
✅ Range queries
❌ Can become skewed (unbalanced)

### Heap Advantages
✅ Priority ordering
✅ Fast extract min/max
✅ Complete binary tree
❌ Not suitable for searching

### Hashing Advantages
✅ O(1) average insertion/search
✅ Fast lookup
❌ O(n) worst case (collisions)
❌ Unordered

### Trie Advantages
✅ Fast prefix search
✅ Autocomplete
✅ Spell checking
❌ High space complexity

### Graph Advantages
✅ Model relationships
✅ Pathfinding
✅ Network analysis
❌ Complexity depends on structure

---

## 📝 Practice Problems

### Easy
1. Insert & search in BST
2. Build and traverse tree
3. Heap operations (push/pop)
4. Hash table lookup

### Medium
1. BST deletion
2. Validate BST
3. K-th largest element (heap)
4. Two sum (hashing)
5. Trie prefix search
6. Graph BFS/DFS

### Hard
1. Serialize/Deserialize tree
2. Balance BST
3. Median in data stream (heap)
4. LRU Cache (hash + linked list)
5. Word ladder (BFS)
6. Strongly connected components (DFS)

---

## 🚀 How to Run

```bash
# Compile
g++ -o 01_BST 01_BST_Insert_Search.cpp
g++ -o 02_Delete 02_BST_Delete.cpp
g++ -o 03_Validate 03_BST_Validate.cpp
g++ -o 04_Heap 04_Heap_Implementation.cpp
g++ -o 05_PQ 05_PriorityQueue_STL.cpp
g++ -o 06_Hash 06_Hashing_STL.cpp
g++ -o 07_Trie 07_Trie.cpp
g++ -o 08_Graph 08_Graph_BFS_DFS.cpp

# Run
./01_BST
./02_Delete
# ... and so on
```

---

## 📚 Reference Links

- BST: [GeeksforGeeks - BST](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
- Heaps: [GeeksforGeeks - Heaps](https://www.geeksforgeeks.org/heap-data-structure/)
- Hashing: [GeeksforGeeks - Hashing](https://www.geeksforgeeks.org/hashing-data-structure/)
- Tries: [GeeksforGeeks - Tries](https://www.geeksforgeeks.org/trie-insert-and-search/)
- Graphs: [GeeksforGeeks - Graphs](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)

---

## ✅ Checklist

- [x] Understand BST properties
- [x] Implement insert & search
- [x] Implement delete (all 3 cases)
- [x] Validate BST
- [x] Build heap from scratch
- [x] Learn heap operations
- [x] Use priority queue STL
- [x] Understand hashing
- [x] Use unordered_map & unordered_set
- [x] Implement Trie
- [x] Build graph with adjacency list
- [x] Implement BFS & DFS
- [x] Practice different problems
- [x] Analyze time/space complexity

---

## 🎓 Topics Completed

✅ Module 12: Backtracking, LinkedList & Stack
✅ Module 13: Queue, Greedy & Binary Trees
✅ Module 14: BST, Heaps, Hashing & Advanced DS

---

## 🎉 Congratulations!

You've completed **14 comprehensive modules** of SIGMA-9 CPP DSA course!

**Next:** Advanced topics like Dynamic Programming, Segment Trees, etc.

---

**Happy Learning! 🚀**

*Made with ❤️ for SIGMA-9 CPP DSA Course*
