class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.size() - needle.size();
        for(int i =0; i<=len; i++){
            int x = i;
            int j=0;
            int cnt = 0;
            while(j< needle.size()){
                if(haystack[x] == needle[j]){
                    x++;
                    j++;
                    cnt++;
                    if(cnt == needle.size()){
                        return i;
                    }
                }else{
                    break;
                }
            }
        }
        return -1;
    }
};