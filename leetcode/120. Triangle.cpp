class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        int dp1[m],dp2[m];
        dp1[0] = dp2[0]= triangle[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp1[j] = dp2[j];
                dp2[j] = 0;
            }
            dp2[0] = dp1[0]+triangle[i][0];
            dp2[triangle[i].size()-1] = dp1[triangle[i-1].size()-1]+triangle[i][triangle[i].size()-1];

            for(int j = 1; j < triangle[i].size()-1; j++) {
                dp2[j] = min(dp1[j-1],dp1[j])+triangle[i][j];
            }
        }
        int ret = 1e9;
        for(int i = 0; i < m; i++) {
            ret = min(dp2[i],ret);
        }
        return ret;
    }
};
