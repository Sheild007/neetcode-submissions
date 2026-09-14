class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sub_len=0;
        int l=0;
        unordered_map<char,int> freq;
        for(int r=0;r<s.size();r++){
            freq[s[r]]++;
            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            
            }
            sub_len=max(sub_len,r-l+1);

        }
        return sub_len;
    }
};
