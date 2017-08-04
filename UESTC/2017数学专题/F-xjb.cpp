#include<bits/stdc++.h>
using namespace std;
int vis[205][10000];
int d[300];
int main()
{
    memset(d,0,sizeof(d));
    for(int i=2;i<=14;i++)
    {
        for(int j=i*i;j<=200;j*=i)
        {
            if(!d[j])
            d[j] = i;
        }
    }

    memset(vis,0,sizeof(vis));
    int m,n,a,b;
    cin>>m>>n>>a>>b;
    int aa=a,bb;
    int ans = n*m;
    for(int i=1;i<=m;i++)
    {
        bb = b;
        for(int j=1;j<=n;j++)
        {
            int aaa = aa,bbb = bb;
            if(d[aa])
            {
                int k = 1;
                while(aaa/d[aa]>1)
                {
                    aaa/=d[aa];
                    k++;
                }
                bbb*=k;
            }
            if(vis[aaa][bbb])
            {
               ans--;
            }
            vis[aaa][bbb] = 1;
            bb++;
        }
        aa++;
    }
    cout<<ans<<endl;
    return 0;
}
