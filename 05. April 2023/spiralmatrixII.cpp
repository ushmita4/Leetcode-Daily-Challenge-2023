class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n,-1));
        
        int rounds = ceil(n / 2);
        int lc = 0;
        int rc = n-1;
        
        int tr = 0;
        int br = n-1;
        
        int k=1;
        int curr = 0;
  
        while(curr <= rounds) {
            
            // top row
            for(int i=lc; i<=rc; i++){
                matrix[tr][i] = k;
                k++;
            }
            
            
            tr++;
            if(tr > br || lc > rc) break;
            
            // right column
            for(int i=tr; i<=br; i++){
                matrix[i][rc] = k;
                k++;
            }
            
            rc--;
            if(tr > br || lc > rc) break;
            
            // bottom row
            for(int i=rc; i>=lc; i--){
                matrix[br][i] = k;
                k++;
            }
            
            br--;
            if(tr > br || lc > rc) break;
            
            // left column
            for(int i=br; i>=tr; i--){
                matrix[i][lc]=k;
                k++;
            }
            
            lc++;
            if(tr > br || lc > rc) break;
            
            curr++;
        }
        
        return matrix;
        
    }
};
