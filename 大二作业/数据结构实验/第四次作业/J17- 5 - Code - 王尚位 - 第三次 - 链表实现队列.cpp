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

void menu() {
	printf(
		"1.初始化\n"
		"2.插入\n"
		"3.删除\n"
		"4.取队列顶\n"
		"0.退出\n"
	);
}

int main() {
	menu(); 
	LinkQueue Q1;
	int choose ,e ;
	while ( true ) {
		printf("请输入你的选择 :");
		cin >> choose ; cout << endl; 
		switch ( choose ) {
			case 1:
				InitQueue(Q1);
				break;
			case 2:
				printf("请输入你的要插入的元素 :");
				cin >> e; cout << endl; 
				EnQueue(Q1 ,e );
				printf("插入成功\n");
				break;
			case 3:
				if(DeQueue(Q1 ,e )) {
					printf("删除成功\n");
				} else {
					printf("error:队列以空\n");
				}
				break;
			case 4:
				printf("队列顶的元素为: %d\n",GetHead(Q1));
				break;
			case 0:
				break;
		}
		if ( choose == 0 ) break;
	} 
	return 0;
}
