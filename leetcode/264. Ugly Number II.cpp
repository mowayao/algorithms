class Solution {
public:
    int nthUglyNumber(int n) {

        int cnt2=0,cnt3=0,cnt5 = 0;
        int ugly[n+10]={0};
        ugly[0] = 1;
        for(int i = 1; i < n; i++) {
            int m = min(min(ugly[cnt2]*2,ugly[cnt3]*3),ugly[cnt5]*5);
            if(m==ugly[cnt2]*2) {
                cnt2++;
            }
            if(m==ugly[cnt3]*3){
                cnt3++;
            }
            if(m==ugly[cnt5]*5){
                cnt5++;
            }
            ugly[i] = m;
        }
        return ugly[n-1];
    }
};
