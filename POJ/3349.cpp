#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
template<class T> inline void readint(T& x) {
      char c;
      int mul = 1;
      while((c = getchar()) != EOF){
         if(c == '-')mul = -1;
         if(c >= '0' && c <= '9'){
              x = c-'0';
              break;
         }
      }
      if(c == EOF){x = EOF;return;}
      while(c = getchar()){
          if(c >= '0' && c <= '9'){
              x = (x<<1)+(x<<3)+(c-'0');
          }else break;
      }
      x *= mul;
}
typedef long long LL;
const int MOD = 14997;
const int maxn = 100000+10;
vector<int> g[MOD+10];
int n;
int snow[maxn][6];
int getKey(int x) {
    return (snow[x][0] + snow[x][1] + snow[x][2] + snow[x][3] + snow[x][4] + snow[x][5])%MOD;
}
inline bool isSame(int x,int y) {
    bool flag = true;
    for(int i = 0; i < 6; i++){
        if(snow[x][i]!=snow[y][i])
            return false;
    }
    return true;
}
bool HASH[MOD];
int main(){

    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < 6; k++) {
            readint(snow[i][k]);
        }
        sort(snow[i],snow[i]+6);
    }
    bool flag = false;
    for(int i = 0; i < n; i++) {
        int key = getKey(i);
        int sz = g[key].size();
        if(sz!=0){
            for(int k = 0; k < sz; k++){
                if(isSame(g[key][k],i)){
                    flag = true;
                }
            }
        }
        if(flag) break;
        g[key].push_back(i);
    }
    if(flag) puts("Twin snowflakes found.");
    else puts("No two snowflakes are alike.");

    return 0;
}
