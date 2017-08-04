#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    //freopen("2.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        double a[100105];
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        pair<int ,int>p1,p2;
        while(q--){
            scanf("%d%d",&p1.first,&p1.second);
            scanf("%d%d",&p2.first,&p2.second);
            if(p1.first>p2.first)swap(p1.first,p2.first);
            if(p1.second>p2.second)swap(p1.second,p2.second);
            int len1=p1.second-p1.first+1;
            int len2=p2.second-p2.first+1;
            int mid=(len1+len2+1)/2;
            double ans;
            if(p2.first>p1.second){
                if((len1+len2)%2==1){
                    if(p1.first+mid-1<=p1.second)
                        ans=(double)a[p1.first+mid-1];
                    else
                        ans=(double)a[p1.first+mid-1-p1.second+p2.first-1];
                }
                else {
                    if(p1.first+mid<=p1.second)
                        ans=(double)(a[p1.first+mid-1]+a[p1.first+mid])/2.0;
                    else if(p1.first+mid-1==p1.second)
                        ans=(double)(a[p1.second]+a[p2.first])/2.0;
                    else {
                        int x=p1.first+mid-1-p1.second+p2.first-1;
                        ans=(double)(a[x]+a[x+1])/2.0;
                    }
                }

            }
            else {
                    int f=p1.second-p2.first+1;
                    if((len1+len2)%2==1){
                        if(mid+p1.first-1<=p1.second+f){
                            if(mid+p1.first-1<=p1.second-f)ans=(double)a[mid+p1.first-1];
                            else ans=(double)a[p1.second-f+(mid+p1.first-p1.second+f)/2];
                        }
                        else
                            ans=(double)a[p1.first+mid-1-p1.second-f+p1.second];
                    }
                    else {
                            int l=p1.second-f+(mid+p1.first-p1.second+f)/2.0;
                            int l1=p1.second-f+(mid+p1.first-p1.second+f+1)/2.0;
                        if(mid+p1.first-1<=p1.second+f){
                            if(mid+p1.first-1<=p1.second-f)ans=(double)(a[mid+p1.first-1]+a[mid+p1.first])/2.0;

                            else ans=(double)(a[l]+a[l1])/2.0;
                        }
                        else
                            ans=(double)(a[p1.first+mid-1-p1.second-f+p1.second]+a[p1.first+mid-1-p1.second-f+p1.second])/2.0;
                    }

            }
            printf("%.1f\n",ans);
        }
    }
    return 0;
}
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <queue>
//#include <map>
//#include <set>
//#include <stack>
//#include <vector>
//#include <list>
//#define LL long long
//#define eps 1e-8
//#define maxn 101000
//#define mod 100000007
//#define inf 0x3f3f3f3f
//#define mid(a,b) ((a+b)>>1)
//#define IN freopen("in.txt","r",stdin);
//using namespace std;
//
//int n, m;
//LL num[maxn];
//
//LL query1(int l1,int r1,int l2,int r2, int aim) {
//    if(l1+aim-1 < l2) return num[l1+aim-1];
//    else if(aim > (l2-l1)+2*(r1-l2+1)) {
//        int pos = aim - ((l2-l1)+2*(r1-l2+1));
//        return num[r1+pos];
//    } else {
//        aim -= (l2-l1);
//        int pos = aim / 2;
//        if(aim % 2) return num[l2+pos+1-1];
//        else return num[l2+pos-1];
//    }
//}
//
//LL query2(int l1,int r1,int l2,int r2, int aim) {
//    if(l1+aim-1 <= r1) return num[l1+aim-1];
//    aim -= (r1-l1+1);
//    return num[l2+aim-1];
//}
//
//int main(int argc, char const *argv[])
//{
//    freopen("1.out","w",stdout);
//
//    int t; cin >> t;
//    while(t--)
//    {
//        scanf("%d %d", &n, &m);
//        for(int i=1; i<=n; i++) {
//            scanf("%lld", &num[i]);
//        }
//
//        while(m--) {
//            int L1,L2,R1,R2;
//            int l1,r1; scanf("%d %d", &L1, &R1);
//            int l2,r2; scanf("%d %d", &L2, &R2);
//            l1 = min(L1,L2); l2 = max(L1,L2);
//            r1 = min(R1,R2); r2 = max(R1,R2);
//
//            int tol = (r1-l1+1) + (r2-l2+1);
//
//            if(r1 < l2) {
//                if(tol & 1) {
//                    printf("%lld.0\n", query2(l1,r1,l2,r2, (tol+1)/2));
//                } else {
//                    LL ans = query2(l1,r1,l2,r2, (tol+1)/2) + query2(l1,r1,l2,r2, (tol+1)/2+1);
//                    printf("%lld", ans/2);
//                    if(ans % 2) printf(".5\n");
//                    else printf(".0\n");
//                }
//            }
//            else {
//                if(tol & 1) {
//                    printf("%lld.0\n", query1(l1,r1,l2,r2, (tol+1)/2));
//                } else {
//                    LL ans = query1(l1,r1,l2,r2, (tol+1)/2) + query1(l1,r1,l2,r2, (tol+1)/2+1);
//                    printf("%lld", ans/2);
//                    if(ans % 2) printf(".5\n");
//                    else printf(".0\n");
//                }
//            }
//        }
//    }
//
//    return 0;
//}


//3
//6 10
//1 3 5 7 8 10
//1 6
//2 3
//2 3
//4 6
//1 5
//2 3
//1 5
//4 6
//1 6
//2 3
//1 5
//6 6
//1 2
//2 5
//2 5
//3 6
//1 2
//6 6
//1 4
//3 6
//3 6
//1 5 6
//1 1
//1 1
//1 2
//2 2
//1 3
//1 3
//2 3
//3 3
//1 2
//2 3
//1 3
//1 1
//5 6
//1 5 6 7 8
//5 5
//1 5
//2 5
//3 5
//5 5
//1 2
//1 5
//1 5
//2 5
//3 4
//3 3
//3 5






