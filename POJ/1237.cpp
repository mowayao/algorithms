//Code here
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 26;
#define INF 1000000000
int dis[maxn][maxn];
int du[maxn];
int len;
int main(){
   
    string temp;
   // memset(dis,INF,sizeof(dis));MARKED!!! why?
    for(int i = 0; i < maxn; i++)
       for(int j = 0; j < maxn; j++)
         if(i == j)
          dis[i][j] = 0;
         else{
           dis[i][j] = INF;
           dis[j][i] = INF;
         }
    memset(du,0,sizeof(du));
    int len = 0;
    while(cin >> temp){
       if(temp == "deadend"){
          for(int k = 0; k < 26; k++)
             for(int i = 0; i < 26; i++)
                for(int j = 0; j < 26; j++)
                   if(dis[i][j] > dis[i][k] + dis[k][j])
                       dis[i][j] = dis[i][k] + dis[k][j];
               
          int start,end; 
          bool flag = false;
          for(int i = 0; i < 26; i++)
            if(du[i]%2){
                if(flag)
                  end = i;
                else{
                  start = i;
                  flag = true;
                }
            }          
          if(!flag)
             cout << len << endl;
          else{
            
             cout << len + dis[start][end]<<endl;   
           }                                               
         // memset(dis,INF,sizeof(dis)) ??
          for(int i = 0; i < maxn; i++)
            for(int j = 0; j < maxn; j++)
              if(i == j)
                dis[i][j] = 0;
              else{
                dis[i][j] = INF;
                dis[j][i] = INF;
         }
          memset(du,0,sizeof(du));
          len = 0;
          
        }else{
            dis[temp[0]-'a'][temp[temp.size()-1]-'a'] = temp.size();
            dis[temp[temp.size()-1]-'a'][temp[0]-'a'] = temp.size(); 
            len += temp.size();
            du[temp[0]-'a']++;
            du[temp[temp.size()-1]-'a']++;
         }
       
         
    }


    return 0;
} 