#include<bits/stdc++.h>
using namespace std;
#define mod
int main()
{
    int n;
    while(cin>>n)
    {
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            ans^=x;
        }
        if(ans)printf("Win\n");
        else printf("Lose\n");
    }

    return 0;
}
