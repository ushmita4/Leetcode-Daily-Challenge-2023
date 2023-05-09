class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int r_start=0;
        int r_end=matrix.size()-1;
        int col_start=0;
        int col_end=matrix[0].size()-1;

        vector<int> ans;

        while(r_start<=r_end && col_start<=col_end)
        {
            for(int i=col_start;i<=col_end;i++)
            {
                ans.push_back(matrix[r_start][i]);
            }
            r_start++;
            for(int i=r_start;i<=r_end;i++)
            {
                ans.push_back(matrix[i][col_end]);
            }
            col_end--;
            for(int i=col_end;i>=col_start && r_start<=r_end ;i--)
            {
                ans.push_back(matrix[r_end][i]);
            }
            r_end--;
            for(int i=r_end;i>=r_start && col_start<=col_end;i--)
            {
                ans.push_back(matrix[i][col_start]);
            }
            col_start++;
        }
        return ans;
        
    }
};
