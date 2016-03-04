#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 400000+10;
char str[maxn];
int len;
int next[maxn];
void getNext(char *str){
    next[0] = next[1] = 0;
    for(int i = 1; i < len; i++){
        int j = next[i];
        while(j && str[j] != str[i]) j = next[j];
        if(str[i] == str[j]) next[i+1] = j+1;
        else next[i+1] = 0;
    }
}

int main(){

    while(~scanf("%s",str)){
        len = strlen(str);
        getNext(str);
        vector<int> vn;
        int x = len;
        //vn.push_back(x);
        while(x) {
            vn.push_back(x);
            x = next[x];
        }
        for(int i = vn.size()-1; i >= 0; i--){
            if(!i) printf("%d",vn[i]);
            else printf("%d ",vn[i]);
        }
        puts("");
    }
    return 0;
}
