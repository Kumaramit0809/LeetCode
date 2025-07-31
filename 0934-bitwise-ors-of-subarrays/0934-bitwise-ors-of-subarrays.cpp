class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        const int n = arr.size();
        for (int i = 0; i < n; i++){
            const int x = arr[i];
            int next = 0, curr = x;
            result.insert(curr);
            for (int j = i - 1; j >= 0; j--){
                next |= arr[j];
                curr = next | x;
                if (next == curr)
                    break;
                result.insert(curr);
            }
        }
        return result.size();
    }
};