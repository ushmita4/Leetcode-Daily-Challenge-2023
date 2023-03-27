class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int a,b;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0)
                continue;
                else{
                    if(i-1>=0)
                    a=grid[i-1][j];
                    else
                    a=INT_MAX;

                    if(j-1>=0)
                    b=grid[i][j-1];
                    else
                    b=INT_MAX;


                    grid[i][j]+=min(a,b);
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
