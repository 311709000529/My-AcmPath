#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 100050

int par[maxn] ,n ,m ;

struct edge {
	int u ,v ,w ; // u起点 v 终点 w 边权 
} ss[maxn * 10] ;

void init() { // 并查集的初始化，开始的时候树根都指向自己 
	for (int i = 0 ; i < maxn ; i ++ ) {
		par[i] = i;
	}
}

//并查集 ：查找树根，如果不会的话可以参考一下之前发的视频 
int find(int x) {
	if ( par[x] == x ) return x;
	return par[x] = find(par[x]) ; //路径压缩 
}

void unite(int x,int y) { // 合并连个两个树 
	x = find(x) ,y = find(y) ;
	if ( x != y ) par[x] = y; 
} 

//比较函数，将结构体按照w这一个参数从大到小排序 
// 参见 :  https://blog.csdn.net/latte_z/article/details/17049479
int cmp(edge x,edge y) {
	return x.w < y.w ;
} 

int kruskal() {
	int nedge = 0 ,sum = 0 ; 
	//sum统计最小生成树的权值，
	//nedge统计加入的边的数量，n个点需要加入n-1条边，如果少于n-1条，说明没有形成最小生成树 
	for (int i = 1 ; i <= m ; i ++ ) {
		if ( find(ss[i].u) != find(ss[i].v) ) { //如果起点和终点没有在一个集合，那么加入这条边 
			sum += ss[i].w ; // 加上这条边的边权 
			unite(ss[i].u ,ss[i].v ) ; //然后将这两个集合合并 
			nedge ++ ; //边数加加 
		}
	}
	if ( nedge == n - 1 ) return sum ;
	else return -1 ;
}

int main() {
	init() ;   
	scanf("%d %d",&n ,&m ) ; // n点的数量 m边的数量 
	for (int i = 1 ; i <= m ; i ++ ) {
		scanf("%d %d %d",&ss[i].u ,&ss[i].v ,&ss[i].w ) ; // 读入格式:   起点  终点  边权  
	} 
	// sort排序 
	sort(ss + 1 ,ss + m + 1 ,cmp ) ;
	int ans = kruskal() ;
	if ( ans == -1 ) {
		printf("最小生成树不存在\n") ;
	} else {
		printf("最小生成树是: %d\n",ans) ;
	}
	return 0;
}

/*
两组测试数据 : 
 
5 4
1 2 5
2 4 6
1 4 7
3 5 5

5 10
1 2 11
1 3 30
1 4 9
1 5 10
2 3 7
2 4 11
2 5 20
3 4 16
3 5 21
4 5 18
*/
