class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n=nums.size();
        
        fnc(res,nums,temp,n,0);
        return res;
    }

void fnc( vector<vector<int>>& res,vector<int>& nums,vector<int>& temp,int n,int index   ){ 
if(index==n){
    res.push_back(temp);
    return;
}
if(index<n){ 
temp.push_back(nums[index]);
fnc(res,nums,temp,n,index+1);
temp.pop_back();
fnc(res,nums,temp,n,index+1);
return;}
return ;
}
};