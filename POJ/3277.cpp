//POJ3277(线段树)
//Coder Yao
//Code here
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
struct tree{
   int l,r,h;
   bool friend operator<(tree a,tree b){
       return a.h<b.h;
   }
}A[maxn*4],temp[maxn];
long long sum = 0;
int a[maxn],b[maxn],len;
void buildtree(int root,int l,int r){

   A[root].l = l;
   A[root].r = r;
   A[root].h = 0;
   if(r-l==1)return ;
   int mid=(l+r)/2;
   buildtree(root*2,l,mid);
   buildtree(root*2+1,mid,r);

}
void insert(int root,int l,int r,int h)
{
       if(l==A[root].l && A[root].r==r){
            A[root].h=h;
            return;
       }
       if(A[root].h > 0){//已访问过
            A[root*2].h=A[root].h;
            A[root*2+1].h=A[root].h;
            A[root].h=0;
       }
    
      int mid=(A[root].l+A[root].r)/2;
      if(r <= mid)
         insert(root*2,l,r,h);
      else if(l >= mid)
         insert(root*2+1,l,r,h);
      else{
           insert(root*2,l,mid,h);
           insert(root*2+1,mid,r,h);
       }
}
void search(int root)
{
     if(A[root].h > 0){
          sum +=(long long)(b[A[root].r]-b[A[root].l])*A[root].h;//强转 mark
          return;
     }
     if(A[root].r == A[root].l + 1)
          return;
     search(root*2);
     search(root*2+1);

}
void discre(int u)//离散化
{
       sort(a+1,a+u);
       b[1]=a[1],len=1;
       int i;
       for(i=2,len=2;i < u; i++){ 
             if(a[i-1] != a[i]){
                  b[len++]=a[i];   
              }
       }
}
int find(int x){
   int mid,l,r;
   l=1;
   r=len-1;
   while(l <= r){   
       mid=(l+r)/2;
       if(x < b[mid])
          r=mid-1;
       else if(x > b[mid]) 
          l=mid+1;
       else 
          return mid;
   }
}
int main(){

   int 	N;
   cin >> N;
   int j = 1;
   for(int i = 0; i < N; i++){
      scanf("%d%d%d",&temp[i].l,&temp[i].r,&temp[i].h);
      a[j++] = temp[i].l;
      a[j++] = temp[i].r;
   }
   discre(2*N+1);
   sort(b+1,b+len-1);
   buildtree(1,1,len-1);
   sort(temp,temp+N);   
   for(int i = 0;i < N; i++){
      insert(1,find(temp[i].l),find(temp[i].r),temp[i].h);
   }
    search(1);
    printf("%I64d\n",sum);
    return 0;
};