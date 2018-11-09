#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6+5;

char str1[maxn],str2[maxn],temp[maxn];
int nxt[maxn];

void get_nxt(char *s,int len) {
	int k = 0;
	nxt[1] = 0;
	for (int i = 2;i<=len;i++) {
		while(k > 0 && s[i] != s[k+1] ) k = nxt[k];
		if ( s[i] == s[k+1] ) k++;
		nxt[i] = k;
	}
}

int kmp(char *s1,char *s2,int len1,int len2) {
	get_nxt(s2,len2);
	int k = 0,cnt = 0;
	for (int i = 1;i<=len1;i++) {
		while(k > 0 && s1[i] != s2[k+1] ) k = nxt[k];
		if ( s1[i] == s2[k+1] ) k++;
		if(k == len2)  {
			cnt++; k = nxt[k]; 
		}
	}
	return cnt;
}
int main() {
	int t; cin>>t;
	while(t--)
	{
		scanf("%s %s",str2+1,str1+1);
		int len1 = strlen(str1+1),len2 = strlen(str2+1);
		if ( len2 > len1 ) {
			printf("0\n"); continue;
		}
		int v = kmp(str1,str2,len1,len2);
		printf("%d\n",v);
	}
	return 0;
}
