#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int end;
    int index;
};

// Comparator - end time के हिसाब से sort करने के लिए
bool compare(Activity a, Activity b) {
    return a.end < b.end;  // कम end time पहले
}

// Activity selection करो
void selectActivities(vector<Activity>& activities) {
    int n = activities.size();
    
    // Step 1: End time के हिसाब से sort करो
    sort(activities.begin(), activities.end(), compare);
    
    cout << "Activities sorted by end time:\n";
    for (auto act : activities) {
        cout << "Activity " << act.index << ": (" 
             << act.start << ", " << act.end << ")\n";
    }
    cout << "\n";
    
    cout << "Selected Activities:\n";
    
    // Step 2: पहली activity select करो
    int lastEnd = activities[0].end;
    cout << "Activity " << activities[0].index << ": (" 
         << activities[0].start << ", " << activities[0].end << ")\n";
    int count = 1;
    
    // Step 3: अगली activities को check करो
    for (int i = 1; i < n; i++) {
        // अगर current activity पिछली से overlap नहीं करता
        if (activities[i].start >= lastEnd) {
            cout << "Activity " << activities[i].index << ": (" 
                 << activities[i].start << ", " << activities[i].end << ")\n";
            lastEnd = activities[i].end;
            count++;
        }
    }
    
    cout << "\nTotal Activities Selected: " << count << "\n";
}

int main() {
    vector<Activity> activities = {
        {1, 3, 1},
        {2, 5, 2},
        {3, 9, 3},
        {4, 6, 4},
        {6, 8, 5},
        {8, 10, 6}
    };
    
    cout << "--- Activity Selection Problem (Greedy) ---\n\n";
    cout << "Given Activities (start, end):\n";
    for (auto act : activities) {
        cout << "Activity " << act.index << ": (" 
             << act.start << ", " << act.end << ")\n";
    }
    cout << "\n";
    
    selectActivities(activities);
    
    return 0;
}

/*
Output:
--- Activity Selection Problem (Greedy) ---

Given Activities (start, end):
Activity 1: (1, 3)
Activity 2: (2, 5)
Activity 3: (3, 9)
Activity 4: (4, 6)
Activity 5: (6, 8)
Activity 6: (8, 10)

Activities sorted by end time:
Activity 1: (1, 3)
Activity 4: (4, 6)
Activity 5: (6, 8)
Activity 2: (2, 5)
Activity 3: (3, 9)
Activity 6: (8, 10)

Selected Activities:
Activity 1: (1, 3)
Activity 4: (4, 6)
Activity 5: (6, 8)
Activity 6: (8, 10)

Total Activities Selected: 4

Time Complexity: O(n log n) - sorting के लिए
Space Complexity: O(1) - कोई extra space नहीं
*/
