#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int m;
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            int x = 0;
           for(int j=i;j<=n;j++)
           {
               x|=a[j];
               if(x<m)
               {
                   ans++;
               }
               else break;
           }
        }
        printf("Case #%d: %d\n",T++,ans);
    }

    return 0;
}
