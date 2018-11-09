#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5+50;

struct book {
	string id;
	string name;
	double price;
	book () {}
	book (string _id,string _name,double _price) { id = _id; name = _name; price = _price;}
};

typedef struct {
	book* elem;
	int length;
} sqtable;

int init(sqtable &s) { //
	s.elem = new book[maxn];
	if ( !s.elem ) exit(-2);
	s.length = 0;
	return 1;
}

int delect(sqtable &s,int pos) {
	if ( s.length <= 0 || s.length < pos ) return 0;
	for (int i = pos ; i <= s.length - 1 ; i ++ ) {
		s.elem[i] = s.elem[i+1];
	} 
	s.length --;
	return 1;
}

int insert(sqtable &s,int pos,book val) {
	if ( s.length + 1 == pos ) {
		s.length ++; s.elem[s.length] = val; return 1;
	}
	if ( s.length >= maxn - 1 || pos > s.length ) return 0;
	for (int i = s.length ; i >= pos ; i -- ) {
		s.elem[i+1] = s.elem[i];
	}
	s.elem[pos] = val;
	++ s.length;
	return 1; 
}

void Print(sqtable &s) {
	if ( s.length == 0 ) printf("-----顺序表为空-----\n");
	else {
		for (int i = 1 ; i <= s.length ; i ++ ) {
			cout << "id = "<<s.elem[i].id << " -- "<< "name = "<< s.elem[i].name << " -- "<< "price = "<< s.elem[i].price<< endl;
		}
	} 
}

int Scanner(int length,sqtable &s) {
	if ( s.length + length > maxn - 1) return 0;
	printf("*************************** 请依次输入 id -- name -- price (每行一个信息) *******************************\n");
	for (int i = s.length + 1 ; i <= s.length + length ; i ++ ) {
		cin >> s.elem[i].id >> s.elem[i].name >> s.elem[i].price ;
	} 
	s.length += length; 
	return 1;
}

int findder(sqtable &s,double price) {
	for (int i = 1 ; i <= s.length ; i ++) {
		if ( s.elem[i].price == price ) return i;
	}
	return 0;
}

int main() {
	int length ,val ; 
	double price;
	book temp; 
	while(true) {
		int choose = -1;
		puts("------------欢迎来到图书管理系统-------------");
		puts("");
		puts("**********************************************");
		puts("*******************1. 建立********************");
		puts("*******************2. 输入********************");
		puts("*******************3. 查找********************");
		puts("*******************4. 插入********************");
		puts("*******************5. 删除********************");
		puts("*******************6. 输出********************");
		puts("*******************0. 退出********************");
		puts("**********************************************");
		puts("");
		sqtable s;
		while(cin >> choose && choose) {
			if ( choose == 1 ) {
				if(!init(s)) printf("-----内存分配失败-----\n");
				else printf("-----内存分配成功-----\n");
			} else if ( choose == 2 ) {
				printf("请输入需要输入的信息的长度 : \n");
				cin >> length;
				if ( Scanner(length ,s ) ) {
					printf("-----输入完毕-----\n");
				} else {
					printf("----- error : 内存超限 -----\n");
				}
			} else if ( choose == 3 ) {
				printf("请输入一个书的价格信息:\n");
				cin >> price;
				val = findder(s ,price );
				if ( val ) {
					printf("该书的信息为: ");
					cout << "id = "<< s.elem[val].id<< " -- "<< "name = "<< s.elem[val].name<< " -- "<< "price = "<< s.elem[val].price<< endl; 
				} else {
					printf("-----对不起:没有该书的消息-----\n");
				}
			} else if ( choose == 4 ) {
				printf("请输入插入的书本位置和信息 (id--name--price):\n");
				cin >> val >> temp.id >> temp.name >> temp.price;
				if ( insert(s ,val ,temp ) ) {
					printf("-----插入成功-----\n");
				} else {
					printf("-----插入失败-----\n");
				}
			} else if ( choose == 5 ) {
				printf("请输入删除书本的位置:\n");
				cin >> val;
				if ( delect(s ,val ) ) {
					printf("-----删除成功-----\n");
				} else {
					printf("-----删除失败-----\n"); 
				}
			} else if ( choose == 6 ) {
				Print(s);
				printf("-----输出完毕-----\n"); 
			} 
		}
		printf("-----谢谢使用-----\n您还需要继续使用吗?(1.继续使用,2.停止使用)");
		cin >> val;
		if ( val == 1 ) continue;
		else if ( val == 2 ) break; 
	}
	return 0;
}
