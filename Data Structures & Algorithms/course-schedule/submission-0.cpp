class Solution {
public:
//map course to its prereq
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; ++i){
            preMap[i] = {};
        }

        for(const auto& req : prerequisites){
            preMap[req[0]].push_back(req[1]);
        }

        for(int c = 0; c < numCourses; ++c){
            if(!dfs(c)) return false;
        }
        return true;
    }

    bool dfs(int crs){
        if(visiting.count(crs)){
            //cycle
            return false;
        }

        //no prereqs
        if(preMap[crs].empty()) return true;

        visiting.insert(crs);
        for(int c : preMap[crs]){
            if(!dfs(c)) return false;
        }

        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
