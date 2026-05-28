#include<bits/stdc++.h>
using namespace std;

// Function to find all permutations
void findPermutations(vector<int>& arr, int index, vector<vector<int>>& result) {
    
    // Base Case: अगर सभी elements fixed हो गए
    if (index == arr.size()) {
        result.push_back(arr);  // Current arrangement को save करो
        return;
    }
    
    // हर position पर सभी unused numbers को try करो
    for (int i = index; i < arr.size(); i++) {
        
        // Swap: arr[index] को arr[i] से बदलो
        swap(arr[index], arr[i]);
        
        // Recursively बाकी elements को arrange करो
        findPermutations(arr, index + 1, result);
        
        // ⚠️ BACKTRACK: Swap को undo करो
        swap(arr[index], arr[i]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    
    findPermutations(arr, 0, result);
    
    cout << "All Permutations:\n";
    for (auto perm : result) {
        cout << "{ ";
        for (auto num : perm) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    
    return 0;
}

/*
Output:
All Permutations:
{ 1 2 3 }
{ 1 3 2 }
{ 2 1 3 }
{ 2 3 1 }
{ 3 2 1 }
{ 3 1 2 }

Time Complexity: O(n! × n)
Space Complexity: O(n)
*/