#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node {
	int data;
	struct node *nxt;
}node ,*likedlist ;

node *s;
int n ,m ;

void init() {
	s = new node;
	s->nxt = NULL;
}

void Push(node *s,int x) {
	node *l; l = new node;
	l->data = x;
	l->nxt = s->nxt;
	s->nxt = l; 
}

void Pop(node *s) {
	node* temp;
	if ( s->nxt == NULL )
		return;
	else {
		temp = s->nxt;
		printf("%d",temp->data );
		s->nxt = temp->nxt;
		free(temp);
	}
} 

bool empty(node *s) {
	if ( s->nxt == NULL ) return true;
	else return false;
}

int main() {
	while ( cin >>n >> m ) {
		init();
		while( n ) { Push(s ,n % m ); n /= m; } 
		while(!empty(s)) { Pop(s); }
		printf("\n");
	}
	return 0;
}
