#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int  maxn = 1 << 8;
double p[maxn][maxn];
int n,all;
double dp[2][maxn];
int main(){

    while(cin >> n&&n!=-1){
        all = (1 << n);
        for(int i = 1; i <= all; i++)
            dp[1][i] = 1;
        for(int i = 1; i <= all; i++)
            for(int j = 1; j <= all; j++)
                scanf("%lf",&p[i][j]);
        for(int i = 0; i < n; i++){
            int d = 1<<i;
            for(int k = 1; k <= all; k++){
                dp[0][k] = dp[1][k];
                dp[1][k] = 0;
            }

            int sta=1,ed=sta+d;
            while(ed <= all){
                for(int k = sta; k < ed; k++){
                    for(int a = ed; a < ed+d; a++){
                        dp[1][k] += dp[0][k]*dp[0][a]*p[k][a];
                        dp[1][a] += dp[0][a]*dp[0][k]*p[a][k];
                    }
                }
                sta += 2*d;
                ed = sta+d;
            }
        }
        double ans = dp[1][1];
        int idx = 1;
        for(int i = 2; i <= all; i++){
            if(dp[1][i] > ans){
                ans = dp[1][i];
                idx = i;
            }
        }
        cout<<idx<<endl;
    }
    return 0;
}
