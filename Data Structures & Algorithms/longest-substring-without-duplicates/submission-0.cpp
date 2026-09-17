class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;

        unordered_set<int> mySet;
        int l = 0;
        int res = 0;
        
        for(int r = 0; r < s.size(); ++r){
            while(mySet.find(s[r]) != mySet.end()){
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
