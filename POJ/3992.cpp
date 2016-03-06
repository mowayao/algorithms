#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a,long long b){
	return b == 0 ? a : gcd(b,a%b);
}
int main(){

    long long a,b;
    while(~scanf("%lld%lld",&a,&b) && a+b){
        long long lcm = a*b/gcd(a,b);
        cout<<lcm/a*lcm/b<<endl;

    }
    return 0;
}
