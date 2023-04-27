#include <bits/stdc++.h>

using namespace std;
vector<int> cfg;

void process(const vector<int>& cfg) {
    for(auto x:cfg) cout << x << "";
    cout << endl;
}
void bt(int idx, const vector<int>& arr) {
    int n = arr.size();

    if (idx == 2) {
        process(cfg);
        return;
    }

    for (int i = 0; i < n; ++i) {
        // verify idx position isn't present in arr
        bool checking = true;
        for (int j = 0; j < cfg.size(); ++j) {
            if (cfg[j] == arr[i]) {
                checking = false;
                break;
            }
            // if (abs(cfg[j] - arr[i]) == (j+1)) {
            //     checking = false;
            //     break;
            // }
        }
        if (checking == false) continue;
        cfg.push_back(arr[i]);
        bt(idx+1, arr);
        cfg.pop_back();
    }
}
int main() {
    vector<int> arr = {1,2,3,4};

    bt(0, arr);
    return 0;
}