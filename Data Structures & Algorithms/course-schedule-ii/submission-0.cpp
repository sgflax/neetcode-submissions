class Solution {
public:
    
    unordered_map<int, vector<int>> premap;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(const auto& p : prerequisites){
            premap[p[0]].push_back(p[1]);
        }

        unordered_set<int> visited;
        unordered_set<int> cycle;
        vector<int> res;

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i, visited, premap, cycle, res)){
                return {};
            }
        }
        return res;

    }

    bool dfs(int course, unordered_set<int>& visited, unordered_map<int, vector<int>>& premap,
            unordered_set<int>& cycle, vector<int>& res){
        if(cycle.contains(course)){
            return false;
        }

        if(visited.contains(course)){
            return true;
        }
        //active path
        cycle.insert(course);

        if(premap.count(course)){
            for(int pre : premap[course]){
                if(!dfs(pre, visited, premap, cycle, res)){
                    return false;
                }
            }
        }

        visited.insert(course);
        cycle.erase(course);
        res.push_back(course);
        return true;

    }
};
