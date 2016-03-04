#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
const int maxn = 2000+10;
int n,m;
map<char,pair<int,int> > mm;
string st;
int an[maxn][maxn];
int dp(int i,int j){
    if(i>=j)
        return 0;
    if(an[i][j]!=-1)   return an[i][j];
    if(st[i]==st[j]){
        return an[i][j] = dp(i+1,j-1);
    }else{
        int ans = 1000000000;
        int a = dp(i+1,j)+mm[st[i]].first;
        ans = min(a,ans);
        int b = dp(i,j-1)+mm[st[j]].first;
        ans = min(b,ans);
        int c = dp(i+1,j-1)+mm[st[i]].second+mm[st[j]].second;
        ans = min(c,ans);
        int d = dp(i+1,j)+mm[st[i]].second;
        ans = min(d,ans);
        int e = dp(i,j-1)+mm[st[j]].second;
        ans = min(e,ans);
        return an[i][j] = ans;

    }
}
int main(){
    memset(an,-1,sizeof(an));
    scanf("%d%d",&n,&m);
    cin >> st;
    while(n--){
        char a;
        int b,c;
        cin >> a >> b >> c;
        mm[a] = make_pair(b,c);
    }
    cout<<dp(0,m-1);
    return 0;
}
