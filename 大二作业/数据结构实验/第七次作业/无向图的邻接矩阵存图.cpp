#include <bits/stdc++.h>

using namespace std;

const int inf = 32678;
const int maxn = 1e3 + 50 ;

typedef int ArcType; 
typedef char vertexType;

typedef struct {
	vertexType vertex[maxn] ;
	ArcType arrMap[maxn][maxn] ;
	int veterixNum ,veterixEdge ;
}adjMaterix;

adjMaterix G;
int u ,v ,w ;

int main() {
	
	printf("请输入点的数量和边的数量: ") ;
	scanf("%d %d",&G.veterixNum ,&G.veterixEdge ) ;
	for (int i = 0 ; i <= G.veterixNum ; i ++ ) {
		for (int j = 0 ; j <= G.veterixNum ; j ++ ) {
			G.arrMap[i][j] = inf ;
		}
	}
	for (int i = 1 ; i <= G.veterixNum ; i ++ ) {
		printf("请输入第%d个顶点信息: ",i);
		getchar(); 
		scanf("%c",&G.vertex[i]); 
	}
	for (int i = 1 ; i <= G.veterixEdge ; i ++ ) {
		printf("请输入第%d条边的起始位置和终止位置以及权重: ",i );
		scanf("%d %d %d",&u ,&v ,&w) ;
		G.arrMap[u][v] = G.arrMap[v][u] =  w;
	}
	return 0;
}
