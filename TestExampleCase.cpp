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

int N = 5;
vector<int> A = {1, 3, 5, 7, 9};

void Solve(){
    int value, cnt=0, from=0;
    cout << N << endl;
    value = A[from];
    while (cnt < N){
        while (value == 0){
            cout <<" 1: " << from << " ";
            from = (from + 1) % N;
            value = A[from];
        }
        cout << from << "," << value << " ";
        cnt++;
        A[from] = 0;
        from = (value + from) % N;
        value = A[from];
        cout << from << "," << value << endl;
    }
    // cout << from << "," << value << endl;
}

 
int main() {
    Solve();
    return 0;
}