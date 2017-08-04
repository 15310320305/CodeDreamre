/** 5874  */


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
    long long n,m;
    while(cin>>n>>m){
        if(n/2*(n-n/2)<=m)printf("T\n");
        else printf("F\n");
    }
    return 0;
}
