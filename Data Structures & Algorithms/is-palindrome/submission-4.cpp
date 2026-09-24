class Solution {
public:
    bool isPalindrome(string s) {
        string cat;
        int j = 0;
        for(int i = 0; i<s.size();i++)
        {
            if(isalnum(s[i]))
            {
                cat.push_back(tolower(s[i]));
                j++;
            }
        }
        int k = cat.size()-1;

        for(int i = 0; i < k;i++)
        {
            if(cat[i]!=cat[k])
            {
                return false;
            }
            k--;
        }
        return true;
    }
};
