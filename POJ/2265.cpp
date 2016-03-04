//Code here
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 1001000
struct node{
  int x,y;     
}N[maxn];
const int dir[6][2] = {{0,-1},{-1,0},{-1,1},{0,1},{1,0},{1,-1}};
int n;
void init(){
  N[1].x = N[1].y = 0;
    int cnt = 0;
    while(1+(cnt-1)*cnt*3 <= maxn-1000){   
       int step = 1 + cnt*(cnt+1)*3,tmp = 0;
       int curx = cnt,cury = 0;
       for(int i = 0; i < 6;i++){
            tmp = 0 ;
             while(tmp < cnt){
                 if(step<=1+(cnt-1)*cnt*3)
                    break; 
                 N[step].x = curx;
                 N[step].y = cury;
                 curx += dir[i][0];
                 cury += dir[i][1];    
                 step--;    
                 tmp++;   
             }
                
       }         
         cnt++;     
    }

}
int main(){
    
    
   init();
    while(scanf("%d",&n)==1){
       
       printf("%d %d\n",N[n].x,N[n].y);
     //  [sqrt(12x-3)-3]/6
    }
    return 0;
}