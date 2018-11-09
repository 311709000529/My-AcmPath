#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

vector<int>G[maxn];
stack<int>sta ;
int n ,m ,st ,u ,v ; 

void DFS(int st) {
	sta.push(st) ;
	while ( !sta.empty() ) {
		int top = sta.top(); sta.pop();
		int len = G[top].size();
		for (int i = 0 ; i < len ; i ++ ) {
			sta.push(G[top][i]);
		}
		printf("%d ",top);
	}
}

int main() {
	printf("请输入点的数量和边的数量: ");
	scanf("%d %d",&n ,&m ) ;
	for (int i = 1 ; i <= m ; i ++ ) {
		printf("请输入第%d条边的起点终点: ",i ); 
		scanf("%d %d",&u ,&v ) ;
		G[u].push_back(v);
	}
	printf("请输入起点位置: ");
	scanf("%d",&st);
	printf("DFS递归遍历结果为: ");
	DFS(st);
	return 0;
}

