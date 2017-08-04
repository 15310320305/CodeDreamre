#include<bits/stdc++.h>

using namespace std;

int n,m,ans;
int in[10];
int x[30],y[30];
int d1[10],d2[10];
bool check()
{
    for(int i=1;i<=n;i++)
        if(d1[i]!=d2[i])return false;
    return true;
}

void dfs(int num)
{
    if(num==m+1)
    {
        if(check())
            ans++;
        return ;
    }
    int xx = x[num],yy = y[num];

    if(d1[xx]<in[xx]/2&&d1[yy]<in[yy]/2)
    {
        d1[xx]++;
        d1[yy]++;
        dfs(num+1);
        d1[xx]--;
        d1[yy]--;
    }
    if(d2[xx]<in[xx]/2&&d2[yy]<in[yy]/2)
    {
        d2[xx]++;
        d2[yy]++;
        dfs(num+1);
        d2[xx]--;
        d2[yy]--;
    }

}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(in,0,sizeof(in));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            in[x[i]]++;
            in[y[i]]++;
        }
        int ok = 0;
        for(int i=1;i<=n;i++)
        {
            if(in[i]&1)
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        {
            printf("0\n");
            continue;
        }
        ans = 0;
        dfs(1);
        printf("%d\n",ans);
    }

    return 0;
}
