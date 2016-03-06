//Code here
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Point{
    int x,y;
    int face;
    int step;
    bool friend operator ==(Point a,Point b){return a.x==b.x && a.y==b.y;}
};
class Robot{

      private:
      int N,M,ans;
      Point start,end;
      bool board[60][60];
      bool vis[60][60][4];
      public:
      void init(int n,int m);
      void readCase();
      void computing();
      void outResult(){cout<<ans<<endl;}
};
void Robot::init(int n,int m){

   N = n;
   M = m;
   ans = -1;
   memset(vis,false,sizeof(vis));
   memset(board,false,sizeof(board));
}
void Robot::readCase(){
   
   string ori;
   for(int i = 0; i < N;i++)
      for(int j = 0; j < M; j++){
         int temp;
         cin >> temp;
         if(temp){
           board[i][j] = true;
           board[i+1][j]= true;
           board[i][j+1] = true;
           board[i+1][j+1] = true;    
         }
     }
    cin >> start.x >>start.y >> end.x >> end.y >> ori;
    //cout<<ori;
    if(ori == "south")
      start.face = 3;
    else  if(ori == "north")
      start.face = 1;
    else  if(ori == "west")
      start.face = 0;
    else  if(ori == "east")
      start.face = 2;
      
}
void Robot::computing(){
     
     Point n,ns;
     if(board[end.x][end.y]||board[start.x][start.y])
        return;
     queue<Point> Q;
     start.step = 0;
     Q.push(start);
     vis[start.x][start.y][start.face] = true;
     while(!Q.empty()){
       
        n = Q.front();
        Q.pop();
        if(n == end ){
          ans = n.step;
          break;
        }
        if(n.face == 0){
         ns = n;
         ns.face = 1;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         ns.face = 3;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         for(int i = 1; i <= 3; i++){
              ns.y = n.y-i;
              ns.x = n.x;  
              ns.face = n.face;
              if(ns.y < 1 )
                break;
              if(board[ns.x][ns.y])
                break;  
              
              if(!vis[ns.x][ns.y][ns.face] ){
                 vis[ns.x][ns.y][ns.face] = true;
                 ns.step = n.step + 1;
                 Q.push(ns);
             }  
           }
           
        }
      else  if(n.face == 1){
         ns = n;
         ns.face = 2;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         ns.face = 0;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
             for(int i = 1; i <= 3; i++){
                ns.x = n.x - i;
                ns.y = n.y;
                ns.face = n.face;
                
                if(ns.x < 1)
                   break;
                if(board[ns.x][ns.y])
                   break;  
                if(!vis[ns.x][ns.y][ns.face]){
                     vis[ns.x][ns.y][ns.face] = true;
                     ns.step = n.step + 1;
                     Q.push(ns);
               }  
             }
         }
       else  if(n.face == 2){
         ns = n;
         ns.face = 3;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         ns.face = 1;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         for(int i = 1; i <= 3; i++){
                ns.y = n.y + i;
                ns.x = n.x;
                ns.face = n.face;
                if(ns.y > M-1)
                  break;
                if(board[ns.x][ns.y])
                   break;  
                if(!vis[ns.x][ns.y][ns.face] ){
                     vis[ns.x][ns.y][ns.face] = true;
                     ns.step = n.step + 1;
                     Q.push(ns);
                }  
             }
         }
         else if(n.face == 3){
         ns = n;
         ns.face = 2;
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         ns.face = 0;    
         if(!vis[ns.x][ns.y][ns.face]){
            vis[ns.x][ns.y][ns.face] = true;
            ns.step = n.step + 1;
            Q.push(ns);
         }
         for(int i = 1; i <= 3; i++){
                ns.x = n.x + i;
                ns.y = n.y;
                ns.face = n.face;
                if(ns.x > N-1)
                   break;
                if(board[ns.x][ns.y])
                   break;   
                if(!vis[ns.x][ns.y][ns.face] ){
                     vis[ns.x][ns.y][ns.face] = true;
                     ns.step = n.step + 1;
                     Q.push(ns);
                }  
          }
         }
        
     }
}
int main(){

    int N,M;
    Robot xx;
    while(cin >> N >> M && N+M){
       xx.init(N,M);
       xx.readCase();
       xx.computing();
       xx.outResult();
   }
   return 0;
}