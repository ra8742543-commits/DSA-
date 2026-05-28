#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Unordered Map (Hash Table) ---\n\n";
    
    unordered_map<string, int> freq;
    
    // Insert
    cout << "Inserting elements:\n";
    freq["apple"] = 5;
    freq["banana"] = 3;
    freq["orange"] = 7;
    freq["apple"] = 6;  // Update
    
    cout << "apple -> 5, updated to 6\n";
    cout << "banana -> 3\n";
    cout << "orange -> 7\n\n";
    
    // Access
    cout << "Accessing elements:\n";
    cout << "freq[\"apple\"] = " << freq["apple"] << "\n";
    cout << "freq[\"banana\"] = " << freq["banana"] << "\n\n";
    
    // Iteration
    cout << "All elements:\n";
    for (auto& pair : freq) {
        cout << pair.first << " -> " << pair.second << "\n";
    }
    
    // Check if key exists
    cout << "\nKey exists?\n";
    cout << "apple: " << (freq.find("apple") != freq.end() ? "YES" : "NO") << "\n";
    cout << "grape: " << (freq.find("grape") != freq.end() ? "YES" : "NO") << "\n";
    
    // Size
    cout << "\nSize: " << freq.size() << "\n";
    
    // Delete
    cout << "\nDeleting 'banana'\n";
    freq.erase("banana");
    cout << "Size: " << freq.size() << "\n\n";
    
    cout << "--- Unordered Set ---\n\n";
    
    unordered_set<int> nums = {10, 20, 30, 20, 10};
    
    cout << "Set elements (no duplicates):\n";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
Output:
--- Unordered Map (Hash Table) ---

Inserting elements:
apple -> 5, updated to 6
banana -> 3
orange -> 7

Accessing elements:
freq["apple"] = 6
freq["banana"] = 3

All elements:
apple -> 6
banana -> 3
orange -> 7

Key exists?
apple: YES
grape: NO

Size: 3

Deleting 'banana'
Size: 2

--- Unordered Set ---

Set elements (no duplicates):
30 10 20

STL Hashing Methods:
  - insert/[]: O(1) average
  - erase: O(1) average
  - find: O(1) average
  - size: O(1)
  - empty: O(1)

Unordered Map vs Map:
  - unordered_map: O(1) avg, O(n) worst (hash collisions)
  - map: O(log n) (balanced BST)
*/
