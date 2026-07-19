class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(rooms,0,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;

        }
        return true;
            }

    void dfs(vector<vector<int>>& rooms,int node,vector<int>&vis){
        vis[node]=1;
        int m=rooms[node].size();
        for(int j=0;j<m;j++){
            int neigh=rooms[node][j];
            if(vis[neigh]==0){
                dfs(rooms,neigh,vis);
            }
        }
        return;





    }
};