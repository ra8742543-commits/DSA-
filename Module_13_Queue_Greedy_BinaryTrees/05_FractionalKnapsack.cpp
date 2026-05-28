#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
    int index;
    
    // Profit density को access करने के लिए
    double getProfitDensity() {
        return (double)value / weight;
    }
};

// Comparator - profit density के हिसाब से sort
bool compare(Item a, Item b) {
    return a.getProfitDensity() > b.getProfitDensity();
}

// Fractional Knapsack solve करो
double fractionalKnapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    
    // Step 1: Profit density के हिसाब से sort करो
    sort(items.begin(), items.end(), compare);
    
    cout << "Items sorted by profit density:\n";
    for (auto item : items) {
        cout << "Item " << item.index << ": weight=" << item.weight 
             << ", value=" << item.value 
             << ", density=" << item.getProfitDensity() << "\n";
    }
    cout << "\n";
    
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    
    cout << "Adding items to knapsack (capacity=" << capacity << "):\n";
    
    // Step 2: Profit density के हिसाब से items लो
    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        // अगर पूरा item fit हो जाता है
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
            cout << "Item " << items[i].index << ": Added completely (weight=" 
                 << items[i].weight << ", value=" << items[i].value << ")\n";
        } 
        // अगर सिर्फ fraction fit हो सकता है
        else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << "Item " << items[i].index << ": Added fraction " << fraction 
                 << " (weight=" << remainingCapacity 
                 << ", value=" << items[i].value * fraction << ")\n";
            remainingCapacity = 0;
        }
    }
    
    return totalValue;
}

int main() {
    vector<Item> items = {
        {10, 60, 1},
        {20, 100, 2},
        {30, 120, 3}
    };
    
    int capacity = 50;
    
    cout << "--- Fractional Knapsack Problem (Greedy) ---\n\n";
    
    double maxValue = fractionalKnapsack(items, capacity);
    
    cout << "\nMaximum value: " << maxValue << "\n";
    
    return 0;
}

/*
Output:
--- Fractional Knapsack Problem (Greedy) ---

Items sorted by profit density:
Item 1: weight=10, value=60, density=6
Item 2: weight=20, value=100, density=5
Item 3: weight=30, value=120, density=4

Adding items to knapsack (capacity=50):
Item 1: Added completely (weight=10, value=60)
Item 2: Added completely (weight=20, value=100)
Item 3: Added fraction 0.666667 (weight=20, value=80)

Maximum value: 240

Time Complexity: O(n log n) - sorting
Space Complexity: O(1)
*/
