#include<bits/stdc++.h>
using namespace std;

int dp[20][2];
int a[20];

int dfs(int pos,int pre,int sta,bool limit)
{
    if(pos==-1)return 1;
    if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
    int up = limit?a[pos]:9;
    int tmp = 0;
    for(int i=0;i<=up;i++)
    {
        if(pre==6&&i==2)continue;
        if(i==4)continue;
        tmp+=dfs(pos-1,i,i==6,limit&&i==a[pos]);
    }
    if(!limit)dp[pos][sta]= tmp;
    return tmp;
}

int sove(int x).
{
    int len = 0;
    while(x)
    {
        a[len++] = x%10;
        x/=10;
    }
    return dfs(len-1,-1,0,true);
}

int main()
{
    int x,y;
    while(~scanf("%d%d",&x,&y),x+y)
    {
        memset(dp,-1,sizeof(dp));
        printf("%d\n",sove(y)-sove(x-1));
    }
    return 0;
}
