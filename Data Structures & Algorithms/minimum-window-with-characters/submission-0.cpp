class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t) return s;
        if (t.size() > s.size()) return "";

        unordered_map<char,int> freq_t;
        for (char c : t) freq_t[c]++;
        unordered_map<char,int> freq_window;

        int l = 0;
        int have = 0;
        int need = freq_t.size();

        int minLen = INT_MAX;
        int minL = 0;

        for (int r = 0; r < s.size(); r++) {
            freq_window[s[r]]++;
            if(freq_t.contains(s[r]) && freq_t[s[r]]==freq_window[s[r]])
                have++;

            while (have == need) {

                if(r-l+1<minLen){
                    minLen=r-l+1;
                    minL=l;
                }

                freq_window[s[l]]--;

                if (freq_t.contains(s[l]) && freq_window[s[l]] < freq_t[s[l]]) 
                    have--;
                

                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(minL, minLen);
    }
    
};