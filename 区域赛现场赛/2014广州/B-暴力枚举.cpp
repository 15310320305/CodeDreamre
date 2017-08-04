#include<bits/stdc++.h>

using namespace std;
struct point
{
    int x,y;
}p[33];
struct rec
{
  int x1,y1,x2,y2;
}s[10000];
bool cmp(point a,point b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int cnt;
int n;
bool isrec(int i,int j,int k,int l)
{
    if(p[i].x==p[j].x&&p[k].x==p[l].x&&p[k].x>p[j].x&&p[i].y==p[k].y&&p[j].y==p[l].y&&p[j].y>p[i].y)return true;
    else return false;
}
int isok(int i,int j)
{
    if(s[i].x2<s[j].x1||s[i].x1>s[j].x2||s[i].y2<s[j].y1||s[i].y1>s[j].y2)
        return 1;
    if(s[i].x1>s[j].x1&&s[i].x2<s[j].x2&&s[i].y1>s[j].y1&&s[i].y2<s[j].y2)
        return 2;
    if(s[j].x1>s[i].x1&&s[j].x2<s[i].x2&&s[j].y1>s[i].y1&&s[j].y2<s[i].y2)
        return 2;
    return 0;
}
int main()
{
    while(cin>>n,n)
    {
        cnt = 0;
        for(int i=0;i<n;i++)scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        if(isrec(i,j,k,l))
                        {
                            s[cnt].x1 = p[i].x,s[cnt].y1 = p[i].y,s[cnt].x2 = p[l].x,s[cnt++].y2 = p[l].y;
                        }
                    }
                }
            }
        }
       // cout<<cnt<<endl;
        int ans = 0;
        for(int i=0;i<cnt;i++)
        {
            for(int j=i+1;j<cnt;j++)
            {

                if(isok(i,j)==1)
                {
//                    cout<<s[i].x1<<" "<<s[i].y1<<" "<<s[i].x2<<" "<<s[i].y2<<endl;
//                    cout<<s[j].x1<<" "<<s[j].y1<<" "<<s[j].x2<<" "<<s[j].y2<<endl;
//                    cout<<endl;
                    ans = max(ans,(s[i].x2-s[i].x1)*(s[i].y2-s[i].y1)+(s[j].x2-s[j].x1)*(s[j].y2-s[j].y1));
                }
                else if(isok(i,j)==2)
                {
                    ans = max(ans,max((s[i].x2-s[i].x1)*(s[i].y2-s[i].y1),(s[j].x2-s[j].x1)*(s[j].y2-s[j].y1)));
                }
            }
        }
        if(ans==0)printf("imp\n");
        else printf("%d\n",ans);

    }
    return 0;
}
