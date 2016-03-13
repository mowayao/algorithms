class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 1,r = nums.size()-1;
        if(target<=nums[0]) return 0;
        if(target>nums.back()) return nums.size();
        while(l <= r) {
            int mid = (l+r)>>1;
            if(target > nums[mid]) {
                l = mid+1;
            }else{
                r = mid-1;
            }

        }
        return l;

    }
};
