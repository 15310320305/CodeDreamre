#include<bits/stdc++.h>
using namespace std;

struct st
{
    int nex[2];
    st()
    {
        nex[0] = nex[1] = 0;
    }
}s[2000000];
int Size;
int n,m;
void Insert(int num[35])
{
    int now = 0;
    for(int i=33;i>=0;i--)
    {
        int x = num[i];
        if(s[now].nex[x]==0)
        {
            s[now].nex[x] = Size++;
        }
        now = s[now].nex[x];
    }
}

long long Serch(int num[35])
{
    int ans[35];
    int now = 0;
    for(int i=33;i>=0;i--)
    {
        int x = num[i]^1;
        if(s[now].nex[x])
        {
            ans[i] = 1;
            now = s[now].nex[x];
        }
        else
        {
            ans[i] = 0;
            now = s[now].nex[x^1];
        }
    }
    long long res = 0,x = 1;
    for(int i=0;i<=33;i++)
    {
        if(ans[i])res+=x;
        x*=2ll;
    }
    return res;
}

int main()
{
    Size = 1;
    int num[35];
    int cnt = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cnt = 0;
        int x;scanf("%d",&x);
        while(x)
        {
            num[cnt++] = x%2;
            x/=2;
        }
        for(;cnt<=33;cnt++)
            num[cnt] = 0;
        Insert(num);
    }
    cin>>m;
    while(m--)
    {
        cnt = 0;
        int x;scanf("%d",&x);
        while(x)
        {
            num[cnt++] = x%2;
            x/=2;
        }
        for(;cnt<=33;cnt++)
            num[cnt] = 0;
        printf("%lld\n",Serch(num));
    }
    return 0;
}
