class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, minlen = INT_MAX, sum=0;
        for(int r=0;r<nums.size();r++){
            sum =sum + nums[r];
            while(sum>=target){
                minlen = min(minlen,r-l+1);
                sum =sum - nums[l];
                l++;
            }
        }
        return minlen==INT_MAX ? 0 : minlen;
    }
};