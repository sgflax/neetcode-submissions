class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int i = 0; i < piles.size(); i++){
            r = max(r, piles[i]);
        }
        int res = r;

        while(l <= r){
            int k = (l + r) / 2;
            long long totalTime = 0;
            for(int pile : piles){
                totalTime += (ceil(static_cast<double>(pile) / k));
            }
            if(totalTime <= h){
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
