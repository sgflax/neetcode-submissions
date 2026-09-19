class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk; //{temp, idx}
        
        for(int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while(!stk.empty() && t > stk.top().first){
                pair<int, int> top = stk.top();
                stk.pop();

                res[top.second] = i - top.second;
            }
            stk.push({t, i});
        }
        return res;
    }
};
