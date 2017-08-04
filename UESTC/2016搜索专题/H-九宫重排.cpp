#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;

struct nod
{
    char s[10];
    int len;
};
queue<nod>q;
int fx[4][2] = {1,0,-1,0,0,-1,0,1};
void bfs()
{

    while(!q.empty())
    {
        nod a = q.front();
        q.pop();
        nod b;
        b.len = a.len+1;
        int x,y;
        char s[10];
        for(int i=0;i<9;i++)
        {
            if(a.s[i]=='9')
            {
                x = i/3;
                y = i%3;
                break;
            }
        }
        for(int i=0;i<9;i++)s[i] = a.s[i];
        s[9] = '\0';
       // printf("%s\n",s);
        //cout<<x<<"             "<<y<<endl;
        for(int i=0;i<4;i++)
        {
            int xx = x+fx[i][0],yy = y+fx[i][1];
           // cout<<xx<<" "<<yy<<endl;
            if(xx>=0&&xx<3&&yy>=0&&yy<3)
            {
                swap(s[x*3+y],s[xx*3+yy]);
               // printf("%s\n",s);
                if(mp[s]==0)
                {
                    //cout<<s<<" "<<a.len+1<<endl;
                    mp[s]=a.len+1;
                    for(int j=0;j<9;j++)
                        b.s[j] = s[j];
                    b.s[9] = '\0';
                    q.push(b);
                }
                swap(s[x*3+y],s[xx*3+yy]);
            }
        }

    }

}

int main()
{
    nod a;
    for(int i=1;i<=9;i++)a.s[i-1] = '0'+i;a.s[9] = '\0';
    mp[a.s] = 1;
    a.len = 1;
    q.push(a);
    bfs();

    int t;cin>>t;
    while(t--)
    {
        char ch[2];
        char s[10];
        for(int i=0;i<9;i++)
        {
            scanf("%s",ch);
            if(ch[0]=='x')
                ch[0]='9';
            s[i] = ch[0];
        }
        s[9] = '\0';
        printf("%d\n",mp[s]-1);
    }
    return 0;
}
