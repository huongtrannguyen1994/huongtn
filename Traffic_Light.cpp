#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i=0; i<n; ++i)
#define ll long long

int caculator(const string& s,int n, const char c) {
    int p = 0, maxx = 0;
    while (p < n) {
        p = s.find(c, p) ;
       int b = s.find('g', p);
        // if (count_c != string::npos) {
        //     count_g = s.find('g', count_c);
        //     maxx = max(maxx, count_g - count_c);
        // }
        if (maxx < b - p) {
            maxx = b - p;
        }
        p = b + 1;
        cout << b << " " << p  << " "; 
    }
    return maxx;
}

void test_script() {
    int n;
    char c;
    string s;
    cin >> n >> c;
    cin >> s;
    s += s;
    cout << caculator(s, n, c) << endl;
}

int main() {
    int t;
    cin >> t;
    forn(i, t) {
        test_script();
    }
    return 0;
}