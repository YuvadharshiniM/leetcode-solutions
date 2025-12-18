class Solution {
public:
void dfs(vector<vector<char>>& grid,int r,int c)
{
    if(r<0 || c<0 || r>=grid.size() || c>= grid[0].size()) return;
    if(grid[r][c]=='X')
    {
        grid[r][c]='.';
        dfs(grid,r,c+1);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);
        dfs(grid,r-1,c);
    }
}
    int countBattleships(vector<vector<char>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='X')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    };
