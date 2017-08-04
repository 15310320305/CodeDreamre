#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int t;cin>>t;int T=1;
    while(t--){
        long long n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        long long Min = ceil(log(n*1.0)/log(2.0))+ceil(log(m*1.0)/log(2.0))+ceil(log(k*1.0)/log(2.0));
        long long Max = n*(m*k-1)+n-1;
        printf("Case #%d: %lld %lld\n",T++,Max,Min);
    }

    return 0;
}
N
