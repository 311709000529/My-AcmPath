#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

vector<int>G[maxn] ;
int n ,m ,u ,v ,st ;

void DFS(int st) {
	int len = G[st].size();
	for (int i = 0 ; i < len ; i ++ ) {
		printf("%d ",G[st][i]);
		DFS(G[st][i]);
	}
}

int main() {
	printf("请输入点的数量和边的数量: ");
	scanf("%d %d",&n ,&m ) ;
	for (int i = 1 ; i <= m ; i ++ ) {
		printf("请输入第%d条边的起点终点: ",i); 
		scanf("%d %d",&u ,&v ) ;
		G[u].push_back(v);
	}
	printf("请输入起点位置: ");
	scanf("%d",&st);
	printf("DFS递归遍历结果为: ");
	printf("%d ",st);
	DFS(st);
	return 0;
} 
