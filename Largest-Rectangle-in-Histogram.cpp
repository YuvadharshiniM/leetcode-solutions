class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n= heights.size();
        stack<int> s;
        vector<int> lfs(n);
        vector<int> rfs(n,n-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();

            if(s.empty()) lfs[i] = 0;
            else lfs[i] = s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(!s.empty()) rfs[i] = s.top()-1;
            s.push(i);

        }
        for(int i=0;i<n;i++){
            res = max(res,heights[i]*(rfs[i]-lfs[i]+1));
        }
        return res;
    }
};