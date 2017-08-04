#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-5;
int main()
{
    int T = 1;
    int t;cin>>t;
    while(t--)
    {
        double x1,y1,x2,y2,x3,y3;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double x4 = (x2+x3)/2.0,y4 = (y3+y2)/2.0;
        double ab = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        double bc = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
//        double xx = -1.0,yy= -1.0;
//        for(double i=-1000.0;i<=1000.0;i+=1.0)
//        {
//            for(double j=0;j<=1000.0;j+=1.0)
//            {
//                if(j>=1000.0-fabs(i))continue;
//                if(i==0.0)continue;
//                double a = sqrt((i-x1)*(i-x1)+(j-y1)*(j-y1));
//                double b = sqrt((i-x2)*(i-x2)+(j-y2)*(j-y2));
//                double c = sqrt((i-x3)*(i-x3)+(j-y3)*(j-y3));
//                double d = sqrt((i-x4)*(i-x4)+(j-y4)*(j-y4));
//                double angle1 = acos(((b*b)+d*d-bc*bc/4.0)/(2.0*b*d));
//                double angle2 = acos(((a*a)+c*c-ab*ab)/(2.0*a*c));
//                if(fabs(angle1+angle2-pi)<=eps)
//                {
//                    if(xx==-1&&yy==-1)
//                    {
//                        xx = i,yy = j;
//                    }
//                    else
//                    {
//                        printf("%lf\n",j-yy/i-xx);
//                    }
//                    printf("%.4lf %.4lf\n",i,j);
//                }
//            }
//        }

        double ans = sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4));
        double r = ans*bc/2.0/(bc/2.0+ab);
        double R = (r*r+bc*bc/4.0)/(2.0*r);
        double angle = acos((R*R+(R-r)*(R-r)-bc*bc/4.0)/(2.0*R*(R-r)))*2.0;
        ans+=2.0*pi*R*angle/(2.0*pi);                                                                                                                                                                                 ;
        printf("Case #%d: %.4lf\n",T++,ans);

    }
    return 0;
}
