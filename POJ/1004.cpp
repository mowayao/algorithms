#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    
       float sum,a;
       sum = 0;
       
       for(int i =1 ;i <= 12;i++){
           
           scanf("%f",&a);
           sum += a;
       }
       printf("$%.2f\n",sum/12);
    
       return 0;
}
