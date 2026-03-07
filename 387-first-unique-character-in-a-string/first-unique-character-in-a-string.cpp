class Solution {
public:
    int firstUniqChar(string s) {
        int r=0;
        int index=-1;
        unordered_map<int,int> mp;
        while(s[r]){
         mp[s[r]]++;

r++;
        }
r=0;
         while(s[r]){
            if(mp[s[r]]==1){
index=r;
break;
            } r++;
         }
         return index;
    }

    
};