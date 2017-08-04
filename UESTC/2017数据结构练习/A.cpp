/**
CDOJ1591 RMQ
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4+100;
int dpMin[maxn][20],dpMax[maxn][20];
int a[maxn];
int n,q;

void RMQ()
{
    for(int i=1;i<=n;i++)
        dpMin[i][0] = dpMax[i][0] = a[i];

    for (int j=1;j<=log(n)/log(2);j++)
    {
        for(int i=1;i<=n;i++)
        {
            if (i+(1<<j)-1<=n)
            {
                dpMin[i][j]=min(dpMin[i][j-1],dpMin[i+(1<<(j-1))][j-1]);
                dpMax[i][j]=max(dpMax[i][j-1],dpMax[i+(1<<(j-1))][j-1]);
            }
        }
    }
}

int getMin(int l,int r)
{
    int k=log(r-l+1)/log(2.0);
    return min(dpMin[l][k],dpMin[r-(1<<k)+1][k]);
}

int getMax(int l,int r)
{
    int k=log(r-l+1)/log(2.0);
    return max(dpMax[l][k],dpMax[r-(1<<k)+1][k]);
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    RMQ();
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",getMax(l,r)-getMin(l,r));
    }
    return 0;
}
