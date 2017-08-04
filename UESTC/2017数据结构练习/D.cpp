#include<bits/stdc++.h>
using namespace std;
const  int maxn = 5e4+100;
const int maxm = 1e5+100;
int pre[maxn],rk[maxn];

int ans[maxm];
int cnt = 0;
int n,m;

int get(int x)
{
    if(x!=pre[x])
    {
        int tmp = pre[x];
        pre[x] = get(pre[x]);
        rk[x] = (rk[x]+rk[tmp])%3;
    }
    return pre[x];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        pre[i] = i;
        rk[i] = 0;
    }
    int t = 1;
    while(m--)
    {
        int id,x,y;
        scanf("%d%d%d",&id,&x,&y);
        if(x>n||y>n)
        {
            ans[cnt++] = t;
            t++;
            continue;
        }
        if(x==y)
        {
            if(id==2)
            {
                ans[cnt++] = t;
            }
            t++;
            continue;
        }
        int xx = get(x);
        int yy = get(y);
        if(id==1)
        {
            if(xx!=yy)
            {
                rk[xx] = (0-rk[x]+rk[y]+3)%3;
                pre[xx] = yy;
            }
            else
            {
                if(rk[x]!=rk[y])
                {
                    ans[cnt++] = t;
                }
            }
        }
        else
        {
            if(xx!=yy)
            {
                rk[xx] = (1-rk[x]+rk[y]+3)%3;
                pre[xx] = yy;
            }
            else
            {
                if(rk[y]!=(rk[x]+2)%3)
                {
                    ans[cnt++] = t;
                }
            }
        }

        t++;
    }
    for(int i=0;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
