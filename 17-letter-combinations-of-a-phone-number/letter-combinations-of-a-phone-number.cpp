 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> uo;
      
uo['2'] = "abc";
uo['3'] = "def";
uo['4'] = "ghi";
uo['5'] = "jkl";
uo['6'] = "mno";
uo['7'] = "pqrs";
uo['8'] = "tuv";
uo['9'] = "wxyz";
        string op="";
        vector<string> res;
        sol(res, op, uo, digits, 0);
        return res;
    }
    void sol(vector<string>& res, string& op, unordered_map<char, string> uo, string digits, int i){
        if (i == digits.size()){
            res.push_back(op);
            return;
        }
        for (char c : uo[digits[i]]) {
            op.push_back(c);
            sol(res, op, uo, digits, i + 1);
            op.pop_back(); // backtracking
        }
    }
};