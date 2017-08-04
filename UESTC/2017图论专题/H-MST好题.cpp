#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int inf = 1e9+20;
int mp[maxn][maxn];
int n;

int prim()
{
    int f[maxn],vis[maxn];
    for(int i=0;i<=n;i++)
    {
        f[i] = mp[0][i];
        vis[i] = 0;
    }
    int res = 0;
    vis[0] = 1;
    for(int i=0;i<n;i++)
    {
        int to = -1,v = inf;
        for(int j=0;j<=n;j++)
        {
            if(v>f[j]&&!vis[j])
            {
                v = f[j];
                to = j;
            }
        }
        vis[to] = 1;
        res+=v;

        for(int j=0;j<=n;j++)
        {
            if(!vis[j]&&j!=to&&f[j]>mp[to][j])
            {
                f[j]=mp[to][j];
            }
        }

    }
    return res;

}

int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i!=j)mp[i][j] = inf;
            else mp[i][j] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int x;scanf("%d",&x);
            mp[i-1][j] =mp[j][i-1] = min(mp[j][i-1],x);

        }
    }

    printf("%d\n",prim());

    return 0;
}
