#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 30000+10;
int fa[maxn];
int rank[maxn];
int dist[maxn];
void init(){
    for(int i = 0; i < maxn; i++){
        fa[i] = i;
        rank[i] = 1;
        dist[i] = 0;
    }
}
int find(int x){
    if(x != fa[x]){
        int t = fa[x];
        fa[x] = find(fa[x]);
        dist[x] += dist[t];
    }
    return fa[x];
}


int main(){
    int n;
    while(~scanf("%d",&n)){
        init();
        char op;
        while(n--){
            cin >> op;
            int a,b;
            if(op=='M'){
                scanf("%d%d",&a,&b);
                int faA = find(a);
                int faB = find(b);
                if(faA != faB){
                    fa[faB] = faA;
                    dist[faB] = rank[faA];
                    rank[faA] += rank[faB];
                }
            }else{
                scanf("%d",&a);
                int x = find(a);
                printf("%d\n",rank[x]-dist[a]-1);
            }
        }
    }
    return 0;
}
