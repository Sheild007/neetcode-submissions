class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        
        map<vector<int>,vector<string>> emb;
        int n=strs.size();
        // genrating embeding of all strings
        for (int i=0;i<n;i++){
            vector<int> freq(256,0);
            string str=strs[i];
            for(int j=0;j<str.size();j++){
                freq[str[j]-'a']++;
            }
            emb[freq].push_back(str);
        }
        
       vector<vector<string>> ans;

           for (auto& pair : emb) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
