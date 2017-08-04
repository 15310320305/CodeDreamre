#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[70];
    for(int i=1;i<=n;i++)a[i] = i;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n/2;j++)printf("%d %d%c",a[j],a[n-j+1],j==n/2?'\n':' ');
        int t= a[2];
        for(int j=2;j<n;j++)a[j] = a[j+1];
        a[n] = t;
    }

    return 0;
}
