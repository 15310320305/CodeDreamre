#include<bits/stdc++.h>
using namespace std;
struct st
{
    string s;
    int len;
    st(string s,int len):s(s),len(len){}
    st(){}
    bool operator<(const st&a)const
    {
        return len>a.len;
    }
};
string s1,s2;
int bfs()
{
    map<string,int>mp;
    priority_queue<st>q;
    q.push(st(s1,0));
    while(!q.empty())
    {
        st a = q.top();
        q.pop();
        if(mp[a.s])continue;
        mp[a.s]++;
        if(a.s==s2)return a.len;

        string ss = a.s;
        ss[2]=a.s[0],ss[3]=a.s[1];
        ss[1]=a.s[2],ss[0]=a.s[3];
        q.push(st(ss,a.len+1));
        ss[2]=a.s[1],ss[3]=a.s[0];
        ss[1]=a.s[3],ss[0]=a.s[2];
        q.push(st(ss,a.len+1));
        ss = a.s;
        ss[5] = a.s[0],ss[4]=a.s[1];
        ss[0]=a.s[4],ss[1]=a.s[5];
        q.push(st(ss,a.len+1));
        ss[5] = a.s[1],ss[4]=a.s[0];
        ss[0]=a.s[5],ss[1]=a.s[4];
        q.push(st(ss,a.len+1));
    }
    return -1;
}
int main()
{
    int x;
    while(~scanf("%d",&x))
    {
        s1.clear();
        s2.clear();
        s1+='0'+x;
        for(int i=0;i<5;i++)
        {
            scanf("%d",&x);
            s1+='0'+x;
        }
        for(int i=0;i<6;i++)
        {
            scanf("%d",&x);
            s2+='0'+x;
        }
        //cout<<s1<<" "<<s2<<endl;
        printf("%d\n",bfs());
    }

    return 0;
}
