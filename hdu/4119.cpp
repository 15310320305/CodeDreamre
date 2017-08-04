#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

char mp[55][55],s[4][55][55];
int n,m;
map<string,int>word;
char ans[4][2500];
int cnt[4];

struct nod{
    char word[1350][25];
    int word_num;
    nod(){word_num=0;}
};

int main()
{
    int t;cin>>t;int T=1;
    while(t--){
        word.clear();
        scanf("%d",&n);
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=0;i<n;i++)scanf("%s",mp[i]);
        for(int i=0;i<n;i++)scanf("%s",s[0][i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            char str[25];scanf("%s",str);
            word[str]=1;
        }
        for(int k=1;k<4;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    s[k][i][j]=s[k-1][n-j-1][i];
                }
                s[k][i][n]='\0';
            }
        }
        for(int k=0;k<4;k++){
            for(int i=0;i<n;i++){
                 for(int j=0;j<n;j++){
                    if(s[k][i][j]=='*'){
                        if(mp[i][j]=='.')mp[i][j]=' ';
                        ans[k][cnt[k]++]=mp[i][j];
                    }
                 }
            }
            ans[k][cnt[k]]='\0';
        }
        nod res;
        for(int i=0;i<4;i++){
                nod c;
                int len=0,flag=1;
                char str[1000];
            for(int j=0;j<4;j++){
                int id = (i+j)%4;
                for(int k=0;k<cnt[id];k++){
                    if(ans[id][k]!=' '){
                        str[len++]=ans[id][k];
                        if(j==3&&k==cnt[id]-1)goto A;
                    }
                    else {
                        A:
                        if(len==0)continue;
                        str[len]='\0';
                        if(word[str]==0){
                            flag=0;
                            break;
                        }
                        c.word_num++;
                        memcpy(c.word[c.word_num],str,sizeof(c.word[c.word_num]));
                        len = 0;
                    }
                }
                if(flag==0)break;

            }

            if(flag){
             if(res.word_num==0){
                res = c;
             }else {
                for(int ii = 1;ii<=c.word_num;ii++){
                    if(strcmp(res.word[ii],c.word[ii])>0){
                        res = c;
                        break;
                    }else if(strcmp(res.word[ii],c.word[ii])<0)break;
                }
             }

            }
        }
        printf("Case #%d:",T++);
        if(res.word_num==0)printf(" FAIL TO DECRYPT\n");
        else {
            for(int i=1;i<=res.word_num;i++)
                printf(" %s",res.word[i]);
            printf("\n");
        }

    }
    return 0;
}







