#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
int n , m , x , y , ans;
int ss()
{
    ans = (n+1)/2 ;
        if( n == m && n%2==1 && ans == x && ans == y )
            ans-- ;
    int flag = max(ans,max(min(x-1,min(y,m-y+1)),min(n-x,min(y,m-y+1))) );
    return flag;
}
int main() {


    while( scanf("%d %d %d %d", &n, &m, &x, &y) != EOF ) {
        if( n > m ) {
            swap(n,m) ;
            swap(x,y) ;
        }
        if( n == 1 )
            printf("1\n") ;
        else
            printf("%d\n",ss());
    }
    return 0 ;
}
