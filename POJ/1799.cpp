#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = acos(-1.0);
int main(){
    int ncase,T=1;
    cin >> ncase;
    while(ncase--){
       double r,n,ans;
       cin >> r >> n;
       double ang = pi/n;
       ans = r*sin(ang)/(1+sin(ang));
       printf("Scenario #%d:\n%.3lf\n",T++,ans);
       cout<<endl;              
                   
    }
    
    return 0;   
}
