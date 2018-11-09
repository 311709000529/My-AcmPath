#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;
 
typedef struct Node {
    ElemType data;               
    struct Node *next;          
}Node,*LinkedList;

LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node)); 
    if(L == NULL) { 
        printf("申请内存空间失败\n");
    }
    L->next = NULL;                  
 	return L;
}

LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   
    L->next = NULL;                     
     
    ElemType x;                         
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));    
        p->data = x;                      
        p->next = L->next;                    
        L->next = p; 
    }
    return L; 
} 

LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) {
    Node *pre;                     
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
    	pre = pre->next;                  
	}
    Node *p;                                
    p = (Node *)malloc(sizeof(Node));
    p->data = x; 
    p->next = pre->next;
    pre->next = p;
     
    return L;                           
} 

LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;                    
    p = L->next;
    pre = L; 
	/**************************
		添加上 per = L; 就行了
		原因 : 刚开始 per 没有赋值如果删除第一个元素 
			   可能造成因为per为空指针的情况下指针失陪的情况 
	***************************/
	while(p->data != x) {               
        pre = p; 
        p = p->next;
    }
    pre->next = p->next;          
    free(p);
    return L;
} 

int findder(LinkedList L,int x) { //查找功能 
	/*
	* @ x 所要查找的值 
	* @ L 所要操作的链表
	* 返回 -1 时表示链表中没有所在得值 
	*/ 
	LinkedList start; int i = 1;
	L = L->next;
	for (start = L;start != NULL;start = start->next) {
		if ( start->data == x ) {
			return i;
		}
		i++;
	} 
	return -1;
}

LinkedList Delete(LinkedList L,int st,int en) { // 多组数据删除功能 
	/*
	* @ st 删除的起始位置 
	* @ en 删除的终止为止 
	* @ L 所要操作的的链表 
	*/
	bool flag1 = false;
	Node *per,*p;
	per = L;
	L = L->next; int i = 1;
	LinkedList start;
	for (start = L;start != NULL ; start = start->next ) {
		if ( st == i ) {
			flag1 = true;
		}
		if ( en == i ) {
			per->next = start->next;
			break;
		}
		i++;
		if ( !flag1 )
			per = start;
	}
	return L;
}

int main() {
    LinkedList list,start;
 	printf("请输入单链表的数据："); 
   	list = LinkedListCreatH();
	for(start = list->next; start != NULL; start = start->next) {
		printf("%d ",start->data);
	}
	printf("\n");
    int i;
    ElemType x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x); 
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n"); 
    return 0;
}
