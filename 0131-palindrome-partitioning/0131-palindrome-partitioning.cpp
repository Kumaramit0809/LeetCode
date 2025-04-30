class Solution {
    bool isPalindrome(string& s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void count_pal(int ind, string& s, vector<string>& temp, vector<vector<string>>& ans){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i-ind+1));
                count_pal(i+1, s, temp, ans);
                temp.pop_back();

            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        count_pal(0, s, temp, ans);
        return ans;

        
    }
};