#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
    vector<int> elements;  // Vector में elements store करेंगे
    
public:
    // Element को stack में add करो (PUSH)
    void push(int val) {
        elements.push_back(val);  // आखिर में add करो
        cout << val << " pushed to stack\n";
    }
    
    // Top element को remove करो (POP)
    void pop() {
        if (!isEmpty()) {
            cout << elements.back() << " popped from stack\n";
            elements.pop_back();  // आखिर से remove करो
        } else {
            cout << "Stack Underflow!\n";
        }
    }
    
    // Top element को देखो (PEEK)
    int peek() {
        if (!isEmpty()) {
            return elements.back();  // आखिरी element
        }
        return -1;  // Error
    }
    
    // Check करो stack empty है या नहीं
    bool isEmpty() {
        return elements.size() == 0;
    }
    
    // Stack size
    int size() {
        return elements.size();
    }
    
    // Stack को print करो (top से bottom तक)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (Top to Bottom): ";
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack st;
    
    // Elements add करो
    cout << "--- Pushing Elements ---\n";
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    cout << "\n--- Display Stack ---\n";
    st.display();  // 40 30 20 10
    
    cout << "\n--- Peek ---\n";
    cout << "Top element: " << st.peek() << "\n";  // 40
    
    cout << "\n--- Popping Elements ---\n";
    st.pop();  // Remove 40
    st.pop();  // Remove 30
    
    cout << "\n--- Display Stack After Pop ---\n";
    st.display();  // 20 10
    
    cout << "\nSize: " << st.size() << "\n";  // 2
    
    return 0;
}

/*
Output:
--- Pushing Elements ---
10 pushed to stack
20 pushed to stack
30 pushed to stack
40 pushed to stack

--- Display Stack ---
Stack (Top to Bottom): 40 30 20 10

--- Peek ---
Top element: 40

--- Popping Elements ---
40 popped from stack
30 popped from stack

--- Display Stack After Pop ---
Stack (Top to Bottom): 20 10

Size: 2

Stack Operations (LIFO - Last In First Out):
  - Push: O(1) - add element
  - Pop: O(1) - remove top element
  - Peek: O(1) - view top element
  - isEmpty: O(1) - check if empty

Space Complexity: O(n)
*/