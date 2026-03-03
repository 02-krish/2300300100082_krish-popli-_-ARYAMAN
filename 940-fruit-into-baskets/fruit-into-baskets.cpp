class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0,maxx=0,len=0,end=0;
        unordered_map<int,int> bucket;
        for(end=0;end<fruits.size();end++){
            bucket[fruits[end]]++;
           while(bucket.size()>2){
            bucket[fruits[start]]--;
            if( bucket[fruits[start]]==0){
                 bucket.erase(fruits[start]);
            }
            start++;
           }
           maxx=max(maxx,end-start+1);
            
           


        }
    return maxx;
     }
};