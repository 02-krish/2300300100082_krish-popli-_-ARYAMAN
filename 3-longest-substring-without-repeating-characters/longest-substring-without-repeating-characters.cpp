class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mp;
       int n=s.size();
       int maxi=0;
       int len=0;
       int i=0;int j=0;
       while(j<n) {
        char c=s[j];
        
         mp[c]++;
         

          if(mp[c]==2){
            while(mp[c]==2){
                mp[s[i]]--;
                i++;
            }
          }
    len=j-i+1;
    maxi=max(len,maxi);





j++;
       }
       return maxi;
    }
};