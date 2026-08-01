class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0;
        int n=heights.size();

        for(int i=0;i<=n;++i){
            // if i==n add 0 so that we can flush all the heights from stack for calculation
            int curr_h = (i==n) ? 0 : heights[i];

            while(!st.empty() && curr_h < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(h * w, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};
