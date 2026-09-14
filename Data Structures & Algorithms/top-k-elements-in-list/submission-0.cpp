class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        map<int, vector<int>> rev;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& [num, count] : freq) {
            rev[count].push_back(num);
        }

        vector<int> res;

        for (auto it = rev.rbegin(); it != rev.rend() && res.size() < k; ++it) {

            for (int num : it->second) {
                res.push_back(num);

                if (res.size() == k)
                    break;
            }
        }

        return res;
    }
};