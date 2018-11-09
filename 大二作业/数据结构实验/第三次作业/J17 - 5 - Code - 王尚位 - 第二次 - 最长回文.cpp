#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
 
const int N = 200010;
char s[N], str[N*2];
int p[N*2];
int manacher()
{
    int i;
    for(i = 1; s[i]; i++)
        str[i*2] = s[i], str[i*2+1] = '#';
    str[0] = '?', str[1] = '#', str[i*2] = '\0';
    int res = 0, k = 0, maxk = 0;
    for(int i = 2; str[i]; i++)
    {
        p[i] = i < maxk ? min(maxk - i, p[2*k-i]) : 1;
        while(str[i-p[i]] == str[i+p[i]]) p[i]++;
        if(p[i] + i > maxk)
            k = i, maxk = i + p[i];
        res = max(res, p[i]);
    }
    return res - 1;
}
 
int main()
{
    while(~ scanf(" %s", s + 1))
        printf("%d\n", manacher());
 
    return 0;
}

