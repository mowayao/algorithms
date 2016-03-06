class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n+10];
        memset(isPrime,true,sizeof isPrime);
        int ret = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                ret++;
                for(int j = i+i; j <= n; j+=i) isPrime[j] = false;
            }
        }
        return ret;
    }
};
