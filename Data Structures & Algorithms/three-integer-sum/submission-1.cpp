class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> results;

        int prev = INT_MIN;

        for (int i = 0; i < n; i++) {

            int a = nums[i];

            if (a == prev)
                continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {

                int sum = nums[l] + nums[r];

                if (sum < -a)
                    l++;

                else if (sum > -a)
                    r--;

                else {
                    results.push_back({a, nums[l], nums[r]});

                    l++;
                    r--;

                    
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }

            prev = a;
        }

        return results;
    }
};