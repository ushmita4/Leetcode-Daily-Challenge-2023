class Solution {
public:
     bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;

       vector<bool>dp(s2.length()+1);
        dp[0]=1; //satisfies because s1,s2,and s3 are empty strings
        for(int j=1;j<s2.length()+1;j++){ //check when s1 length is zero
             dp[j]=dp[j-1]&&(s2[j-1]==s3[j-1]);
        }
        
        for(int i=1;i<s1.length()+1;i++){
            dp[0]=(s3[i-1]==s1[i-1])&&dp[0];
            for(int j=1;j<s2.length()+1;j++){
                bool a=(s1[i-1]==s3[i+j-1])&&dp[j];
                bool b=(s2[j-1]==s3[i+j-1])&&dp[j-1];
                dp[j]=a||b;
            }
        }
        return dp[s2.length()];
    }

};
