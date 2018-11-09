#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 50;
const int mod = 1e9 + 7;

char str1[maxn] ,str2[maxn] ;
ll nxt[maxn] ,len1 ,len2 ,help[maxn] ;

void get_nxt(char *s,int len) {
	nxt[1] = 0; int k = 0;
	for (int i = 2 ; i <= len ; i ++ ) {
		while ( k > 0 && s[i] != s[k+1] ) k = nxt[k];
		if ( s[i] == s[k+1] ) k ++;
		nxt[i] = k;
	} 
}

void kmp(char *s1 ,char *s2 ,int l1 ,int l2) {
	get_nxt(s2 ,l2 ); int k = 0;
	for (int i = 1 ; i <= l1 ; i ++ ) {
		while ( k > 0 && s1[i] != s2[k+1] ) k =nxt[k];
		if ( s1[i] == s2[k+1] ) k ++;
		help[k] ++;
	}
}

int main() {
	int t; cin >> t;
	while( t -- ) {
		scanf("%s %s",str1 + 1 ,str2 + 1 );
		memset(nxt ,0 ,sizeof(nxt) ) ;
		memset(help ,0 ,sizeof(help) );
		len1 = strlen(str1 + 1) ,len2 = strlen(str2 + 1);
		char temp;
		for (int st = 1 ,en = len1 ; en >= st ;st ++ ,en -- ) {
			temp = str1[st] ; str1[st] = str1[en] ; str1[en] = temp;
		} 
		for (int st = 1 ,en = len2 ; en >= st ;st ++ ,en -- ) {
			temp = str2[st] ; str2[st] = str2[en] ; str2[en] = temp ;
		}
		kmp(str1 ,str2 ,len1 ,len2 );
		for (int i = len2 ; i >= 1 ; i -- ) {
			help[nxt[i]] += help[i];
		} 
		ll ans = 0;
		for (int i = 1 ; i <= len2 ; i ++ ) {
			ans = (ans + i * help[i] % mod ) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
