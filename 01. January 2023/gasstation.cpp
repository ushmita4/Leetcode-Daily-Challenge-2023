class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuel=0,price=0,n=cost.size(),currentfuel=0,start=0;
        for(int i=0;i<n;i++)
        {
            fuel+=gas[i];
            price+=cost[i];
        }
        if(fuel<price)
            return -1;
        for(int i=0;i<n;i++){
            if(currentfuel<0){
                start=i;
                currentfuel=0;
            }
            currentfuel+=gas[i]-cost[i];
        }
        return start;
    }
};
