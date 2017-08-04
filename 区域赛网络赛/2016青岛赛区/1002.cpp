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
#define esp 1e-5


const ll inf = 1073741824;

int main()
{
     long long s[10000];
     long long a=1,b=1,c=1,d=1;
     long long res=0;
     int n;
     int cnt=0;
     for(int i=0;i<31;i++){
        if(i)a=a*2;
        b=1;
        for(int j=0;j<19;j++)
        {
            if(j)b=b*3;
            c=1;
            for(int k=0;k<13;k++){
                if(k)c=c*5;
                d=1;
                for(int l=0;l<11;l++){
                    if(l)d=d*7;
                    if(a*b<=inf&&a*c<=inf&&a*d<=inf&&b*c<=inf&&b*d<=inf&&c*d<=inf){
                        res=a*b*c*d;
                    if(res<=inf)s[cnt++]=res;
                    }
                }
            }
        }
     }
     sort(s,s+cnt);
     int ans[1000];
     int t;cin>>t;
     int num=0;
     while(t--){
        scanf("%d",&n);
        n=lower_bound(s,s+cnt,n)-s;
        printf("%d\n",s[n]);
     }

    return 0;
}




/**
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         I have a dream!A AC deram!!
 orz orz orz orz orz orz orz orz orz orz orz
 orz orz orz orz orz orz orz orz orz orz orz
 orz orz orz orz orz orz orz orz orz orz orz

**/
