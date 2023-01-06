class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0;
        int c=0;
        for(int i=0;i<costs.size();i++){
            sum +=costs[i];
            if(sum<=coins)
            c++;
            else
            break;
        }
        return c;
    }
};
