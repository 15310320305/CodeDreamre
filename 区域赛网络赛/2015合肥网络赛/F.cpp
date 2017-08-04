#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int n,l;
int b[maxn],cnt[maxn];
int a[maxn];

int main()
{
    int T = 1;
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int len = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)b[len++] = -a[i],cnt[i] = len;
            else if(-a[i]>b[len-1])b[len++]=-a[i],cnt[i] = len;
            {
                int x = lower_bound(b,b+len,-a[i])-b;
                cnt[i] = x+1;
                b[x] = -a[i];
            }
        }

        int ans = 0;
        len = 0;
        for(int i=l;i<n;i++)
        {
            if(i==l)
            {
                ans = cnt[i];
                b[len++] = a[i-l];
            }
            else
            {
                int x = lower_bound(b,b+len,a[i])-b;
                ans = max(ans,x+cnt[i]);
                if(a[i-l]>b[len-1])b[len++] = a[i-l];
                else
                {
                    int x = lower_bound(b,b+len,a[i-l])-b;
                    b[x] = a[i-l];
                }
            }
        }
        ans = max(ans,len);
        printf("Case #%d: %d\n",T++,ans);
    }
    return 0;
}
