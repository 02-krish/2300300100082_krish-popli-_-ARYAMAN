class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0,l=0,zero=0 ,maxx=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0) zero++;
            while(zero>k){
                if(nums[l]==0)zero--;
                l++;
            }
            if(zero<=k){
                len=r-l+1;
                maxx=max(maxx,len);
            } r++;
        }
        return maxx;
    }
};