#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    
    double ans[400];
    ans[1] = .5;
    for(int i = 2; i < 400; i++){
        ans[i] = ans[i-1] + 1/double(i+1);
       // cout<<ans[i]<<endl;        
    }
    double c;
    while(cin >> c && abs(c)>0){
        //cout<<c<<endl;
        int k = lower_bound(ans,ans+400,c)-ans;
        cout<<k<<" "<<"card(s)"<<endl;         
    }
    
    return 0;   
}
