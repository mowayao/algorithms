//Code here
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
#define  INF 1<<22
class UVA423{

     private:
     int ans;
     int dis[maxn][maxn];
     int n;
     public:
     void init(int N);
     void readCase();
     void computing();
     void outResult(){cout<<ans<<endl;}
};

void UVA423::init(int N){
 
   n = N;
   ans = 0;

}
void UVA423::readCase(){

   char temp[100];
   int t;
   for(int i = 2; i <= n; i++)
      for(int j = 1; j < i; j++){
        cin >> temp;
        if(temp[0] != 'x'){
          t = atoi(temp);
          dis[i][j] = t;
          dis[j][i] = t;
        }
        else{
           dis[i][j] = INF;
           dis[j][i] = INF;
        }
     }
}
void UVA423::computing(){
    for(int k = 1; k <= n;  k++)
      for(int i = 1; i <= n; i++)
       for(int j = 1; j <= n; j++)
       if(dis[i][j] > dis[i][k] + dis[k][j])
         dis[i][j] = dis[i][k] + dis[k][j];
    for(int i = 2; i <= n; i++){
      if(!ans)
         ans = dis[1][i];
      ans = max(dis[1][i],ans);
    }
}
int main(){

    int n;
    UVA423 xx;
    while(cin >> n){
      xx.init(n);
      xx.readCase();
      xx.computing();
      xx.outResult();
    }
}