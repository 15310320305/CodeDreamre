
/** ���粢�鼯1856   */
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 10000001
int p[MAX],vis[MAX];
int n,m;
void init(){for(int i=1;i<=MAX-1;i++){p[i]=i;}} //��ʼ��
int Getfather (int a){if(a!=p[a])p[a]=Getfather(p[a]);return p[a];} //�õ����ڵ�
void Union(int a,int b){    //�ϲ�a��b�����������ļ���
    int ta = Getfather(a);
    int tb = Getfather(b);
    if(ta==tb)return ;
     if(ta<=tb){p[tb]=p[ta];}
    else {p[ta]=p[tb];}
    return ;
}

int main()
{
    while(cin>>n){
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        init();
        while(n--){
            int a,b;
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        for(int i=1;i<=MAX-1;i++){
             if(p[i]==i)vis[i]++;
             else {
                vis[Getfather(i)]++;
             }
        }
        int ans=vis[1];
         for(int i=2;i<=MAX-1;i++){
            if(vis[i]>ans)ans=vis[i];
         }
         printf("%d\n",ans);

    }
    return 0;
}
