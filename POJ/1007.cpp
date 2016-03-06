#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct node{
    int ans;
    int ind;
    friend bool operator < (node a,node b){
       if(a.ans!=b.ans)
          return a.ans < b.ans;
       else
           return a.ind < b.ind;   
    }        
};
int main(){
    int r,c;
    string st[110];
    while(cin >> r >> c){
       vector<node>a;
       a.resize(c);
       for(int i = 0 ; i < c; i++){
          cin >> st[i];
          int sum = 0;
          for(int j = 1; j < st[i].size(); j++){
              for(int k = 0; k < j; k++){
                   if(st[i][k] > st[i][j]) 
                     sum++;   
              }
              
          }
         // cout<<sum<<endl;
          a[i].ans = sum;
          a[i].ind = i;      
       }
       sort(a.begin(),a.end());
       for(int i = 0; i < c; i++)
         cout<<st[a[i].ind]<<endl;
    
    
    }
    return 0;
}
