#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        s += s;
        int ans = 0, i = 0;
        while(i < n) {
            if(s[i] == c) {
                int pos = find(s.begin()+i, s.end(), 'g') - s.begin();
                int maxL = pos - i;
                ans = max(ans, maxL);
                i = pos+1;
            } else i++;
        }
        cout << ans << endl;
    }
    return 0;
}