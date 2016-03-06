#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000+10;
int pyer[maxn],n,ans;
int main(){
    int ncase;
    cin >> ncase;
    while(ncase--){
        ans = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++) scanf("%d",&pyer[i]);
        if(n<=2){
            for(int i = 1; i <= n; i++) ans = max(ans,pyer[i]);
            cout<<ans<<endl;
            continue;
        }
        sort(pyer+1,pyer+1+n);
        int i = n;
        if(i == 3){
            ans += pyer[1]+pyer[2]+pyer[3];
            cout<<ans<<endl;
            continue;
        }
        while(i >= 4){
            if(pyer[2]*2>pyer[i-1]+pyer[1]){
                ans += pyer[1]*2+pyer[i]+pyer[i-1];
                i -= 2;
            }else{
                ans += pyer[1]+pyer[i]+pyer[2]*2;
                i -= 2;
            }
            if(i==3){
                ans += pyer[3]+pyer[1];
            }
        }
        ans += pyer[2];
        cout<<ans<<endl;

    }
    return 0;
}
