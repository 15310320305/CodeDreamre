#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    int T = 1;
    while(t--)
    {
        int x,y;scanf("%d%d",&x,&y);
        int k = __gcd(x,y);
        if(x<y)swap(x,y);
        int ans = 1;
        while(x%(y+k)==0)
        {

            ans++;
            x/=(y/k+1);
            k = __gcd(x,y);
            if(x<y)swap(x,y);
           // cout<<x<<" "<<y<<" "<<k<<endl;
        }
        printf("Case #%d: ",T++);
        cout<<ans<<endl;
    }
    return 0;
}
