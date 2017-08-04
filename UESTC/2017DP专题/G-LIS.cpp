#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int b[1005],len = 0;
        int dp[1005];
        int dd[1005];
        int a[1005];
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            a[i] = x;
            if(i==0)b[len++] = x,dp[len-1] = i,dd[i] =-1;
            else if(x>b[len-1])b[len++] = x,dp[len-1] = i,dd[i] = dp[len-2];
            else
            {
                int xx = lower_bound(b,b+len,x)-b;
                b[xx] = x;
                dd[i] = dp[xx-1];
                dp[xx] = i;
            }
        }
        printf("%d",len);
        int u = dp[len-1];
        int x = 0;
        while(u!=-1)
        {
            b[x++] = a[u];
            u = dd[u];
        }
        for(int i=len-1;i>=0;i--)
            printf(" %d",b[i]);

        printf(" \n");
    }
    return 0;
}
