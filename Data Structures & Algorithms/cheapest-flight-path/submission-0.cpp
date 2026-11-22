class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adj[u].push_back({v,w});
        }

        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;

        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int wt=it.second.second;

            if(stops>k) continue;

            for(auto it:adj[node]){
                int adjn=it.first;
                int adw=it.second;
                int newstops=stops+1;
                int weight=wt+adw;
                if(weight<dist[adjn]){
                    dist[adjn]=wt+adw;
                    q.push({newstops,{adjn,weight}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};
