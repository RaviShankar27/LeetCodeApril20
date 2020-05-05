class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pr_queue(stones.begin(), stones.end());
        while(!pr_queue.empty()) {
            if (pr_queue.size() == 1) {
                int val = pr_queue.top();
                return val;
            }
            int heavy_1 = pr_queue.top(); 
            pr_queue.pop();
            int heavy_2 = pr_queue.top();
            pr_queue.pop();
            if (heavy_1 != heavy_2) {
                pr_queue.push(abs(heavy_1-heavy_2));
            }
        }
        return 0;
    }
};