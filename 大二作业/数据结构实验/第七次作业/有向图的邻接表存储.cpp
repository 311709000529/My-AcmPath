#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 50 ;
const int inf = 0x3f3f3f3f;

typedef char VertexType ;
typedef char GraphType ;
typedef int OtherInfo;

typedef struct ArcNode{
     int adjvex;
     struct ArcNode *nextarc;
     OtherInfo info ;
}ArcNode;

typedef struct VNode{
     VertexType data;
     ArcNode *firstarc;
}VNode, AdjList[maxn];       

typedef struct{
     AdjList vertices ;
     int vexnum, arcnum ;
     GraphType kind ;
}ALGraph;

ALGraph G;
int u ,v ,w ;

void Push(int u ,int v ,int w ) {
	if ( G.vertices[u].firstarc == NULL ) {
		G.vertices[u].firstarc = new ArcNode;
		G.vertices[u].firstarc->nextarc = NULL;
		G.vertices[u].firstarc->info = w;
		G.vertices[u].firstarc->adjvex = v;
	} else {
		ArcNode *temp = G.vertices[u].firstarc;
		while ( temp != NULL ) {
			temp = temp->nextarc;
		}
		temp = new ArcNode;
		temp->info = w;
		temp->adjvex = v;
	}
}

int main() {
	printf("请输入点的数量和边的数量: ") ;
	scanf("%d %d",&G.vexnum ,&G.arcnum ) ; 
	for (int i = 0 ; i <= G.vexnum ; i ++ ) G.vertices[i].firstarc = NULL;
	for (int i = 1 ; i <= G.vexnum ; i ++ ) {
		printf("请输入第%d个顶点信息: ",i);
		getchar(); 
		scanf("%c",&G.vertices[i].data);
	}
	for (int i = 1 ; i <= G.arcnum ; i ++ ) {
		printf("请输入第%d条边的起始位置和终止位置以及权重: ",i );
		scanf("%d %d %d",&u ,&v ,&w ) ;
		Push(u ,v ,w ) ;
	}
	return 0;
}
