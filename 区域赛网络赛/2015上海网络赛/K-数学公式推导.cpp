#include<bits/stdc++.h>
using namespace std;
long long C,k1,k2,b1;
long long cal(long long k,long long c)
{
    long long ans = 1,x = c;
    while(k)
    {
        if(k&1)
        {
            ans*=x;
            ans%=C;
        }
        x*=x;
        x%=C;
        k/=2ll;
    }
    return ans;
}
int main()
{
    int T = 1;
    while(cin>>C>>k1>>b1>>k2)
    {
        printf("Case #%d:\n",T++);
        int f = 1;
        for(long long i=1;i<C;i++)
        {
            long long ak =cal(k1,i);
            long long b = (C-cal(k1+b1,i))%C;

            long long bk = cal(k2,b);
           // cout<<i<<" "<<b<<" "<<bk<<endl;
            if(ak==bk)
            {
                printf("%lld %lld\n",i,b);

                f = 0;
            }
        }
        if(f)printf("-1\n");

    }
    return 0;
}
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<queue>
//#include<stack>
//#include<math.h>
//#include<vector>
//#include<map>
//#include<set>
//#include<stdlib.h>
//#include<cmath>
//#include<string>
//#include<algorithm>
//#include<iostream>
//#define exp 1e-10
//using namespace std;
//const int N = 200001;
//const int inf = 1000000000;
//const int mod = 2009;
//__int64 Quick_Mod(int a, int b, int m)
//{
//    __int64 res = 1,term = a % m;
//    while(b)
//    {
//        if(b & 1) res = (res * term) % m;
//        term = (term * term) % m;
//        b >>= 1;
//    }
//    return res%m;
//}
//int main()
//{
//    int C,k1,b1,k2,i,k=1;
//    __int64 a,b,s;
//    bool flag;
//    while(~scanf("%d%d%d%d",&C,&k1,&b1,&k2))
//    {
//        flag=false;
//        printf("Case #%d:\n",k++);
//        for(i=1;i<C;i++)
//        {
//            a=Quick_Mod(i,k1,C);
//            b=C-Quick_Mod(i,k1+b1,C);
//            s=Quick_Mod(b,k2,C);
//            cout<<a<<" "<<b<<" "<<s<<endl;
//            //printf("##%I64d %I64d\n",a,s);
//            if(a==s)
//                flag=true,printf("%d %I64d\n",i,b);
//        }
//        if(!flag)
//            puts("-1");
//    }
//    return 0;
//}
