#include<bits/stdc++.h>
using namespace std;
long long a,b;
const long long mod = 2147493647;
int n;

struct Maxtrix
{
    long long ans[8][8];
    Maxtrix operator *(const Maxtrix a)
    {
        Maxtrix ans1;
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                long long sum = 0;
                for(int k=0;k<7;k++)
                    sum+=ans[i][k]*a.ans[k][j]%mod;
                ans1.ans[i][j] = sum%mod;
            }
        }
        return ans1;
    }
};

void sove()
{
    Maxtrix ans,m,mm;
    memset(ans.ans,0,sizeof(ans.ans));
    memset(m.ans,0,sizeof(m.ans));
    memset(mm.ans,0,sizeof(mm.ans));
    for(int i=0;i<7;i++)mm.ans[i][i] = 1;
    ans.ans[0][0] = a,ans.ans[1][0] = b,ans.ans[2][0] = 16ll,ans.ans[3][0] = 8ll,ans.ans[4][0] = 4ll;
    ans.ans[5][0] = 2ll,ans.ans[6][0] = 1ll;
    m.ans[0][1] = 1;
    m.ans[1][0] = 2,m.ans[1][1] = 1,m.ans[1][2] = 1,m.ans[1][3] = 4,m.ans[1][4] = 6,m.ans[1][5] = 4,m.ans[1][6] = 1;
    m.ans[2][2] = 1,m.ans[2][3] = 4,m.ans[2][4] = 6,m.ans[2][5] = 4,m.ans[2][6] = 1;
    m.ans[3][3] = 1,m.ans[3][4] = 3,m.ans[3][5] = 3,m.ans[3][6] = 1;
    m.ans[4][4] = 1,m.ans[4][5] = 2,m.ans[4][6] = 1;
    m.ans[5][5] = 1,m.ans[5][6] = 1;
    m.ans[6][6] = 1;
    if(n==1)printf("%lld\n",a);
    else if(n==2)printf("%lld\n",b);
    else
    {
        n-=2;
        while(n)
        {
            if(n%2)mm = mm*m;
            m= m*m;
            n/=2;
        }
        ans = mm*ans;
        printf("%lld\n",ans.ans[1][0]);
    }

}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%lld%lld",&n,&a,&b);
        sove();
    }

    return 0;
}
