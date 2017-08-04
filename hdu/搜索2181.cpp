/** º¼µç2181   */


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct ss{
    int a;
    int b;
    int c;
}s[21];

int bj[21];
int ans[21];
int mm;
int js;

void dfs(int m,int n)
{
    if(m==mm&&n==20){
           printf("%d:  ",js++);
        for(int i=0;i<n;i++)
        {
            if(i==0)printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        printf(" %d\n",mm);
        return ;
    }
    if(m==0)
    m=mm;
    ans[n++]=m;
    if(s[m].a<s[m].b){
        swap(s[m].a,s[m].b);
    }
    if(s[m].a<s[m].c){
        swap(s[m].a,s[m].c);
    }
    if(s[m].b<s[m].c){
        swap(s[m].b,s[m].c);
    }
    if(bj[s[m].c]==0){
        bj[s[m].c]=1;
        dfs(s[m].c,n);
        bj[s[m].c]=0;
    }
    if(bj[s[m].b]==0){
        bj[s[m].b]=1;
        dfs(s[m].b,n);
        bj[s[m].b]=0;
    }
      if(bj[s[m].a]==0){
        bj[s[m].a]=1;
        dfs(s[m].a,n);
        bj[s[m].a]=0;
    }
}

int main()
{
    for(int i=1;i<=20;i++)
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
    while(cin>>mm&&mm){
            js=1;
            memset(bj,0,sizeof(bj));
        dfs(0,0);
    }
    return 0;
}
