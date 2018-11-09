#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

typedef char **HuffmanCode;
typedef struct Node
{
	int weight;
	int parent ,lchild ,rchild ;
}HTNode ,*HuffmanTree ;

int weight[maxn] ;
char str[maxn] ;
map<char ,int >mp ;
map<int ,char >mmp;

void Select(HuffmanTree HT ,int pos ,int &s1 ,int &s2 ) {
	int min1 = 0x3f3f3f3f ,min2 = 0x3f3f3f3f ;
	for (int i = 1 ; i <= pos ; i ++ ) {
		if ( !HT[i].parent && min1 > HT[i].weight) {
			min1 = HT[i].weight; s1 = i;
		}
	}
	HT[s1].parent = 1;
	for (int i = 1 ; i <= pos ; i ++ ) {
		if ( !HT[i].parent && min2 > HT[i].weight ) {
			min2 = HT[i].weight; s2 = i ;
		}
	}
}

void CreatHuffmanTree(HuffmanTree &HT ,int n ) {
	if ( n <= 1 ) return;
	int m = 2 * n  ;
	HT = new HTNode[m+1] ;
	for (int i = 1 ; i <= m ; i ++ ) {
		HT[i].parent = HT[i].lchild = HT[i].rchild = HT[i].weight = 0;
	}
	for (int i = 1 ; i <= n ; i ++ ) {
		HT[i].weight = weight[i] ;
	}
	int s1 ,s2 ;
	for (int i = n + 1 ; i <= m ; i ++ ) {
		Select(HT ,i - 1 ,s1 ,s2 );
		HT[s1].parent = i ; HT[s2].parent = i ;
		HT[i].lchild = s1 ,HT[i].rchild = s2 ;
		HT[i].weight = HT[s1].weight + HT[s2].weight ;
	}
} 

void CreatHuffmanCode(HuffmanTree HT ,HuffmanCode &HC ,int n ) {
	char *cd ;
	int start ,c ,f ;
	HC = new char*[n+1] ;
	cd = new char[n];
	cd[n-1] = '\0';
	for (int i = 1 ; i <= n ; i ++ ) {
		start = n - 1 ;
		c = i ; f = HT[i].parent ;
		while(f != 0) {
			-- start ;
			if ( HT[f].lchild == c ) cd[start] = '0' ;
			else cd[start] = '1' ;
			c = f ; f = HT[f].parent ; 
		}
		HC[i] = new char [n - start] ;
		strcpy(HC[i] ,&cd[start] ) ;
	}
	delete cd;
} 

int main() {
	FILE *fp , *filestream ;
	fp = fopen("SourceFile.txt" ,"r" );
	for (int k = 1 ; k <= 100 ; k ++ ) {
		
		mp.clear(); mmp.clear();
		fgets(str + 1 ,maxn ,fp) ;
		int len = strlen(str + 1) ;
		int cnt = 0;
		for (int i = 1 ; i <= len - 1 ; i ++ ) {
			if ( !mp[str[i]] ) {
				mp[str[i]] = ++cnt ;
				mmp[cnt] = str[i] ;
			}
			weight[cnt] ++;
		}
		HuffmanTree HT; HuffmanCode HC ;
		CreatHuffmanTree(HT ,cnt );
//		for (int i = 1 ; i <= cnt * 2 - 1 ; i ++ ) {
//			printf("i = %d, mp[str[i]] = %c,HT[i].parent = %d,HT[i].weight = %d,HT[i].lchild = %d,HT[i].rchild = %d\n",i ,mmp[i] ,HT[i].parent,HT[i].weight ,HT[i].lchild ,HT[i].rchild );
//		}
		CreatHuffmanCode(HT ,HC ,cnt ) ;
		filestream = fopen("ResultFile.txt" , "a");
		fprintf(filestream ,"第%d组样例结果\n" ,k );
		for (int i = 1 ; i <= cnt ; i ++ ) {
			int len1 = strlen(HC[i]);
			fprintf(filestream ,"%c : ",mmp[i]) ;
			for (int j = 1 ; j <= len1 ; j ++ ) {
				fprintf(filestream ,"%c" ,HC[i][j] );
			} fprintf(filestream ,"\n" ) ;
		} 
		fprintf(filestream ,"第%d组样例结束\n" ,k );
	}
	fclose(filestream);
	fclose(fp) ;
	return 0;
}
