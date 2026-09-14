class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int len=0;
        int max_freq=0;
        unordered_map<char,int>freq;
        for(int r=0;r<n;r++){
            char c =s[r];
            max_freq=max(max_freq,++freq[c]);
            while((r-l+1)-max_freq>k){
                freq[s[l]]--;
                l++;
            }
            len=max(len,r-l+1);
            
        }
        return len;
    }
};
