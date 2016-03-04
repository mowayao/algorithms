//Code here
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 10;
struct tree{
   int l,r,max,min;
}node[maxn*4];
int val[maxn];
int Max,Min;
void build(int root,int l,int r){

     node[root].l = l;
     node[root].r = r;
     if(l == r){
       node[root].min = val[r];
       node[root].max = val[r];
       return;
     }
     int mid =(node[root].l + node[root].r)/2;
     build(root*2,l,mid);
     build(root*2+1,mid+1,r);
     node[root].max = max(node[root*2].max,node[root*2+1].max);
     node[root].min = min(node[root*2].min,node[root*2+1].min);
}
void query(int root,int l,int r){

     if(node[root].l == l && node[root].r == r){
        Max = max(node[root].max,Max);
        Min = min(node[root].min,Min);
        return; 
     }
     int mid = (node[root].l + node[root].r)/2;
         if(l > mid){
             query(2*root+1,l,r);
         }
         else if(r <= mid){
             query(2*root,l,r);
         }
         else{
             query(root*2,l,mid);
             query(2*root+1,mid+1,r);
         } 

}
int main(){


    int n,q;
    
    while(cin >> n >> q){
      for(int i = 1; i <= n; i++){
        scanf("%d",&val[i]);
      }
      build(1,1,n);
      
     while(q--){
         int s,e;
         scanf("%d%d",&s,&e);
         Max = 0;
         Min = 10000000;
         query(1,s,e);
         cout<<Max-Min<<endl;
      }
    }

    return 0;
}