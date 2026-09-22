class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> window;
        for(int i = 0; i < t.size(); ++i){
            countT[t[i]]++;
        }

        int have = 0;
        int need = countT.size();
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                //if its in the Needed map && we have same amount in window
                have++;
            }

            while(have == need){
                if(r - l + 1 < resLen){//update min res len
                    resLen = r - l + 1;
                    res = {l, r};
                }

                //pop left side of window
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    //if left char is needed and window doesnt have it
                    have--;
                }
                l++;
            }
        }

        if(resLen == INT_MAX){
            return "";
        } else {
            return s.substr(res.first, resLen);
        }
    }
};
