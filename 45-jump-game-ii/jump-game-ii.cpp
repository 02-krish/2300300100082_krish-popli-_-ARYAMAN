class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
int maxReach = 0;
int r = 0;
int l=0;
int n=nums.size();
while(r<n-1){
    for(int i=l;i<=r;i++){
        maxReach=max(maxReach,nums[i]+i);
    }
    l=r+1;
    r=maxReach;
    jumps++;
}
return jumps;


    }

};