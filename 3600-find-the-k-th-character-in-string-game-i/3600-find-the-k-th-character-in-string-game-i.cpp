class Solution {
public:
    char kthCharacter(int k) {
        string s1 = "a"; 
        while(s1.length() < k){
            string s2 = "";
            for(char c : s1){
                s2 += (c - 'a' + 1) % 26 + 'a';
            }
            s1 += s2;
        }
        return s1[k - 1];
    }
};