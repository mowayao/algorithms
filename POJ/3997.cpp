#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 260;
int n,t,ans;
bool mat[maxn][maxn];
void init(){
    ans=0;
    memset(mat,0,sizeof(mat));
    for(int i = 1; i <= n; i++){
        mat[i][i] = 1;
    }
}
int main(){

    int T=1;
    while(~scanf("%d%d",&n,&t) &&n+t){
        init();
        while(t--){
            int a,b;
            scanf("%d%d",&a,&b);
            if(mat[b][a]){
                ans++;
            }
            else if(!mat[a][b]){
                mat[a][b] = 1;
                for(int i = 1; i <= n; i++){
                    if(mat[i][a]){
                        mat[i][b] = 1;
                        for(int j = 1; j <= n; j++)
                            if(mat[b][j]) mat[i][j] = 1;
                    }
                }

            }

        }
        printf("%d. %d\n",T++,ans);

    }

    return 0;
}
