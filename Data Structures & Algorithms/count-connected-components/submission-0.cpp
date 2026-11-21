class Solution {
public:
    void solve(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;

        for(auto it:adj[node]){
            if(!vis[it]){
                solve(it,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,vis,adj);
                cnt++;
            }
        }

        return cnt;
    }
};
