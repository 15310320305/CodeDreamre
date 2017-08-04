#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define M_PI 3.1415926
int main()
{
    int n;
    double len;
    while(~scanf("%d%lf",&n,&len)){
        double angle;
        double ans=0;
        for(int i=0;i<n;i++){
            scanf("%lf",&angle);
            ans+=len*len*sin((angle)*M_PI/180.0)/2.0;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}


