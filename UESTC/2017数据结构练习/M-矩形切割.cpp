#include<bits/stdc++.h>
using namespace std;

struct st
{
    double x1,y1,x2,y2;
}s[205];
double sum[205];
int n;

void sove(double x1,double y1,double x2,double y2,int x,int k)
{
    while(k<n&&(x1>=s[k].x2||x2<=s[k].x1||y1>=s[k].y2||y2<=s[k].y1))k++;
    if(k>=n)
    {
        sum[x]+=(x2-x1)*(y2-y1);
        return ;
    }
    if(x1<s[k].x1)
    {
        sove(x1,y1,s[k].x1,y2,x,k+1);
        x1 = s[k].x1;
    }
    if(x2>s[k].x2)
    {
        sove(s[k].x2,y1,x2,y2,x,k+1);
        x2 = s[k].x2;
    }
    if(y1<s[k].y1)
    {
        sove(x1,y1,x2,s[k].y1,x,k+1);
        y1 = s[k].y1;
    }
    if(y2>s[k].y2)
    {
        sove(x1,s[k].y2,x2,y2,x,k+1);
        y2 = s[k].y2;
    }
}

int main()
{
    while(cin>>n,n)
    {
        for(int i=0;i<n;i++)scanf("%lf%lf%lf%lf",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2),sum[i] = 0;
        double ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            sove(s[i].x1,s[i].y1,s[i].x2,s[i].y2,i,i+1);
        }
        for(int i=0;i<n;i++)
            ans+=sum[i];
        printf("%.2lf\n",ans);
    }
    return 0;
}
