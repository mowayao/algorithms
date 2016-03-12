
class Solution {
public:
    int numSquares(int n) {
        int dp[n+10];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = 1e9;
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i-j*j]+1,dp[i]);
            }
        }
        return dp[n];

    }
};
