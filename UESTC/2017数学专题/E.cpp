#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long m = 1;
    for(long long i=1;i<=n;i++)
        m*=i;
    cout<<m/n*m<<endl;
    return 0;
}
