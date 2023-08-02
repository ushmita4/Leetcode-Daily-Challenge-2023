class Solution {
public:
   void backtrack(int n,vector<int>& nums,vector<vector<int>>& arr,int start){
       if(start==n-1){
           arr.push_back(nums);
           return;
       }
       for(int i=start;i<n;i++){
            swap(nums[start],nums[i]);
            backtrack(n,nums,arr,start+1);
            swap(nums[start],nums[i]);
       }

   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> arr;
        int n=nums.size();
        backtrack(n,nums,arr,0);
        return arr;
    }
};
