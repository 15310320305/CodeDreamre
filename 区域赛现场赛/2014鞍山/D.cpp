//#include<bits/stdc++.h>
//using namespace std;
//
//int n,k;
//double a[50005];
//double l[50005],r[50005];
//
//int main()
//{
//    int t;cin>>t;
//    while(t--)
//    {
//        scanf("%d%d",&n,&k);
//        for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
//        if(k==n||n==1){
//            printf("0\n");
//            continue;
//        }
//        sort(a+1,a+n+1);
//        l[0] = 0,r[0] = 0;
//
//        for(int i=1;i<=n;i++)
//            l[i] = l[i-1]+a[i]*a[i],r[i] = r[i-1]+a[i];
//        double ans = 1e18;
//        for(int i=1;i<=k+1;i++)
//        {
//            double mid = (r[i+n-k-1]-r[i-1])/(n-k)*1.0;
//            double sum = l[i+n-k-1] - l[i-1]+mid*mid*(n-k)*1.0-2.0*mid*(r[i+n-k-1]-r[i-1]);
//            ans = min(sum,ans);
//        }
//       // if(ans==1e18)ans = 0;
//        printf("%.12lf\n",ans);
//
//    }
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int h,u,d,f;
    while(~scanf("%d %d %d %d",&h,&u,&d,&f))
    {
        bool flag=false;
        double sum=0;
        double shao=u*1.0*f*0.01;
        long long i;
        for(i=0;;i++)
        {
            sum+=(u-i*shao);
          //  printf("%lf ssss\n",sum);
            if(sum>h)
            {
                flag=true;
                break;
            }
            sum-=d;
            if(sum<0)
                break;
        }
        if(flag)
            printf("success  %lld\n",i+1);
        else
            printf("failure  %lld\n",i+1);
    }
    return 0;
}
