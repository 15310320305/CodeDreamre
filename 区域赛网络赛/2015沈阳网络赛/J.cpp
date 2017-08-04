#include<bits/stdc++.h>
using namespace std;
#define mod 530600414
const int maxn = 211314;
long long lengh[maxn],cnt[maxn],ans[maxn],sum[maxn];
int n;

void init()
{
    ans[3] = ans[4] = 0;
    lengh[3] = 3,lengh[4] = 5;
    cnt[3] = cnt[4] = 1;
    sum[3] =1, sum[4] = 3;
    for(int i=5;i<=201314;i++)
    {
        cnt[i] = (cnt[i-1]+cnt[i-2])%mod;
        lengh[i] = (lengh[i-1]+lengh[i-2])%mod;
        sum[i] = (sum[i-2] +sum[i-1]+cnt[i-1]*lengh[i-2])%mod;
        ans[i] = (ans[i-1]+ans[i-2]+sum[i-1]*cnt[i-2]+(lengh[i-2]*cnt[i-2]-sum[i-2]+mod)%mod*cnt[i-1])%mod;
    }
}

int main()
{
    int T;scanf("%d",&T);
    init();
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        printf("Case #%d: %lld\n",t,ans[n]);
    }
    return 0;
}
