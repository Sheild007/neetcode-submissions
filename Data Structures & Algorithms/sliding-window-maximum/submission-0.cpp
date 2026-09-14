class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;

        for (int r = 0; r < nums.size(); r++) {
            pq.push({nums[r], r});
            if (r >= k - 1) {
                while (pq.top().second < r - k + 1) {
                    pq.pop();
                }
                result.push_back(pq.top().first);
            }
        }

        return result;
    }
};