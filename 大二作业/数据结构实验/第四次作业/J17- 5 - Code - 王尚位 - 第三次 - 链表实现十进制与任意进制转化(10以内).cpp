#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define OK 1
#define ERROR 0

typedef int QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode ,*QueuePtr;
typedef int Status ;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status EnQueue (LinkQueue & Q ,QElemType e) {
	QueuePtr p;
	p = new QNode;
	p->data = e;
	p->next = NULL; Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q ,QElemType e) {
	QueuePtr p;
	p = new QNode;
	if ( Q.front == Q.rear ) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if ( Q.rear == p ) Q.rear = Q.front;
	delete p;
	return OK;
}

QElemType GetHead(LinkQueue Q) {
	if ( Q.front != Q.rear ) {
		return Q.front->next->data;
	}
}

int n ,e ,m ; 
const int maxsize = 10000;
int stack[maxsize];

int main() {
	LinkQueue Q1;
	InitQueue(Q1);
	scanf("%d %d",&n,&m);
	int pos = 0;
	while ( n ) {
		EnQueue(Q1 , n % m);
		n /= m;
	}
	int t = GetHead(Q1);
	while ( DeQueue(Q1 ,e ) ) {
		stack[++pos] = t;
		t = GetHead(Q1);
	}
	while ( pos ) {
		printf("%d",stack[pos]);
		pos --;
	}
  	return 0;
}
