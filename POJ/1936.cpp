#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100000+10;
char str[maxn],text[maxn];
int main(){

    while(~scanf("%s %s",str,text)){
        int n = strlen(str), m = strlen(text);
        int i=0,j=0;
        while(i < n && j < m){
            if(str[i]==text[j]){
                i++;
            }
            j++;
        }
        if(i==n){
            puts("Yes");
        }else{
            puts("No");
        }

    }
    return 0;
}
