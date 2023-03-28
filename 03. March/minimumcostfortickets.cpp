class Solution {
public:
    int helper(int ind,vector<int>& days,vector<int>& costs,vector<int>& dp){
        if(ind>=days.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];

        int day_1 = costs[0] + helper(ind+1,days,costs,dp);

        auto ub = upper_bound(days.begin()+ind,days.end(),days[ind]+6);
        int day_7 = costs[1] + helper(ub - days.begin(),days,costs,dp);

        ub = upper_bound(days.begin()+ind,days.end(),days[ind]+29);
        int day_30 = costs[2] + helper(ub - days.begin(),days,costs,dp);

        int a = min(day_1 , day_7);
        return dp[ind] = min(a , day_30);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return helper(0,days,costs,dp);
    }
};
