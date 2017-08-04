#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int maxn = 10005;
const int maxm = 20005;

int n,m,e;

int hed[maxn],pnt[maxm],nex[maxm];

int M[maxn],num[maxn];

void addedge(int u,int v){
    pnt[e]=v,nex[e]=hed[u],hed[u]=e++;
}

void topsort(){
    queue<int>q,q1;
    for(int i=1;i<=n;i++){
        if(!num[i]){
            q.push(i);
            M[i]=888;
        }
    }
    while(!q.empty()){
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=hed[u];~i;i=nex[i]){
                int v=pnt[i];
                if(--num[v]==0){
                    q1.push(v);
                    M[v]=M[u]+1;
                }
            }
        }
        swap(q,q1);
    }
}

int main()
{
    while(cin>>n>>m){
        memset(hed,-1,sizeof(hed));
        memset(num,0,sizeof(num));
        memset(M,0,sizeof(M));
        e=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&v,&u);
            addedge(u,v);
            num[v]++;
        }
        topsort();
        int sum=0;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(M[i])sum+=M[i];
            else flag=1;
        }
        if(flag)cout<<-1<<endl;
        else cout<<sum<<endl;
    }
    return 0;
}
