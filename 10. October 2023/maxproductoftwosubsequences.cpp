class Solution {
private:
    const int INF=1e9;
    vector<vector<int>> dp;
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size();
        dp.resize(len1+1,vector<int>(len2+1,-INF));
        for(int i=1;i<=len1;++i) {
            for(int j=1;j<=len2;++j) {
                dp[i][j]=max({nums1[i-1]*nums2[j-1]+dp[i-1][j-1],
                              dp[i-1][j],
                              dp[i][j-1],
                              nums1[i-1]*nums2[j-1]});
            }
        }
        return dp[len1][len2];
    }
};
