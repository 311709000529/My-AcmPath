#include <stdio.h>

#define maxn 1005

int arr[maxn][maxn] ;
int n ,m ,v[100050] ;

int main() {
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i ++ ) {
		scanf("%d",&v[i]);
	}
	for (int i = 1 ; i <= 1005 ; i ++ ) {
		if(i * i == n) {
			m = i ;
			break;
		}
	}
	int pos = 1;
	for (int i = 1 ; i <= m ; i ++) {
		for (int j = 1 ; j <= m ; j ++ ) {
			arr[i][j] = v[pos ++] ;
		}
	}
	for (int i = 1 ; i <= m ; i ++ ) {
		for (int j = 1 ; j <= m ; j ++ ) {
			printf("%d ",arr[i][j]);
		} puts("");
	}
	return 0;
}
