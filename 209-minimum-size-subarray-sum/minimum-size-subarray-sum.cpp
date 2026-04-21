class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
       int l=0;
       int r=0;
       int sum=0;
       int length=  INT_MAX;
       int n =arr.size();
       while(r<n){
        sum =sum+arr[r];
        while(sum>=k){
            length=min(length,r-l+1);
            sum=sum-arr[l];
            l++;
        }
        r++;


       }
return length==INT_MAX?0:length;
    }
};