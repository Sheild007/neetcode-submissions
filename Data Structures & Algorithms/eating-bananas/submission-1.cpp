class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1;
        long long right = 1;

        for (long long d : piles)
            right = max(right, d);

        long long ans = right;

        while (left <= right) {
            long long k = left + (right - left) / 2;

            long long hours = 0;

            for (long long d : piles) {
                hours += ceil((double)d / k);
            }

            if (hours <= h) {
                ans = k;
                right = k - 1;
            }
            else {
                left = k + 1;
            }
        }

        return ans;
    }
};
