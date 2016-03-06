#include <iostream>

using namespace std;

int main(){
    
    int n,num[31],sum1,sum2;
    while(cin >> n && n){
       
       sum1 = 0;
       sum2 = 0;
       for(int i = 0;i < n;i++){
         cin >> num[i];
         sum1 += num[i];
       }
      
      for(int i = 0 ;i < n;i++){
           sum2 +=num[i];
           if((sum1 - sum2) ==sum2){
               cout<<"Sam stops at position "<<i+1<< " and Ella stops at position "<<i+2<<"."<<endl;
               break;
           }
           else if((sum1-sum2) < sum2){
                cout<<"No equal partitioning."<<endl;
                break;
           }
     }
    
    }   
    return 0;   
     
}
