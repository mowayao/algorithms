#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 200000+10;
struct node{
    int x;
    int step;
    node(int x,int step):x(x),step(step){}
    node(){}
};
bool vis[maxn];
int n,k,ans;
queue<node> que;
int bfs(){
    memset(vis,0,sizeof vis);
    vis[n] = 0;
    while(!que.empty()) que.pop();
    que.push(node(n,0));
    int ans = maxn;
    while(!que.empty()){
        node ns = que.front();
        que.pop();
        if(ns.x == k) {
            ans = min(ans,ns.step);
            break;
                //return ns.step;
        }
        node na;
        int x = ns.x;
        if(x > k){
            if(!vis[x-1]){
                vis[x-1] = 1;
                ans = min(ans,x-k+ns.step);
               // na.x = x-1;
               // na.step = ns.step+1;
               // que.push(na);
            }
        }else{
            if(x>0&&!vis[x-1]){
                vis[x-1] = 1;
                na.x = x-1;
                na.step = ns.step+1;
                que.push(na);
            }
            if(!vis[x+1]){
                vis[x+1] = 1;
                na.x = x+1;
                na.step = ns.step+1;
                que.push(na);
            }
            if(!vis[2*x]){
                vis[2*x] = 1;
                na.x = 2*x;
                na.step = ns.step+1;
                que.push(na);
            }
        }
    }
    return ans;
}
int main(){

    while(cin >> n >> k){
        if(n==k) cout<<0<<endl;
        else cout<<bfs()<<endl;
    }
    return 0;
}
