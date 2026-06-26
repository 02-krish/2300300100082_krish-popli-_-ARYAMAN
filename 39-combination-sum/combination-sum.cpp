class Solution {
public:
void fnc(vector<int>&a,int n,int idx,vector<int>&dairy,int sum,vector<vector<int>>& res,int target)
 {
if(idx==n){
    if(sum==target)
    res.push_back(dairy);
    return;
}
fnc(a,n,idx+1,dairy,sum,res,target);
if(a[idx]+sum<=target){
    dairy.push_back(a[idx]);
    sum=sum+a[idx];
    fnc(a,n,idx,dairy,sum,res,target);
    dairy.pop_back();
    sum=sum-a[idx];}
    return;
}


 


    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n=a.size();
        vector<int> dairy;
            vector<vector<int>>  res;
            int sum =0;
            fnc(a,n,0, dairy,sum , res,target)  ; 
            return res;    
           }
};