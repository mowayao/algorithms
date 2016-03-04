#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100+10;
const int INF = 1e9;
int n;
int num[maxn];
int dp[maxn][maxn];
int dfs(int sta,int ed){
    if(ed-sta<2) return 0;
    if(dp[sta][ed] != -1) return dp[sta][ed];
    int ans = INF;
    for(int i = sta+1; i < ed; i++){
        ans = min(ans,dfs(sta,i)+dfs(i,ed)+num[sta]*num[i]*num[ed]);
    }
    return dp[sta][ed] = ans;
}

int main(){

    while(cin >> n){
        for(int i = 0; i < n; i++) cin >> num[i];
        memset(dp,-1,sizeof dp);
        cout<<dfs(0,n-1)<<endl;
    }

    return 0;
}
