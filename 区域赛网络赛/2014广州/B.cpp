//#include<bits/stdc++.h>
//const int maxn = 1e6+100;
//
//using namespace std;
//
//int Tree[maxn<<2],c[maxn<<2];
//int n,q;
//
//void pushup(int rt)
//{
//    Tree[rt] = Tree[rt<<1]|Tree[rt<<1|1];
//}
//void pushdown(int rt)
//{
//    if(c[rt])
//    {
//        c[rt<<1]=c[rt];
//        c[rt<<1|1]=c[rt];
//        Tree[rt<<1]=c[rt];
//        Tree[rt<<1|1]=c[rt];
//        c[rt] = 0;
//    }
//}
//
//void Build(int l,int r,int rt)
//{
//    c[rt] = 0;
//    if(l==r)
//    {
//        Tree[rt] = 2;
//        return ;
//    }
//    int mid = (l+r)>>1;
//    Build(l,mid,rt<<1);
//    Build(mid+1,r,rt<<1|1);
//    pushup(rt);
//}
//
//void updata(int l,int r,int rt,int L,int R,int w)
//{
//    if(L<=l&&r<=R)
//    {
//        c[rt]=(1<<w);
//        Tree[rt]=(1<<w);
//        return ;
//    }
//    pushdown(rt);
//
//    int mid = (l+r)>>1;
//    if(L<=mid)
//    {
//        updata(l,mid,rt<<1,L,R,w);
//    }
//    if(R>mid)
//    {
//        updata(mid+1,r,rt<<1|1,L,R,w);
//    }
//    pushup(rt);
//}
//
//int query(int l,int r,int rt,int L,int R)
//{
//    if(L<=l&&r<=R)
//    {
//        return Tree[rt];
//    }
//    pushdown(rt);
//    int res = 0;
//    int mid = (l+r)>>1;
//    if(L<=mid)res|=query(l,mid,rt<<1,L,R);
//    if(R>mid)res|=query(mid+1,r,rt<<1|1,L,R);
//    return res;
//}
//
//int main()
//{
//    while(~scanf("%d%d",&n,&q),n+q)
//    {
//        Build(1,n,1);
//        while(q--)
//        {
//            char str[10];
//            int a,b,w;
//            scanf("%s",str);
//            if(str[0]=='P')
//            {
//                scanf("%d%d%d",&a,&b,&w);
//                updata(1,n,1,a,b,w-1);
//            }
//            else
//            {
//                scanf("%d%d",&a,&b);
//                int ans = query(1,n,1,a,b);
//                int f = 0;
//                for(int i=1;i<=30;i++)
//                {
//                    if((1<<(i-1))&ans)
//                    {
//                        if(f)printf(" ");
//                        printf("%d",i);
//                        f = 1;
//                    }
//                }
//                if(f)cout<<endl;
//            }
//        }
//    }
//
//    return 0;
//}
