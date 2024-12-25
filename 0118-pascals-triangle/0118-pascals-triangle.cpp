class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i =1;i<=numRows;i++){
             long long ans = 1;
            vector<int>row;
            row.push_back(1);
           
            
            for(int  col = 1;col<i; col++){
                
                ans = ans*(i-col)/(col);
                row.push_back(ans);
             
            }
            
            result.push_back(row);
        }
        return result;
    }
};