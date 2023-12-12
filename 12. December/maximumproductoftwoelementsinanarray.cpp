class Solution {
public:
    int maxProduct(vector<int>& nums) {
      priority_queue<int> pq;
        int p=1;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        p*=(pq.top())-1;
        pq.pop();
        p*=(pq.top())-1;
        return p;
    }
};
