#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
     
    int n;
    while(cin >> n){
       int ans;
       int i = 1,cnt=0;
       while(i < n){
          int ans = n - (i-1)*i/2;
          if(ans <= 0)
            break;
          if(ans % i==0)
            cnt++;
          //cout<<i<<" "<<ans<<endl;
          i++;
          //cout<<i<<endl;
       }   
       cout<<cnt<<endl;
              
    }  
   
    
    return 0;
}
