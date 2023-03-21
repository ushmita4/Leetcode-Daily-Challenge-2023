class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long ans = 0, c = 0;
       
        for(int i = 0; i<a.size() ; i++) {
            if(a[i] == 0) c++;
            else{
                ans += (c* (c+1))/2; c = 0;
            }
        }
        ans += (c*(c+1))/2;
        return ans;
    }
};
