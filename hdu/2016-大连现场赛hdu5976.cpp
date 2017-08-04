#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;

double x[205],y[205];
int main()
{

     map<pair<double,double>,int>mp;
     map<double,int>mp1;
    int t;scanf("%d",&t);
    while(t--){
        mp.clear();
        mp1.clear();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&x[i],&y[i]);
        }
        int ans = 0;
        int flag=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[j]-x[i])==0){
                    if(mp1[x[j]]==0){
                        ans++;
                        mp1[x[j]]++;
                    }
                }else {
                    double k = (y[j]-y[i])/(x[j]-x[i])*1.00;
                    double b = y[i]-k*x[i];
                    if(mp[make_pair(k,b)]==0){
                        ans++;
                        mp[make_pair(k,b)]=1;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


//#include<cstdio>
//#define min(x,y) ((x)<(y)?(x):(y))
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int a[5],b[5];
//        int n;scanf("%d",&n);
//        int ans = 0;
//        for(int i=1;i<=n;i++){
//            scanf("%d%d%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&b[1],&b[2],&b[3],&b[4]);
//            for(int j=1;j<=4;j++){
//                if(a[j]>b[j]){
//                    a[j]^=b[j];
//                    b[j]^=a[j];
//                    a[j]^=b[j];
//                }
//                ans+=(min(b[j]-a[j],a[j]+10-b[j]));
//            }
//        }
//        printf("%d\n",ans);
//
//    }
//
//    return 0;
//}



