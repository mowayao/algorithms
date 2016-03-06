#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int n,num[30];
    while(cin >> n){
       int ans;
       cin >> ans;
       for(int i = 1; i < n; i++){
           cin >> num[i];
           ans ^= num[i];
       }
       if(!ans)
         cout<<"No"<<endl;
       else
         cout<<"Yes"<<endl;
     //  cout<<ans<<endl;         
    }
    
    
    return 0;
}