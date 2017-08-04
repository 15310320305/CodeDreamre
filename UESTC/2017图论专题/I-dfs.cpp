#include<bits/stdc++.h>

using namespace std;

int num[50000];
int ans[50000];
int vis[50000];
int n,nn;
int flag;
void dfs(int x,int fa)
{
    if(flag)return ;

    if(x==nn+n)
    {
        for(int i=1;i<=nn;i++)
            ans[i] = num[i];
        flag = 1;
        return ;
    }
    if(x>nn)
    {
        int now = fa;
        if(num[x-n])now -=(1<<(n-1));
        now = now<<1;
        if(!vis[now])
        {
            vis[now] = 1;
            num[x] = 0;
            dfs(x+1,now);
            vis[now] = 0;
        }

        return ;
    }

    for(int i=0;i<2&&flag<1;i++)
    {
        int now=fa;
        if(num[x-n])now -=(1<<(n-1));
        now = now<<1;
        if(!vis[now+i])
        {
            vis[now+i] = 1;
            num[x] = i;
            dfs(x+1,now+i);
            vis[now+i]  =0;
        }
    }
}

int main()
{
    cin>>n;
    nn = 1<<n;
    flag = 0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        num[i] = 0;
    vis[0] =1;
    dfs(n+1,0);

    for(int i=1;i<=nn;i++)
        printf("%d",ans[i]);
    cout<<endl;

    return 0;
}
