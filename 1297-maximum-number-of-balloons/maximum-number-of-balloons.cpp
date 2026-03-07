class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        
        for(char c : text)
            mpp[c]++;

        string s = "balloon";
        int count = 0;

        while(true){
            for(int i = 0; i < s.size(); i++){
                if(mpp[s[i]] == 0)
                    return count;
                mpp[s[i]]--;
            }
            count++;
        }
    }
};