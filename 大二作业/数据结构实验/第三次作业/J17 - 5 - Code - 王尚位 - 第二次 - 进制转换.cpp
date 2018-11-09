#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char str[20] =  {'0' ,'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' } ;

stack<char >sta;
int n ,m ; 

int main() {
	while ( ~scanf("%d %d",&n ,&m ) ) {
		bool flag = false;
		if ( n < 0 ) flag = true , n = -n ;
		while ( n ) {
			sta.push(str[n % m]);
			n /= m; 
		}
		if ( flag ) printf("-");
		while(!sta.empty()) {
			printf("%c",sta.top());
			sta.pop();
		} puts("");
	}
	return 0;
}
