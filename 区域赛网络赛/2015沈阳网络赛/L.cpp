#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s[5000005],a,b;
int n;
int main()
{
    int t;cin>>t;
    int T = 1;
    while(t--)
    {
        scanf("%d%lld%lld",&n,&a,&b);
        long long Max = -1e18;
        long long Maxa=-1e18,Maxb = -1e18;
        int ida,idb;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&s[i]);
            if(a*s[i]*s[i]>Maxa)
            {
                Maxa = a*s[i]*s[i];
                ida = i;
            }
            if(b*s[i]>Maxb)
            {
                Maxb = b*s[i];
                idb = i;
            }
        }
        printf("Case #%d: ",T++);
        if(ida!=idb)
        {
            printf("%lld\n",Maxa+Maxb);
            continue;
        }
        long long Maxa1 = -1e18,Maxb1 = -1e18;

        for(int i=0;i<n;i++)
        {
            if(a*s[i]*s[i]>Maxa1&&i!=ida)
            {
                Maxa1 = a*s[i]*s[i];
            }
            if(b*s[i]>Maxb1&&i!=idb)
            {
                Maxb1 =  b*s[i];
            }
        }
        printf("%lld\n",max(Maxa+Maxb1,Maxa1+Maxb));
    }
    return 0;
}
