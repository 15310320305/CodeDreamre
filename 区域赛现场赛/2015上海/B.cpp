#include<bits/stdc++.h>

using namespace std;

long long num[64];
int main()
{
    num[0] = 1;
    for(int i=1;i<=60;i++)
        num[i] = num[i-1]*2ll;
    int t;cin>>t;int T = 1;
    while(t--)
    {
        long long n,k;scanf("%lld%lld",&n,&k);
        long long nn = num[k]-n;
        long long flag = nn%2ll;
        nn/=2ll;
        long long f[64],cnt = 0;
        memset(f,0,sizeof(f));
        while(nn)
        {
            f[cnt++] = nn%2ll;
            nn/=2ll;
        }
        long long ans = 1;
        printf("Case #%d:\n",T++);
        for(int i=0;i<k;i++)
        {
            if(i==k-1)
            {
                if(!flag)ans++;
                printf("%lld +\n",ans);
            }
            else
            {
                printf("%lld ",ans);
                if(f[i])printf("-\n");
                else printf("+\n");
                ans*=2;
            }

        }

    }
    return 0;
}
