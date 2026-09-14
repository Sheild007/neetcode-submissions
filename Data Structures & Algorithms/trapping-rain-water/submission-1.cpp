class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
       
        int l=0 , l_max=INT_MIN;
        int r=n-1,r_max=INT_MIN;
        int sum=0;
        
        while(l<r){
            if(height[l]<=height[r]){
                if(l_max<height[l]) l_max=height[l];
                else sum+=l_max-height[l];
                l++;

            }
            else{
                if(r_max<height[r]) r_max=height[r];
                else sum+=r_max-height[r];
                r--;

            }
        }
       
        return sum;
    }
};
