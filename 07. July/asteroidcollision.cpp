class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
 
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(nums[i]>0 || st.empty())
                st.push(nums[i]);     
            else{
                while(!st.empty() && st.top()>0 && st.top() < abs(nums[i]))
                    st.pop();
                if(!st.empty() && st.top() == abs(nums[i]))
                    st.pop();
                else{
                    if(st.empty() || st.top()<0) st.push(nums[i]); 
                }
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
