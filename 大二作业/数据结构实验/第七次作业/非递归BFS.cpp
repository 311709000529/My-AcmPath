#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

vector<int>G[maxn] ;
int n ,m ,u ,v ,st ;

void BFS(int st) {
	queue<int>que;
	que.push(st) ;
	while ( !que.empty() ) {
		int top = que.front() ; que.pop() ;
		printf("%d ",top) ;
		int len = G[top].size();
		for (int i = 0 ; i < len ; i ++ ) {
			que.push(G[top][i]);
		}
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
	printf("BFS非递归遍历结果为: ");
	BFS(st) ;
	return 0;
}
