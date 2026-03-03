class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        
        for(int r = 0; r < nums.size(); r++) {
            
            if(nums[r] == 0) k--;   // treat k as zero budget
            
            if(k < 0) {
                if(nums[l] == 0) k++;
                l++;
            }
        }

        return nums.size() - l;
    }
};