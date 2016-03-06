//Code here
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
//////////////////////////////////////
const int maxn = 3000 + 10;
struct rect{
   int len;
   int wid;
   int hei;
  // int area;
   rect(int a = -1,int b = -1,int c = -1){
      len = a;
      wid = b;
      hei = c;
   }
   friend bool operator < (rect a,rect b){
       return (a.len<b.len && a.wid<b.wid);      
   }
  
};
int n,height[maxn];
vector<rect> R;
/////////////////////////////////////////
void init(){
    R.clear();
    memset(height,0,sizeof(height));
}
//////////////////////////////////////////////
void input(){
    int a,b,c;
    for(int i = 0; i < n; i++){ 
      scanf("%d%d%d",&a,&b,&c);
      int d,e;
      d = min(a,b),e = max(a,b);
      R.push_back(rect(d,e,c));
      d = min(a,c),e = max(a,c);
      R.push_back(rect(d,e,b));
      d = min(b,c),e = max(b,c);
      R.push_back(rect(d,e,a));
    }
}
///////////////////////////////////////////////////
void solve(){
    for(int i = 0; i < R.size()-1; i++)
      for(int j = i+1; j < R.size(); j++)
         if(R[j] < R[i]){
            rect tmp;
            tmp = R[j];
            R[j] = R[i];
            R[i] = tmp;
         }
    height[0] = R[0].hei;    
    int ans = 0;
    for(int i = 0; i < R.size(); i++){
       int Max = 0;
       for(int j = 0; j < i; j++){
           if(R[i].len > R[j].len && R[i].wid > R[j].wid && Max <= height[j]){
              Max = height[j];
           }
       }
       height[i] = Max + R[i].hei;
       ans = max(ans,height[i]);
    
    }
    printf("%d\n",ans);    
}
/////////////////////////////////////////////////
int main(){
    
    int T = 1;
    while(scanf("%d",&n)==1 && n){
        printf("Case %d: maximum height = ",T++);
        init();
        input();
        solve();
    }
    return 0;
}
/*   for( int i=1 ; i<=tot; i++)
             for( int j=1 ; j<=tot; j++)
               if( a[ j ].b>a[ i ].b && a[ j ].a>a[ i ].a )
                 map[ j ][ i ]=a[ i ].h+a[ j ].h;      建边

           for( int k=1 ; k<=tot ;k++)
             for( int i=1 ; i<=tot ; i++)
               for( int j=1 ; j<=tot ; j++)
               if( i!=j ){
                 map[ i ][ j ]=max( map[ i ][ j ] , map[ i ][ k ]+map[ k ][ j ]-a[ k ].h );
                 ans=max( ans , map[ i ][ j ] );
               }          floyd最长路Case 1: maximum height = 342
Case 2: maximum height = 588
Case 3: maximum height = 5
Case 4: maximum height = 481
Case 5: maximum height = 180
Case 6: maximum height = 273
Case 7: maximum height = 200
Case 8: maximum height = 310
Case 9: maximum height = 50*/