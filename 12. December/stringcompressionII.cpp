class Solution {
public:
    int dp[101][101];
    int helper(int index, string& s, int K){
        if(index+K>=s.length()) return 0;
        int k = K;
        if(dp[index][k]!=-1) return dp[index][k];
        int deleted = k? helper(index+1,s,k-1): 100;
        int j = index+1;
        int count = 1;
        while(j<=s.length()){
            deleted = min(deleted, helper(j, s, k) + 1 + (count>=100?3:count>=10? 2:count > 1? 1:0));
            if(s[j] == s[index]) count++;
            else if(--k<0) break;
            j++;
        }
        
        return dp[index][K]=deleted;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int p = s.length();
        memset(dp, -1, sizeof(dp));
        return helper(0, s, k);
    }
     
};
