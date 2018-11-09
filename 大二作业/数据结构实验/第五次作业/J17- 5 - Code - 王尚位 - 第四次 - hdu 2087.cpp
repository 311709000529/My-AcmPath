#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
char a[maxn],b[maxn];
int nextt[maxn];
void kmpnext(char* c){
	int len = strlen(c);
	nextt[0] = -1;
	int k = -1;
	for(int i = 1;i<len;i++){
		while(k>-1 && c[k+1] != c[i]){
			k = nextt[k];
		}
		if(c[i] == c[k+1]){
			k++;
		}
		nextt[i] = k;
	}
}
int kmp(char* c,char* d){
	kmpnext(d);
	int lenc = strlen(c),lend = strlen(d);
	int k = -1,cnt = 0;
	for(int i = 0;i<lenc;i++){
		while(k>-1 && d[k+1] != c[i]){
			k = nextt[k];
		}
		if(c[i] == d[k+1]){
			k++;
		}
		if(k == lend - 1){
			cnt++;
			k = nextt[k];
			i += lend-1;
		}
	}
	return cnt;
}
int main()
{
	while(~scanf("%s",a))
	{
		if(a[0] == '#') break;
		scanf("%s",b);
		int l = kmp(a,b);
		printf("%d\n",l);
	}
	return 0;
}
