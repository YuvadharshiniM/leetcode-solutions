class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0, maxlen = 0;
        while(r<s.size()){
            if(!st.count(s[r])){
                st.insert(s[r]);
                maxlen = max(maxlen, r-l+1);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};