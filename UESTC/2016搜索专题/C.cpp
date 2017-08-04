#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n;
long long tot;
long long check(int mid)
{
    long long ans = 0;
    for(int i=0;i<n-1;i++)
    {
        int x ;
        if(mid+a[i]<=a[n-1])x=lower_bound(a+i,a+n,a[i]+mid)-a;
        else x = n;
        ans+=(long long)n-x;
    }
    return ans;

}

int main()
{
    while(~scanf("%d",&n))
    {
        tot = (long long)n*(n-1ll)/2ll;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        if(tot%2)tot = (tot+1)/2ll;
        else tot = tot/2ll+1ll;
        sort(a,a+n);
        int ans1=-1;
        long long l =0,r = 2e9,mid;
        while(l<=r)
        {
            mid = (l+r)/2ll;
            long long ans =check((int)mid);
            if(ans<tot)
            {
                r = mid-1;
            }
            else
            {
                 ans = check((int)mid+1);
                 if(ans<tot)
                 {
                     ans1 = mid;
                     break;
                 }
                 else
                 {
                     l = mid+1;
                 }

            }
        }
        printf("%d\n",ans1);
    }


    return 0;
}
