#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxsize 11000
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct {
	QElemType *base;
	int front ;
	int rear;
}SqQueue;

Status InitQueue(SqQueue & Q) {
	Q.base = new QElemType[maxsize];
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLenght(SqQueue Q) {
	return (Q.rear - Q.front + maxsize) % maxsize ;
}

Status EnQueue (SqQueue &Q ,QElemType e) {
	if ( (Q.rear + 1 ) % maxsize == Q.front ) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = ( Q.rear + 1 ) % maxsize ;
	return OK; 
}

Status DeQueue(SqQueue &Q ,QElemType &e) {
	if ( Q.front == Q.rear ) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1 ) % maxsize;
	return OK;
}

Status GetHead(SqQueue Q) {
	if ( Q.front != Q.rear ) {
		return Q.base[Q.front];
	}
}

int n ,e ;

int stack[maxsize];

int main() {
	SqQueue Q1 ,Q2 ;
	InitQueue(Q1); InitQueue(Q2); 
	int pos = 0;
	scanf("%d",&n);
	while ( n ) {
		EnQueue (Q1 ,n % 2);
		n /= 2;
	}
	while ( QueueLenght(Q1) != 0 ) {
		DeQueue(Q1 ,e );
		stack[++pos] = e;
	}
	while ( pos ) {
		printf("%d",stack[pos]); pos--;
	}
	return 0;
} 
