class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) 
            cars.push_back({position[i], speed[i]});
        
        sort(cars.begin(), cars.end());

        stack<double> time_diff;

        for (int i = n - 1; i >= 0; i--) {
            double curr = (double)(target - cars[i].first) / cars[i].second;

            if (time_diff.empty() || curr > time_diff.top()) {
                time_diff.push(curr);
            }
        }

        return time_diff.size();
    }
};