class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>nset(nums.begin(),nums.end());
        int longest = 0;
        for(int n : nset)
        {
            int k = n;
            if(nset.find(k-1)==nset.end())
            {
                int length = 1;
                while(nset.find(k+length)!=nset.end())
                {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
