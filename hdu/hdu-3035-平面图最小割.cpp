#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int maxn = 1e6+100;
const int inf = 1e9;

struct nod{
   int v,w,nex;
}edge[maxn<<2];

int n,m,nn,e,k;
int dis[maxn],hed[maxn];
bool vis[maxn];

void add(int u,int v,int w){
    edge[e].v = v,edge[e].w = w,edge[e].nex = hed[u],hed[u]=e++;
    edge[e].v = u,edge[e].w = w,edge[e].nex = hed[v],hed[v]=e++;
}

void dij(){
   for(int i=0;i<=nn;i++)
    dis[i]=inf,vis[i]=0;
   dis[0]=0;
   priority_queue<pair<int,int > >q;
   q.push(make_pair(-dis[0],0));
   while(!q.empty()){
        int u = q.top().second;q.pop();
        if(vis[u])continue;vis[u]=1;
        for(int i=hed[u];~i;i=edge[i].nex){
            int v = edge[i].v;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if(!vis[v]){
                    q.push(make_pair(-dis[v],v));
                }
            }

        }
   }
}

int main()
{
    while(~scanf("%d%d",&n,&m)){
        nn = n*m*4+1;e=0;
        memset(hed,-1,sizeof(hed));
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&k);
                if(i==1)                  //������ı�
                    add(nn,(j-1)*4+1,k);
                else if(i==n+1)            //������ı�
                    add(0,(n-1)*m*4+(j-1)*4+3,k);
                else                       //�м�ˮƽ�ı�
                    add((i-2)*m*4+(j-1)*4+3,(i-1)*m*4+(j-1)*4+1,k);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m+1;j++){
                scanf("%d",&k);
                if(j==1)                 //������ı�
                    add(0,(i-1)*m*4+2,k);
                else if(j==m+1)            //������ı�
                    add(nn,i*m*4,k);
                else                        //�м䴹ֱ�ı�
                    add((i-1)*m*4+(j-1)*4,(i-1)*m*4+(j-1)*4+2,k);
            }
        }
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*m;j++){
                scanf("%d",&k);
                //�м�б�ŵıߣ������ʽ��ͼ�ϻ���Ӧ�ò�����
                add(i/2*m*4+j/2*4+1+(i%2)*2,i/2*m*4+j/2*4+2+(j%2)*2,k);
            }
        }
        dij();
        printf("%d\n",dis[nn]);
    }
    return 0;
}
