class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double average;
        int sum = 0;
        int maxi = INT_MIN;

        
        if (n >= k) {
              
            for (int i = 0; i < k; i++) {
                sum += nums[i];
            }

            maxi = sum;   

             
            for (int i = k; i < n  ; i++) {
                sum = sum - nums[i-k] + nums[i];
                maxi = max(maxi, sum);
            }

         
            average = (double) (maxi) / k;
            return average;
        }

        
        else {
             
            for (int i = 0; i < n; i++) {
                sum += nums[i];
            }

 
            average = (double) (sum) / n;
            return average;
        }
    }
};