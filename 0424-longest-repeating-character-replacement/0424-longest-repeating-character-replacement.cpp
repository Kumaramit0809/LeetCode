class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxlen=0, maxf=0;
        int arr[26]={0};
        while(r<s.size()){
            arr[s[r]-'A']++;
            maxf=max(maxf,arr[s[r]-'A']);
            if(r-l+1-maxf>k){
                arr[s[l]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++){
                    maxf=max(maxf,arr[s[r]-'A']);
                }
                l++;
            }
         
            maxlen=max(r-l+1,maxlen);
            
            r++;
        }
        return maxlen;
    }
};