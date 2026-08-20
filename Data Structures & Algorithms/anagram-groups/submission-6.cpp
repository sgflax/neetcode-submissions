class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> resmap;
        for(int s = 0; s < strs.size(); ++s){//for each string
            vector<int> count(26, 0);
            for(char c : strs[s]){//for each char in each string
                count[c - 'a']++;//that char's index now has ++ value
            }

            //then, make key to map the strings to it
            string key = "";
            for(int i = 0; i < 26; ++i){
                key += ';' + to_string(count[i]);
            }
            resmap[key].push_back(strs[s]);
        }
        //then put all of the vectors in the map in the result vec
        vector<vector<string>> result;
        for(const auto& pair : resmap){
            result.push_back(pair.second);
        }
        return result;
    }
};
