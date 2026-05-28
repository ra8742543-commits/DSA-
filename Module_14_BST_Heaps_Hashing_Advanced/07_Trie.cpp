#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert word in trie
    void insert(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            // अगर character नहीं है, create करो
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        
        node->isEndOfWord = true;
        cout << "Inserted: " << word << "\n";
    }
    
    // Search word in trie
    bool search(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Character नहीं मिला
            }
            node = node->children[c];
        }
        
        return node->isEndOfWord;  // Word complete होना चाहिए
    }
    
    // Check if word starts with prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        
        return true;  // Prefix मिल गया
    }
};

int main() {
    Trie trie;
    
    cout << "--- Inserting Words ---\n\n";
    vector<string> words = {"apple", "app", "apricot", "banana", "band"};
    
    for (string word : words) {
        trie.insert(word);
    }
    
    cout << "\n--- Searching Words ---\n\n";
    vector<string> searchWords = {"app", "apple", "appl", "banana", "bat"};
    
    for (string word : searchWords) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "Found ✅" : "Not Found ❌") << "\n";
    }
    
    cout << "\n--- Prefix Search ---\n\n";
    vector<string> prefixes = {"ap", "ban", "cat", "app"};
    
    for (string prefix : prefixes) {
        bool found = trie.startsWith(prefix);
        cout << "Prefix '" << prefix << "': " << (found ? "Found ✅" : "Not Found ❌") << "\n";
    }
    
    return 0;
}

/*
Output:
--- Inserting Words ---

Inserted: apple
Inserted: app
Inserted: apricot
Inserted: banana
Inserted: band

--- Searching Words ---

Search 'app': Found ✅
Search 'apple': Found ✅
Search 'appl': Not Found ❌
Search 'banana': Found ✅
Search 'bat': Not Found ❌

--- Prefix Search ---

Prefix 'ap': Found ✅
Prefix 'ban': Found ✅
Prefix 'cat': Not Found ❌
Prefix 'app': Found ✅

Trie Structure:
        root
       / | \
      a  b  c
      |  |
      p  a
     /|\  |
    p r i n
    |   |  |
   l   c  a
   |   |  |
   e   o  n
       |  | \
       t  d  a

Time Complexity:
  - Insert: O(m) - m = word length
  - Search: O(m)
  - startsWith: O(m)

Space Complexity: O(ALPHABET_SIZE * N)
  - N = total number of nodes
*/
