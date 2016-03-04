#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
struct device{
    vector<int> band;
    vector<int> price;
    device(){
        band.clear();
        price.clear();
    }
};
int n;
int dp[2][400];
vector<device> vd;
int main(){


    int ncase;
   // freopen("in","r",stdin);
    cin >> ncase;
    while(ncase--){
        cin >> n;
        vd.clear();
        vd.resize(n);
        for(int i = 0; i < n; i++){
            int k;
            scanf("%d",&k);
            for(int j = 0; j < k; j++){
                int a,b;
                scanf("%d%d",&a,&b);
                vd[i].band.push_back(a);
                vd[i].price.push_back(b);
            }
        }
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 400; j++)
               dp[i][j] = 1e8;
        for(int i = 0; i < vd[0].band.size(); i++){
            dp[0][vd[0].band[i]] = min(vd[0].price[i],dp[0][vd[0].price[i]]);
        }
        for(int i = 1; i < n; i++){
            for(int k = 0; k < 400; k++){
                    dp[1][k] = dp[0][k];
                    dp[0][k] = 1e8;
            }
            for(int j = 0; j < vd[i].band.size(); j++){
                int band = vd[i].band[j];
                int price = vd[i].price[j];
                //cout<<dp[1][80]<<"  "<<dp[1][100]<<"  "<<dp[1][120]<<"  "<<dp[1][150]<<endl;

                for(int k = 0; k < 400; k++){
                    if(band < k){
                        dp[0][band] = min(dp[1][k]+price,dp[0][band]);
                    }else{
                        dp[0][k] = min(dp[1][k]+price,dp[0][k]);
                    }
                }

            }
            //cout<<dp[0][80]<<"  "<<dp[0][100]<<"  "<<dp[0][120]<<"  "<<dp[0][150]<<endl;
        }
        double ans = 0;

      //   for(int i = 0; i < 300; i++){
          //  cout<<dp[0][100]<<endl;
      //  }
        for(int i = 0; i < 400; i++){
            //cout<<dp[0][i]<<endl;
            ans = max(i*1.0/dp[0][i],ans);
        }
        printf("%.3f\n",ans);

    }
    return 0;
}
