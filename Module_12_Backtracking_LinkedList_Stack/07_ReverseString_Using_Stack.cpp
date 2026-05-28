#include<bits/stdc++.h>
using namespace std;

// String को reverse करो using Stack
string reverseString(string str) {
    stack<char> st;  // Character stack
    
    // Step 1: सभी characters को stack में push करो
    for (char c : str) {
        st.push(c);
    }
    
    // Step 2: सभी को pop करके reversed string बनाओ
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();   // Top element लो
        st.pop();               // Remove करो
    }
    
    return reversed;
}

int main() {
    string str1 = "hello";
    string str2 = "PROGRAMMING";
    string str3 = "12345";
    
    cout << "--- String Reversal Using Stack ---\n\n";
    
    cout << "Original: " << str1 << "\n";
    cout << "Reversed: " << reverseString(str1) << "\n\n";
    
    cout << "Original: " << str2 << "\n";
    cout << "Reversed: " << reverseString(str2) << "\n\n";
    
    cout << "Original: " << str3 << "\n";
    cout << "Reversed: " << reverseString(str3) << "\n";
    
    return 0;
}

/*
Output:
--- String Reversal Using Stack ---

Original: hello
Reversed: olleh

Original: PROGRAMMING
Reversed: GNIMMARGORP

Original: 12345
Reversed: 54321

Algorithm:
  1. सभी characters को stack में push करो
  2. सभी को pop करके नई string में add करो
  3. String reverse हो जाएगी

Example: "hello"
  Push: h, e, l, l, o
  Stack: [o, l, l, e, h]
  Pop: o, l, l, e, h
  Result: "olleh"

Time Complexity: O(n)
Space Complexity: O(n)
*/