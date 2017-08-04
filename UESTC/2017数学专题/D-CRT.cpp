#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

long long a[10], m[10];
void extend_Euclid(long long a, long long b, long long &x, long long &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    extend_Euclid(b, a % b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}

long long CRT(long long a[],long long m[],int n)
{
    long long M = 1;
    long long ans = 0;
    for(int i=1; i<=n; i++)
        M *= m[i];
    for(int i=1; i<=n; i++)
    {
        long long x, y;
        long long Mi = M / m[i];
        extend_Euclid(Mi, m[i], x, y);
        ans = (ans + Mi * x * a[i])%M;
    }
    if(ans < 0) ans += M;



    return ans;
}

int main()
{

    long long Max = 0,xx = 1;
    for(int i=1;i<=6;i++)
        scanf("%lld",&m[i]),xx*=m[i];
    for(int i=1;i<=6;i++)
    {
        scanf("%lld",&a[i]);
        Max = max(Max,a[i]);
        a[i]%=m[i];
    }

    long long ans = CRT(a, m, 6);
    if(ans<Max)
    {
        long long x  = (Max-ans)/xx;
        ans+=xx*x;
        while(ans<Max)ans+=xx;
    }
    cout<<ans<<endl;
    return 0;
}
