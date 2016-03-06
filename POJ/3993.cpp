#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=1000000;
vector <int> prime;
bool isprime[maxn+10];
int a,b,ans;
map<int,int> pa,pb;
set<int> pp;

void ini(){
for(int i=0;i<=maxn;i++) isprime[i]=true;
isprime[0]=false;isprime[1]=false;
for(int i=4;i<=maxn;i+=2) isprime[i]=false;
for(int i=3;i<=maxn;i+=2){
for(int j=i;j<=maxn/i;j+=2){
isprime[i*j]=false;
}
}
for(int i=2;i<=maxn;i++){
if(isprime[i]) prime.push_back(i);
}
//for(int i=0;i<=100;i++) cout<<prime[i]<<endl;
//cout<<prime.size()<<endl;
}
void init(){
    pa.clear();
    pb.clear();
    pp.clear();
    ans = 0;
}
void prime_fj(int x,map<int,int> &xshu){
    int i;
    for(i = 0; i < prime.size() && x!=1; i++){
        if(x%prime[i] ==0) pp.insert(prime[i]);
        while(x%prime[i]==0){
            xshu[prime[i]]++;
            x/=prime[i];
        }
        if(isprime[x])
            break;
    }
    if(x!=1){
        xshu[x]++;
        pp.insert(x);
    }
}
int main(){
    int cas = 1;
    ini();
     while(~scanf("%d%d",&a,&b)&&a+b){
        init();
        prime_fj(a,pa);
        prime_fj(b,pb);
        set<int>::iterator it;
        for(it = pp.begin(); it != pp.end(); it++)   ans += abs(pa[*it]-pb[*it]);
        printf("%d. %d:%d\n",cas++,pp.size(),ans);

     }
     return 0;

}

