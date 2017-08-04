#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long a[10000];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lld",&a[i]),a[i]++;
        sort(a,a+n);
        long long ans =0;
        if(n==1)printf("1\n");
        else
        {
            ans = 0;
            for(int i=0;i<n-1;i++)
            {
                long long sum = min(a[i],a[i+1]);
                for(int j=0;j<n;j++)
                {
                    if(j==i||j==i+1)continue;
                    sum*=a[j];
                    sum%=mod;
                }
                ans = max(ans,sum);
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}
