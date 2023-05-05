#include <bits/stdc++.h>
 
using namespace std;
 
 

bool comp(int a, int b)
{
    return a > b;	
}

int main()
{
    int a[] = {40, 30, 20, 20, 50, 40, 30, 20, 10};
    vector < int > v(a, a + 9);
	
    // a = {10, 10, 20, 20, 30, 30, 40, 40, 50}
    sort(a, a + 9);
	
    // Tìm vị trí của phần tử đầu tiên lớn hơn 30 trong mảng a.
    // Muốn đưa ra vị trí là số nguyên thì lấy kết quả hàm trừ đi iterator a[0].
    int pos1 = lower_bound(a, a + 9, 30) - a;
    cout << "Vị trí đầu tiên lớn hơn 30 là: " << pos1 << endl;

    // v = {50, 40, 40, 30, 30, 20, 20, 10, 10};
    sort(v.begin(), v.end(), comp);
    
    // Tìm vị trí đầu tiên nhỏ hơn hơn 50 trong đoạn [0, 5] của vector v.
    // Tương tự, lấy hai iterator trừ cho nhau để ra được vị trí là số nguyên.
    int pos2 = lower_bound(v.begin(), v.end(), 50) - v.begin();
    cout << "Vị trí đầu tiên nhỏ hơn 50 là: " << pos2;
	
    return 0;
}