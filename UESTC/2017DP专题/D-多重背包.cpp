#include<bits/stdc++.h>
using namespace std;

int dp[200005]={0};
int n,C;
int cost[200005],value[200005],cnt[200005],ff[200005];
void CompletePark(int c,int v)
{
    for(int i=c;i<=C;i++)
    {
        dp[i] = max(dp[i],dp[i-c]+v);
    }
}

void ZeroOnePark(int c,int v)
{
    for(int i=C;i>=c;i--)
    {
        dp[i] = max(dp[i],dp[i-c]+v);
    }
}

void MulPark(int c,int v,int m)
{
    if(m==1)
    {
        CompletePark(c,v);
        return ;
    }
    ZeroOnePark(c,v);
}

int main()
{
    cin>>n>>C;
    for(int i=0;i<n;i++)
    {
        int t,a,b;scanf("%d%d%d",&t,&a,&b);
        cost[i] = b,value[i] = a;
        ff[i] = t;
    }
    for(int i=0;i<n;i++)
    {
        MulPark(cost[i],value[i],ff[i]);
    }
    cout<<dp[C]<<endl;
    return 0;
}
