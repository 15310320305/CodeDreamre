/**����1232 ���鼯   */


#include int pre[1000 ];
int find(int x)
{
    int r=x;
   while (pre[r ]!=r)
   r=pre[r ];
   int i=x; int j;
   while(i!=r)
   {
       j=pre[i ];
       pre[i ]=r;
       i=j;
   }
   return r;
}
int main()
{
   int n,m,p1,p2,i,total,f1,f2;
   while(scanf("%d",&n) && n)         //����n�����nΪ0������
   {                                                    //�տ�ʼ��ʱ����n������һ��·��û�� //��ôҪ��n-1��·���ܰ�����������
       total=n-1;
       //ÿ���㻥��������Գ�һ�����ϣ���1��ŵ�n //����ÿ������ϼ������Լ�
       for(i=1;i<=n;i++) { pre[i ]=i; }                //����m��·
       scanf("%d",&m); while(m--)
       { //������δ��룬��ʵ����join������ֻ�������Ķ�����Ӧ��ĿҪ��
           //ÿ����һ��·�������Ķ˵�p1��p2�Ƿ��Ѿ���һ����ͨ��֧����
           scanf("%d %d",&p1,&p2);
           f1=find(p1);
           f2=find(p2);
               //����ǲ���ͨ�ģ���ô����������֧������
               //��֧�������ͼ�����1�����轨��·Ҳ�ͼ���1
           if(f1!=f2)
            {
               pre[f2 ]=f1;
               total--;
           }
           //��������Ѿ���ͨ�ˣ���ô����·ֻ����ͼ��������һ���� //����ͨ��û���κ�Ӱ�죬���ӵ�
       }
//��������Ҫ�޵�·����
       printf("%d\n",total);
   }
   return 0;
}

/**  д��2  */
/*

#include<iostream>
using namespace std;

int  pre[1050];
bool t[1050];               //t ���ڱ�Ƕ�����ĸ����

int Find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];

    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}

void mix(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
    {
        pre[fy]=fx;
    }
}

int main()
{
    int N,M,a,b,i,j,ans;
    while(scanf("%d%d",&N,&M)&&N)
    {
        for(i=1;i<=N;i++)          //��ʼ��
            pre[i]=i;

        for(i=1;i<=M;i++)          //���ղ���������
        {
            scanf("%d%d",&a,&b);
            mix(a,b);
        }


        memset(t,0,sizeof(t));
        for(i=1;i<=N;i++)          //��Ǹ����
        {
            t[Find(i)]=1;
        }
        for(ans=0,i=1;i<=N;i++)
            if(t[i])
                ans++;

        printf("%d\n",ans-1);

    }
    return 0;
}//dellaserss

*/


