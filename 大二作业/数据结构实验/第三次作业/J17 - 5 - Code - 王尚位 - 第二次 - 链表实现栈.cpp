#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int ElemType;

typedef struct linknode
{
       ElemType data;
       struct linknode *next;
}ListStack;

ListStack *s; 

void init() {
	s = (ListStack*) malloc(sizeof(ListStack));
	s->next = NULL;
}

void Push(ListStack *s,ElemType e) {  
    ListStack *p; 
    p=(ListStack*) malloc(sizeof(ListStack));
    p->data=e;
    p->next=s->next;
    s->next=p;   
} 
	
void Pop(ListStack *s) {  
	ListStack *temp;
	int e;
	if(s->next==NULL) {
		printf("当前栈为空\n");
		return ;
	} else {  
		temp=s->next;
		printf("当前栈顶元素为 :%d\n",temp->data);
		s->next=temp->next;
		free(temp);  
	}
}
	
bool empty(ListStack *s) {
	if ( s->next == NULL ) return true;
	else return false; 
}

void printStack(ListStack *s) { 
    ListStack *p=s->next; 
    while(p!=NULL){
       	printf("%d ",p->data);
       	p=p->next;
    }      
}

void menu() {
	printf(
		   "***********************************************************************************************\n"
		   "                                               1.插入                                     \n"
		   "                                               2.删除                                     \n"
		   "                                               3.判断是否为空                             \n"
		   "                                               4.输出栈中的元素                           \n"
		   "                                               0.退出                                     \n"
		   "***********************************************************************************************\n"
	);
}



int main() {
	menu(); init();
	int choose ,x ;
	while ( cin >> choose ) {
		switch (choose) {
			case 1:
				printf("请输入插入的元素: ");
				scanf("%d",&x);
				Push(s ,x );
				break; 
			case 2:
				Pop(s);
				break;
			case 3:
				if ( empty(s) ) printf("当前栈为空\n");
				else printf("当前栈不为空\n"); 
				break;
			case 4:
				printf("当前栈里面的元素为 :");
				printStack(s); puts("");
				break;
			case 0: 
				break;
			default:
				printf("请重新输入\n");
		}
		if ( !choose ) break;
	}
	return 0;
}
