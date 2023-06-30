#include <bits/stdc++.h>

using namespace std;

int longestMountain(vector<int>& arr) {
    int ans = 0;
    int n = arr.size();
    int left[n], right[n];
    left[0] = 0;
    right[n-1] = 0;

    for(int i=1; i<n; ++i) {
        if(arr[i] <= arr[i-1]) left[i] = 0;
        else left[i] = left[i-1] + 1;
    }

    for(int i=n-2; i>=0; --i) {
        if(arr[i] <= arr[i+1]) right[i] = 0;
        else right[i] = right[i+1] + 1;
    }

    for(int i=0; i<n-1; ++i) {
        if(left[i] > 0 && right[i] > 0) ans = max((left[i]+right[i]+1),ans);
    }
    return ans;
        
}

int main() {
    vector<int> arr = {2,1,4,7,3,2,5};
    cout << longestMountain(arr);
    return 0;

}