#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<queue>
#include<stack>
#include<list>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll sum[1110][1110];
ll jiec[1102];

int main(){
	jiec[0]=1;jiec[1]=1;jiec[2]=2;
    for(ll i=3;i<1002;i++){
        jiec[i]=(jiec[i-1]*i)%mod;
    }
	for(ll i=0;i<=1002;i++){
		for(ll j=0;j<=1002;j++){
			if( j==0 || j>i )sum[i][j]=0;
			else if( i==j || j==1 )sum[i][j]=1;
			else sum[i][j]=( sum[i-1][j-1] + j*sum[i-1][j] )%mod;
		}
	}
	int n,m;
	int t;cin>>t;
	while(t--){
        scanf("%d %d",&n,&m);
		printf("%lld\n",(sum[n][m] )%mod );
	}



	return 0;
}
