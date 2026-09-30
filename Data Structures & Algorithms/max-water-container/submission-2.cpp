class Solution {
public:
    int maxArea(vector<int>& heights) {
        int longest = 0;
        int i = 0;
        int j = heights.size()-1;
        while(i < j)
        {
            int width = j - i;
            int height = min(heights[i],heights[j]);
            int target = width*height;
            longest = max(longest,target);
            if(heights[i] <= heights[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return longest;
    }
    
};
