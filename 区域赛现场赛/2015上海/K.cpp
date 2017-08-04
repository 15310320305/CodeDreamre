#include<bits/stdc++.h>
using namespace std;
long long l[100005],r[100005],l1[100005],r1[100005];
char str[100005];
int main()
{
    int t;
    int T = 1;
    cin>>t;
    while(t--)
    {
        scanf("%s",str+1);
        int len = strlen(str+1);
        for(int i=0;i<=len+1;i++)
            l[i] = r[i] = l1[i] = r1[i] = 0;
        for(int i=1;i<=len;i++)
        {
            if(str[i-1]=='0')l[i] = l[i-1]+1;
            //else l[i] = 0;
            if(str[i-1]=='1')l1[i] = l1[i-1]+1;
            //else l1[i] = 0;
        }
        for(int i=len;i>=1;i--)
        {
            if(str[i+1]=='0')r[i] = r[i+1]+1;
           // else r[i] = 0;
            if(str[i+1]=='1')r1[i] = r1[i+1]+1;
            //else r1[i] = 0;
        }
        long long ans = 0;
        for(int i=1;i<=len;i++)
        {
            if(str[i]=='0')
            {
                ans+=(r[i]+1ll)*(r[i]+1ll);
                i+=r[i];
            }
            else
            {
                ans+=(r1[i]+1ll)*(r1[i]+1ll);
                i+=r1[i];
            }
        }
        long long ans1 = ans,ans2;
        for(int i=1;i<=len;i++)
        {
            ans2 = ans1;
            if(str[i]=='0')
            {
                long long x = 1;
                ans2-=(l[i]+r[i]+1ll)*(l[i]+r[i]+1ll);
                ans2+=(long long)l[i]*l[i]+r[i]*r[i];
                if(str[i-1]=='1')
                ans2-=(long long)(l1[i])*(l1[i]),x++;
                if(str[i+1]=='1')
                ans2-=(long long)(r1[i])*(r1[i]),x++;
                ans2+=(l1[i]+r1[i]+1)*(l1[i]+r1[i]+1);

                i+=r[i];
                ans = max(ans,ans2);
                x = 1;
                ans2 = ans1;
                ans2-=(l[i]+r[i]+1ll)*(l[i]+r[i]+1ll);
                ans2+=(long long)l[i]*l[i]+r[i]*r[i];
                if(str[i-1]=='1')
                ans2-=(long long)(l1[i])*(l1[i]),x++;
                if(str[i+1]=='1')
                ans2-=(long long)(r1[i])*(r1[i]),x++;
                ans2+=(l1[i]+r1[i]+1)*(l1[i]+r1[i]+1);
                ans = max(ans,ans2);
            }
            else
            {
                long long x = 1;
                ans2-=(l1[i]+r1[i]+1ll)*(l1[i]+r1[i]+1ll);
                ans2+=(long long)l1[i]*l1[i]+r1[i]*r1[i];
               // cout<<ans2<<endl;
                if(str[i-1]=='0')
                ans2-=(long long)(l[i])*(l[i]),x++;
                if(str[i+1]=='0')
                ans2-=(long long)(r[i])*(r[i]),x++;
                //cout<<ans2<<endl;
                ans2+=(l[i]+r[i]+1)*(l[i]+r[i]+1);
                //cout<<ans2<<endl;
                i+=r1[i];
                ans = max(ans,ans2);
                x = 1;
                ans2 = ans1;
                ans2-=(l1[i]+r1[i]+1ll)*(l1[i]+r1[i]+1ll);
                ans2+=(long long)l1[i]*l1[i]+r1[i]*r1[i];
                //cout<<ans2<<endl;
                if(str[i-1]=='0')
                ans2-=(long long)(l[i])*(l[i]),x++;
                if(str[i+1]=='0')
                ans2-=(long long)(r[i])*(r[i]),x++;
                ans2+=(l[i]+r[i]+1)*(l[i]+r[i]+1);
               // cout<<ans2<<endl;
                ans = max(ans,ans2);
            }
        }
        printf("Case #%d: ",T++);
        cout<<ans<<endl;

    }
    return 0;
}
