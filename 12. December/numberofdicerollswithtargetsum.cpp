class Solution {
    int mod = 1e9+7;
    int solve(int n, int k, int target, vector<vector<int>> &dp){
        if(n==0 && target==0) return 1;
        if(n<=0 || target<=0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans += solve(n-1, k, target-i, dp);
            ans %= mod;
        }
        return dp[n][target] = ans;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > (n*k)) return 0;
        vector<vector<int>> dp(31, vector<int>(1001, -1));
        return solve(n, k, target, dp);
    }
}
