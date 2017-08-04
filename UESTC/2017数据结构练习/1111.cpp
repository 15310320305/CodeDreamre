#include<bits/stdc++.h>

using namespace std;
const int N = 10005;

typedef struct
{
    int x,y;
    int ans;
}Node;

Node node[N];

int n;

void Cover(int l,int r,int k,int c)
{
    while(k<n&&(r<node[k].x||l>node[k].y)) k++;
    if(k>=n)        //当前进行切割的线段并没有和后面的线段相交
    {
        node[c].ans+=r-l+1;
        return;
    }
    if(l<node[k].x) Cover(l,node[k].x-1,k+1,c);   //当前线段的右边被覆盖；
    if(r>node[k].y) Cover(node[k].y+1,r,k+1,c);   //当前线段的左边被覆盖；
}

int main()
{
    freopen("1.txt","r",stdin);
    int t,i,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        memset(node,0,sizeof(node));
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&node[i].x,&node[i].y);
        for(i=n-1;i>=0;i--)            //这里是用后面的海报覆盖前面的海报，所以要从后面开始进行插入（进行线段切割）；
            Cover(node[i].x,node[i].y,i+1,i);
        for(i=0;i<n;i++)
            if(node[i].ans>0)
                sum++;
        printf("%d\n",sum);
    }
    return 0;
}

