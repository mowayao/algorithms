//coder rusher
//easy lis
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10000 + 10;
int n,b[maxn];
vector<int>V;
void init(){
    V.clear();
   // b.clear();
    n = 0;    
}
int binary(int x){
    int l = 0,r = V.size();
    while(l+1 != r){
        int mid = (l + r)>>1;
        if(V[mid] > x)
          l = mid;
        else
          r = mid;
    
    }
    return r;
   
}
void solve(){
     
     V.push_back(-1);
     V.push_back(b[0]);
     for(int i = 1; i < n; i++){
        if(b[i] < V[V.size()-1])
           V.push_back(b[i]);
        else if (b[i] > V[V.size()-1]){
           int tmp = binary(b[i]);
           V[tmp] = b[i];   
        } 
     }
        
     
}
int main(){
    
    int a;
    int casen = 1;
    bool flag = 0;
    while(scanf("%d",&a)==1 && a!=-1){
            
         init(); 
         b[n++] = a;
         while(scanf("%d",&b[n])==1&&b[n]!=-1)
            n++;
           
         solve();
        // for(int i = 0 ; i < V.size(); i++)
         //  cout<<V[i]<<" "<<endl;
         if(flag)
           cout<<endl;
         printf("Test #%d:\n",casen++);
         printf("  maximum possible interceptions: %d\n",V.size()-1);
         flag = 1;
    }
    return 0;
}
/*
Sample Input

389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1

Sample Output

Test #1:
  maximum possible interceptions: 6

Test #2:
  maximum possible interceptions: 2

*/
