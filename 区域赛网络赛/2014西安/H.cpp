#include<bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int n;
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<=n;i++)scanf("%d",&a[i]);
        memset(b,-1,sizeof(b));
        long long ans = 0;
        for(int i=n;i>=0;i--)
        {
            if(b[i]==-1)
            {
                int x = 0,y=i;
                while(y)
                {
                    x++;
                    y/=2;
                }
                if(i==(1<<x)-1)
                {
                    b[i] = 0;
                    b[0] = i;
                    ans+=(long long)i;
                }
                else
                {
                    b[i] = (1<<x)-1-i;
                    b[(1<<x)-1-i] = i;
                    ans+=(long long)i^((1<<x)-1-i);
                }
            }
        }
        cout<<ans*2ll<<endl;
        for(int i=0;i<=n;i++)
        {
            int x = b[a[i]];
            printf("%d%c",x,i==n?'\n':' ');
        }
    }

    return 0;
}
