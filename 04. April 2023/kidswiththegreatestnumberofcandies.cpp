class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int maxi=0;
       vector<bool> ans;
       for(int i=0;i<candies.size();i++){
           maxi=max(candies[i],maxi);
       }
       for(int i=0;i<candies.size();i++){
           if(candies[i]+extraCandies>=maxi)
           ans.push_back(true);
           else
           ans.push_back(false);
       }
       return ans; 
    }
};
