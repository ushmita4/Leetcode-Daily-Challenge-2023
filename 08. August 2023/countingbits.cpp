class Solution {
public:    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++){
            bitset<32> bs(i); 
            ans.push_back(bs.count());
        }
        return ans;
    }
};
