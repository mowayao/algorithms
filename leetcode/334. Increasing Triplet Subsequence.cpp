class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int ret[3]={1e9},cur = 0;
        for(int i = 0; i < n; i++) {
            if(cur==0 || ret[cur-1] < nums[i]) {

                ret[cur] = nums[i];

                cur++;
                if(cur==3) return true;
            }else
                for(int j = 0; j <= cur; j++) {
                    if(ret[j] >= nums[i]) {
                        ret[j] = nums[i];
                        break;
                    }
                }


        }
        return false;
    }
};
