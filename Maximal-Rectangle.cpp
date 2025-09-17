class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n,0);
        int maxarea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            maxarea = max(maxarea, largestRectangleArea(heights));
        }
        return maxarea;
    }
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