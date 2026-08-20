class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); ++i){
            res += to_string(strs[i].size()) + '#' + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0; //pointer to iterate thru each char in s
        while(i < s.size()){
            int j = i; //j finds #
            while(s[j] != '#'){
                j++;//now j is stopped at the # sign
            }
            //so everyhting behind j is the length of teh string
            int length = stoi(s.substr(i, j - i));
            //s.substr starts at idx i and takes j - i characters forwad

            res.push_back(s.substr(j+1, length));
            i = j + length + 1;
        }
        return res;
    }
};
