class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxcur = nums[0];
        int bestmax = nums[0];
        int mincur = nums[0];
        int bestmin = nums[0];
        for (int i = 1; i < nums.size(); i++){
            maxcur = max(nums[i], maxcur + nums[i]);
            mincur = min(nums[i], mincur + nums[i]);
            bestmax = max(bestmax, maxcur);
            bestmin = min(bestmin, mincur);
        }
        int res = max(bestmax, -bestmin);
        return res;
    }
};