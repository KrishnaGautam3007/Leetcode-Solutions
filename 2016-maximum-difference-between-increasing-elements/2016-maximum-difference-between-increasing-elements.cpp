class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minm=nums[0];
        int maxdiff=0;
        for(int i=1;i<nums.size();i++){
            maxdiff=max(maxdiff,nums[i]-minm);
            minm=min(minm,nums[i]);
        }
        if(maxdiff==0){
            return -1;
        }
        return maxdiff;
    }
};