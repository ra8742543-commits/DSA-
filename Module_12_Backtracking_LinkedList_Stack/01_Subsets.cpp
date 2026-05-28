#include<bits/stdc++.h>
using namespace std;

// Function to find all subsets using backtracking
void findSubsets(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
    
    // Base Case: अगर सभी elements process हो गए
    if (index == arr.size()) {
        // Current subset को result में add करो
        result.push_back(current);
        return;
    }
    
    // Choice 1: Current element को INCLUDE करो
    current.push_back(arr[index]);          // Element add करो
    findSubsets(arr, index + 1, current, result);  // आगे बढ़ो
    current.pop_back();                     // ⚠️ BACKTRACK: Remove करो
    
    // Choice 2: Current element को EXCLUDE करो
    findSubsets(arr, index + 1, current, result);  // Direct आगे बढ़ो
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> current;
    
    findSubsets(arr, 0, current, result);
    
    // सभी subsets print करो
    cout << "All Subsets:\n";
    for (auto subset : result) {
        cout << "{ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    
    return 0;
}

/*
Output:
All Subsets:
{ }
{ 1 }
{ 1 2 }
{ 1 2 3 }
{ 1 3 }
{ 2 }
{ 2 3 }
{ 3 }

Time Complexity: O(2^n)
Space Complexity: O(n)
*/