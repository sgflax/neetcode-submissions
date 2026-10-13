class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if(stone1==stone2){
                continue;
            } else if(stone1 < stone2){
                stone2-=stone1;
                pq.push(stone2);
            } else {
                stone1-=stone2;
                pq.push(stone1);
            }
        }

        if(!pq.empty()){
            return pq.top();
        } else {
            return 0;
        }
    }
};
