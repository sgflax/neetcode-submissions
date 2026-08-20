class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;//interger to its index
        for(int i = 0; i < nums.size(); ++i){
            int diff = target - nums[i];
            if(mymap.find(diff) != mymap.end()){//if the diff is in map
                return {mymap[diff], i};
            }
            mymap.insert({nums[i], i});
        }
        return {};
    }
};
