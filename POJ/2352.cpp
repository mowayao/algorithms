//Code here
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 32000 + 10;
const int maxm = 16000 + 10;
struct tree{
  int lchild,rchild,sum;
}A[maxn*4];
void buildtree(int lchild,int rchild,int step){

   //int mid = (A[step].lchild + A[step].rchild)/2;
   A[step].lchild = lchild;
   A[step].rchild = rchild;
   A[step].sum = 0;
   if(lchild == rchild)  return;
   int mid = (A[step].lchild + A[step].rchild)/2;
   buildtree(lchild,mid,2*step);
   buildtree(mid+1,rchild,2*step+1);

}

int query(int lchild,int rchild,int step){
     int sum = 0;
     if(A[step].lchild == lchild && A[step].rchild == rchild)
        return A[step].sum;
     else{
         int mid = (A[step].lchild + A[step].rchild)/2;
         if(lchild > mid){
             sum += query(lchild,rchild,step*2+1);
         }
         else if(rchild <= mid){
             sum += query(lchild,rchild,step*2);
         }
         else{
             sum += query(lchild,mid,step*2)+query(mid+1,rchild,step*2+1);
         } 
         
       return sum;
      }   
     
}
void insert(int x, int step){
      
      A[step].sum++;
      if(x == A[step].rchild && A[step].lchild == A[step].rchild){ 
          return;
      }
      int mid=(A[step].lchild+A[step].rchild)/2;
      if (mid >= x)   insert(x,step*2);//如果中点在r的右边，则应该插入到左儿子
      else insert(x,step*2+1);//如果中点在l的左边，则应该插入到右儿子
    
}
int main(){
    
   int ncase;
   while(~scanf("%d",&ncase)){
      buildtree(0,maxn,1);
      
      int l,r,ans[maxm];
      memset(ans,0,sizeof(ans));
      for(int i = 0; i < ncase; i++){
         scanf("%d%d",&l,&r);
         ans[query(0,l,1)]++;
         insert(l,1);
      }
      for(int i = 0; i < ncase; i++)
        cout<<ans[i]<<endl;
   
   
   }
   return 0;
}
