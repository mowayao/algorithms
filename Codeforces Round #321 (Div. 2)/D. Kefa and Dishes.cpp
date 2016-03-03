#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 30;
int n,m,k,a[maxn],rule[maxn][maxn];
long long dp[1<<19][19];
int main() {

    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    while(k--) {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        rule[x-1][y-1] = c;
    }
    int Mm = 1<<n;
    for(int i = 0; i < n; i++) dp[1<<i][i] = a[i];
    for(int mask = 0; mask < Mm; mask++) {
        for(int i = 0; i < n; i++) {
            if ((mask>>i)&1) {
                for(int j = 0; j < n; j++) {
                    if(!((mask>>j)&1)) {
                        int tmp = mask | (1<<j);
                        dp[tmp][j] = max(dp[mask][i]+a[j]+rule[i][j],dp[tmp][j]);
                    }
                }
            }
        }
    }
    long long  ans = 0;
    for(int mask = 0; mask < Mm; mask++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if( (mask>>j) & 1) cnt++;
        }
        if(cnt == m){
            for(int j = 0; j < n; j++) {
                ans = max(ans,dp[mask][j]);
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}
