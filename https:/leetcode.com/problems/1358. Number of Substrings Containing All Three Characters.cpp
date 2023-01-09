class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int i=0, j=0, ans=0;
        
        while(j != n)
        {
            mp[s[j]]++;
            while(mp['a'] && mp['b'] && mp['c'])
            {
                ans += n-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};