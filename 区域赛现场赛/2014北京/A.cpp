#include<bits/stdc++.h>
using namespace std;
struct st
{
    double x,y;
}s[10005];
bool cmp(st a,st b)
{
    return a.x<b.x;
}
int n;
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&s[i].x,&s[i].y);
        sort(s,s+n,cmp);
        double Max = 0;
        for(int i=1;i<n;i++)
        {
            Max = max(Max,fabs((s[i].y-s[i-1].y)/(s[i].x-s[i-1].x)));
        }
        printf("Case #%d: %.2lf\n",T++,Max);
    }
    return 0;
}
