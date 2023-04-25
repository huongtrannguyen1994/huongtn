 #include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
    void solve()
    {
      int n;
      cin>>n;
      vector<int>a(n+1);
        vector<int> b;
      for(int i=1;i<=n;i++)
      {
        cin>>a[i];
        if(a[i]<i)
        {
            b.push_back(i);
        }
      }
    //   debug(b);
     int result=0;
     for(int i=1;i<=n;i++)
     {
        if(a[i]>=i) continue;
        int pos = lower_bound(b.begin(),b.end(),a[i])-b.begin();
        result+=pos;
     }
      cout<<result<<endl;
    }
 
 
            int32_t main()
            {
                int t;
                cin>>t;
                while(t--)
                {
                    solve();
                }
                
                return 0;
            }