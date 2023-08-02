class Solution {
private:
     void backtracking(int n,int k,vector<vector<int>>& result,vector<int>& combination,int start){
         if(combination.size()==k){
         result.push_back(combination);
         return;
         }
         for(int i=start;i<=n;i++)
         {
            combination.push_back(i);
            backtracking(n,k,result,combination,i+1);
            combination.pop_back();
         }
     }
     public:
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>> result;
     vector<int> combination;
     backtracking(n,k,result,combination,1);   
     return result;
    }
};
