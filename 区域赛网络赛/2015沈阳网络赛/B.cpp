//#include<bits/stdc++.h>
//using namespace std;
//int m;
//double ans;
//int cal(int x)
//{
//    int ans = 1,tmp = 2;
//    while(x)
//    {
//        if(x&1)
//        {
//            ans*=tmp;
//        }
//        tmp*=tmp;
//        ans%=m;
//        tmp%=m;
//        x/=2;
//    }
//    return ans;
//}
//
//double sove(int x)
//{
//    double tmp = 5.0+2*sqrt(6),ans = 1.0;
//    while(x)
//    {
//        if(x&1)
//        {
//            ans*=tmp;
//            int xx = ans/m;
//            ans = ans-m*xx;
//        }
//        tmp*=tmp;
//
//        int yy = tmp/m;
//
//        tmp = tmp-m*yy;
//        x/=2;
//
//    }
//    return ans;
//}
//
//int main()
//{
//
//    int t,x;cin>>t;
//    while(t--)
//    {
//        scanf("%d%d",&x,&m);
//        x= (cal(x)+1)%m;
//        int ans = sove(x);
//        printf("%d\n",ans);
//    }
//    return 0;
//}


#include<bits/stdc++.h>
using namespace std;
#define esp 1e-7
int n;
double t;
struct st
{
    double d,s;
}s[1005];

bool check(double mid)
{
    double x = 0;
    for(int i=0;i<n;i++)
    {
        x+=s[i].d/(s[i].s+mid);
        if(s[i].s+mid<0)return true;
    }
    if(x-t>esp)return true;
    else return false;
}

int main()
{
    scanf("%d%lf",&n,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&s[i].d,&s[i].s);
    }
    double ans=-1e9,l = -1e7,r = 1e7,mid;
    while(r-l>esp)
    {
        mid = (l+r)/2.0;
        if(check(mid))
        {
            l = mid+esp;
        }
        else r = mid-esp;
    }
    if(l<1e7&&l>-1e7)printf("%lf\n",l);
    else printf("-1\n");

    return 0;
}



