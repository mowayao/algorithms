#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int maxn = 100+10;
string st;
int n;
int dp[maxn][maxn];
map<char,char> mma;

int dfs(int sta,int ed){
    if(sta>=ed) return 0;
    if(dp[sta][ed] != -1) return dp[sta][ed];
    int ans = 0;
    if(mma[st[sta]]==st[ed] ) ans = dfs(sta+1,ed-1)+2;
    for(int i = sta; i < ed; i++){
            ans = max(ans,dfs(sta,i)+dfs(i+1,ed));
    }
    return dp[sta][ed] = ans;
}

int main(){
    mma['('] = ')';
    mma['['] = ']';
    while(cin >> st && st != "end"){
        memset(dp,-1,sizeof dp);
        n = st.size();
        cout<<dfs(0,n-1)<<endl;
    }
    return 0;
}
