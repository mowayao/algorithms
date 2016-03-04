#include <iostream>
#include <cstdio>
#include <cstring>
#define REP(_,a,b) for(_ = (a); _ <= (b); _++)
using namespace std;
const int maxn = 100000+10;
struct node{
	int lson,rson;
	int lSmin,rSmin,lSmax,rSmax,sum;
	int mid(){
		return (lson+rson)>>1; 
	}
	int minn,maxx;
}tree[maxn<<2];
int n;
int num[maxn];
void pushUp(int rt){
	tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
	tree[rt].lSmax = max(tree[rt<<1].lSmax,tree[rt<<1].sum+tree[rt<<1|1].lSmax);
	tree[rt].lSmin = min(tree[rt<<1].lSmin,tree[rt<<1].sum+tree[rt<<1|1].lSmin);
	tree[rt].rSmin = min(tree[rt<<1|1].rSmin,tree[rt<<1|1].sum+tree[rt<<1].rSmin);
	tree[rt].rSmax = max(tree[rt<<1|1].rSmax,tree[rt<<1|1].sum+tree[rt<<1].rSmax);
	tree[rt].maxx = max(max(tree[rt<<1].maxx,tree[rt<<1|1].maxx),tree[rt<<1].rSmax+tree[rt<<1|1].lSmax);
	tree[rt].minn = min(min(tree[rt<<1].minn,tree[rt<<1|1].minn),tree[rt<<1].rSmin+tree[rt<<1|1].lSmin);
}
void build(int L,int R,int rt){
	tree[rt].lson = L;
	tree[rt].rson = R;
	tree[rt].sum = 0;
	if(L==R){
		scanf("%d",&num[L]);
		tree[rt].lSmin = tree[rt].rSmin = tree[rt].lSmax = tree[rt].rSmax = tree[rt].sum = tree[rt].minn = tree[rt].maxx = num[L];
		return;
	} 
	int mid = tree[rt].mid();
	build(L,mid,rt<<1);
	build(mid+1,R,rt<<1|1); 
	pushUp(rt);
}
void update(int pos,int l,int r,int rt,int x){
	if(l==r){
		tree[rt].minn = tree[rt].maxx = tree[rt].lSmin = tree[rt].rSmin = tree[rt].lSmax = tree[rt].rSmax = tree[rt].sum = x;
		return;
	}
	int mid = tree[rt].mid();
	if(pos <= mid){
		update(pos,l,mid,rt<<1,x);
	}else{
		update(pos,mid+1,r,rt<<1|1,x);
	}
	pushUp(rt);
}

int main(){
	int m;
	while(~scanf("%d",&n)){
		build(1,n,1);
		scanf("%d",&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			update(a,1,n,1,b);
			if(tree[1].sum == tree[1].maxx){
				printf("%d\n",tree[1].sum-tree[1].minn);
			}else{
				printf("%d\n",max(tree[1].sum-tree[1].minn,tree[1].maxx)); 
			}	
		} 
	}
	
	return 0;
}