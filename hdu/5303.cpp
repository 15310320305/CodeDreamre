#include<bits/stdc++.h>
using namespace std;
int n,l,k;
struct st
{
    int x,a;
    bool operator <(const st& a)const
    {
        return a.x>x;
    }
}s[100005];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long ans = 0;
        int cnt = 0;
        scanf("%d%d%d",&l,&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&s[i].x,&s[i].a);
        }
        sort(s,s+n);
        cnt = k;
        int now = 0;
        for(int i=0;i<n;i++)
        {
            while(s[i].a)
            {
                if(abs(s[i].x-now)<=abs(now+l-s[i].x))
                {
                    if(cnt>=s[i].a%k)
                    {
                        ans+=(long long)s[i].x - now;
                        int xx = cnt;
                        cnt-=min(cnt,s[i].a);
                        s[i].a-=min(s[i].a,xx);
                        now = s[i].x;
                    }
                    else
                    {
                        ans+=(long long)now;
                        now = 0;
                        cnt = k;
                    }
                }
                else
                {
                    int xx = cnt;
                    ans+=(long long)abs(now+l-s[i].x);
                    cnt = k;
                    cnt-=min(cnt,s[i].a);
                    s[i].a-=min(s[i].a,xx);
                    now = s[i].x;
                }
                if(cnt==0)
                {
                    ans+=(long long)min(now,l-now);
                    cnt = k;
                    now = 0;
                }
            }
        }
        if(now)
        {
            ans+=(long long)min(now,l-now);
        }
        printf("%lld\n",ans);

    }

    return 0;
}
