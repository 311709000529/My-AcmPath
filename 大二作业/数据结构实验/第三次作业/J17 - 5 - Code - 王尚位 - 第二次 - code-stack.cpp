#include <stdio.h> 
#include <malloc.h> 
#include <iostream>

using namespace std;

typedef int SElemType; 
typedef int Status; 

#define INIT_SIZE 100 
#define STACKINCREMENT 10 
#define Ok 1 
#define Error 0 
#define True 1 
#define False 0 

typedef struct  { 
	SElemType *base; 
	SElemType *top; 
	int stacksize; 
}SqStack; 

//初始化栈 
Status InitStack(SqStack *s) 
{ 
	s->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType)); 
	if(!s->base) { 
		puts("存储空间分配失败！"); 
	    return Error; 
	} 
	s->top = s->base; 
	s->stacksize = INIT_SIZE; 
	return Ok; 
}
  
//清空栈 
Status ClearStack(SqStack *s){ 
	s->top = s->base; 
	return Ok; 
} 
  
//栈是否为空 
Status StackEmpty(SqStack *s) { 
	if(s->top == s->base) return True; 
	else return False; 
}
  
//销毁栈 
Status Destroy(SqStack *s) {
	free(s->base); 
	s->base = NULL; 
	s->top = NULL; 
	s->stacksize=0; 
	return Ok; 
} 
  
//获得栈顶元素 
Status GetTop(SqStack *s, SElemType &e) {
	if(s->top == s->base) return Error; 
	e = *(s->top - 1); 
	return Ok; 
} 
  
//压栈 
Status Push(SqStack *s, SElemType e) {
	if(s->top - s->base >= s->stacksize) { // 栈满 
		s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType)); 
		if(!s->base) {
			puts("存储空间分配失败！"); 
			return Error; 
		} 
		s->top = s->base + s->stacksize;//修改栈顶位置 
		s->stacksize += STACKINCREMENT;//修改栈长度 
	} 
	*s->top++ = e; 
	return Ok; 
} 
  
//弹栈 
Status Pop(SqStack *s, SElemType *e) { 
	if(s->top == s->base) return Error; 
	--s->top; 
	*e = *(s->top); 
	return Ok; 
} 
  
//遍历栈 
Status StackTraverse(SqStack *s,Status(*visit)(SElemType)) { 
	SElemType *b = s->base;//此处不能直接用base或top移动，即不能改变原栈的结构 
	SElemType *t = s->top; 
	while(t > b) 
		visit(*b++); 
	printf("\n"); 
	return Ok; 
} 
  
Status visit(SElemType c) { 
	printf("%d ",c); 
	return Ok; 
} 

void menu() {
	cout<<" menu："<<endl;
    cout<<"1.进栈"<<endl;
    cout<<"2.出栈"<<endl;
    cout<<"3.输出"<<endl;
    cout<<"4.menu"<<endl;
    cout<<"0.结束"<<endl;
}

int main()
{
    SqStack a ,*s = &a ;
    SElemType e;
    InitStack(s);  menu();
    int choose ,x ;
    while(true){
        cout<<"\n请选择:";
        cin >> choose;
        int k = 0;
        switch(choose){
            case 1:
                printf("请输出需要进栈的个数:");
            	scanf("%d",&x);
                printf("请输入%d个元素:",x);
                while(x--){
                    scanf("%d",&e);
                    Push(s,e);
                }
                break;
            case 2:
                Pop(s,&e);
                printf("出栈的元素是:%d\n", e);
                break;
            case 3:
                StackTraverse(s, visit);
                printf("栈已全部输出!\n");
                break;
            case 4:
                menu();
                break;
            case 0:
                k = 1;
                break;
            default:
                printf("请重新输入！");
                break;
        }
        if(k)   break;
    }
    Destroy(s);
    return 0;
}

