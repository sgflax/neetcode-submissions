class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        for(int i = 0; i < position.size(); i++){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        vector<double> stk;

        for(auto& p : pairs){
            stk.push_back((double)(target - p.first) / p.second);

            if(stk.size() >= 2 && stk.back() <= stk[stk.size() - 2]){
                //if theres 2+ cars and the car in back is slower than the in front of it
                stk.pop_back();
                //get rid of slow car bc it will never ctach up + be a fleet
            }
        }
        return stk.size();
    }
};
