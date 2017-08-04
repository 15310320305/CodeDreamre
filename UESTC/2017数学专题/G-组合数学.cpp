#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200055
#define M 1000000007
char s[N];
int pre[N];

ll fac[N],inv[N],f[N];
ll C(ll a,ll b){
    if(b>a)return 0;
    return fac[a]*inv[b]%M*inv[a-b]%M;
}
void init(){//快速计算阶乘的逆元
    fac[0] = fac[1] = 1;
    inv[1] = inv[0] = 1;
    f[0] = f[1] = 1;

    for(int i=2;i<N;i++){
        fac[i]=fac[i-1]*i%M;
        f[i]=(M-M/i)*f[M%i]%M;
        inv[i]=inv[i-1]*f[i]%M;
    }
}


int main()
{
    init();
    scanf("%s",s);
    int n = strlen(s);
    pre[n] = 0;
    for(int i=n-1;i>=0;i--)
    {
        pre[i] = pre[i+1];
        if(s[i]=='1')pre[i]++;
    }

    long long ans = 0;
    int num = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            num++;
            int num1 = pre[i];
            ans=(ans+((C((ll)num+num1,(ll)min(num1,num))-1+M)%M-(C((ll)num+num1-1ll,(ll)min(num1,num-1))-1+M)%M+M)%M)%M;
        }
    }
    cout<<ans<<endl;

    return 0;
}
