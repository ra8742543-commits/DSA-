#include<bits/stdc++.h>
using namespace std;

// Check करो parentheses valid हैं या नहीं
bool isValidParentheses(string str) {
    stack<char> st;
    
    for (char c : str) {
        
        // अगर opening bracket है तो push करो
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        
        // अगर closing bracket है
        else if (c == ')' || c == ']' || c == '}') {
            
            // Stack empty तो invalid
            if (st.empty()) {
                return false;
            }
            
            char top = st.top();
            st.pop();
            
            // Check करो matching है या नहीं
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    // अंत में stack empty होना चाहिए
    return st.empty();
}

int main() {
    vector<string> testCases = {
        "()",
        "(())",
        "([{}])",
        "(]",
        "([)]",
        "{[]}",
        "((()))",
        "([{"
    };
    
    cout << "--- Valid Parentheses Checker ---\n\n";
    
    for (string test : testCases) {
        bool valid = isValidParentheses(test);
        cout << test << " → " << (valid ? "Valid ✅" : "Invalid ❌") << "\n";
    }
    
    return 0;
}

/*
Output:
--- Valid Parentheses Checker ---

() → Valid ✅
(()) → Valid ✅
([{}]) → Valid ✅
(] → Invalid ❌
([)] → Invalid ❌
{[]} → Valid ✅
((()) → Invalid ❌
([{ → Invalid ❌

Algorithm Logic:
  1. हर opening bracket को stack में push करो
  2. हर closing bracket के लिए:
     - अगर stack empty है: Invalid
     - अगर top से match नहीं करता: Invalid
     - अगर match करता है: pop करो
  3. अंत में अगर stack empty है: Valid

Example: "([)]"
  '(' → push, stack: [(]
  '[' → push, stack: [([]
  ')' → top='[', doesn't match ')' → Invalid ❌

Example: "([])"
  '(' → push, stack: [(]
  '[' → push, stack: [([]
  ']' → top='[', matches → pop, stack: [(
  ')' → top='(', matches → pop, stack: []
  Valid ✅

Time Complexity: O(n)
Space Complexity: O(n)
*/