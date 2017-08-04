#include<bits/stdc++.h>

using namespace std;
double num[100];
int main()
{
    num[0] = 1;
    for(int i=1;i<=50;i++)
        num[i] = num[i-1]*0.95;
    int t;cin>>t;
    while(t--)
    {
        int n;
        double a[100];
        cin>>n;
        double sum = 0;
        for(int i=0;i<n;i++)
            scanf("%lf",&a[i]);
        sort(a,a+n);
        for(int i=n-1;i>=0;i--)
            sum+=a[i]*num[n-1-i];
        printf("%lf\n",sum);
    }
    return 0;
}
