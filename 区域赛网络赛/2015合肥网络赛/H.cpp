#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    int T = 1;
    while(t--)
    {
        long long d;
        int s1,s2;
        scanf("%lld%d%d",&d,&s1,&s2);
        long long dd = d;
        int num = 0;
        int len = 0;
        long long num1[35];
        while(dd)
        {
            num1[len] = dd%2;
            if(dd%2)num++;
            len++;
            dd/=2;
        }
        num1[len] = 0;
        long long x = 1;
        int i;
        for(i=0;i<=len;i++)
        {
            if(num1[i]==0&&(i>0&&num1[i-1]==1||i==0&&num<s2))
            {
                d+=x;
                num++;
                x/=2ll;
                i--;
                break;
            }
            else if(num1[i]==1)d-=x,num--;
            x*=2;
        }
        x = 1;
        for(i=0;num<s1;i++)
        {
            d+=x;
            x*=2;
            num++;
        }
        printf("Case #%d: %lld\n",T++,d);

    }
    return 0;
}
