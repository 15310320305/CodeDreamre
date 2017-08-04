#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int n,k;
double v1,v2,l,T;

int check(double mid)
{
    T = 0;
    int num = n-k;
    double t1 = mid/v2;
    T+=t1;
    double x1 = v1*t1;
    double x2 = v2*t1;
    while(num>0)
    {
        double len  = x2-x1;
        double t2 = len/(v1+v2);
        T+=t2;
        x1+=t2*v1;
        x2+=t2*v1;
        if(x2>=l)return 0;
        num-=k;
        t1 = (x2-x1)/(v2-v1);
        if(num<=0)
        {
            if(fabs((l-x1)/v2-(l-x2)/v1)<=eps)
            {
                T+=(l-x1)/v2;
                return 1;
            }
            else if((l-x1)/v2>(l-x2)/v1)
            {
                T+=(l-x1)/v2;
                return 0;
            }
            else
            {
                T+=(l-x2)/v1;
                return -1;
            }
        }
        T+=t1;
        x1+=t1*v1;
        x2+=t1*v1;
        if(x2>=l)return 0;
    }
}

int main()
{
    while(~scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k))
    {
        if(k==n)
        {
            printf("%.6lf\n",l/v2);
            continue;
        }
        double l = 0,r = 1e9,mid,ans;
        while(r-l>=eps)
        {
            mid = (l+r)/2.0;
            int x = check(mid);
            if(x==1)
            {
               break;
            }
            else if(x==0)
            {
                r = mid-eps;
            }
            else l = mid+eps;
        }
        printf("%.10lf\n",T);
    }
    return 0;
}
