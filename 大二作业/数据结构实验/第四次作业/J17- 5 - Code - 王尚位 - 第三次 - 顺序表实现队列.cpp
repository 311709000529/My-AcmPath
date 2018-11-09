#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxsize 110
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

void menu() {
	printf( "1.初始化\n"
			"2.插入元素\n"
			"3.删除元素\n"
			"4.取出队列长度\n"
			"5.取出队顶元素\n"
			"0.退出\n"
	);
}

int main() {
	menu();
	int choose = -1 ,e ; 
	SqQueue Q1;
	while ( true ) {
		printf("请输入你的选择 : \n");
		cin >> choose;
		switch (choose){
			case 1:
				InitQueue(Q1);
				break;
			case 2:
				printf("请输入要插入的元素 : \n");
				cin >> e;
				if ( EnQueue(Q1 ,e ) ) {
					printf("插入成功\n");
				} else {
					printf("插入失败,队列已满\n"); 
				} break; 
			case 3:
				if ( DeQueue(Q1 ,e ) ) {
					printf("删除成功\n");
				} else {
					printf("删除失败,队列以空\n");
				}
				break;
			case 4:
				printf("队列长度为: %d\n",QueueLenght(Q1));
				break; 
			case 5:
				if ( QueueLenght(Q1) == 0 ) {
					printf("error:队列以空\n");
				} else {
					printf("队顶元素为 : %d\n" ,GetHead(Q1));
				} 
				break;
			case 0: 
				break;
		}	
		if ( choose == 0 ) break;
	}
	return 0;
} 
