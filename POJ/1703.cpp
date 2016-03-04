#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
const int maxn = 100000;
int n,m;
int fa[maxn*2+10];

void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        fa[i+maxn] = i+maxn;
    }
}

int find(int x){
    if(x != fa[x]) return fa[x] = find(fa[x]);
    return fa[x];
}

void Union(int x,int y){
    int a = find(x);
    int b = find(y);
    if(a != b){
        fa[a] = b;
    }

}
int main(){

    int ncase;
    cin >> ncase;
    while(ncase--){
        scanf("%d%d",&n,&m);
        init();
        char op[20];
        int a,b;
        while(m--){
            scanf("%s",op);
            scanf("%d%d",&a,&b);
            if(op[0]=='A'){
                if(find(a+maxn)==find(b)||find(a)==find(b+maxn)){
                    printf("In different gangs.\n");
                }
                else if(find(a)==find(b)){
                    printf("In the same gang.\n");
                }else{
                    printf("Not sure yet.\n");
                }
            }else{
                Union(a+maxn,b);
                Union(a,b+maxn);
            }

        }

    }
    return 0;
}
