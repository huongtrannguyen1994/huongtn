#include <bits/stdc++.h>

using namespace std;

// void checkConfigIsCorrect(string& s) {
//     int open = 0, end = 0;
//     if (s[0] != '(') return;
//     for(auto ch : s) {
//         if (ch == '(') {
//             ++open;
//         } else if (ch == ')') {
//             ++end;
//         }
//         if (open < end) return;
//     }
//     if(open == end) cout << s << " ";
// }

void test_script() {
    int n;
    cin >> n;
    string s = "";
    for(int i = 0; i<n; ++i){
        s += "112";
    }
//    cout << next_permutation(s.begin(), s.end()) << endl;
//    cout << s;
    do {
        cout << s << endl;
        // checkConfigIsCorrect(s);
    }while(next_permutation(s.begin(), s.end()));
    // s = "";
    // for(int i = 0; i<n; ++i){
    //     s += ")(";
    // }
    // do {
    //     // cout << s << endl;
    //     checkConfigIsCorrect(s);
    // }while(next_permutation(s.begin(), s.end()));
}

int main() {
    test_script();
    return 0;
}