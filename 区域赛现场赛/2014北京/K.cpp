#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        int n;scanf("%d",&n);
        int ans = 0;
        int Max = 1000000000;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>Max)ans++;
            Max = min(Max,a[i]);
        }
        printf("Case #%d: ",T++);
        cout<<ans<<endl;
    }
    return 0;
}
