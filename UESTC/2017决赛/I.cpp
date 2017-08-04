//#include<bits/stdc++.h>
//using namespace std;
//#define mod  1000000007
//int main()
//{
//    long long a,b,c;
//    cin>>a>>b>>c;
//    cout<<(((a+1)%mod)*((b+1)%mod))%mod<<endl;
//
//    return 0;
//}


#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define lcr(a,b) memset(a,b,sizeof(a))
#define sfor(i,n) for(i=0;i<n;i++)
#define dfor(i,n) for(i=n-1;i>=0;i--)
#define sc(x) scanf("%d",&x)
#define pr(x) printf("%d\n",x)
#define ll long long
#define INF 0x7fffffff
#define esp 1e-8


int main()
{
     for(int i=1;i<=30500;i++)
     {
         int j = i*i;
         int num[10];
         lcr(num,0);
         int flag = 1;
         while(j){
            num[j%10]++;
            if(num[j%10]>1){
                flag = 0;
                break;
            }
            j/=10;
         }
         if(flag)cout<<i*i<<endl;
     }
     return 0;
}
