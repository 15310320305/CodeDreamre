#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,p,m,t,T=1;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&p,&m);
        int x = (m-(a+c)%p+p)%p;
        int cnt1 = max(0,(b-(a+x))/p)+(a+x<=b);
        int cnt2 = (d-c)/p+1;
        //cout<<cnt1<<" "<<cnt2<<" "<<x<<endl;
        long long ans = (long long)cnt1*cnt2;
        int xx = cnt1?(b-(a+x)-(p*cnt1-p)):(b-a+1);
        int yy = d-(c+p*cnt2-p);
        int prex = (a+x<=b)?x:0;
        int prey = 0;
        int numx = cnt1>=2?cnt1-1:0;
        int numy = cnt2>=2?cnt2-1:0;
//        cout<<xx<<" "<<yy<<endl;
//        cout<<prex<<" "<<prey<<endl;
//        cout<<numx<<" "<<numy<<endl;
        ans+=(long long)numx*numy*(p-1)+(long long)numx*(yy+prey)+(long long)numy*(xx+prex);
        //ans+=(long long)numy*(p-1)*(numx*(p-1))+(xx>0?1:0)+(prex>0?1:0);
        if(m==0)m=p;
        p = m;
        if(prex+prey>=p)ans+=(prex+prey-p+1);
        if(prex+yy>=p)ans+=(prex+yy-p+1);
        if(xx+prey>=p)ans+=(xx+prey-p+1);
        if(xx+yy>=p)ans+=(xx+yy-p+1);
        long long gcd = __gcd(ans,(long long)(b-a+1)*(d-c+1));
        printf("Case #%d: %lld/%lld\n",T++,ans/gcd,(long long)(b-a+1)*(d-c+1)/gcd);

    }
    return 0;
}
