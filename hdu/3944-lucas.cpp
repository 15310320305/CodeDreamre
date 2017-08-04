#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
long long p;
LL mod[10000][10005];
bool isprime[10005];
LL prime[10005];
int pnt[10005];
LL n,m;
int cnt;
void initprime()
{
    cnt = 0;
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<=10000;i++)
    {
        if(isprime[i])
        {
            pnt[i] = cnt;
            prime[cnt++] = i;
            for(int j=i+i;j<=10000;j+=i)
                isprime[j]=false;
        }
    }
}

long long extend_gcd(long long a, long long b, long long &x , long long &y)
{
    if(a==0&&b==0) return -1;
    if(b==0){ x = 1;y = 0;return a; }
    else{
        long long d=extend_gcd(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }
}

long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extend_gcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}

LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(m > n) return 0;
    if(m==0)return 1;
    int id = pnt[p];
    LL nn = mod[id][n],mm=(mod[id][m]*mod[id][n-m])%p;
    LL x = mod_reverse(mm,p);
    return (nn*x)%p;
//    LL ans = 1;
//    for(int i=1; i<=m; i++)
//    {
//        LL a = (n + i - m) % p;
//        LL b = i % p;
//        ans = ans * (a * quick_mod(b, p-2) % p) % p;
//    }
//    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

void init()
{
    initprime();
    for(int i=0;i<cnt;i++)
    {
        mod[i][0] = 1;
        for(int j=1;j<=prime[i];j++)
        {
            mod[i][j] = (mod[i][j-1]*j)%prime[i];
        }
    }
}

int main()
{
    init();
    int T = 1;
    while(~scanf("%lld%lld%lld", &n, &m,&p))
    {
        if(2*m<n)
            printf("Case #%d: %lld\n",T++,(Lucas(n+1,m)+n-m)%p);
        else
            printf("Case #%d: %lld\n",T++,(Lucas(n+1,m+1)+m)%p);
    }

    return 0;
}
