class Solution {
public:
    void reverseString(vector<char>& s) {
         int string = 0;
        int length = s.size()-1;
        
        while(string <length){
            swap(s[string++],s[length--]);
        }
        
    }
};
// int l=0,r=s.size()-1;
//         while(l<r)
//             swap(s[l++],s[r--]);