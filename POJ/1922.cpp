#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int n;
    while(cin >> n && n){
        int speed,t,time1;
        double  ans = 100000000;
    
        for(int  i = 0; i < n; i++){
            cin >> speed >> t;
            if(t >= 0){
              double tmp = ceil(16200.0/speed)+t;
              if(ans > tmp)
                ans = tmp;
            }
              
        }
        cout<<ans<<endl;        
              
    }
    
    return 0;   
}
