#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int s[1005];
        for(int i=1;i<=n;i++)
            scanf("%d",&s[i]);
        int q;scanf("%d",&q);
        while(q--)
        {
            int l,r;scanf("%d%d",&l,&r);
            int Max = 1;
            for(int i=l;i<=r;i++)
                Max = max(Max,s[i]);
            printf("%d\n",Max);
        }
    }
    return 0;
}
