#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 9989899+1;

bool prim[maxn+1];
int ans[800];

void init() {
    memset(prim,true,sizeof(prim));
    prim[0] = prim[1] = false;
    for (int i = 2 ; i < maxn ; i ++ ) {
    	for (int j = 2 ; i * j < maxn ; j ++ ) prim[i * j] = false;
	}
}

bool palindrome(int n) {
    int sum = 0 ,nn = n ;
    while (n) {
        sum = sum * 10 + n % 10 ;
        n /= 10;
    }
    return sum==nn;
}

int main() {
   int n ,m ,k = 0 ;
   init();
   for (int i = 2 ; i < maxn ; i ++ ) {
       if(prim[i] && palindrome(i)) ans[k++] = i ;
   }
   while ( ~scanf("%d %d",&n ,&m ) ) {
        for (int i = 0 ; i <= k ; i ++ ) {
            if( ans[i] < n ) continue;
            else if( ans[i] > m ) break;
            else cout<<ans[i]<<endl;
        }
        cout<<endl;
   }
    return 0;
}
