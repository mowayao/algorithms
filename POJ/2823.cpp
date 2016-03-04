#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1000000+10;
const int INF = 1e16;
struct node{
    long long val;
    int id;
    node(int val=0,int id=0):val(val),id(id){}
};
node nd[maxn],ni[maxn];
vector<long long> ans1,ans2;
int n,k;
long long num[maxn];
int main(){
    nd[0].val = -INF; nd[0].id = 0;
    ni[0].val = INF; ni[0].id = 0;
    while(~scanf("%d%d",&n,&k)){
        int head1 = 1,head2=1,tail1 = 0,tail2=0;
        ans1.clear();
        ans2.clear();
        for(int i = 1; i <= n; i++) scanf("%lld",num+i);
       // for(int i = 1; i <= n; i++) cout<<num[i]<<endl;
        for(int i = 1; i < k; i++){
            while(num[i] > nd[tail1].val && tail1 >= head1) tail1--;
            nd[++tail1] = node(num[i],i);
            while(num[i] < ni[tail2].val && tail2 >= head2) tail2--;
            ni[++tail2] = node(num[i],i);
        }
        for(int i = k; i <= n; i++){
            while(num[i] > nd[tail1].val && tail1 >= head1) tail1--;
            nd[++tail1] = node(num[i],i);
            while(tail1 >= head1 && nd[head1].id <= i-k) head1++;
            while(num[i] < ni[tail2].val && tail2 >= head2) tail2--;
            ni[++tail2] = node(num[i],i);
            while(tail2 >= head2 && ni[head2].id <= i-k) head2++;
            ans2.push_back(ni[head2].val);
            ans1.push_back(nd[head1].val);
        }
        printf("%d",ans2[0]);
        for(int i = 1; i < ans2.size(); i++){
            printf(" %d",ans2[i]);
        }
        printf("\n");
        printf("%d",ans1[0]);
        for(int i = 1; i < ans1.size(); i++){
            printf(" %d",ans1[i]);
        }
        printf("\n");



    }
    return 0;
}
