class Solution {
public:
long long sum=0;
    void dfs(vector<vector<int>>& grid, int r, int c) {
        
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()||grid[r][c]==0)
            return ;

        
      sum+=grid[r][c];
      grid[r][c]=0;
      dfs(grid, r, c + 1);
      dfs(grid, r + 1, c);
      dfs(grid, r, c - 1);
      dfs(grid, r - 1, c);
    }

     int countIslands(vector<vector<int>>& grid, int k) {
        
        int count= 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] >0) {
                    sum=0;
                    dfs(grid,i,j);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }

   
};