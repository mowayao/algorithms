#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000000;
int n;
int prime[300];
bool isprime[maxn+10];
int cnt;
int main(){
	cnt = 0;
	for(int i = 1; i <= maxn; i++)
	  isprime[i] = 1;
    isprime[1] = 0;
    for(int i = 2; i*i <= maxn; i++)
        if(isprime[i]){
           prime[cnt++] = i;
           for(int j = i*i; j <= maxn; j +=i)
              isprime[j] = 0;                
        }          
    while(cin >> n && n){   
        int ans;
        bool flag = 1;
        //cout<<cnt<<endl;
        for(int i = 0; i < cnt; i++){
              if(n > prime[i] && isprime[n-prime[i]]){
                  ans =  prime[i];
                  flag = 0;   
                  break;
              }
        }
       if(!flag)
          printf("%d = %d + %d\n",n,ans,n-ans);
        else
          printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}