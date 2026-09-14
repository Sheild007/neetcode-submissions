class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lefts;
        int left_max=INT_MIN;
        for(int i=0;i<n;i++){
            left_max=max(left_max,height[i]);
            lefts.push_back(left_max);
        }

        vector<int> rights;
        int right_max=INT_MIN;
        for(int i=n-1;i>=0;i--){
            right_max=max(right_max,height[i]);
            rights.push_back(right_max);
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(lefts[i],rights[n-1-i])-height[i];
        }
        return sum;
    }
};
