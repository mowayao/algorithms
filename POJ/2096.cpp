#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1000+10;
double dp[maxn][maxn];
int n,s;
int main(){
    while(cin >> n >> s){
        dp[n][s] = 0;
        double t = n*s;
        for(int i = n; i >= 0; i--){
            for(int j = s; j >= 0; j--){
                if(i!=n||j!=s){
                    dp[i][j] = dp[i+1][j]*j*(n-i)/t+dp[i][j+1]*i*(s-j)/t+dp[i+1][j+1]*(n-i)*(s-j)/t+1;
                    dp[i][j] = dp[i][j]/(1.0-(i*j)/t);
                }
            }
        }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
