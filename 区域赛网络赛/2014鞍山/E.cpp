#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int ff;
int flag;
struct Matrix
{
    double a[55][55];
    struct Matrix operator *(const Matrix &b)
    {
       struct Matrix ans;
       for(int i=0;i<flag;i++)
       {
           for(int j=0;j<n;j++)
           {
               double sum = 0;
               for(int k=0;k<n;k++)
               {
                   sum+=a[i][k]*b.a[k][j];
               }
               ans.a[i][j] = sum;
           }
       }
       return ans;
    }
};

vector<int>G[55];

struct Matrix cal(struct Matrix a,struct Matrix b)
{
    int k = d;
    while(k)
    {
        if(k&1)
        {
            flag = 1;
            a = a*b;
        }
        flag = n;
        b = b*b;
        k/=2;
    }
    return a;
}

int main()
{
    struct Matrix a;
    int t;cin>>t;
    while(t--)
    {
        memset(a.a,0,sizeof(a.a));
        scanf("%d%d%d",&n,&m,&d);
        d++;
        n++;
        memset(G,0,sizeof(G));
        while(m--)
        {
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1;i<n;i++)
        {
            int x = G[i].size();
            for(int j=0;j<x;j++)
            {
                a.a[i][G[i][j]] = 1.0/x;
            }
        }
        for(int i=1;i<n;i++)
            a.a[0][i] = 1.0/(n-1.0);
        Matrix ans;
        memset(ans.a,0,sizeof(ans));
        for(ff=1;ff<n;ff++)
        {
            Matrix aa = a;
            for(int i=0;i<n;i++)
                aa.a[i][ff] = aa.a[ff][i] = 0;
            Matrix b;
            memset(b.a,0,sizeof(b));
            b.a[0][0] = 1.0;
            b = cal(b,aa);
            for(int j=1;j<n;j++)
            {
                ans.a[0][ff]+=(b.a[0][j]);
            }
        }

        for(int i=1;i<n;i++)
            printf("%lf\n",ans.a[0][i]);
    }
    return 0;
}
