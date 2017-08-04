/**  HDU5876  */


#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

const int maxn = 200055;

struct nod{
    int v,nex;
}edge[maxn<<1];

int n,m,e;
int hed[maxn],dis[maxn];

void addedge(int u,int v){edge[e].v=v,edge[e].nex=hed[u],hed[u]=e++;}

void bfs(int ss){
    set<int>s,s1;
    queue<int>q;
    q.push(ss);
    for(int i=1;i<=n;i++)if(i!=ss)s.insert(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=hed[u];~i;i=edge[i].nex){
            int v=edge[i].v;
            if(!s.count(v))continue;
            s.erase(v);
            s1.insert(v);
        }

        for(set<int>::iterator it=s.begin();it!=s.end();++it){
            dis[*it]=dis[u]+1;
            q.push(*it);
        }
        s.swap(s1);
        s1.clear();
    }
}

int main()
{
    int t;cin>>t;
    while(t--){
       scanf("%d%d",&n,&m);
       memset(hed,-1,sizeof(hed));
       for(int i=1;i<=n;i++)dis[i]=1e9;
       e=1;
        for(int i=0;i<m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            addedge(u,v);addedge(v,u);
        }
        int s;scanf("%d",&s);
        dis[s]=0;
        bfs(s);
        int flag=0;
        for(int i=1;i<=n;i++){
            if(i!=s){
                if(flag)printf(" ");
                if(dis[i]!=1e9)printf("%d",dis[i]);
                else printf("-1");
                flag=1;
            }
        }
        printf("\n");
    }

    return 0;
}
