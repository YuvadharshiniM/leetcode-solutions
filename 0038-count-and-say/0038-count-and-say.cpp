class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i=1;i<n;i++){
            string s = "";
            int count = 1;
            for(int j=1;j<str.length();j++){
                if(str[j]==str[j-1]) count++;
                else{
                    s += to_string(count)+str[j-1];
                    count = 1;
                }
            }
            s += to_string(count)+str.back();
            str = s;
        }
        return str;
    }
};