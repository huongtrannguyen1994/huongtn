#include <bits/stdc++.h>

using namespace std;

void test_script() {
    int n;
    cin >> n;
    int l = 0, r = n-1;
    string s;
    cin >> s;
    while (l <= r) {
        if (s[l] == s[r]) {
            break;
        }
        ++l;
        --r;
    }
    if (r >= l) {
        cout << r-l+1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        test_script();
    }
    return 0;
}