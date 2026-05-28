# Module 12: Backtracking, LinkedList & Stack

## Complete Learning Guide for SIGMA-9 CPP DSA

---

## 📚 Topics Covered

### Part 1: Backtracking
- [x] Introduction to Backtracking
- [x] How Backtracking Works (Memory Diagrams)
- [x] Find All Subsets
- [x] Find All Permutations

### Part 2: Linked List
- [x] Introduction to Linked List
- [x] Node Structure
- [x] Creating Linked List & Push Front
- [x] Push Back (Element को अंत में जोड़ो)
- [x] Reverse a Linked List (Iterative)
- [x] Detect Cycle in Linked List (Floyd's Algorithm)

### Part 3: Stack
- [x] Introduction to Stack (LIFO Principle)
- [x] Stack Implementation Using Vector
- [x] Reverse a String Using Stack
- [x] Valid Parentheses Problem

---

## 📁 File Structure

```
Module_12_Backtracking_LinkedList_Stack/
├── 01_Subsets.cpp                    (Find all subsets using backtracking)
├── 02_Permutations.cpp               (Find all permutations)
├── 03_LinkedList_Basics.cpp          (Push Front & Push Back)
├── 04_LinkedList_Reverse.cpp         (Reverse linked list iteratively)
├── 05_LinkedList_DetectCycle.cpp     (Floyd's Cycle Detection Algorithm)
├── 06_Stack_Using_Vector.cpp         (Stack implementation)
├── 07_ReverseString_Using_Stack.cpp  (Reverse string using stack)
├── 08_ValidParentheses.cpp           (Check valid parentheses)
└── README.md                         (This file)
```

---

## 🎯 Quick Reference

### Time & Space Complexity

| Topic | Time Complexity | Space Complexity | Key Learning |
|-------|-----------------|------------------|---------------|
| Subsets | O(2^n) | O(n) | Include/Exclude choices |
| Permutations | O(n! × n) | O(n) | Swap & Backtrack |
| LinkedList Basics | O(1)/O(n) | O(1) | Node structure |
| Reverse LL | O(n) | O(1) | Three pointers |
| Cycle Detection | O(n) | O(1) | Floyd's Algorithm |
| Stack Operations | O(1) | O(n) | LIFO principle |
| Valid Parentheses | O(n) | O(n) | Stack matching |

---

## 🔍 Detailed Explanations

### 1️⃣ Backtracking - Find Subsets

**Algorithm:**
```cpp
void findSubsets(vector<int>& arr, int index, vector<int>& current) {
    if (index == arr.size()) {
        print current;  // Found one subset
        return;
    }
    
    // Choice 1: Include current element
    current.push_back(arr[index]);
    findSubsets(arr, index + 1, current);
    current.pop_back();  // BACKTRACK
    
    // Choice 2: Exclude current element
    findSubsets(arr, index + 1, current);
}
```

**Example:**
```
Input: [1, 2, 3]
Output:
{}
{1}
{1, 2}
{1, 2, 3}
{1, 3}
{2}
{2, 3}
{3}
```

---

### 2️⃣ Linked List - Reverse

**Algorithm:**
```cpp
void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;       // Save next
        curr->next = prev;       // Reverse the link
        prev = curr;             // Move prev forward
        curr = next;             // Move curr forward
    }
    
    head = prev;  // Update head
}
```

**Visual:**
```
Before: 1 → 2 → 3 → NULL
After:  3 → 2 → 1 → NULL

Step by step:
Step 1: NULL ← 1   2 → 3 → NULL
Step 2: NULL ← 1 ← 2   3 → NULL
Step 3: NULL ← 1 ← 2 ← 3   NULL
```

---

### 3️⃣ Cycle Detection - Floyd's Algorithm

**Algorithm:**
```cpp
bool hasCycle() {
    Node* slow = head;   // 1 step
    Node* fast = head;   // 2 steps
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;  // Cycle found!
        }
    }
    
    return false;  // No cycle
}
```

**Why it works:**
- अगर cycle है, तो fast pointer slow को catch करेगा
- अगर cycle नहीं है, तो fast pointer NULL पर पहुंचेगा

---

### 4️⃣ Stack - Valid Parentheses

**Algorithm:**
```cpp
bool isValid(string str) {
    stack<char> st;
    
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty() || !matches(st.top(), c)) {
                return false;
            }
            st.pop();
        }
    }
    
    return st.empty();
}
```

**Examples:**
```
"()" → Valid ✅
"([{}])" → Valid ✅
"([)]" → Invalid ❌
```

---

## 💡 Key Concepts

### Backtracking
- **What:** Solve problems by trying all possibilities
- **When:** Use when you need to find all solutions
- **How:** Explore → Backtrack if invalid

### Linked List
- **Advantages:** Dynamic size, efficient insertion/deletion
- **Disadvantages:** No random access, extra memory for pointers
- **Use:** When you need frequent insertions/deletions

### Stack
- **LIFO:** Last In, First Out
- **Real-world:** Browser history, undo functionality, function call stack
- **Operations:** Push, Pop, Peek all O(1)

---

## 👨‍🎓 Learning Tips

1. **Dry Run करो:** हर algorithm को manually trace करो
2. **Visualize करो:** Memory diagrams बनाओ
3. **Code करो:** सभी code examples को खुद से implement करो
4. **Practice करो:** अलग-अलग inputs के साथ test करो
5. **Optimize करो:** Time और space complexity को improve करने की कोशिश करो

---

## 📝 Practice Problems

### Easy
1. Print all subsets of an array
2. Reverse a string using stack
3. Check valid parentheses

### Medium
1. Find all permutations
2. Reverse a linked list
3. Next greater element using stack

### Hard
1. N-Queens problem
2. Detect and remove cycle in linked list
3. Largest rectangle in histogram

---

## 🚀 How to Run

```bash
# Compile
g++ -o 01_Subsets 01_Subsets.cpp
g++ -o 02_Permutations 02_Permutations.cpp
# ... and so on

# Run
./01_Subsets
./02_Permutations
# ... and so on
```

---

## 📖 Reference Links

- Backtracking: [InterviewBit - Backtracking](https://www.interviewbit.com/courses/programming/topics/backtracking/)
- Linked List: [GeeksforGeeks - Linked List](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)
- Stack: [GeeksforGeeks - Stack](https://www.geeksforgeeks.org/stack-data-structure/)

---

## ✅ Checklist

- [x] Understand backtracking concept
- [x] Implement subsets and permutations
- [x] Master linked list operations
- [x] Learn cycle detection
- [x] Implement stack from scratch
- [x] Solve valid parentheses problem
- [x] Practice with different inputs
- [x] Understand time/space complexity

---

## 🎉 Next Steps

👉 Move to **Module 13: Queue, Greedy & Binary Trees**

---

**Happy Learning! 🚀**

*Made with ❤️ for SIGMA-9 CPP DSA Course*
