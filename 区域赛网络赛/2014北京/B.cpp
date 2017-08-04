#include<bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;

int n,q;
struct Nod
{
    double x,h;
    int f,id;
    Nod(double x,double h,int f):x(x),h(h),f(f){}
    Nod(){}

}nod[200005];
double ans[100005];
bool cmp1(Nod a,Nod b)
{
    return a.x<b.x;
}
double cal(Nod a,Nod b)
{
    return fabs(a.h-b.h)/fabs(a.x-b.x);
}
bool cmp2(Nod a,Nod b)
{
    return a.x>b.x;
}
void sove()
{
    int stc[200005];
    int cnt = 0;

    for(int i=0;i<n+q;i++)
    {
        if(nod[i].f==0)
        {
            while(cnt>0&&nod[stc[cnt-1]].h<=nod[i].h)
        }
        while(cnt>1&&cal(nod[stc[cnt-2]],nod[stc[cnt-1]])>=cal(nod[stc[cnt-1]],nod[i]))cnt--;
        if(nod[i].f==0)
        {
            stc[cnt++] = i;
        }
        else
        {
           ans[nod[i].id]+=90.0-atan(cal(nod[stc[cnt-1]],nod[i]))*180.0/pi;
        }
    }

}
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&nod[i].x,&nod[i].h),nod[i].f = 0;
        scanf("%d",&q);
        for(int i=n;i<q+n;i++)
            scanf("%lf",&nod[i].x),nod[i].h = 0,nod[i].f = 1,nod[i].id = i-n;

        sort(nod,nod+n+q,cmp1);
        sove();
        sort(nod,nod+n+q,cmp2);
        sove();
        printf("Case #%d:\n",T++);
        for(int i=0;i<q;i++)
        {
            printf("%lf\n",ans[i]);
        }
    }
}
