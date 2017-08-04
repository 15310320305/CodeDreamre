#include<bits/stdc++.h>
using namespace std;
struct st
{
    long long r,e,l;
    bool operator<(const st&a)const
    {
        return a.e>e;
    }
}s[100005];
int n;
int main()
{
    int t;
    cin>>t;
    for(int T=1;T<=t;T++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&s[i].r,&s[i].e,&s[i].l);
        }
        sort(s,s+n);
        long long l = 0;
        int flag = 1;
        for(int i=0;i<n;i++)
        {
            l+=(s[i].r);
            if(l>s[i].e)
            {
                flag = 0;
                break;
            }
            l+=s[i].l;
        }
        printf("Case #%d: ",T);
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
