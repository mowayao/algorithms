#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100000+10;

struct node{
    int lson,rson;
    int mid(){
        return (lson+rson)>>1;
    }
}tree[maxn*4];

int seg[25][maxn];
int n,m;
int num[maxn];
int sta,ed;

void build(int L,int R,int rt,int deep){
    tree[rt].lson = L;
    tree[rt].rson = R;
    if(L==R){
        seg[deep][L] = num[L];
        return;
    }
    int mid = tree[rt].mid();
    build(L,mid,rt<<1,deep+1);
    build(mid+1,R,rt<<1|1,deep+1);
    int i = L,j = mid+1,k = L;
    while(i <= mid && j <= R){
        if(seg[deep+1][i] < seg[deep+1][j]){
            seg[deep][k] = seg[deep+1][i];
            i++;
        }else{
            seg[deep][k] = seg[deep+1][j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        seg[deep][k] = seg[deep+1][i];
        i++;
        k++;
    }
    while(j <= R){
        seg[deep][k] = seg[deep+1][j];
        j++;
        k++;
    }
    return;
}

int query(int rt,int dep,int key){
    if(tree[rt].lson >= sta && tree[rt].rson <= ed){
        int t = lower_bound(&seg[dep][tree[rt].lson],&seg[dep][tree[rt].rson]+1,key)-&seg[dep][tree[rt].lson];
        return t;
    }
    int mid = tree[rt].mid();
    int  res = 0;
    if(mid >= sta){
        res += query(rt<<1,dep+1,key);
    }
    if(mid < ed){
        res += query(rt<<1|1,dep+1,key);
    }
    return res;
}

int binary(int tk){
    int L = 1,R = n;
    while(L < R){
        int mid = (L+R+1) >> 1;
        if(query(1,0,seg[0][mid]) > tk){
            R = mid-1;
        }else{
            L = mid;
        }
    }
    return seg[0][L];

}

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d",&num[i]);
    }
    build(1,n,1,0);
    while(m--){
        int k;
        scanf("%d%d%d",&sta,&ed,&k);
        printf("%d\n",binary(k-1));
    }
    return 0;
}
