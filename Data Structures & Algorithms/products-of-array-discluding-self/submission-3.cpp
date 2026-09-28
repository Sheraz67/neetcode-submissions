class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int k = nums.size();
        vector<int>prefix(k);
        vector<int>suffix(k);
        prefix[0]=1;
        suffix[k-1]=1;
        for(int i = 1; i <k; i++)
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i = k-2 ; i >= 0;i--)
        {
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        vector<int>res(k);
        for(int i = 0; i <k;i++)
        {
            res[i] = prefix[i]*suffix[i];
        }
        return res;
    }
};
