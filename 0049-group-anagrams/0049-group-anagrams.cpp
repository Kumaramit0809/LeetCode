class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const auto& s : strs) {
            string newString = s;                
            sort(newString.begin(), newString.end()); 
            map[newString].push_back(s);         
        }

        vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);      
        }

        return result;
    }
};