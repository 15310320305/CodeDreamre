#include<bits/stdc++.h>

using namespace std;

int n;
int s[13];
double dp[4096];
double f[1728];
int st[1728];
int cnt;

int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(s[i]+s[j]>s[k]&&abs(s[i]-s[j])<s[k])
                    {
                        double y = (s[i]*s[i]+s[j]*s[j]-s[k]*s[k])*1.0/(2.0*s[i]*s[j]);
                        double x = 0.5*s[i]*s[j]*sqrt(1.0-y*y);
                        st[cnt] = (1<<i)|(1<<j)|(1<<k);
                        f[cnt++]= x;
                    }
                }
            }
        }
        memset(dp,0,sizeof(dp));
        double ans = 0;
        for(int i=0;i<(1<<n)-1;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if((i&st[j])==0)
                {
                    dp[i|st[j]] = max(dp[i|st[j]],dp[i]+f[j]);
                    ans = max(ans,dp[i|st[j]]);
                }
            }
        }
        printf("%.2lf\n",ans);

    }
    return 0;
}
