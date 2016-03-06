#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100+10;
const int xx[4] = {0,0,1,-1};
const int yy[4] = {1,-1,0,0};
const int dir[4][2] = {2,-1,2,1,-2,1,-2,-1};
const int dre[4][2] = {1,2,1,-2,-1,-2,-1,2};
struct node{
	int x,y,type;
	node(int x=0,int y=0,int type=0):x(x),y(y),type(type){}
};
vector<node> xq;
int gx,gy;
int mat[maxn][maxn];
bool in_chess(int x,int y){
	return x >= 1 && x <= 10 && y >= 1 && y <= 9;
}
bool in_board(int x,int y){
	return x>=1 && x <=3 && y >=4 && y <= 6;
}
bool checkmate(node black,node red){
		int minx = min(black.x,red.x);
		int maxx = max(black.x,red.x);
		int miny = min(black.y,red.y);
		int maxy = max(black.y,red.y);
		if(red.type == 1){
		   if(red.y == black.y){
		    for(int k = minx+1; k < maxx; k++){
		   	  if(mat[k][red.y])
		   		return false;
		    }
		    return true;
	       }else  return false;
	
		}
		else if(red.type == 2){
		   if(black.x == red.x){
		   	for(int k = miny+1; k < maxy; k++)
		   		if(mat[red.x][k]) return false;
		   	return true;
		   }
		   else if(red.y == black.y){
		   	for(int k = minx+1; k < maxx; k++)
		   		if(mat[k][red.y])  return false;
		   	return true;
		   }else  return false;
		}	
		else if(red.type == 4){
		   int cnt = 0;
		   if(red.x == black.x){
		   	for(int k = miny+1; k < maxy; k++)
		   		if(mat[red.x][k]) cnt++;
			if(cnt == 1)  return true;
		    else  return false;
		   }
		   else if(red.y == black.y){
		   	for(int k = minx+1; k < maxx; k++)
		   		if(mat[k][red.y])  cnt++;
		   	if(cnt == 1)  return true;
		    else  return false;
		   	
		   }else return false;
		   
		    
		}
		else{
           for(int i = 0; i < 4; i++){
           	int tx = red.x+xx[i];
           	int ty = red.y+yy[i];
           	if(!in_chess(tx,ty))  continue;
           	if(!mat[tx][ty]){
           		switch (i){
           			case 0:
           				if(tx+1==black.x && ty+1 == black.y) return 1;
           				if(tx-1==black.x && ty+1 == black.y) return 1;
           				break;
           			case 1:
           				if(tx+1==black.x && ty-1 == black.y) return 1;
           				if(tx-1==black.x && ty-1 == black.y) return 1;
           				break;
           			case 2:
           				if(tx+1==black.x && ty-1 == black.y) return 1;
           				if(tx+1==black.x && ty+1 == black.y) return 1;
           				break;
           			case 3:
           				if(tx-1==black.x && ty-1 == black.y) return 1;
           				if(tx-1==black.x && ty+1 == black.y) return 1;
           			
           				
           		}
           	}
           }
		   return false;   
       }
		
	
}
void init(){
	memset(mat,0,sizeof(mat));
	xq.clear();
}
/*1 : 将军
  2 : 车
  3 ：马
  4 ：炮 
*/ 
int main(){
	int n;
	while(~scanf("%d%d%d",&n,&gx,&gy) && n|gx|gy){
		init();
		while(n--){
		   char type;
		   int a,b; 
		   cin >> type >> a >> b;
		   mat[a][b] = 1;
		   if(type == 'G'){
		   	 xq.push_back(node(a,b,1));
		   	 
		   }	
		   else if(type == 'R'){
		     xq.push_back(node(a,b,2));
		   }
		   else if(type == 'H'){
		   	 xq.push_back(node(a,b,3));
		   }else{
		   	 xq.push_back(node(a,b,4));
		   }
		  
		} 
		bool flag;
		for(int i = 0; i < 4; i++){
			 
		   	 int x = gx + xx[i];
		   	 int y = gy + yy[i];
		   	 if(in_board(x,y)){
				flag = 0;
		   	 	node tmp;
		   	 	tmp.x = x;
		   	 	tmp.y = y;
		   	 	for(int j = 0; j < xq.size(); j++){
		   	 		if(x == xq[j].x && y == xq[j].y)  continue;
		   	 		if(checkmate(tmp,xq[j])){
		   	 			flag = 1;
		   	 			break;
		   	 		}
		   	 	}
				if(!flag)  break;
		   	 
		   	 }
		   	 
		}
		if(!flag)  cout<<"NO"<<endl;
		else    cout<<"YES"<<endl;
	}
	return 0;
}