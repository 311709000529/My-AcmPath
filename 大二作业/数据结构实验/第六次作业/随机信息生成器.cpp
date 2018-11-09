#include <bits/stdc++.h>

using namespace std;

int Random(int start, int end){
    int dis = end - start;
    return rand() % dis + start;
}

int main() {
	FILE *fp ;
	fp = fopen("SourceFile.txt" ,"a" );
	for (int i = 1 ; i <= 100 ; i ++ ) {
		int lenght = 100;
		for (int j = 1 ; j <= lenght ; j ++ ) {
			fprintf(fp , "%c" , Random(65 ,90 )) ;
		} fprintf(fp , "\n") ;
	}
	fclose(fp) ;
	return 0;
}
