class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> ans(k);

        auto cmp = [](const vector<int>& x, const vector<int>& y){
            return (x[0]*x[0] + x[1]*x[1]) < (y[0]*y[0] + y[1]*y[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        for(auto& point : points){
            maxHeap.push(point);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        for(int i=k-1; i>=0; --i){
            ans[i] = maxHeap.top();
            maxHeap.pop();
        }

        return ans;
    }
};
