#include<bits/stdc++.h>
using namespace std;
double xx1,yy1,r1,xx2,yy2,r2,ans;
const double pi = acos(-1.0);
double sove()
{
    double len = sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));
    if(len>=r1+r2)ans = 0;
    else if(r1-r2>=len)
    {
        ans = pi*r2*r2;
    }
    else if(r2-r1>=len)
    {
        ans = pi*r1*r1;
    }
    else
    {
        double angle1 = acos((r1*r1+len*len-r2*r2)/(2.0*r1*len))*2.0;
        double angle2 = acos((r2*r2+len*len-r1*r1)/(2.0*r2*len))*2.0;
        double S = angle1/(2.0*pi)*pi*r1*r1+angle2/(2.0*pi)*pi*r2*r2;
        double s = r1*len*sin(angle1/2.0);
        ans = S-s;
    }

}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&xx1,&yy1,&r1,&xx2,&yy2,&r2);
        sove();
        printf("%.6lf\n",ans);
    }
    return 0;
}
