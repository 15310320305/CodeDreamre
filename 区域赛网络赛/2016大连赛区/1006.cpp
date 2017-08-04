/** HDU5873  */


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

const int maxn = 1e5+100;

int i,j,k;
int n,m;

int main()
{
    int t;
    while(cin>>t){
        while(t--){
            scanf("%d",&n);
            m=1;
            k=0;
            for(i=1;i<=n;i++){
                scanf("%d",&j);
                if(j>2*(n-1)||j<0)m=0;
                k+=j;
            }
            if(k!=(n-1)*n)m=0;
            if(m==0)printf("F\n");
            else printf("T\n");
        }
    }
    return 0;
}





