#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1000 + 10;
vector<int> V;
int a[maxn],n;
void init(){
     
   V.clear();
}
int binary(int x){
     
    int l = 0, r = V.size();
    while(l+1!=r){ 
        int mid = (l + r) >> 1;
        if(V[mid] < x)
           l = mid; 
        else
           r = mid;  
        
    }
    return r;
}
void solve(){
     
    V.push_back(1000000);
    V.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] > V[V.size()-1])
          V.push_back(a[i]);
        else if(a[i] < V[V.size()-1]){
           int k = binary(a[i]);
           //cout<<V[k]<<endl;
           V[k] = a[i];     
             
        }
               
    }
    //for(int i = 0; i < V.size(); i++)
     // cout<<V[i]<<" ";
    printf("%d\n",V.size()-1);     
     
     
}
int main(){
    
    while(scanf("%d",&n)==1){    
        init();
        for(int i = 0; i < n; i++){
           scanf("%d",&a[i]);            
        }
        solve();
        
    }
    return 0;
}
