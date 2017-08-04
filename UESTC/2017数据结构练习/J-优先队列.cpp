#include<bits/stdc++.h>
using namespace std;
struct nod
{
    long long v;
    nod(int v):v(v){}
    nod(){}
    bool operator<(const nod&a)const
    {
        return a.v<v;
    }
};
int n;
int main()
{
    cin>>n;
    priority_queue<nod>q;
    for(int i=1;i<=n;i++)
    {
        long long x;scanf("%lld",&x);
        q.push(nod(x));
    }
    long long ans = 0;
    while(q.size()>1)
    {
        nod b = q.top();
        q.pop();
        nod a = q.top();
        q.pop();
        ans+=a.v+b.v;
        q.push(a.v+b.v);
    }
    cout<<ans<<endl;

    return 0;
}
