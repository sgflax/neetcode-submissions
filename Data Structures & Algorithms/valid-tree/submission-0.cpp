class Solution {
public:
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n - 1 < edges.size()){
            return false;
        }

        vector<vector<int>> adj(n);

        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        if(!dfs(0, -1, visited, adj)){
            return false;
        }

        return visited.size() == n;
    }

    bool dfs(int node, int parent, unordered_set<int>& visited, vector<vector<int>>& adj){
        if(visited.contains(node)){
            //cycle
            return false;
        }

        visited.insert(node);
        //dfs on every connection
        for(int neighbor : adj[node]){
            if(neighbor == parent){
                continue;
            }

            if(!dfs(neighbor, node, visited, adj)){
                return false;
            }
        }
        return true;
    }
};
