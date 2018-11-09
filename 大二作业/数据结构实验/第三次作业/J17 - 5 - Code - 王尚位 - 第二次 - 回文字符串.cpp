#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 50 ;

int dp[maxn][maxn] ,t ,len ;
char str[maxn] ;

inline int Min(int a,int b) { return a > b ? b : a; }

int main() {
	cin >> t ;
	while ( t -- ) {
		memset(dp ,0 ,sizeof(dp) ) ;
		scanf ("%s",str + 1);
		len = strlen(str + 1) ; 
		for (int i = 1 ; i <= len ; i ++ ) dp[i][i] = 0;
		for (int l = 2 ; l <= len ; l ++ ) {
			for (int i = 1 ; i <= len - l + 1 ; i ++ ) {
				int j = i + l - 1 ; 
				dp[i][j] = Min(dp[i + 1][j] ,dp[i][j-1] ) ;
				if ( str[i] == str[j] ) dp[i][j] = dp[i+1][j-1];
				else {
					dp[i][j] ++;
				} 
			}
		}
//		for (int i = 1 ; i <= len ; i ++) {
//			for (int j = 1 ; j <= len ; j ++ ) {
//				printf("%d ",dp[i][j]);
//			} printf("\n");
//		}
		printf("%d\n",dp[1][len]);
	} 
	return 0;
}
