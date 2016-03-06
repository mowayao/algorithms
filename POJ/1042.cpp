#include <iostream>
#include <cstdio>
#include <cstring>
using   namespace std;
const int maxn = 50;
int D[maxn],F[maxn],T[maxn];
int n,h,ans;
void input(){
    ans = 0;
    scanf("%d",&h);
    for(int i = 0; i < n; i++)   scanf("%d",&F[i]);
    for(int i = 0; i < n; i++)   scanf("%d",&D[i]);
    for(int i = 0; i < n-1; i++)  scanf("%d",&T[i]);

}
void solve(){
    int cnt[maxn]={0},tmp[maxn]={0};
    int tf[maxn],td[maxn];
    for(int i = 0; i < n; i++){
        for(int ii= 0; ii < n; ii++){
            tf[ii] = F[ii];
            td[ii] = D[ii];
            tmp[ii] = 0;
        }
        int sum = 0;
        int t = 0;
        for(int j = 0; j < i; j++){
            t += 5*T[j];
        }
        int k = (h*60-t)/5;
        for(int ii = 0; ii < k; ii++){
            int mi = 0;
            for(int m = 0; m <= i; m++){
                if(tf[m]>tf[mi]){
                    mi = m;
                }
            }
            tmp[mi]++;
            sum += tf[mi];
            tf[mi] -= td[mi];
            if(tf[mi]<0) tf[mi] = 0;
        }
        if(sum >= ans){
            if(sum == ans){
                if(cnt[0]<tmp[0]){
                    for(int i = 0; i < n; i++) cnt[i] = tmp[i];
                }
                else if(cnt[0]==tmp[0]&&cnt[1]<tmp[1]){
                    for(int i = 0; i < n; i++) cnt[i] = tmp[i];
                }

            }else{
                ans = sum;
                for(int i = 0; i < n; i++) cnt[i] = tmp[i];
            }
        }
    }
    cout<<cnt[0]*5;
    for(int i = 1; i < n; i++){
        cout<<", "<<cnt[i]*5;
    }
    cout<<" "<<endl;
    printf("Number of fish expected: %d\n",ans);
}
int main(){
    int T = 1;
    while(~scanf("%d",&n) && n!=0){
       if(!T) cout<<endl;
       input();
       solve();
       T = 0;




    }

    return 0;
}
