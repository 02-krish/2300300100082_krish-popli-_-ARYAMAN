class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0;
        int prefix=0;
        for(int i =0;i<nums.size();i++){
            sum=sum+nums[i];

        }
        for (int i=0;i<nums.size();i++){
            int suffix =sum-prefix-nums[i];
            if(suffix==prefix){
                return i;
            }
            prefix=prefix+nums[i];
        }
        return -1;
    }
};