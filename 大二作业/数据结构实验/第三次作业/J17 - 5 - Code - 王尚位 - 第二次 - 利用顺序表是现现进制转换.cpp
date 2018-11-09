#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxsize = 1e5+ 50;

struct Sqlist{
	int data[maxsize];
	int length;
}sqlist;

int n ,m ;

void init() {
	sqlist.length = 0;
}

int main() {
	while ( cin >> n >> m ) {
		init(); 
		while ( n ) { sqlist.data[++ sqlist.length] = n % m; n /= m; }
		while ( sqlist.length ) { printf("%d",sqlist.data[sqlist.length --]); }
		printf("\n");
	}
	return 0;
}
