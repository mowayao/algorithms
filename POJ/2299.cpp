#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn =  500000 + 10;
int A[maxn],C[maxn];
int MAX;
struct node{
	int val,id;
	bool operator <(const node & a)const{
		return val < a.val;
	}
}Node[maxn];
int lowbit(int x){ 
    return x&(-x); 
} 
void update(int x,int val){ 
    while(x <= MAX){ 
        C[x] += val; 
        x += lowbit(x); 
    } 
} 
int get(int x){ 
    int sum=0; 
    while(x > 0){ 
        sum += C[x]; 
        x -= lowbit(x); 
    } 
    return sum; 
} 

int main(){

    
    while(scanf("%d",&MAX)==1 && MAX){
    	
    	memset(A,0,sizeof(A));
    	memset(C,0,sizeof(C));
    	for(int i = 1; i <= MAX; i++){
    	   scanf("%d",&Node[i].val);
    	   Node[i].id = i;
        }
        
        sort(Node+1,Node+MAX+1);
        A[Node[1].id] =  1;
        for(int i=2; i <= MAX; i++){
           if(Node[i].val != Node[i-1].val)
              A[Node[i].id] = i;
           else
              A[Node[i].id] = A[Node[i-1].id];
       }
       long long  ans = 0;
       for(int i=1; i<=MAX; i++){
           update(A[i], 1);
           ans += get(MAX) -  get(A[i]); 
       }
       printf("%I64d\n",ans);
    }
    return 0;
}