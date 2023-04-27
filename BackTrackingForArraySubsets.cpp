#include <bits/stdc++.h>

using namespace std;

vector<int> cfg;

void process(const vector<int>& cfg) {
    for(auto x:cfg) cout << x << "";
    cout << endl;
}

void bt(int idx, const vector<int>& arr) {
    int n = arr.size();
    if (idx == n) {
        process(cfg);
        return;
    }

    cfg.push_back(arr[idx]);
    bt(idx+1, arr);

    cfg.pop_back();
    bt(idx+1, arr);
}

int main() {
    vector<int> arr = {1,2,3};

    bt(0, arr);
    return 0;
}