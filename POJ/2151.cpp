#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int M,T,N;
double p[1010][40];
double dp[40][40];
int main(){

    while(~scanf("%d%d%d",&M,&T,&N) && N+T+M){
        double all  = 1.0;
        for(int i = 0; i < T; i++){
            double t = 1.0;
            for(int j = 0; j < M; j++){
                scanf("%lf",&p[i][j]);
                t *= (1-p[i][j]);
            }
            all *= (1-t);
        }
        double no = 1.0;
        for(int i = 0; i < T; i++){
            dp[0][0] = 1-p[i][0];
            dp[0][1] = p[i][0];
            for(int j = 1; j < M; j++){
                dp[j][0] = dp[j-1][0]*(1-p[i][j]);
                for(int k = 1; k <= j+1; k++){
                    dp[j][k] = dp[j-1][k]*(1-p[i][j])+dp[j-1][k-1]*p[i][j];
                }
            }
            double t = 0.0;
            for(int j = 1; j < N; j++){
                t += dp[M-1][j];
            }
            no *= t;
        }
        printf("%.3f\n",all-no);
    }
    return 0;
}
