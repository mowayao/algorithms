#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1000000+10;
int next[maxn];
char str[maxn];
int n;
void getNext(){
    next[0] = next[1] = 0;
    for(int i = 1,j; i < n; i++){
        j = next[i];
        while(j && str[i] != str[j]) j = next[j];
        if(str[i]==str[j]) next[i+1] = j+1;
        else next[i+1] = 0;
    }
}
int main(){

    while(~scanf("%s",str) && strcmp(str,".")!=0){
        n = strlen(str);
        getNext();
        int ans;
        if(n%(n-next[n])!=0) ans = 1;
        else ans =  n/(n-next[n]);
        printf("%d\n",ans);
    }
    return 0;
}
