#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef   long long ll;
const int maxn = 50000;
vector<ll> prime;
vector<ll> digit,cnt;
bool isPrime[maxn];

long long multi(long long a,long long b,long long m)//a*b%m
{
    long long ret=0;
    while(b>0)
    {
        if(b&1)ret=(ret+a)%m;
        b>>=1;
        a=(a<<1)%m;
    }
    return ret;
}
long long quick_mod(long long a,long long b,long long m)//a^b%m
{
    long long ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b/=2;
        a=multi(a,a,m);
    }
    return ans;
}
ll pow_mod(ll a,ll b,ll mod){
    ll ret = 1;
    ll tmp = a;
    while(b){
        if(b&1) ret = ret*tmp%mod;
        tmp = tmp*tmp%mod;
        b >>=1;
    }
    return ret;
}
void getPrime(){
    memset(isPrime,1,sizeof isPrime);
    for(ll i = 2; i < maxn; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(ll j = i*i; j < maxn; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

void getDigit(ll x){
    digit.clear();
    cnt.clear();
    for(int i = 0; i < prime.size() && x >= prime[i]; i++){
        if(x%prime[i]==0){
            digit.push_back(prime[i]);
            int t = 0;
            while(x%prime[i]==0){
                x /= prime[i];
                t++;
            }
            cnt.push_back(t);
        }
    }
    if(x > 1){
        digit.push_back(x);
        cnt.push_back(1);
    }

}
ll euler_phi(ll n){
    int m = sqrt(n+0.5);
    ll ans = n;
    for(int i = 2; i <= m; i++){
        if(n%i==0){
            ans = ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n > 1) ans = ans / n *(n-1);

    return ans;
}

ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}


ll L,ans;
int main(){
    int T = 1;
    getPrime();
    while(cin >> L && L){
        ll MOD = L/gcd(8,L)*9;
        if(gcd(MOD,10)!=1){
            printf("Case %d: 0\n",T++);
        }else{
            ll k = euler_phi(MOD);
            getDigit(k);

            for(int i = 0; i < digit.size(); i++){
                for(int j = 0; j < cnt[i]; j++){
                    //cout<<k/digit[i]<<endl;
                    //cout<<pow_mod(10,k/digit[i],MOD)<<endl;
                    if(quick_mod(10,k/digit[i],MOD)==1) k /= digit[i];
                }
            }
            printf("Case %d: ",T++);
            cout<<k<<endl;
        }



    }
    return 0;
}
