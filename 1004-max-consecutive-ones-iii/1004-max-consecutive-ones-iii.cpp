class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0,l=0,r=0;
        int zero=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }
            if(zero>k){
                r++;
                l++;
                if(nums[l-1]==0){
                    zero--;
                }
            }
            else{
                count=max(count,r-l+1);
                r++;
            }
        }
        return count;
    }
};