#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		char c;
		cin >> n >> c;
		
		string s;
		cin >> s;
		s += s;
		int max = 0, p = 0;
		while(p < n)
		{
			p = s.find(c,p);
			int b = s.find('g',p);
			if(max < b - p)
			{
				max = b - p;
			}
			p = b + 1;
		}
		cout << max << "\n";
	}
 
    return 0;
}