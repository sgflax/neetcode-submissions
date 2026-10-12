class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(edges.size()+1, false);

            if(dfs(u, -1, visited, adj)){
                return {u, v};
            }

        }

        return {};
    
    }

    bool dfs(int node, int parent, vector<bool>& visited, vector<vector<int>> &adj){
        if(visited[node]){
            return true;//theres a cycle
        }
        visited[node] = true;
        for(auto& neighbor : adj[node]){
            if(neighbor == parent) continue;

            if(dfs(neighbor, node, visited, adj)){
                return true;
            }
        }
        return false;
    }
};
