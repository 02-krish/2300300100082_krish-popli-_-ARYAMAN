class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        fnc(0,0,n,"" ,res);
        return res;
    }


    void fnc(int open,int close,int n,string temp,vector<string>& res){
        if(open==n&&close==n){
            res.push_back(temp);
            return;
        }
        // open 
        if(open<n){
            temp.push_back('(');
            fnc(open+1,close,n,temp,res);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            fnc(open,close+1,n,temp,res);
            temp.pop_back();
        }

    }
};