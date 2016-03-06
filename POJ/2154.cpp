#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N =40000;
int n,p;
int prime[20000];
bool isprime[N];
int prime_num;

int gcd(int a,int b){
	return b == 0?a:gcd(b,a%b);
}
int phi(int x)//欧拉函数
{
    int num=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            num = (num/i)*(i-1);
            while(x % i == 0)
            {
                x = x / i;
            }
        }
    }
    if(x != 1) num = (num/x)*(x-1);
    return num % p;
}
int pow_mod(int x, int y)
{
    long long i;
    if(y == 0) return 1;
    if(y == 1) return x%p;
    i = pow_mod(x,y/2);
    i = (i*i)%p;
    if(y&1) i=i*x;
    return i % p;
}
int main(){
	
	
	int ncase;
	cin >> ncase;
	//init();
	while(ncase--){
		cin >> n >> p;
		int ans = 0;
		for(int i = 1; i*i <= n; i++){ 
		    if(i*i ==n){
		       ans += (phi(i)*pow_mod(n,n/i-1))%p;
		       ans %= p;
		       break;
		    }
			if(n%i==0){
			   ans += (phi(i)*pow_mod(n,n/i-1))%p;
			   ans += (phi(n/i)*pow_mod(n,i-1))%p;
			   ans %= p;
		    }
		   
		   //cout<<gcd(i,n)<<endl;
		   //cout<<i<<" "<<gcd(i,n)<<" "<<pow_mod(n,gcd(i,n),p)<<endl;
		}
		//ans /= n;
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}