class Solution {
public:
    string reorganizeString(string s) {
       
        string res="";
      unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
      priority_queue<pair<int,char>> pq;
      for(pair<int,int> i :mp){
        
            char element = i.first;
            int freq = i.second;
            pq.push({freq,element});

      }
  int i=0;
      while(!pq.empty()){
       pair<int,char> p = pq.top();
pq.pop();
        if(i==0||res[i-1]!=p.second){
            res.push_back(p.second);
            i++;
            p.first--;
            if(p.first>0) pq.push(p);
        }
        else{
            if(pq.empty()) return "";
            pair<int,char> p1=pq.top();
            pq.pop();
            res.push_back(p1.second);
            i++;
            p1.first--;
           if(p1.first>0) pq.push(p1);
           if(p.first>0) pq.push(p);
        }



      }
      return res;

    }
};