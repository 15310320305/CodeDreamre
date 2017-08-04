#include<bits/stdc++.h>

using namespace std;
int fx[4][2] = {1,0,-1,0,0,1,0,-1};
int main()
{
    int n,m,t;
    cin>>t;
    while(t--)
    {
        int a[55][55];
        scanf("%d%d",&n,&m);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j])
                {
                    ans+=6*a[i][j];
                    ans-=(2*(a[i][j]-1)+1);
                    for(int k=0;k<4;k++)
                    {
                        int ii = i+fx[k][0],jj = j+fx[k][1];
                        if(ii>=1&&ii<=n&&jj>=1&&jj<=m)
                        {
                            ans-=min(a[i][j],a[ii][jj]);

                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
