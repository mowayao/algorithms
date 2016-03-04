#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 10000+10;
stack<int> stk;
struct node{
    char ch;
    int lft;
    int rgt;
};
vector<node> vn;
vector<int> g[maxn];
int mmax;
void dfs(int dep,int id){
    if(vn[id].lft != -1){
        g[dep].push_back(vn[id].lft);
        g[dep].push_back(vn[id].rgt);

        dfs(dep+1,vn[id].lft);
        dfs(dep+1,vn[id].rgt);
    }else{
        mmax = max(dep,mmax);
    }

}
int main(){

    string st;
    int ncase;
    cin >> ncase;
    while(ncase--){
        cin >> st;
        vn.clear();
        vn.resize(st.size());
        mmax = -1;
        while(!stk.empty()) stk.pop();
        for(int i = 0; i < st.size(); i++) g[i].clear();
        int dep = 1;
        for(int i = 0; i < st.size(); i++){
            if(st[i] >= 'a' && st[i] <= 'z'){
                vn[i].ch = st[i];
                vn[i].lft = -1;
                vn[i].rgt = -1;
                stk.push(i);
            }else{
                dep++;
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                vn[i].ch = st[i];
                vn[i].lft = a;
                vn[i].rgt = b;
                stk.push(i);
            }
        }
        dfs(0,st.size()-1);
        for(int i = mmax; i >= 0; i--){
            for(int j = 0; j < g[i].size(); j++){
                cout<<st[g[i][j]];
            }
        }
        cout<<st[st.size()-1]<<endl;

    }
    return 0;
}
