#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100 + 10;
int n,ans;
int map[maxn][maxn];
bool vis[maxn][maxn];
bool color[maxn];
void init(){
     
  memset(map,0,sizeof(map));
  memset(color,0,sizeof(color));     
  memset(vis,0,sizeof(vis)); 
  ans = 0;  
}
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};
void dfs(int x,int y){
      
    if(vis[x][y]|| x > n || x <=0 || y > n || y <= 0 )
      return;
    vis[x][y] = 1;
    ans++;
   // cout<<ans<<endl;
    color[map[x][y]] = 1;
    for(int i = 0; i < 4; i++){
       int x1 = x + xx[i];
       int y1 = y + yy[i];
       if(!color[map[x1][y1]] || map[x1][y1] == map[x][y])
           dfs(x1,y1);
    }
     
     
}
int main(){
    
    while(scanf("%d",&n)==1 && n){
        
         init();
         int cnt = 1;
         for(int i = 1; i <= n-1; i++){
             for(int j = 1; j <= n; j++){
                    int x,y;
                    scanf("%d%d",&x,&y);
                    map[x][y] = cnt;
             }
              cnt++;
        }
        dfs(1,1);
        if(ans == n*n)
          printf("good\n");
        else
          printf("wrong\n");
           
    }
    return 0;    
}
