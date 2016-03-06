#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 14;
const int MOD = 100000000;
int n,m;
int mat[maxn];
int dp[2][1<<maxn];
int main(){

    while(~scanf("%d%d",&n,&m)){
        memset(mat,0,sizeof mat);
        for(int i = 0; i < n; i++){
            int d = 0;
            for(int j = 0; j < m; j++){
                int t;
                scanf("%d",&t);
                if(t==1)
                    d |= (1<<j);
            }
            mat[i] = d;
        }
        int mask = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < (1<<m); j++) dp[1][j] = dp[0][j];
            memset(dp[0],0,sizeof dp[0]);
            bool flag;
            if(i==0){
                for(int j = 0; j < (1<<m); j++){
                    int t = 0;
                    flag = true;
                    for(int k = 0;k < m; k++){
                        if((1<<k)&j){
                            if(!(mat[i]&(1<<k))){
                                flag = false;
                                break;
                            }
                            if(k==0){
                                if((1<<(k+1))&j){
                                    flag = false;
                                    break;
                                }
                            }
                            else if(k==m-1){
                                if((1<<(k-1))&j){
                                    flag = false;
                                    break;
                                }
                            }else{
                                if(((1<<(k+1))&j)||((1<<(k-1))&j)){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                    if(flag){
                        dp[0][j]++;
                    }
                }
                continue;
            }
            for(int d = 0; d < (1<<m); d++){
                for(int j = 0; j < (1<<m); j++){
                    int t = 0;
                    flag = true;
                    for(int k = 0;k < m; k++){
                        if ((1<<k)&j){
                            if(!(mat[i]&(1<<k))){
                                flag = false;
                                break;
                            }
                            if(d&(1<<k)){
                                flag = false;
                                break;
                            }
                            if(k==0){
                                if((1<<(k+1))&j){
                                    flag = false;
                                    break;
                                }
                            }
                            else if(k==m-1){
                                if((1<<(k-1))&j){
                                    flag = false;
                                    break;
                                }
                            }else{
                                if(((1<<(k+1))&j)||((1<<(k-1))&j)){
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                    if(flag){
                        dp[0][j] = (dp[1][d]+dp[0][j])%MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < (1<<m); i++){
            ans = (dp[0][i]+ans)%MOD;
        }
        printf("%d\n",ans);

    }
    return 0;
}
