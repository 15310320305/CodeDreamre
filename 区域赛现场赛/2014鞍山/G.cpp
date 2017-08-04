#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;scanf("%d",&n);
        double a[1005],x[1005],y[1005],ans = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&a[i],&x[i],&y[i]);
            if(i)ans=max(ans,sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]))/(a[i]-a[i-1]));
        }
        printf("%.9lf\n",ans);
    }
    return 0;
}
