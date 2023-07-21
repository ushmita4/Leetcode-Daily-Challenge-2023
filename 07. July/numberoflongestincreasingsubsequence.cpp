class Solution {
public:
    vector<int> dp;
    vector<int> count;

    void LIS_bottom_up(vector<int>& nums, int n){
        dp.assign(n, 1);
        count.assign(n, 1);
        for (int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    if (dp[i]<dp[j]+1) {
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                    else if (dp[i]==dp[j]+1){
                        count[i]+=count[j];   
                    }    
                }      
            }
        } 
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        LIS_bottom_up(nums, n);

        int M=*max_element(dp.begin(), dp.end());
 
        int ans=0;
        for (int i=0; i<n; i++){
   
            if (M==dp[i])
                ans+=count[i];
        }   

        return ans;
    }
};
