class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1;
        int maxArea = 0;
        
        while (p1 < p2) {
            int H = min(height[p1], height[p2]);
            int L = p2 - p1;
            int current = H * L;
            maxArea = max(current, maxArea);
            
            if (height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
        }
        return maxArea;
    }
};