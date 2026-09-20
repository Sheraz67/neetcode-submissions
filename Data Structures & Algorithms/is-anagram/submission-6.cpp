class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>seen,seenT;
        if(s.length()!=t.length())
        {
            return false;
        }
        for(int i =0;i<s.size(); i++)
        {
            seen[s[i]]++; 
            seenT[t[i]]++;
        }
        return seenT==seen;
    }
};
