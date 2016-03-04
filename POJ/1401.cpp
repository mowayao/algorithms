#include <iostream>
#include <cmath>
#include <cstdio>
using namespace  std;
int main(){
    
    int ncase;
    cin >> ncase;
    int num[16];
    num[0] = 1;
    for(int i = 1; i < 16; i++){
        num[i] = num[i-1]*5;
    }
    while(ncase--){   
        int n,ans;
        cin >> n;
        ans = 0;
        for(int i = 1; i < 16; i++){
            if(n/num[i]>0)
              ans += n/num[i];
            else
              break;     
        }
        cout<<ans<<endl;
    }
    return 0;
}
