#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 40000+10;
int n,m,k;
int fa[maxn];
int distX[maxn],distY[maxn];
int ans[maxn];

struct node{
    int s,e,id,last;
    node(int s,int e,int last,int id):s(s),e(e),last(last),id(id){}
    friend bool operator <(node a,node b){
        return a.last < b.last;
    }
};

struct edge{
    int s,e,d;
    char dir;
    edge(int s,int e,int d,char dir):s(s),e(e),d(d),dir(dir){}

};
vector<edge> ve;
vector<node> vn;
void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        distX[i] = 0;
        distY[i] = 0;
    }
    vn.clear();
    ve.clear();
}

int find(int x){
    if(fa[x] != x){
        int t = fa[x];
        fa[x] = find(fa[x]);
        distX[x] += distX[t];
        distY[x] += distY[t];
    }
    return fa[x];
}

int main(){

    while(~scanf("%d%d",&n,&m)){
        init();
        int a,b,w,pre;
        char op[20];
        while(m--){
            scanf("%d%d%d%s",&a,&b,&w,op);
            ve.push_back(edge(a,b,w,op[0]));
        }
        scanf("%d",&k);
        for(int i = 0; i < k; i++){
            scanf("%d%d%d",&a,&b,&pre);
            vn.push_back(node(a,b,pre-1,i));
        }
        sort(vn.begin(),vn.end());
        for(int i = 0,j = 0; i < ve.size()&&j < vn.size();i++){
            int offX=0,offY=0;
            if(ve[i].dir=='E'){
                offX = -ve[i].d;
                //distX[ve[i].s] += ve[i].d;
            }
            else if(ve[i].dir=='W'){
                offX = ve[i].d;
               // distX[ve[i].s] += -ve[i].d;
            }
            else if(ve[i].dir=='N'){
                offY =  -ve[i].d;
                //distY[ve[i].s] +=  -ve[i].d;
            }
            else{
                offY = ve[i].d;
                //distY[ve[i].s] +=  ve[i].d;
            }
            int a = find(ve[i].s);
            int b = find(ve[i].e);
            if(a != b){
                fa[b] = a;
                distX[b] = offX+distX[ve[i].s]-distX[ve[i].e];
                distY[b] = offY+distY[ve[i].s]-distY[ve[i].e];
              //  cout<<b<<"  "<<distX[b]<<" "<<distY[b]<<endl;
                //distY[a] += distX[ve[i].s];
                //distX[a] += distY[ve[i].e];
            }
            while(vn[j].last==i){
                if(find(vn[j].s)==find(vn[j].e)){
                   // cout<<distX[vn[j].s]<<" "<<distX[vn[j].e]<<endl;
                    //cout<<distY[vn[j].s]<<" "<<distY[vn[j].e]<<endl;
                    ans[vn[j].id] = abs(distX[vn[j].s]-distX[vn[j].e])+abs(distY[vn[j].s]-distY[vn[j].e]);
                }else{
                    ans[vn[j].id] = -1;
                }
                j++;
            }
        }
        for(int i = 1; i <= n; i++){
           // cout<<fa[i]<<endl;
        }

        for(int i = 0; i < k; i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
