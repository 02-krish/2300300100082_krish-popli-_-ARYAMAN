class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
         for(int i=0;i<=n;i++){
            int check=0;
            for(int j=0;j<n;j++ ){
                if(i==nums[j]){
                    check++;
                }

            }
            if(check==0){
              return i;
                        }

         }
return -1;
    }
};