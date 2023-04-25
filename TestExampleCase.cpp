#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// our configuration
vector<int> cfg;
 
// Process with current configuration
void process_config() {
    for (auto e : cfg) {
        cout << e << " ";
    }
    cout << endl;
}
 
// Backtracking function using recursive technique
// Purpose:
// - Need to get a value for configuration at position "index"
// - Try to do the function again in the next index
void backtrack(int index, const vector<int>& arr) {
    int len = arr.size();
    if (index == len) {
        // got a configuration, so process it
        process_config();
        return;
    }
 
    // Consider what value should be chose next
    for (auto consider_value : arr) {
        bool canUse = true;
        for (auto existed_value : cfg) {
            if (consider_value == existed_value) canUse = false;
        }
        if (canUse) {
            cfg.push_back(consider_value);
            backtrack(index + 1, arr);
            cfg.pop_back();
        }
    }
}
 
 
int main() {
    vector<int> arr = {1, 2, 3};
    backtrack(0, arr);
    return 0;
}