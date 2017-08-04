#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    int T = 1;
    while(t--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int g = __gcd(a,b);
        int x;
        if(g==1)
        {
            x = n-2;
        }
        else
        {
            x = n/g-2;
        }
        printf("Case #%d: ",T++);
        if(x%2)printf("Yuwgna\n");
        else printf("Iaka\n");
    }
    return 0;
}
