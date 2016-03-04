#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int n,temp,sum;
    bool judge[10000];
    memset(judge,false,sizeof(judge));
    n = 1;
    while(n < 10000){
            
     temp = n;
     sum = n;
     while(temp){   
        sum += temp%10;
        temp /= 10;
     }
      if(sum  < 10000)
     judge[sum] = true;
     n++;
   }
   for(int i = 1 ;i < 10000;i++){
      if(!judge[i]){
         cout<<i<<endl;
      }
 
   }
  // system("pause");
    return 0;
}
