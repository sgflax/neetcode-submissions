class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> stk;

        for(int i = 0; i <=n; i++){
            while(!stk.empty() && (i == n || heights[i] <= heights[stk.top()])){
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;

                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }
        return maxArea;
    }
};
