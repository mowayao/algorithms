#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100+10;
const int maxm = 10+10;
char mat[maxn][maxm];
int dp[maxn][maxn][maxn];
int n,m;
int statu[maxn];
vector<int> legal;
vector<int> cnt;
bool isLegal(int mask){
    if(mask&(mask<<1)) return false;
    if(mask&(mask<<2)) return false;
    return true;
}
int getCnt(int x){
    int ret = 0;
    while(x){
        x = x&(x-1);
        ret++;
    }
    return ret;
}
void getLegal(){
    int ed = 1<<m;
    for(int i = 0; i < ed; i++){
        if(isLegal(i)){
            legal.push_back(i);
            cnt.push_back(getCnt(i));
        }
    }
}
void init(){
    memset(statu,0,sizeof statu);
    memset(dp,0,sizeof dp);
    legal.clear();
    cnt.clear();
}
void solve(){
    for(int i = 0; i < legal.size(); i++){
        if(statu[0]&legal[i]) continue;
        dp[0][0][i] = cnt[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < legal.size(); j++){
            if(legal[j]&statu[i]) continue;
            for(int k = 0; k < legal.size(); k++){
                if(legal[j]&legal[k]) continue;
                for(int kk = 0; kk < legal.size(); kk++){
                    if(legal[j]&legal[kk]) continue;
                    dp[i][k][j] = max(dp[i][k][j],dp[i-1][kk][k]+cnt[j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < legal.size(); i++){
        for(int j = 0; j < legal.size(); j++){
            ans = max(ans,dp[n-1][i][j]);
        }
    }
    cout<<ans<<endl;

}
int main(){
    while(~scanf("%d%d\n",&n,&m)){
        init();
        for(int i = 0; i < n; i++){
            gets(mat[i]);
            for(int j = 0; j < m; j++){
                if(mat[i][j]=='H')
                    statu[i] |= (1<<j);
            }
        }
        getLegal();
        solve();

    }
    return 0;
}
